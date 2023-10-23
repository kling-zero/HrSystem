#include "stdafx.h"
#include "LanguageService.h"
#include "../../domain/do/language/LanguageDO.h"
#include "../../dao/language/LanguageDAO.h"
#include "SnowFlake.h"
#include "SimpleDateTimeFormat.h"
#include "bsoncxx/third_party/mnmlstc/core/range.hpp"
#include "uselib/fastdfs/UseFastDFS.h"

/**
 * ��������service��ʵ��
 * �����ˣ���
 */
LanguagePageDTO::Wrapper LanguageService::listAll(const LanguagePageQuery::Wrapper& query)
{
	//�������ض���
	auto pages = LanguagePageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	//��ѯ����������
	LanguageDAO dao;
	uint64_t count = dao.countPage(query);
	if (count <= 0)
	{
		return pages;
	}

	//��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<LanguageDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (LanguageDO sub : result)
	{
		auto dto = LanguageDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, languageAbilityID, LanguageAbilityID, permission, Permission,
			gainTime, GainTime, attachment, Attachment, languageType, LanguageType, createMan, CreateMan,
			updateMan, UpdateMan, languageLevel, LanguageLevel, personID, PersonID, jlss, JLSS,
			jlglbh, JLGLBH, jlspzt, JLSPZT, jlczz, JLCZZ);
		pages->addData(dto);
	}
	return pages;
}

LanguageDTO::Wrapper LanguageService::queryOneDataById(const LanguageQuery::Wrapper& query)
{
	//�������ض���
	auto data = LanguageDTO::createShared();
	//��ѯ����������
	LanguageDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return data;
	}

	//��ȡ��ѯ����
	list<LanguageDO> result = dao.selectOneById(query->languageAbilityID);
	//��DOת����DTO
	//list������
	std::list<LanguageDO>::iterator it = result.begin();
	LanguageDO sub = *it;
	ZO_STAR_DOMAIN_DO_TO_DTO(data, sub, languageAbilityID, LanguageAbilityID, permission, Permission,
		gainTime, GainTime, attachment, Attachment, languageType, LanguageType, createMan, CreateMan,
		updateMan, UpdateMan, languageLevel, LanguageLevel, personID, PersonID, jlss, JLSS,
		jlglbh, JLGLBH, jlspzt, JLSPZT, jlczz, JLCZZ);
	return data;
}

int LanguageService::saveData(const LanguageDTO::Wrapper& dto)
{
	//��װDO����
	LanguageDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, GainTime, gainTime, Attachment, attachment, LanguageType, languageType,
		CreateMan, createMan, LanguageLevel, languageLevel, PersonID, personID);

	//��ʼ��FastDFS������
	UseFastDFS fastDFS("192.168.31.128");
	//�ϴ��ļ�
	string url = fastDFS.upload(dto->attachment);
	data.setAttachment(url);

	//ʹ��SimpleDateTimeFormat�������ɵ�ǰʱ����ַ���
	string currentTime = SimpleDateTimeFormat::format();
	data.setCreateDate(currentTime);

	//ʹ��ѩ��Id���ɹ�������Id
	SnowFlake f3(1, 3);
	string id = to_string(f3.nextId());
	data.setLanguageAbilityID(id);

	// ִ���������;
	LanguageDAO dao;
	return dao.insert(data);
}

bool LanguageService::updateData(const LanguageDTO::Wrapper& dto)
{
	//��װDO����
	LanguageDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, LanguageAbilityID, languageAbilityID, Permission, permission, GainTime, gainTime, Attachment, attachment,
		LanguageType, languageType, UpdateMan, updateMan, LanguageLevel, languageLevel);

	//��ʼ��FastDFS������
	UseFastDFS fastDFS("192.168.31.128");
	//�ϴ��ļ�
	string url = fastDFS.upload(dto->attachment);
	data.setAttachment(url);

	//ʹ��SimpleDateTimeFormat�������ɵ�ǰʱ����ַ���
	string currentTime = SimpleDateTimeFormat::format();
	data.setUpdateDate(currentTime);

	//ִ�������޸�
	LanguageDAO dao;
	return dao.update(data) == 1;
}

int LanguageService::removeData(const DeleteLanguageDTO::Wrapper& dto)
{
	//ִ������ɾ��
	LanguageDAO dao;
	int count = 0;
	for (auto it = dto->languageAbilityID->begin(); it != dto->languageAbilityID->end(); ++it)
	{
		count += dao.deleteById(*it);
	}
	return count;
}
