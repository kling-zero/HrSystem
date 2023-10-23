#pragma once
#ifndef _CONTRACT_DTO_
#define _CONTRACT_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ���������
 */
class ContractDTO_gs : public oatpp::DTO
{
	DTO_INIT(ContractDTO_gs, DTO);
	//Ա�����
	DTO_FIELD(String, personid);
	DTO_FIELD_INFO(personid) {
		info->description = ZH_WORDS_GETTER("contract.field.personid");
	}
	// ��ͬ���
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("contract.field.id");
	}
	// Ա������
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("contract.field.name");
	}
	// ��ͬ���
	DTO_FIELD(String, type);
	DTO_FIELD_INFO(type) {
		info->description = ZH_WORDS_GETTER("contract.field.type");
	}
	// ��ͬ����
	DTO_FIELD(String, variety);
	DTO_FIELD_INFO(variety) {
		info->description = ZH_WORDS_GETTER("contract.field.variety");
	}
	// ��ʼ����
	DTO_FIELD(String, date);
	DTO_FIELD_INFO(date) {
		info->description = ZH_WORDS_GETTER("contract.field.date");
	}
	// ��ͬ״̬
	DTO_FIELD(String, condition);
	DTO_FIELD_INFO(condition) {
		info->description = ZH_WORDS_GETTER("contract.field.condition");
	}
	// ��ͬǩ����λ
	DTO_FIELD(String, department_c);
	DTO_FIELD_INFO(department_c) {
		info->description = ZH_WORDS_GETTER("contract.field.department_c");
	}
	// ���õ���ʱ��
	DTO_FIELD(String, date_end);
	DTO_FIELD_INFO(date_end) {
		info->description = ZH_WORDS_GETTER("contract.field.date_end");
	}
	//Ա��������λ
	DTO_FIELD(String, person_department);
	DTO_FIELD_INFO(person_department) {
		info->description = ZH_WORDS_GETTER("contract.field.person_department");
	}
	//Ա��״̬
	DTO_FIELD(String, person_condition);
	DTO_FIELD_INFO(person_condition) {
		info->description = ZH_WORDS_GETTER("contract.field.person_condition");
	}
	//������λʱ��
	DTO_FIELD(String, date_arrive);
	DTO_FIELD_INFO(date_arrive) {
		info->description = ZH_WORDS_GETTER("contract.field.date_arrive");
	}
	//��������
	DTO_FIELD(String, date_over);
	DTO_FIELD_INFO(date_over) {
		info->description = ZH_WORDS_GETTER("contract.field.date_over");
	}
	//��ͬʣ������
	DTO_FIELD(String, rest);
	DTO_FIELD_INFO(rest) {
		info->description = ZH_WORDS_GETTER("contract.field.rest");
	}
};

class  ContractDTO_gs_insert : public oatpp::DTO
{
	DTO_INIT(ContractDTO_gs_insert, DTO);
	//1��Ա�����
	DTO_FIELD(String, personid);
	DTO_FIELD_INFO(personid) {
		info->description = ZH_WORDS_GETTER("contract.field.personid");
	}
	// 2����ͬ���
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("contract.field.id");
	}
	// 3����ͬ���
	DTO_FIELD(String, type);
	DTO_FIELD_INFO(type) {
		info->description = ZH_WORDS_GETTER("contract.field.type");
	}
	// 4����ͬ����
	DTO_FIELD(String, variety);
	DTO_FIELD_INFO(variety) {
		info->description = ZH_WORDS_GETTER("contract.field.variety");
	}
	// 5����ʼ����
	DTO_FIELD(String, date);
	DTO_FIELD_INFO(date) {
		info->description = ZH_WORDS_GETTER("contract.field.date");
	}
	// 6����ͬ״̬
	DTO_FIELD(String, condition);
	DTO_FIELD_INFO(condition) {
		info->description = ZH_WORDS_GETTER("contract.field.condition");
	}
	//7����ͬ����λ
	DTO_FIELD(String, department_m);
	DTO_FIELD_INFO(department_m) {
		info->description = ZH_WORDS_GETTER("contract.field.department_m");
	}
	// 8�����õ���ʱ��
	DTO_FIELD(String, date_end);
	DTO_FIELD_INFO(date_end) {
		info->description = ZH_WORDS_GETTER("contract.field.date_end");
	}
	//9����ע
	DTO_FIELD(String, tip);
	DTO_FIELD_INFO(tip) {
		info->description = ZH_WORDS_GETTER("contract.field.tip");
	}
};

class ContractDTO_gs_delete : public oatpp::DTO
{
	DTO_INIT(ContractDTO_gs_delete, DTO);
	// ��ɾ�����
	DTO_FIELD(List<String>, deleteById) = {};
	DTO_FIELD_INFO(deleteById) {
		info->description = ZH_WORDS_GETTER("contract.field.id");
	}
};

/**
 * ʾ����ҳ�������
 */
class ContractPageDTO_gs : public PageDTO<ContractDTO_gs::Wrapper>
{
	DTO_INIT(ContractPageDTO_gs, PageDTO<ContractDTO_gs::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_
