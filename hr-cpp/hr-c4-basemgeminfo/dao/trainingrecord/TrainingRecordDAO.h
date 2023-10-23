#pragma once

#ifndef _TRAININGRECORD_DAO_
#define _TRAININGRECORD_DAO_
#include "BaseDAO.h"
#include "../../domain/do/trainingrecord/TrainingRecordDO.h"
#include "../../domain/query/trainingrecord/TrainingRecordQuery.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class TrainingRecordDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const TrainingRecordPageQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<TrainingRecordDO> selectWithPage(const TrainingRecordPageQuery::Wrapper& query);
};
#endif
