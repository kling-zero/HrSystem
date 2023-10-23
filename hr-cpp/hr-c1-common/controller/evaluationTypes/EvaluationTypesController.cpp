#include "stdafx.h"
#include "EvaluationTypesController.h"
#include "service/evaluationTypes/EvaluationTypeService.h"


PullListVO::Wrapper EvaluationTypesController::execQueryEvaluationTypes()
{
	// �������ض���
	auto vo = PullListVO::createShared();

	// ����ʾ������
	/*auto a = ItemDTO::createShared(1, "Yes");
	dto->pullList->push_back(a);
	auto b = ItemDTO::createShared(2, "No");
	dto->pullList->push_back(b);

	auto vo = PullListVO::createShared();
	vo->success(dto);*/

	// TODO: ����service
	EvaluationTypeService service;
	auto dto = service.listAll();
	vo->success(dto);
	return vo;
}

