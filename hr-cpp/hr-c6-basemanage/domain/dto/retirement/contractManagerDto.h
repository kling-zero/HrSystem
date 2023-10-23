#pragma once
#pragma once
#ifndef _CONTRACTMAGAGERDTO_H_
#define _CONTRACTMAGAGERDTO_H_

#include "stdafx.h"
#include "../../GlobalInclude.h"
#include "oatpp/core/Types.hpp"
#include "oatpp/core/macro/codegen.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)
class contractmanagerDTO : public oatpp::DTO
{
	//��ʼ��
	DTO_INIT(contractmanagerDTO, DTO);
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
	DTO_FIELD(String,Employee_unit);
	// Ա��������λ3
	DTO_FIELD_INFO(Employee_unit) {
		info->description = "yuan gong dan wei ";
	}
	DTO_FIELD(String, employee_state);
	// Ա��״̬4
	DTO_FIELD_INFO(employee_state) {
		info->description = "employee state ";
	}
	DTO_FIELD(String, Time_unit);
	// ������λʱ��5
	DTO_FIELD_INFO(Time_unit) {
		info->description = "ben dan wei shi jian";
	}
	DTO_FIELD(String, contract_id);
	// ��ͬ���6
	DTO_FIELD_INFO(contract_id) {
		info->description = "ben dan wei shi jian";
	}
	DTO_FIELD(String, Contract_unit);
	// ��ͬ��λ7
	DTO_FIELD_INFO(Contract_unit) {
		info->description = " he tong dan wei";
	}
	DTO_FIELD(String, Class_contract);
	// ��ͬ���8
	DTO_FIELD_INFO(Class_contract) {
		info->description = "he tong lei bie ";
	}
	DTO_FIELD(String, contract_type);
	// ��ͬ����9
	DTO_FIELD_INFO(contract_type) {
		info->description = "he tong lei xing";
	}
	DTO_FIELD(String, start_date);
	// ��ʼ����10
	DTO_FIELD_INFO(start_date) {
		info->description = "zu zhi";
	}
	DTO_FIELD(String, stop_date);
	// ��������11
	DTO_FIELD_INFO(stop_date) {
		info->description = "bu men";
	}
	DTO_FIELD(String, Operation_column);
	// ������12
	DTO_FIELD_INFO(Operation_column) {
		info->description = "zhi ji";
	}
};

/**
 * ʾ����ҳ�������
 */
class contractmanagerPageDTO : public PageDTO<contractmanagerDTO::Wrapper>
{
	DTO_INIT(contractmanagerPageDTO, PageDTO<contractmanagerDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_CONTRACTMAGAGERDTO_H_
