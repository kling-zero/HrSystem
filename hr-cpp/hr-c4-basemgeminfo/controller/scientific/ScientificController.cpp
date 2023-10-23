#include "stdafx.h"
#include "ScientificController.h"
#include "../../service/scientific/ScientificService.h"

ScientificJsonVO::Wrapper ScientificController::execQueryScientific(const ScientificViewQuery::Wrapper& query) {
	// ����һ��Service
	ScientificService service;
	// ��ѯ����
	auto result = service.listDetail(query);
	// ��Ӧ���
	auto jvo = ScientificJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

StringJsonVO::Wrapper ScientificController::execModifyScientific(const ScientificDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();
	 //����У��
	if (dto->pimresearchfindingsid.getValue("").empty())
	{
		jvo->init(String("pimresearchfindingsid must be not null"), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	ScientificService service;
	// ִ�������޸�
	if (service.updateData(dto)) {
		jvo->success(dto->pimresearchfindingsid);
	}
	else
	{
		jvo->fail(dto->pimresearchfindingsid);
	}
	// ��Ӧ���
	return jvo;
}

StringJsonVO::Wrapper ScientificController::execDownloadScientific(const ScientificDownloadQuery::Wrapper& query)
{
	// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();
	string filedName = ScientificService().download(query);
	// ��Ӧ���
	if (filedName.empty()) {
		jvo->fail("download failed!");
	}
	else {
		jvo->success(filedName);
	}
	return jvo;
}