#pragma once

#include "stdafx.h"
#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"


#ifndef _CONTEACTMANAGERQUERY_H_
#define _CONTEACTMANAGERQUERY_H_


#include OATPP_CODEGEN_BEGIN(DTO)


class contractManagerQuery :public PageQuery {

	DTO_INIT(contractManagerQuery, PageQuery);
	// Ա��id 1
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("retirement_gan.query.id");
	}
	DTO_FIELD(String, name);
	// ��ѯ�ĵڶ���������Ա������
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("retirement_gan.query.name");
	}
	DTO_FIELD(String, Employee_status);
	// ��ѯ�ĵ�����������Ա��״̬
	DTO_FIELD_INFO(Employee_status) {
		info->description = ZH_WORDS_GETTER("retirement_gan.query.Employee_status");
	}
	DTO_FIELD(String, contract_id);
	// ��ͬ���4
	DTO_FIELD_INFO(contract_id) {
		info->description = "he tong bian hao";
	}
	DTO_FIELD(String, contract_class);
	// ��ͬ���5
	DTO_FIELD_INFO(contract_class) {
		info->description = "he tong lei bie";
	}
	DTO_FIELD(String, contract_state);
	// ��ͬ״̬6
	DTO_FIELD_INFO(contract_state) {
		info->description = "he tong zhuang tai";
	}
	DTO_FIELD(String, start_date);
	// ��ʼ����7
	DTO_FIELD_INFO(start_date) {
		info->description = "kai shi r qi";
	}
	DTO_FIELD(String, stop_date);
	// ��������8
	DTO_FIELD_INFO(stop_date) {
		info->description = "jie shu r qi";
	}
	DTO_FIELD(String, contract_type);
	// ��ͬ����9
	DTO_FIELD_INFO(contract_type) {
		info->description = "he tong lei xin";
	}
};

#include OATPP_CODEGEN_END(DTO)



#endif // !_CONTEACTMANAGERQUERY_H_

