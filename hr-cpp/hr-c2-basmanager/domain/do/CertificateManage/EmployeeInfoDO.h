#pragma once
#ifndef _EMPLOYEEINFO_DO_
#define _EMPLOYEEINFO_DO_
#include "../DoInclude.h"
/**
 * ��Ա��Ϣ��ҳ��ѯDO--(֤�����-��ҳ��ѯԱ����Ϣ�б�)--weixiaoman
 */
class EmployeeInfoDO {
	// ����
	CC_SYNTHESIZE(string, name, Name);
	// ��ţ�Ψһ��ʶ��
	CC_SYNTHESIZE(string, id, Id);
public:
	EmployeeInfoDO() {
		name = "";
		id = "";
	}
};
#endif // !_EMPLOYEEINFO_DO_


