#pragma once
#ifndef _ASSIGN_INFO_DAO_
#define _ASSIGN_INFO_DAO_
#include "BaseDAO.h"
#include "../../domain/do/assignInfoDO/AssignInfoDO.h"
#include "../../domain/query/assignInfo/AssignInfoQuery.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class AssignInfoDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const AssignInfoQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<AssignInfoDO> selectWithPage(const AssignInfoQuery::Wrapper& query);
	// ͨ��id��ѯ����
	list<AssignInfoDO> selectById(const string& id);
	// ��������
	uint64_t insert(const AssignInfoDO& iObj);
	// �޸�����
	int update(const AssignInfoDO& uObj);
	// ͨ��IDɾ������
	int deleteById(string id);
};
#endif // !_ASSIGN_INFO_DAO_
