#pragma once
#ifndef TERMINATIONMINDERDTO_H
#define TERMINATIONMINDERDTO_H
#include "oatpp/core/Types.hpp"
#include "oatpp/core/macro/codegen.hpp"
#include "../../GlobalInclude.h"


#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ���������
 */
class TerminationReminderDTO : public oatpp::DTO
{
	DTO_INIT(TerminationReminderDTO, DTO);
	// Ա�����
	DTO_FIELD(String, employee_id);
	DTO_FIELD_INFO(employee_id) {
		info->description = "yuan gong bian hao";//ZH_WORDS_GETTER("sample.field.id");
	}
	// Ա������
	DTO_FIELD(String, employee_name);
	DTO_FIELD_INFO(employee_name) {
		info->description = "yuan gong xing ming";
	}
	//Ա��������λ
	DTO_FIELD(String, employee_part);
	DTO_FIELD_INFO(employee_part) {
		info->description = "yuan gong suo shu bu men";
	}
	// Ա��״̬
	DTO_FIELD(String, employee_status);
	DTO_FIELD_INFO(employee_status) {
		info->description = "yuan gong zhuang tai";
	}
	// ������λʱ��
	DTO_FIELD(String, arrived_time);
	DTO_FIELD_INFO(arrived_time) {
		info->description = "dao ben dan wei shi jian";
	}
	// ��ͬ���
	DTO_FIELD(String, contract_id);
	DTO_FIELD_INFO(contract_id) {
		info->description = "he tong bian hao";
	}
	// ��ͬǩ����λ
	DTO_FIELD(String, contract_sign_part);
	DTO_FIELD_INFO(contract_sign_part) {
		info->description = "he tong qian ding dan wei";
	}
	// ��ͬ���
	DTO_FIELD(String, contract_lb);
	DTO_FIELD_INFO(contract_lb) {
		info->description = "he tong lei bie";
	}
	// ��ͬ����
	DTO_FIELD(String, contract_lx);
	DTO_FIELD_INFO(contract_lx) {
		info->description = "he tong lei xing";
	}
	// ��ʼ����
	DTO_FIELD(String, begin_time);
	DTO_FIELD_INFO(begin_time) {
		info->description = "qi shi ri qi";
	}
	// ��������
	DTO_FIELD(String, deadline);
	DTO_FIELD_INFO(deadline) {
		info->description = "jie shu ri qi";
	}
};

/**
 * ʾ����ҳ�������
 */
class TerminationReminderPageDTO : public PageDTO<TerminationReminderDTO::Wrapper>
{
	DTO_INIT(TerminationReminderPageDTO, PageDTO<TerminationReminderDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif