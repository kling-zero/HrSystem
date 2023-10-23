/*
����Ա������-��Ա������-��ҳ��ѯԱ���б�--����
*/
#include "stdafx.h"
#include "EmployeePageController.h"
#include "../../service/RosterOfPer/EmployeePageService.h"

EmployeePageJsonVO::Wrapper EmployeePageController::execQueryEmployeePage(const EmployeePageQuery::Wrapper& query, const PayloadDTO& payload)
{
	// ����һ��Service
	EmployeePageService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = EmployeePageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
