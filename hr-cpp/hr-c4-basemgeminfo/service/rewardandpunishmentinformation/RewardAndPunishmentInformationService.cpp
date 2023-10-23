#include "stdafx.h"
#include "RewardAndPunishmentInformationService.h"
#include"../../dao/rewardandpunishmentinformation/RewardAndPunishmentInformationDAO.h"
#include <SnowFlake.h>
#include <SimpleDateTimeFormat.h>
#include "ExcelComponent.h"
#include "FastDfsClient.h"
#include "CharsetConvertHepler.h"
#include "domain/do/rewardandpunishmentinformation/RewardAndPunishmentInformationDO.h"
#include "oatpp/core/Types.hpp"


RewardAndPunishmentInformationPageDTO::Wrapper RewardAndPunishmentInformationService::listAll(const RewardAndPunishmentInformationPageQuery::Wrapper& query)
{
	// �������ض���
	auto pages = RewardAndPunishmentInformationPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	RewardAndPunishmentInformationDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	//��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<RewardAndPunishmentInformationDO> result = dao.selectWithPage(query);
	//��DO����DTO
	for (RewardAndPunishmentInformationDO sub : result)
	{
		auto dto = RewardAndPunishmentInformationDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, lx, Lx, pimrewardpunishmentname, Pimrewardpunishmentname, pimpersonid, Pimpersonid, pimrewardpunishmentid, Pimrewardpunishmentid, jcjb, Jcjb, jcje, Jcje, jlsj, Jlsj, jcsj, Jcsj, bz, Bz, fj, Fj, updateman, Updateman, createman, Createman, createdate, Createdate, updatedate, Updatedate);
		pages->addData(dto);
	}
	return pages;
}

uint64_t RewardAndPunishmentInformationService::saveData(const AddRewardAndPunishmentInformationDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// ��װDO����
	RewardAndPunishmentInformationDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Lx, lx, Pimrewardpunishmentname, pimrewardpunishmentname, Jcjb, jcjb, Jcje, jcje, Jlsj, jlsj, Jcsj, jcsj,  Pimpersonid, pimpersonid, Pimrewardpunishmentid, pimrewardpunishmentid, Updateman, updateman, Createman, createman, Createdate, createdate, Updatedate, updatedate, Bz, bz, Fj, fj);
	// ����Ψһ��ʶ
	SnowFlake sf(1, 4);
	auto id = sf.nextId();
	data.setPimrewardpunishmentid(to_string(id));
	// ���ø���ʱ��ʹ���ʱ��
	data.setUpdatedate(SimpleDateTimeFormat::format());
	data.setCreatedate(data.getUpdatedate());
	// �Ӹ��������л�ȡ������
	data.setCreateman(payload.getUsername());
	data.setUpdateman(payload.getUsername());
	// ִ���������
	RewardAndPunishmentInformationDAO dao;
	if (dao.insert(data)) {
		return id;
	}
	return 0;
}

bool RewardAndPunishmentInformationService::removeData(const DelRewardAndPunishmentInformationDTO::Wrapper& dto)
{
	RewardAndPunishmentInformationDAO dao;
	std::string pimpersonid = dto->pimpersonid;
	for (auto it = dto->deleteById->begin(); it != dto->deleteById->end(); ++it)
	{
		dao.deleteById(pimpersonid, *it);
	}
	return true;
}

uint64_t RewardAndPunishmentInformationService::saveManyData(const String& fileBody, const oatpp::data::mapping::type::String& suffix, const oatpp::data::mapping::type::String& pimpersonid, const PayloadDTO& payload)
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

	std::string sheetName = CharsetConvertHepler::ansiToUtf8("������Ϣ��");
	// ���ļ��ж�ȡ
	auto readData = excel.readIntoVector(fileName, sheetName);
	RewardAndPunishmentInformationDAO dao;
	SnowFlake sf(1, 4);
	bool tem = true;
	int len = 0;
	for (auto row : readData)
	{

		//�ж��ļ����Ƿ�������
		for (unsigned int j = 0; j < row.size(); ++j)
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
		RewardAndPunishmentInformationDO data(row);
		//ѩ���㷨����id
		data.setPimrewardpunishmentid(to_string(sf.nextId()));

		//�ж���˭�Ŀ��гɹ�
		data.setPimpersonid(pimpersonid);

		//����ʱ��
		//SimpleDateTimeFormat times;
		data.setUpdatedate(SimpleDateTimeFormat::format());
		data.setCreatedate(data.getUpdatedate());
		// �Ӹ��������л�ȡ������
		data.setCreateman(payload.getUsername());
		data.setUpdateman(payload.getUsername());

		//��������
		len = dao.insert(data);

	}
	return uint64_t(len);
}
