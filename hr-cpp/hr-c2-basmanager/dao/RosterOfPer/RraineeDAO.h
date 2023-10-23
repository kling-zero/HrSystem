#pragma once
/*

*/
#ifndef _SAMPLE_DAO_
#define _SAMPLE_DAO_
#include "BaseDAO.h"
#include "../../domain/do/RosterOfPer/RraineeDO.h"
#include "../../domain/query/RosterOfPer/RraineeQuery.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class RraineeDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const RraineeQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<RraineeDO> selectWithPage(const RraineeQuery::Wrapper& query);
	//// ͨ��������ѯ����
	//list<RraineeDO> selectByName(const string& name);
	//// ��������
	//uint64_t insert(const RraineeDO& iObj);
	//// �޸�����
	//int update(const RraineeDO& uObj);
	//// ͨ��IDɾ������
	//int deleteById(uint64_t id);
};
#endif // !_SAMPLE_DAO_
