#pragma once
#ifndef _EMPLOYEEINFO_DAO_
#define _EMPLOYEEINFO_DAO_
#include "BaseDAO.h"
#include "../../domain/do/CertificateManage/EmployeeInfoDO.h"
#include "../../domain/query/CertificateManage/EmployeeInfoQuery.h"

/**
 * ��Ա��Ϣ��ҳ��ѯDAO--(֤�����-��ҳ��ѯԱ����Ϣ�б�)--weixiaoman
 */
class EmployeeInfoDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const EmployeeInfoQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<EmployeeInfoDO> selectWithPage(const EmployeeInfoQuery::Wrapper& query);
	// �������ֲ�ѯ
	list<EmployeeInfoDO> selectByName(const string& name);
};
#endif // !_EMPLOYEEINFO_DAO_