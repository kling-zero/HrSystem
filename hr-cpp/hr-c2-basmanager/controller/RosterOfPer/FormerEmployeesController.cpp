/**
 *  �������� ���� ��Ա������ ���� ��ְԱ�� ���� ������
 */

#include "stdafx.h"
#include "FormerEmployeesController.h"
#include "../../service/RosterOfPer/FormerEmployeesService.h"

FormerEmployeesPageJsonVO::Wrapper FormerEmployeesController::execQueryFormerEmployees(const FormerEmployeesQuery::Wrapper& query, const PayloadDTO& payload)
{
	// ����һ��Service
	FormerEmployeesService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = FormerEmployeesPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

StringJsonVO::Wrapper FormerEmployeesController::execExportFormerEmployees(const FormerEmployeesQuery::Wrapper& query, const PayloadDTO& payload)
{
	// ��Ӧ���
	auto jvo = StringJsonVO::createShared();

	FormerEmployeesService service;
	
	auto result = service.exportData(query);

	jvo->success(result);
	return jvo;
}