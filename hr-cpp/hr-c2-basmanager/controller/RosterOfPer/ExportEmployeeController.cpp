/*
����Ա������-��Ա������-����Ա����������ҳ��ǰ����ɣ���--luoluo
*/
#include "stdafx.h"
#include "ExportEmployeeController.h"

#include "../../service/RosterOfPer/ExportEmployeeService.h"

ExportEmployeeJsonVO::Wrapper ExportEmployeeController::execExportEmployee(const ExportEmployeeQuery::Wrapper& query, const PayloadDTO& payload)
{
	// ����һ��Service
	//ExportEmployeeService service;
	// ��ѯ����
	//auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = ExportEmployeeJsonVO::createShared();
	//jvo->success(result);
	return jvo;
}
