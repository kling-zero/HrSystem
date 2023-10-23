#pragma once
#ifndef _CONTRACT_CATEGORY_DAO_H_
#define _CONTRACT_CATEGORY_DAO_H_

#include "BaseDAO.h"
#include "../../domain/do/contractcategory/ContractCategoryDO.h"
#include "../../domain/query/contractcategory/ContractCategoryQuery.h"

/**
 * ��ͬ���ͱ����ݿ����ʵ��
 */
class ContractCategoryDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const ContractCategoryQuery::Wrapper& query);
	// ��ҳ��ѯ����
	std::list<ContractCategoryDO> selectWithPage(const ContractCategoryQuery::Wrapper& query);
	// ����Id��ѯ����
	ContractCategoryDO selectById(const std::string& id);
	// �����µĺ�ͬ����
	uint64_t insert(const ContractCategoryDO& data);
	// �����ض���ͬ����
	int update(const ContractCategoryDO& data);
	// ɾ���ض���ͬ����
	int deleteById(const std::string& id);
};

#endif // _CONTRACT_CATEGORY_DAO_H_
