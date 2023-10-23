#pragma once

#ifndef _TRAININGRECORD_SERVICE_
#define _TRAININGRECORD_SERVICE_
#include <list>
#include "domain/vo/trainingrecord/TrainingRecordVO.h"
#include "domain/query/trainingrecord/TrainingRecordQuery.h"
#include "domain/dto/trainingrecord/TrainingRecordDTO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class TrainingRecordService
{
public:
	// ��ҳ��ѯ��������
	TrainingRecordPageDTO::Wrapper listAll(const TrainingRecordPageQuery::Wrapper& query);
};

#endif

