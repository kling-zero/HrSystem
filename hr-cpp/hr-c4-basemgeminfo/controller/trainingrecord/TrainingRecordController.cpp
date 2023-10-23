#include "stdafx.h"
#include "TrainingRecordController.h"
#include "../../service/trainingrecord/TrainingRecordService.h"

//@Author: Diaukray

TrainingRecordPageJsonVO::Wrapper TrainingRecordController::execQueryTrainingRecord(const TrainingRecordPageQuery::Wrapper& query, const PayloadDTO& payload)
{
	// ����һ��Service
	TrainingRecordService service;
	// ��ѯ����
	auto result = service.listAll(query);
	//// ��Ӧ���
	auto jvo = TrainingRecordPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}