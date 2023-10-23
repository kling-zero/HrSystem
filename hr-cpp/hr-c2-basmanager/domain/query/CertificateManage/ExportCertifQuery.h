#pragma once
/*
��֤�����-֤����Ϣ-����֤�飨������ҳ��ǰ����ɣ���--����
*/
#ifndef _CERTIFEXPORT_QUERY_
#define _CERTIFEXPORT_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class ExportCertifQuery : public PageQuery
{
	DTO_INIT(ExportCertifQuery, PageQuery);
	// ���
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("sample.field.name");
	}
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
#endif // !_CERTIFEXPORT_QUERY_