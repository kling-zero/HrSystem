#pragma once
#ifndef _EMPLOYEEINFO_SERVICE_
#define _EMPLOYEEINFO_SERVICE_
#include <list>
#include "domain/vo/CertificateManage/EmployeeInfoVO.h"
#include "domain/dto/CertificateManage/EmployeeInfoDTO.h"
#include "domain/query/CertificateManage/EmployeeInfoQuery.h"
/**
 * ��Ա��Ϣ��ҳ��ѯservice--(֤�����-��ҳ��ѯԱ����Ϣ�б�)--weixiaoman
 */
class EmployeeInfoService {
public:
	EmployeeInfoPageDTO::Wrapper listAll(const EmployeeInfoQuery::Wrapper& query);
};



#endif // !_EMPLOYEEINFO_SERVICE_