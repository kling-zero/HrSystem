#include "stdafx.h"
#include "SciResultService.h"
#include"../../dao/sciresult/SciResultDAO.h"
#include <SnowFlake.h>
#include <SimpleDateTimeFormat.h>
#include "ExcelComponent.h"
#include "FastDfsClient.h"
#include "CharsetConvertHepler.h"
#include "domain/do/sciresult/SciResultDO.h"
using namespace oatpp;
SciResultPageDTO::Wrapper SciResultService::listAll(const SciResultQuery::Wrapper& query)
{
	// �������ض���
	auto pages = SciResultPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	SciResultDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<SciResultDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (SciResultDO sub : result)
	{
		auto dto = SciResultDTO::createShared();

		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub,UPDATEMAN,_UPDATEMAN, PIMRESEARCHFINDINGSNAME, _PIMRESEARCHFINDINGSNAME, FJ, _FJ,ENABLE,_ENABLE, CREATEDATE,_CREATEDATE,CREATEMAN,_CREATEMAN,UPDATEDATE,_UPDATEDATE,CREATEMAN,_CREATEMAN, PIMRESEARCHFINDINGSID, _PIMRESEARCHFINDINGSID, PIMPERSONID, _PIMPERSONID, HQSJ, _HQSJ,JLSS,_JLSS, JLSPZT,_JLSPZT, JLGLBH,_JLGLBH, JLCZZ,_JLCZZ, REASON,_REASON);
		pages->addData(dto);

	}
	return pages;
}
uint64_t SciResultService::saveData(const Add2SciResultDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// ��װDO����
	SciResultDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, _PIMRESEARCHFINDINGSNAME, PIMRESEARCHFINDINGSNAME, _HQSJ, HQSJ, _FJ, FJ, _PIMPERSONID, PIMPERSONID);
	// ����Ψһ��ʶ
	SnowFlake sf(1, 4);
	auto id = sf.nextId();
	data.set_PIMRESEARCHFINDINGSID(to_string(id));
	// ���ø���ʱ��ʹ���ʱ��
	data.set_UPDATEDATE(SimpleDateTimeFormat::format());
	data.set_CREATEDATE(data.get_UPDATEDATE());
	// �Ӹ��������л�ȡ������
	data.set_CREATEMAN(payload.getUsername());
	data.set_UPDATEMAN(payload.getUsername());
	// ִ���������
	SciResultDAO dao;
	if (dao.insert(data)) {
		return id;
	}
	return 0;
}
bool SciResultService::removeData(const DelSciResultDTO::Wrapper& dto)
{
	/*// ��װDO����
	DelWorkHistoryDO data;


	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, pIMPERSONID, pimpersonid);*/

	SciResultDAO dao;
	std::string pimpersonid = dto->PIMPERSONID;
	for (auto it = dto->deleteById->begin(); it != dto->deleteById->end(); ++it)
	{
		dao.deleteById(pimpersonid, *it);
	}
	return true;
}
uint64_t SciResultService::saveManyData(const String& fileBody, const oatpp::data::mapping::type::String& suffix, const oatpp::data::mapping::type::String& pimpersonid, const PayloadDTO& payload)
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


	// ���浽�ļ�
	ExcelComponent excel;

	std::string sheetName = CharsetConvertHepler::ansiToUtf8("���гɹ���");
	// ���ļ��ж�ȡ
	auto readData = excel.readIntoVector(fileName, sheetName);

	SciResultDAO dao;

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
		SciResultDO data(row);
		//ѩ���㷨����id
		data.set_PIMRESEARCHFINDINGSID(to_string(sf.nextId()));

		//�ж���˭�Ŀ��гɹ�
		data.set_PIMPERSONID(pimpersonid);

		//����ʱ��
		data.set_UPDATEDATE(SimpleDateTimeFormat::format());
		data.set_CREATEDATE(data.get_UPDATEDATE());
		// �Ӹ��������л�ȡ������
		data.set_CREATEMAN(payload.getUsername());
		data.set_UPDATEMAN(payload.getUsername());

		//��������
		dao.insert(data);

	}

	return uint64_t(1);
	//ִ������߼�
}
