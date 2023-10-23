#include "stdafx.h"
#include "RraineeController.h"
#include "service/RosterOfPer/RraineeService.h"
/**
*  �������� ���� ��Ա������ ���� ��ϰԱ��  ����Cpt
*/

RraineePageJsonVO::Wrapper RraineeController::execRraineeQuery(const RraineeQuery::Wrapper& query, const PayloadDTO& payload){
	RraineeService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = RraineePageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

RraineePageJsonVO::Wrapper RraineeController::execRraineeExport(const RraineeQuery::Wrapper& query, const PayloadDTO& payload) {
	return RraineePageJsonVO::Wrapper();
}

