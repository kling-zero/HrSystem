#include "stdafx.h"
#include "ExportRetireesController.h"
//#include "../../service/sample/SampleService.h"
/**
 * ��Ա������-��������Ա��-����Ա����--pine
 */
ExportRetireesPageJsonVO::Wrapper ExportRetireesController::execQueryExportRetirees(const PageQuery::Wrapper& query)
{
	//������Ӧ����
	auto vo = ExportRetireesPageJsonVO::createShared();
	//������ҳ����
	auto pdto = ExportRetireesPageDTO::createShared();
	pdto->addData(ExportRetireesDTO::createShared(5, "zs"));
	pdto->addData(ExportRetireesDTO::createShared(6, "ls"));
	//��Ӧ���
	vo->success(pdto);
	return vo;
}
