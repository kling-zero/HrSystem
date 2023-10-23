#pragma once

#ifndef _LEGALENTITYMAISERVICE_H_
#define _LEGALENTITYMAISERVICE_H_
#include <list>
#include "domain/dto/LegalEntityMai/LegalEntityMaiDTO.h"
#include "domain/query/LegalEntityMai/LegalEntityMaiQuery.h"
#include "domain/dto/LegalEntityMai/LegalEntityMaiDelDTO.h"
#include "domain/dto/LegalEntityMai/LegalEntityMaiAddDTO.h"

/* ��������ά������ʵ��--����֯����-��������-��������ά����--TripleGold */
class LegalEntityMaiService
{
public:
	// ��ҳ��ѯ��������
	LegalEntityMaiPageDTO::Wrapper listAll(const LegalEntityMaiQuery::Wrapper& query);
	// �޸�����
	bool updateData(const LegalEntityMaiDTO::Wrapper& dto);
	// ��������
	uint64_t saveData(const LegalEntityMaiAddDTO::Wrapper& dto, const PayloadDTO& payload);
	// �����ļ�
	uint64_t savaBatchDataWithFile(const std::string fileName, const PayloadDTO& payload);
	// ͨ��ID����ɾ������
	bool deleteById(const LegalEntityMaiDelDTO::Wrapper& dto);
	// �����ļ�
	std::string exportFile(const LegalEntityMaiQuery::Wrapper& query);
};

#endif // !_LEGALENTITYMAISERVICE_H_