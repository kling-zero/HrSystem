#pragma once
#ifndef _PROBATIONARY_EMPLOYEE_QUERY_
#define _PROBATIONARY_EMPLOYEE_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��Ա������ - ������ԱQueryʵ�� - ������
 */
class ProbationaryEmployeeQuery : public PageQuery
{
	DTO_INIT(ProbationaryEmployeeQuery, PageQuery);
	// ��Ż�����
	DTO_FIELD(String, id_or_name);
	DTO_FIELD_INFO(id_or_name) {
		info->description = ZH_WORDS_GETTER("sample.field.id_or_name");
	}
	// Ա������
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("sample.field.name");
	}
	// Ա�����id
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("sample.field.id");
	}
	// ֤������
	DTO_FIELD(String, zjhm);
	DTO_FIELD_INFO(zjhm) {
		info->description = ZH_WORDS_GETTER("probationaryemployee.field.zjhm");
	}
	// ��֯����
	DTO_FIELD(String, organization);
	DTO_FIELD_INFO(organization) {
		info->description = ZH_WORDS_GETTER("probationaryemployee.field.organization");
	}
	// ����
	DTO_FIELD(String, bm);
	DTO_FIELD_INFO(bm) {
		info->description = ZH_WORDS_GETTER("probationaryemployee.field.bm");
	}
	// Ա��״̬
	DTO_FIELD(String, ygzt);
	DTO_FIELD_INFO(ygzt) {
		info->description = ZH_WORDS_GETTER("probationaryemployee.field.ygzt");
	}
	// �ڸ�״̬
	DTO_FIELD(String, zgzt);
	DTO_FIELD_INFO(zgzt) {
		info->description = ZH_WORDS_GETTER("probationaryemployee.field.zgzt");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif 
