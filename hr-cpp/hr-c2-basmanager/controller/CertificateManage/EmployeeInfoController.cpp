#include "stdafx.h"
#include "EmployeeInfoController.h"
//#include "../../service/CertificateManage/EmployeeInfoService.h"
/**
* ֤�������Ա��Ϣ��ѯ��������ʹ��--(֤�����-��ҳ��ѯԱ����Ϣ)-weixiaoman
*/
EmployeeInfoPageJsonVO::Wrapper EmployeeInfoController::execQueryEmpInfo(const EmployeeInfoQuery::Wrapper& query, const PayloadDTO& payload)
{
	//// ����һ��Service
	//EmployeeInfoService service;
	//// ��ѯ����
	//auto result = service.listAll(query);
	//// ��Ӧ���
	auto jvo = EmployeeInfoPageJsonVO::createShared();
	//jvo->success(result);
	return jvo;
}
