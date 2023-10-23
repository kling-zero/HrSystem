#include "stdafx.h"
#include "PimarmycadresService.h"
#include "dao/pimarmycadres/PimarmycadresDAO.h"
#include "domain/do/pimarmycadres/DelPimarmycadresDO.h"
#include "domain/do/pimarmycadres/AddPimarmycadresDO.h"
#include "ExcelComponent.h"
#include "CharsetConvertHepler.h"
#include "domain/do/pimarmycadres/PimarmycadresIntoDO.h"
#include "SnowFlake.h"
#include "SimpleDateTimeFormat.h"
#include "FastDfsClient.h"


uint64_t PimarmycadresService::saveManyData(const oatpp::String& fileBody, const oatpp::data::mapping::type::String& suffix, const oatpp::data::mapping::type::String& pimpersonid, const PayloadDTO& payload)
{
	// ����ʱ�������һ����ʱ�ļ�����
	std::stringstream ss;
	ss << "public/static/Excel/";

	// ����ʱ���
	auto now = std::chrono::system_clock::now();
	auto tm_t = std::chrono::system_clock::to_time_t(now);
	ss << std::put_time(std::localtime(&tm_t), "%Y%m%d%H%M%S");
	// ��ȡ����
	auto tSeconds = std::chrono::duration_cast<std::chrono::seconds>(now.time_since_epoch());
	auto tMilli = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch());
	auto ms = tMilli - tSeconds;
	ss << std::setfill('0') << std::setw(3) << ms.count();
	// ƴ�Ӻ�׺��
	ss << suffix.getValue("");

	// ��ʱ�ļ�����
	std::string fileName = ss.str();
	// �����ļ�����ʱĿ¼
	fileBody.saveToFile(fileName.c_str());

	// �ϴ���FastDFS�ļ�������----------------------------------------//
#ifdef LINUX
	//����ͻ��˶���
	FastDfsClient client("conf/client.conf", 3);
#else
	//����ͻ��˶���
	FastDfsClient client("8.130.87.15");
#endif
	std::string fieldName = client.uploadFile(fileName);
	//std::cout << "upload fieldname is : " << fieldName << std::endl;
	ss.str("");
	ss.clear();
	ss << "http://8.130.87.15:8888/" << fieldName;
	cout << ss.str() << endl;
	//�ϴ����----------------------------------------------------------//


	//��fastdfs�����ļ�--------------------------------------------------//
//#ifdef LINUX
//		// ��������ǰ׺
//		std::string urlPrefix;
//	//����ͻ��˶���
//	// ����һ��Nacos�ͻ��˶������ڻ�ȡ����
//	NacosClient ns(ServerInfo::getInstance().getNacosAddr(), ServerInfo::getInstance().getNacosNs());
//	// ����urlǰ׺
//	auto thirdServerConfig = ns.getConfig("third-services.yaml");
//	urlPrefix = "http://" + YamlHelper().getString(&thirdServerConfig, "fastdfs.nginx-servers") + "/";
//	// ��Nacos�������Ļ�ȡFastDFS�ͻ�����������
//	std::string config = ns.getConfigText("client.conf");
//	// ����ͻ��˶���
//	FastDfsClient client(config, false);
//#else
////����ͻ��˶���
//	FastDfsClient client("80.130.87.15");
//#endif
	string name;
	if (!fileName.empty()){
		std::string path = "public/static/Excel/";
		name = client.downloadFile(fieldName, &path);
		std::cout << "download savepath is : " << name << std::endl;
	}
	//�������-------------------------------------------------------------//

	// ���浽�ļ�
	ExcelComponent excel;

	std::string sheetName = CharsetConvertHepler::ansiToUtf8("��ת�ɲ���");
	// ���ļ��ж�ȡ
	auto readData = excel.readIntoVector(name, sheetName);

	PimarmycadresDAO dao;

	SnowFlake sf(1, 4);

	bool tem = true;
	for (auto row : readData)
	{

		//�ж��ļ����Ƿ�������
		for (size_t j = 0; j < row.size(); ++j)
		{
			if (row[j].empty())
			{
				return -1;
			}	
			std::cout << CharsetConvertHepler::utf8ToAnsi(row[j]) << "   ";
		}

		std::cout << endl;
		if (tem)
		{
			tem = false;
			continue;
		}
		AddPimarmycadresDO data(row);
		//ѩ���㷨����id
		data.setpIMARMYCADRESID(to_string(sf.nextId()));

		data.setpIMID(pimpersonid);

		//����ʱ��
		//SimpleDateTimeFormat times;
		data.setuPDATEDATE(SimpleDateTimeFormat::format());
		data.setcREATEDATE(data.getcREATEMAN());
		// �Ӹ��������л�ȡ������
		data.setcREATEMAN(payload.getUsername());
		data.setuPDATEMAN(payload.getUsername());

		//��������
		dao.insert(data);

	}

	return uint64_t(1);
}

