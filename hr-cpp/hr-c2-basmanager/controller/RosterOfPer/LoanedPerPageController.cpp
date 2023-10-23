/*
����Ա������-�����Ա-��ҳ��ѯԱ���б�������ҳ��ǰ����ɣ���--luoluo
*/
#include "stdafx.h"
#include "LoanedPerPageController.h"
#include "../../service/RosterOfPer/LoanedPerPageService.h"

LoanedPerPageVO::Wrapper LoanedPerPageController::execQueryLoanedPerPage(const LoanedPerPageQuery::Wrapper& query, const PayloadDTO& payload)
{
	// ����һ��Service
	LoanedPerPageService service;
	//// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = LoanedPerPageVO::createShared();
	jvo->success(result);
	return jvo;
}

/*
����Ա������-�����Ա-����֤�飨������ҳ��ǰ����ɣ���--δС��
*/
StringJsonVO::Wrapper LoanedPerPageController::execExportLoanedPer(const LoanedPerPageQuery::Wrapper& query, const PayloadDTO& payload)
{
	auto jvo = StringJsonVO::createShared();
	LoanedPerPageService service;
	std::string fileName = service.exportData(query);
	if (fileName.empty()) {
		jvo->fail("����ʧ��");
	}
	else jvo->success(fileName);

	return jvo;
}
