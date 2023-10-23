#pragma once

#include "../Doinclude.h"
class ExpenseLedgeDO
{
	//����ID
	CC_SYNTHESIZE(string, id, ID);
	//�������
	CC_SYNTHESIZE(string, name, Name);
	//���ý��
	CC_SYNTHESIZE(uint64_t, money, Money);
	//��������
	CC_SYNTHESIZE(uint64_t, people_num, People_num);
	//����ʱ��
	CC_SYNTHESIZE(string, time, Time);
	//���ñ�׼
	CC_SYNTHESIZE(uint64_t, stardandmoney, Stardandmoney);

public:
	ExpenseLedgeDO() {
		id = "";
		name = "";
		money = 0;
		people_num = 0;
		time = "2022-01-01";
		stardandmoney = 0;
	}
};