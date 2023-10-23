#pragma once
#ifndef _RETIREMETDTO_H_
#define _RETIREMETDTO_H_


#include "stdafx.h"
#include "../../GlobalInclude.h"
#include "oatpp/core/Types.hpp"
#include "oatpp/core/macro/codegen.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)
class RetirementDTO : public oatpp::DTO
{
	//��ʼ��
	DTO_INIT(RetirementDTO, DTO);
	// Ա��id1
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("retirement_gan.query.number");
	}
	DTO_FIELD(String, name);
	// ��ѯ�ĵڶ���������Ա������2
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("retirement_gan.query.name");
	}
	DTO_FIELD(String, sex);
	// Ա���Ա�3
	DTO_FIELD_INFO(sex) {
		info->description = "xing bie ";
	}
	DTO_FIELD(String, age);
	// Ա������4
	DTO_FIELD_INFO(age) {
		info->description = "nian ling ";
	}
	DTO_FIELD(String, mailing_address);
	// Ա��ͨѶ��ַ5
	DTO_FIELD_INFO(mailing_address) {
		info->description = "di zhi ";
	}
	DTO_FIELD(String, retire_address);
	// Ա�����ݵ�6
	DTO_FIELD_INFO(retire_address) {
		info->description = "tui xiu di ";
	}
	DTO_FIELD(String, Family_contact);
	// Ա����ͥ��ϵ��7
	DTO_FIELD_INFO(Family_contact) {
		info->description = "jia ting lian xi ren ";
	}
	DTO_FIELD(String, Family_contact_tel);
	// Ա����ͥ��ϵ�˵绰
	DTO_FIELD_INFO(Family_contact_tel) {
		info->description = "jia ting lian xi ren dian hua";
	}
	DTO_FIELD(String, organization);
	// ��֯8
	DTO_FIELD_INFO(organization) {
		info->description = "zu zhi";
	}
	DTO_FIELD(String, department);
	// ����9
	DTO_FIELD_INFO(department) {
		info->description = "bu men";
	}
	DTO_FIELD(String, rank);
	// ְ��10
	DTO_FIELD_INFO(rank) {
		info->description = "zhi ji";
	}
	DTO_FIELD(String, before_retire_rank);
	// ����ǰְ��11
	DTO_FIELD_INFO(before_retire_rank) {
		info->description = "tui xiu qian zhi wu";
	}
	DTO_FIELD(String, before_retire_post);
	// ����ǰ��λ12
	DTO_FIELD_INFO(before_retire_post) {
		info->description = "tui xiu qian gang wei";
	}
	DTO_FIELD(String, retire_time);
	// ����ʱ��13
	DTO_FIELD_INFO(retire_time) {
		info->description = "tui xiu shi jian";
	}
	DTO_FIELD(String, read_retire_time);
	// ʵ������ʱ��14
	DTO_FIELD_INFO(read_retire_time) {
		info->description = "shi ji tui xiu shi jian";
	}
	DTO_FIELD(String, tel);
	// �ֻ�����15
	DTO_FIELD_INFO(tel) {
		info->description = "dian hua hao ma";
	}
	DTO_FIELD(String, Approved_pension_amount);
	// ���������Ͻ��16
	DTO_FIELD_INFO(Approved_pension_amount) {
		info->description = "shen pi yang lao jin e";
	}
};

/**
 * ʾ����ҳ�������
 */
class RetirementPageDTO : public PageDTO<RetirementDTO::Wrapper>
{
	DTO_INIT(RetirementPageDTO, PageDTO<RetirementDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_RETIREMETDTO_H_
