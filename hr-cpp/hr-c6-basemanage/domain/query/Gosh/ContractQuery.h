#pragma once
#ifndef _Contract_QUERY_
#define _Contract_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * ��ҳ��ѯ�����࣬������ҳ��ѯ������Լ̳���
 */
class ContractQuery : public PageQuery
{
	// ��ʼ������
	DTO_INIT(ContractQuery, PageQuery);
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
	//��ͬ����λ
	DTO_FIELD(String, department_m);
	DTO_FIELD_INFO(department_m) {
		info->description = ZH_WORDS_GETTER("contract.field.department_m");
	}
	//��ע
	DTO_FIELD(String, tip);
	DTO_FIELD_INFO(tip) {
		info->description = ZH_WORDS_GETTER("contract.field.tip");
	}
	//�ж��Ƿ�ѡ����
	DTO_FIELD(String, row_show);
	DTO_FIELD_INFO(row_show) {
		info->description = ZH_WORDS_GETTER("contract.field.row_show");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_PAGE_QUERY_