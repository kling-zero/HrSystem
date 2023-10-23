#pragma once
/*
����Ա������-��Ա������-��ҳ��ѯԱ�����ݣ�--����
*/
#ifndef _EMPLOYEEPAGE_DAO_
#define _EMPLOYEEPAGE_DAO_
#include "BaseDAO.h"
#include "../../domain/do/RosterOfPer/RosterPersonDO.h"
#include "../../domain/query/RosterOfPer/EmployeePageQuery.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class EmployeePageDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const EmployeePageQuery::Wrapper& query);
	
	// ��ҳ��ѯ����
	list<RosterPersonDO> selectWithPage(const EmployeePageQuery::Wrapper& query);

};
#endif // !_EMPLOYEEPAGE_DAO_
