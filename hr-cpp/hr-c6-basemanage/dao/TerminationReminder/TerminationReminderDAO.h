#pragma once

#include "BaseDAO.h"
#include "../../domain/do/TerminationReminder/TerminationReminderDO.h"
#include "../../domain/query/TerminationReminder/TerminationReminderQuery.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class TerminationReminderDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const TerminationReminderQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<TerminationReminderDO> selectWithPage(const TerminationReminderQuery::Wrapper& query);
	//��ѯȫ��
	list<TerminationReminderDO> selectAll(const TerminationReminderQuery::Wrapper& query);
};