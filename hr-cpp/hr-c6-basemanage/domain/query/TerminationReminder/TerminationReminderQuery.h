#pragma once


#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ҳ��ѯ����
 */
class TerminationReminderQuery : public PageQuery
{
	DTO_INIT(TerminationReminderQuery, PageQuery);
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
	//DTO_FIELD(String, employee_part);
	//DTO_FIELD_INFO(employee_part) {
	//	info->description = "yuan gong suo shu bu men";
	//}
	// Ա��״̬
	DTO_FIELD(String, employee_status);
	DTO_FIELD_INFO(employee_status) {
		info->description = "yuan gong zhuang tai";
	}
	// ������λʱ��
	//DTO_FIELD(String, arrived_time);
	//DTO_FIELD_INFO(arrived_time) {
	//	info->description = "dao ben dan wei shi jian";
	//}
	// ��ͬ���
	DTO_FIELD(String, contract_id);
	DTO_FIELD_INFO(contract_id) {
		info->description = "he tong bian hao";
	}
	// ��ͬǩ����λ
	//DTO_FIELD(String, contract_sign_part);
	//DTO_FIELD_INFO(contract_sign_part) {
	//	info->description = "he tong qian ding dan wei";
	//}
	// ��ͬ״̬
	DTO_FIELD(String, contract_statu);
	DTO_FIELD_INFO(contract_statu) {
		info->description = "he tong zhuang tai";
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

#include OATPP_CODEGEN_END(DTO)