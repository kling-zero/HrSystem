#include "stdafx.h"
#include "ProbationaryEmployeeController.h"
#include "../../service/RosterOfPer/ProbationaryEmployeeService.h"
/**
 *  �������� ���� ��Ա������ ���� ����Ա�� ���� ������
 */
ProbationaryEmployeePageJsonVO::Wrapper ProbationaryEmployeeController::execQueryProbationaryEmployee(const ProbationaryEmployeeQuery::Wrapper& query, const PayloadDTO& payload)
{
	// ����һ��Service
	ProbationaryEmployeeService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = ProbationaryEmployeePageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

StringJsonVO::Wrapper ProbationaryEmployeeController::execExportProbationaryEmployee(const ProbationaryEmployeeQuery::Wrapper& query, const PayloadDTO& payload)
{
	auto jvo = StringJsonVO::createShared();

	ProbationaryEmployeeService Service;

	auto result = Service.exportData(query);
	jvo->success(result);

	return jvo;
}