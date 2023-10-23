#pragma once
#ifndef _CONTRACTDAO_H_
#define _CONTRACTDAO_H_
#include "BaseDAO.h"
#include "../../domain/do/ContractType/ContractTypeDO.h"
#include "../../domain/query/ContractType/ContractTypeQuery.h"

class ContractTypeDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const ContractTypeQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<ContractTypeDO> selectWithPage(const ContractTypeQuery::Wrapper& query);
	// ͨ��������ѯ����
	list<ContractTypeDO> selectByName(const string& name);
	// ��������
	uint64_t insert(const ContractTypeDO& iObj);
	// �޸�����
	int update(const ContractTypeDO& uObj);
	// ͨ��IDɾ������
	int deleteById(uint64_t id);
};

#endif // !_CONTRACTDAO_H_