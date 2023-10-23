
#include "stdafx.h"
#include "Contractmanagement.h"
#include "service/reitirement/contractManagerService.h"

contractManagerQueryPageJsonVO::Wrapper ContractmanageController::execQueryContractmanage(const contractManagerQuery::Wrapper& query)
{
	// ����һ��Service
	contractManagerService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = contractManagerQueryPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}