#pragma once
#ifndef _RETIREMENTDO_H_
#define _RETIREMENTDO_H_
#include "../DoInclude.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class retirementDO
{
	// Ա�����1
	CC_SYNTHESIZE(string, id, Id);
	// Ա������2
	CC_SYNTHESIZE(string, name, Name);
	// Ա���Ա�3
	CC_SYNTHESIZE(string, sex, Sex);
	// Ա������4
	CC_SYNTHESIZE(string, age, Age);
	// Ա��ͨѶ��ַ5
	CC_SYNTHESIZE(string, mailing_address, Mailing_address);
	// Ա�����ݵ�ַ6
	CC_SYNTHESIZE(string, retire_address, Retire_address);
	// Ա����ͥ��ϵ��7
	CC_SYNTHESIZE(string, Family_contact, Family_Contact);
	// Ա����ͥ��ϵ�˵绰8
	CC_SYNTHESIZE(string, Family_contact_tel, Family_Contact_tel);
	// Ա����֯9
	CC_SYNTHESIZE(string, organization, Organization);
	// Ա������10
	CC_SYNTHESIZE(string, department, Department);
	// Ա��ְ��11
	CC_SYNTHESIZE(string, rank, Rank);
	// Ա������ǰְ��12
	CC_SYNTHESIZE(string, before_retire_rank, Before_retire_rank);
	// Ա������ǰ��λ13
	CC_SYNTHESIZE(string, before_retire_post, Before_retire_post);
	// Ա������ʱ��14
	CC_SYNTHESIZE(string, retire_time, Retire_time);
	// Ա��ʵ������ʱ��15
	CC_SYNTHESIZE(string, read_retire_time, Read_retire_time);
	// Ա���绰16
	CC_SYNTHESIZE(string, tel, Tel);
	// Ա�����Ͻ��17
	CC_SYNTHESIZE(string, Approved_pension_amount, Approved_Pension_amount);
public:
	retirementDO() {
	}
};

#endif // !_RETIREMENTDO_H_
