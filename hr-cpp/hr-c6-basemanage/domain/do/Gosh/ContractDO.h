#pragma once
#ifndef _Gosh_DO_
#define _Gosh_DO_
#include "../DoInclude.h"
/**
 * ʾ�����ݿ�ʵ����
 */
class ContractDO
{
	//1Ա�����
	CC_SYNTHESIZE(string, personid, Personid);
	// 2��ͬ���
	CC_SYNTHESIZE(string, id, Id);
	// 3Ա������
	CC_SYNTHESIZE(string, name, Name);
	//4��ͬ���
	CC_SYNTHESIZE(string, type, Type);
	//5��ͬ����
	CC_SYNTHESIZE(string, variety, Variety);
	//6��ʼ����
	CC_SYNTHESIZE(string, date, Date);
	//7��ͬ״̬
	CC_SYNTHESIZE(string, condition, Condition);
	//8��ͬǩ����λ
	CC_SYNTHESIZE(string, department_c, Department_c);
	//9���õ���ʱ��
	CC_SYNTHESIZE(string, date_end, Date_end);
	//10Ա��������λ
	CC_SYNTHESIZE(string, person_department, Person_department);
	//11Ա��״̬
	CC_SYNTHESIZE(string, person_condition, Person_condition);
	//12������λʱ��
	CC_SYNTHESIZE(string, date_arrive, Date_arrive);
	//13��������
	CC_SYNTHESIZE(string, date_over, Date_over);
	//14��ͬʣ������
	CC_SYNTHESIZE(string, rest, Rest);
	//15��ͬ����λ
	CC_SYNTHESIZE(string, department_m, Department_m);
	//16��ע
	CC_SYNTHESIZE(string, tip, Tip);
	//17�Ƿ�չʾ��
	CC_SYNTHESIZE(string, row_show, Row_show);
public:
	ContractDO() {
		personid = "";
		id = "";
		name = "";
		type = "";
		variety = "";
		date= "";
		condition = "";
		department_c = "";
		date_end = "";
		person_department = "";
		person_condition = "";
		date_arrive = "";
		date_over = "";
		rest = "";
		department_m = "";
		tip = "";
		row_show = "11111111111111";
	}
};

#endif 
