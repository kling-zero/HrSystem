#pragma once
#ifndef _Gosh_DAO_
#define _Gosh_DAO_
#include "BaseDAO.h"
#include "domain/do/Gosh/ContractDO.h"
#include "domain/query/Gosh/ContractQuery.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class GoshDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const ContractQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<ContractDO> selectWithPage(const ContractQuery::Wrapper& query);
	// ͨ��������ѯ����
	list<ContractDO> selectByName(const string& name);
	// ��������
	uint64_t insert(const ContractDO& iObj);
	// ͨ��IDɾ������
	int deleteById(std::string id);
};
#endif // !_SAMPLE_DAO_