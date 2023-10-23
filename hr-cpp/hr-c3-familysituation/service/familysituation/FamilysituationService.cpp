#include "stdafx.h"
#include "FamilysituationService.h"
#include "SnowFlake.h"
#include "SimpleDateTimeFormat.h"
#include "../../dao/Familysituation/FamilysituationDAO.h"

// ��ҳ��ѯ��������
FamilysituationPageDTO::Wrapper FamilysituationService::listAll(const FamilysituationQuery::Wrapper& query)
{
	// �������ض���
	auto pages = FamilysituationPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	FamilysituationDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}
	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<FamilysituationDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (FamilysituationDO sub : result)
	{
		auto dto = FamilysituationDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, Id, personid, PersonId, name, Name, frelationship, Relationship, doctype, Doctype, \
			identification, Identification, gender, Gender, dob, Dob, age, Age, workplace, Workplace, job, Job, \
			politicalstatus, Politicalstatus, testament, Testament, ice, Ice);
			pages->addData(dto);
	}
	return pages;
}

FamilysituationDTO::Wrapper FamilysituationService::getOne(const FamilysituationQuery::Wrapper& query)
{
	// �������ض���
	auto data = FamilysituationDTO::createShared();

	// ��ʼ��dao����
	FamilysituationDAO dao;

	// ָ����ѯ����
	list<FamilysituationDO> result = dao.selectWithOne(query);
	// ��DOת����DTO
	for (FamilysituationDO sub : result)
	{
		ZO_STAR_DOMAIN_DO_TO_DTO(data, sub, id, Id, personid, PersonId, name, Name, frelationship, Relationship, doctype, Doctype, \
			identification, Identification, gender, Gender, dob, Dob, age, Age, workplace, Workplace, job, Job, \
			politicalstatus, Politicalstatus, testament, Testament, ice, Ice);
	}
	return data;
}

uint64_t FamilysituationService::saveData(const FamilysituationDTO::Wrapper& dto, const std::string authId)
{
	// ѩ���㷨����id
	SnowFlake c3(1, 3);
	dto->id = to_string(c3.nextId());
	// ������Ա��¼
	dto->authid = authId;
	// ����ʱ���¼
	dto->opertime = SimpleDateTimeFormat::format("%Y-%m-%d %H:%M:%S");
	// ��װDO����
	FamilysituationDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, PersonId, personid, Id, id, Name, name, Relationship, frelationship, Doctype, doctype, \
		Identification, identification, Gender, gender, Dob, dob, Age, age, Workplace, workplace, Job, job, \
		Politicalstatus, politicalstatus, Testament, testament, Ice, ice, AuthId, authid, Opertime, opertime);
	// ִ���������
	FamilysituationDAO dao;
	return dao.insert(data);
}

bool FamilysituationService::updateData(const FamilysituationDTO::Wrapper& dto, const std::string authId)
{
	// ��װDO����
	FamilysituationDO data;
	// ������Ա��¼
	dto->authid = authId;
	// ����ʱ���¼
	dto->opertime = SimpleDateTimeFormat::format("%Y-%m-%d %H:%M:%S");
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, PersonId, personid, Id, id, Name, name, Relationship, frelationship, Doctype, doctype, \
		Identification, identification, Gender, gender, Dob, dob, Age, age, Workplace, workplace, Job, job, \
		Politicalstatus, politicalstatus, Testament, testament, Ice, ice, AuthId, authid, Opertime, opertime);
	// ִ�������޸�
	FamilysituationDAO dao;
	return dao.update(data) == 1;
}

int FamilysituationService::removeData(const FamilyBatchDeleteDTO::Wrapper& dto)
{
	FamilysituationDAO dao;
	int count = 0;
	for (auto it = dto->batchFamilyId->begin(); it != dto->batchFamilyId->end(); it++)
	{
		// ��װDO����
		FamilysituationDO data;
		data.setId(it->getValue({}));
		count += dao.deleteById(data);
	}
	return count;
}
