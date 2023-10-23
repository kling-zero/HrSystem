#pragma once
#ifndef _LEGALENTITYMAIDAO_H_
#define _LEGALENTITYMAIDAO_H_
#include "BaseDAO.h"
#include "domain/query/LegalEntityMai/LegalEntityMaiQuery.h"
#include "domain/do/LegalEntityMai/ormsignorgDO.h"

/* ��������ά��DAO�����--����֯����-��������-��������ά����--TripleGold */
class LegalEntityMaiDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const LegalEntityMaiQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<OrmsignorgDO> selectWithPage(const LegalEntityMaiQuery::Wrapper& query);
	// ͨ�����Ʋ�ѯ����
	//list<OrmsignorgDO> selectByName(const string& name);
	// ��������
	uint64_t insert(const OrmsignorgDO& iObj);
	// �޸�����
	int update(const OrmsignorgDO& uObj);
	// ͨ��IDɾ������
	int deleteById(string id);
};

#endif // !_LEGALENTITYMAIDAO_H_