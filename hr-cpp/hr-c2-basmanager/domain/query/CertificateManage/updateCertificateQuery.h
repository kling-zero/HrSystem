#pragma once
#ifndef _UPDATECERTIFIDATE_QUERY_
#define _UPDATECERTIFIDATE_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class updateCertificateQuery : public PageQuery
{
	DTO_INIT(updateCertificateQuery, PageQuery);
	// ���
	DTO_FIELD(UInt64, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("sample.field.id");
	}
	// ����
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("sample.field.name");
	}
	// ����
	DTO_FIELD(Int32, age);
	DTO_FIELD_INFO(age) {
		info->description = ZH_WORDS_GETTER("sample.field.age");
	}
	// �Ա�
	DTO_FIELD(String, sex);
	DTO_FIELD_INFO(sex) {
		info->description = ZH_WORDS_GETTER("sample.field.sex");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_UPDATECERTIFIDATE_QUERY_