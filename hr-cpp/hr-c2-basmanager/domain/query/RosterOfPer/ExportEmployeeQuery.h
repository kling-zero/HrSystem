#pragma once
/*
����Ա������-��Ա������-����Ա����������ҳ��ǰ����ɣ���--luoluo
*/
#ifndef _EXPORTEMPLOYEE_QUERY_
#define _EXPORTEMPLOYEE_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class ExportEmployeeQuery : public PageQuery
{
	DTO_INIT(ExportEmployeeQuery, PageQuery);
	// ����
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("sample.field.name");
	}
	// �Ա�
	DTO_FIELD(String, sex);
	DTO_FIELD_INFO(sex) {
		info->description = ZH_WORDS_GETTER("sample.field.sex");
	}
	// ����
	DTO_FIELD(UInt32, age);
	DTO_FIELD_INFO(age) {
		info->description = ZH_WORDS_GETTER("sample.field.age");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_EXPORTEMPLOYEE_QUERY_