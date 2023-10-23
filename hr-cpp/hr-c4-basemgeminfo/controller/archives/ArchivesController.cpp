#include "stdafx.h"
#include "ArchivesController.h"
#include "../../service/archives/ArchivesService.h"

ArchivesPageJsonVO::Wrapper ArchivesController::execQueryTest(const ArchivesQuery::Wrapper& query) {
	// ����һ��Service
	ArchivesService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = ArchivesPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}