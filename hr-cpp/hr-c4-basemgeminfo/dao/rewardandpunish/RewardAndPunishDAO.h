#pragma once

#ifndef _REWARDANDPUNISHDAO_H_
#define _REWARDANDPUNISHDAO_H_
#include "BaseDAO.h"
#include "../../domain/do/rewardandpunish/RewardAndPunishDO.h"
#include "../../domain/query/rewardandpunish/RewardAndPunishQuery.h"

class RewardAndPunishDAO : public BaseDAO
{
public:
	// ��ѯ��������
	list<RewardAndPunishDO> selectDetail(const RewardAndPunishDetailQuery::Wrapper& query);
	// �޸�����
	int update(const RewardAndPunishDO& uObj);
	// ��ҳ��ѯ����
	list<RewardAndPunishDO> selectWithPage(const RewardAndPunishDownloadQuery::Wrapper& query);

};

#endif