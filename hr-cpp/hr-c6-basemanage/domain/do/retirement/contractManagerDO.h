#pragma once

#ifndef _CONTRACTMANAGERDO_H_
#define _CONTRACTMANAGERDO_H_
#include "../DoInclude.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class contractManagerDO
{
	// Ա�����1
	CC_SYNTHESIZE(string, id, Id);
	// Ա������2
	CC_SYNTHESIZE(string, name, Name);
	// Ա��������λ3
	CC_SYNTHESIZE(string, Employee_unit, Employee_Unit);
	// Ա��״̬4
	CC_SYNTHESIZE(string, employee_state, Employee_state);
	//����λʱ��5
	CC_SYNTHESIZE(string, Time_unit, Time_Unit);
	//��ͬ���6
	CC_SYNTHESIZE(string, contract_id, Contract_id);
	//��ͬ��λ7
	CC_SYNTHESIZE(string, Contract_unit, Contract_Unit);
	//��ͬ���8
	CC_SYNTHESIZE(string, Class_contract, Class_Contract);
	//9
	CC_SYNTHESIZE(string, contract_type, contract_Type);
	//10
	CC_SYNTHESIZE(string, start_date, Start_date);
	// 11
	CC_SYNTHESIZE(string, stop_date, Stop_date);
	// 12
	CC_SYNTHESIZE(string, Operation_column, Operation_Column);
public:
	contractManagerDO() {
	}
};

#endif // !_CONTRACTMANAGERDO_H_
