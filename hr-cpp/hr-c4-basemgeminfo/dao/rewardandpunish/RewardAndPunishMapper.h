#pragma once

#ifndef _REWARDANDPUNISHMAPPER_H_
#define _REWARDANDPUNISHMAPPER_H_
#include "Mapper.h"
#include "../../domain/do/rewardandpunish/RewardAndPunishDO.h"

class RewardAndPunishMapper : public Mapper<RewardAndPunishDO>
{
public:
	RewardAndPunishDO mapper(ResultSet* resultSet) const override
	{
		RewardAndPunishDO data;

		//���ͱ�ʶ
		data.set_PIMREWARDPUNISHMENTID(resultSet->getString(1));
		//���ͷ���
		data.set_LX(resultSet->getString(2));
		//��������
		data.set_PIMREWARDPUNISHMENTNAME(resultSet->getString(3));
		//���ͼ���
		data.set_JCJB(resultSet->getString(4));
		//���ͽ��
		data.set_JCJE(resultSet->getString(5));
		//����ʱ��
		data.set_JLSJ(resultSet->getString(6));
		//���赥λ
		data.set_DEPARTMENT(resultSet->getString(7));
		//�����¼�
		data.set_JCSJ(resultSet->getString(8));
		//��ע
		data.set_BZ(resultSet->getString(9));
		//����
		data.set_FJ(resultSet->getString(10));

		return data;
	}
};

#endif