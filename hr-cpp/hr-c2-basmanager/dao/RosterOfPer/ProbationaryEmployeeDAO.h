#pragma once
#include "BaseDAO.h"
#include "../../domain/do/RosterOfPer/ProbationaryEmployeeDO.h"
#include "../../domain/query/RosterOfPer/ProbationaryEmployeeQuery.h"

/**
 * ��Ա������ - ������Ա���ݿ����ʵ�� - ������
 */
class ProbationaryEmployeeDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const ProbationaryEmployeeQuery::Wrapper& query);
	// ��ҳ��ѯ��ְԱ������
	list<ProbationaryEmployeeDO> selectWithPage(const ProbationaryEmployeeQuery::Wrapper& query);
	// ��ҳ��ѯ��ְԱ������
	list<ProbationaryEmployeeDO> selectAll(const ProbationaryEmployeeQuery::Wrapper& query);
	// ͨ��������ѯ����
	list<ProbationaryEmployeeDO> selectByName(const string& name);
	// ͨ����Ų�ѯ����
	list<ProbationaryEmployeeDO> selectById(const string& id);
};
#pragma once
