#pragma once
#include "../DoInclude.h"
class TerminationReminderDO
{
	// Ա�����
	CC_SYNTHESIZE(string, employee_id, EmployeeId);
	// Ա������
	CC_SYNTHESIZE(string, employee_name, EmployeeName);
	// Ա��������λ
	CC_SYNTHESIZE(string, employee_part, EmployeePart);
	// Ա��״̬
	CC_SYNTHESIZE(string, employee_status, EmployeeStatus);
	//������λʱ��
	CC_SYNTHESIZE(string, arrived_time,ArrivedTime );
	//��ͬ���						  
	CC_SYNTHESIZE(string, contract_id, ContractId);
	//��ͬǩ����λ						  
	CC_SYNTHESIZE(string, contract_sign_part,ContractSignPart );
	//��ͬ���					  
	CC_SYNTHESIZE(string, contract_lb,ContractLB );
	//��ͬ����						  
	CC_SYNTHESIZE(string, contract_lx,ContractLX );
	//��ʼ����					  
	CC_SYNTHESIZE(string, begin_time, BeginTime);
	//��������					  
	CC_SYNTHESIZE(string, deadline, Deadline);
public:
	TerminationReminderDO() {
	}
};
