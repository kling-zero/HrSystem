#pragma once
/*
����Ա������-��Ա������-����Ա����������ҳ��ǰ����ɣ���--luoluo
*/
#ifndef _EXPORTEMPLOYEE_DTO_
#define _EXPORTEMPLOYEE_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class ExportEmployeeDTO : public oatpp::DTO
{
	DTO_INIT(ExportEmployeeDTO, DTO);
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

class ExportEmployeePageDTO : public PageDTO<ExportEmployeeDTO::Wrapper>
{
	DTO_INIT(ExportEmployeePageDTO, PageDTO<ExportEmployeeDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_EXPORTEMPLOYEE_DTO_