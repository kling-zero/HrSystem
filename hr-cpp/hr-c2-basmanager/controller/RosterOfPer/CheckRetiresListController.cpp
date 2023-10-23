#include "stdafx.h"
#include "CheckRetiresListController.h"
#include "../../service/RosterOfPer/CheckRetiresListService.h"
/**
 * ��Ա������-��������Ա��-��ҳ��ѯԱ���б�--pine
 */
CheckRetiresListPageJsonVO::Wrapper CheckRetiresListController::execQueryCheckRetiresList(const CheckRetiresListQuery::Wrapper& query, const PayloadDTO& payload)
{
	// ����һ��Service
	CheckRetiresListService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = CheckRetiresListPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
