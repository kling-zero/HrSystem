#include "stdafx.h"
#include "LegalEntityMaiService.h"
#include "dao/LegalEntityMai/LegalEntityMaiDAO.h"
#include "CharsetConvertHepler.h"
#include "ExcelComponent.h"
#include "FastDfsClient.h"
#include "SnowFlake.h"
#include "SimpleDateTimeFormat.h"

/* ��������ά��Service�����ʵ��--����֯����-��������-��������ά����--TripleGold */
LegalEntityMaiPageDTO::Wrapper LegalEntityMaiService::listAll(const LegalEntityMaiQuery::Wrapper& query)
{
	// �������ض���
	auto pages = LegalEntityMaiPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	LegalEntityMaiDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0) {
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<OrmsignorgDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (OrmsignorgDO sub : result)
	{
		auto dto = LegalEntityMaiDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, ORMSIGNORGID, Id, ORMSIGNORGNAME, Name,ORGCODE, Code);
		/*ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, ORMSIGNORGID, ORMSIGNORGID,
			UPDATEMAN, UPDATEMAN, CREATEMAN, CREATEMAN,
			CREATEDATE, CREATEDATE, ORMSIGNORGNAME, ORMSIGNORGNAME,
			UPDATEDATE, UPDATEDATE, ORGCODE, ORGCODE, ZZJC, ZZJC);*/
		pages->addData(dto);
	}
	return pages;
}

bool LegalEntityMaiService::updateData(const LegalEntityMaiDTO::Wrapper& dto)
{
	// ��װDO����
	OrmsignorgDO data;
	/*data.setId(dto->ORMSIGNORGID.getValue(""));
	data.setName(dto->ORMSIGNORGNAME.getValue(""));
	data.setCode(dto->ORGCODE.getValue(""));*/
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Id, ORMSIGNORGID, Name, ORMSIGNORGNAME, Code, ORGCODE);
	// ִ���������
	LegalEntityMaiDAO dao;
	return dao.update(data) == 1;
}

uint64_t LegalEntityMaiService::saveData(const LegalEntityMaiAddDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// ��װDO����
	OrmsignorgDO data;
	/*data.setName(dto->ORMSIGNORGNAME.getValue(""));
	data.setCode(dto->ORGCODE.getValue(""));*/
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Name, ORMSIGNORGNAME, Code, ORGCODE);
	
	// ѩ���㷨����Ψһ��ʶID
	SnowFlake f2(1, 2);
	data.setId(to_string(f2.nextId()));
	// ����ʱ��
	SimpleDateTimeFormat time;
	data.setCreateman(payload.getUsername());
	data.setCreateDate(time.format());
	data.setUpdateman(payload.getUsername());
	data.setUpdatedate(time.format());

	// ִ���������
	LegalEntityMaiDAO dao;
	return dao.insert(data);
}

uint64_t LegalEntityMaiService::savaBatchDataWithFile(const std::string fileName, const PayloadDTO& payload)
{
	// ���浽�ļ�
	ExcelComponent excel;
	std::string sheetName = CharsetConvertHepler::ansiToUtf8("���������");
	// ���ļ��ж�ȡ
	auto readData = excel.readIntoVector(fileName, sheetName);

	LegalEntityMaiDAO dao;

	SnowFlake f2(1, 2);

	bool temp = true;	// ��ֹ�ѱ�ͷҲ�������ݿ�
	for (auto row : readData)
	{
		// �ж��ļ����Ƿ�������
		for (size_t j = 0; j < row.size(); ++j)
		{
			if (row[j].empty()) return -1;
			std::cout << CharsetConvertHepler::utf8ToAnsi(row[j]) << " ";
		}

		std::cout << std::endl;
		if (temp) {
			temp = false;
			continue;
		}
		OrmsignorgDO data(row);
		// ѩ���㷨����Ψһ��ʶID
		data.setId(to_string(f2.nextId()));
		// ����ʱ��
		SimpleDateTimeFormat time;
		data.setCreateman(payload.getUsername());
		data.setCreateDate(time.format());
		data.setUpdateman(payload.getUsername());
		data.setUpdatedate(time.format());

		// ��������
		if (!dao.insert(data)) return -1;
	}
	return 1;
}

bool LegalEntityMaiService::deleteById(const LegalEntityMaiDelDTO::Wrapper& dto)
{
	LegalEntityMaiDAO dao;
	// ������ѭ��ɾ������
	for (auto it = dto->Ids->begin(); it != dto->Ids->end(); it++) {
		dao.deleteById(*it);
	}
	return true;
}

std::string LegalEntityMaiService::exportFile(const LegalEntityMaiQuery::Wrapper& query)
{
	// ������������
	LegalEntityMaiDAO dao;
	// ��������ѯ��������
	uint64_t cnt = dao.count(query);
	if (cnt > 5000) {
		query->pageSize = 5000;
	}
	else {
		query->pageSize = cnt;
	}
	// �õ���ѯ���
	list<OrmsignorgDO> res = dao.selectWithPage(query);
	
	
	std::vector<std::vector<std::string>> data;
	// ����Excel��ͷ
	std::vector<std::string> row;
	row.push_back(CharsetConvertHepler::ansiToUtf8("����������֯"));
	row.push_back(CharsetConvertHepler::ansiToUtf8("��֯���"));
	data.push_back(row);
	// ���ݲ�ѯ�������Excel����
	for (auto info : res)
	{
		row.clear();
		row.push_back(info.getName());
		row.push_back(info.getCode());
		data.push_back(row);
	}

	// ���屣������λ�ú�ҳǩ����
	std::string fileName = "./public/excel/LegalEntityMai.xlsx";
	// ע�⣺��Ϊxlnt���ܴ洢��utf8������ַ���������������Ҫת������
	std::string sheetName = CharsetConvertHepler::ansiToUtf8("���������");

	// ���浽�ļ�
	ExcelComponent excel;
	excel.writeVectorToFile(fileName, sheetName, data);
	// ���ļ��ж�ȡ
	auto readData = excel.readIntoVector(fileName, sheetName);
	for (auto row : readData)
	{
		for (auto cellVal : row)
		{
			// ע�⣺����ʹ���˱���ת����Ŀ����Ϊ���ڿ���̨��ӡ��ʾ�����룬����ǽ�����д�����ݿ⣬��ô�Ͳ���Ҫ�ٽ��б���ת����
			cout << CharsetConvertHepler::utf8ToAnsi(cellVal) << ",";
		}
		cout << endl;
	}

	// �ϴ��ļ���FastDfs
#ifdef LINUX
//����ͻ��˶���
	FastDfsClient client("conf/client.conf");
#else
	//����ͻ��˶���
	FastDfsClient client("192.168.241.128");
#endif
	std::string fieldName = client.uploadFile(fileName);
	std::cout << "upload fieldName is: " << fieldName << std::endl;
	remove(fileName.c_str());
	// ��������·��
	std::string url;
	url = "http://192.168.241.128:8888/" + fieldName;
	return url;
}