PimarmycadresDTO::Wrapper PimarmycadresService::listDetail(const PimarmycadresQuery::Wrapper& query)
{
	// �������ض���
	//auto lists = MilitaryDTO::createShared();
	PimarmycadresDAO dao;
	auto lists = dao.selectDetail(query);
	auto dto = PimarmycadresDTO::createShared();
	if (!lists.empty()) {
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, lists.front(), pimid, pIMID, 
			form, fORM, 
			level, lEVEL, 
			occurtime, oCCURTIME, 
			annexPath, aNNEXPATH);
	}
	return dto;
}

bool PimarmycadresService::updateData(const PimarmycadresDTO::Wrapper& dto)
{
	// ��װDO����
	PimarmycadresDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Pimid,pimid);
	// ִ�������޸�
	PimarmycadresDAO dao;
	return dao.update(data) == 1;
}


PimarmycadresFindPageDTO::Wrapper PimarmycadresService::listAll(const PimarmycadresPageQuery::Wrapper& query)
{
	// �������ض���
	auto pages = PimarmycadresFindPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	PimarmycadresDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<PimarmycadresFindDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (PimarmycadresFindDO sub : result)
	{
		auto dto = PimarmycadresFindDTO::createShared();
		// 		dto->id = sub.getId();
		// 		dto->name = sub.getName();
		// 		dto->sex = sub.getSex();
		// 		dto->age = sub.getAge();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, pimid, pIMID,
			form, fORM,
			level, lEVEL,
			occurtime,oCCURTIME,
			annexPath, aNNEXPATH);

		pages->addData(dto);
		dto.getPtr().get()->annexPath;
	}
	

	return pages;
}

uint64_t PimarmycadresService::saveData(const AddPimarmycadresDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// ��װDO����
	AddPimarmycadresDO data;
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, pIMID,pimid,
		fORM,form,
		lEVEL,level,
		oCCURTIME,occurtime,
		aNNEXPATH,annexPath,
		pIMARMYCADRESID,pimarmycadresid)
		// ִ���������
		PimarmycadresDAO dao;
	SnowFlake sf(1, 4);
	SimpleDateTimeFormat times;
	data.setpIMARMYCADRESID(to_string(sf.nextId()));

	data.setcREATEMAN(payload.getUsername());
	data.setuPDATEMAN(payload.getUsername());
	data.setcREATEDATE(times.format());
	data.setuPDATEDATE(times.format());

		
	return dao.insert(data);
}


bool PimarmycadresService::removeData(const DelPimarmycadresDTO::Wrapper& dto)
{
	PimarmycadresDAO dao;
	std::string pimpersonid = dto->pimid;
	for (auto it = dto->deleteById->begin(); it != dto->deleteById->end(); ++it)
	{
		dao.deleteById(pimpersonid, *it);
	}
	return true;
}


