#pragma once
#ifndef _EXPORT_RETIREES_DTO_
#define _EXPORT_RETIREES_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class ExportRetireesDTO : public oatpp::DTO
{
public:
	//�޲ι���
	ExportRetireesDTO() {};
	//�вι���
	//ExportRetireesDTO(UInt64 id, String name, Int32 age, String sex) {};
	ExportRetireesDTO(UInt64 id, String name) :id(id), name(name) {};
	DTO_INIT(ExportRetireesDTO, DTO);
	// ���
	DTO_FIELD(UInt64, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("sample.field.id");
	}
	// ����A
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

class ExportRetireesPageDTO : public PageDTO<ExportRetireesDTO::Wrapper>
{
	DTO_INIT(ExportRetireesPageDTO, PageDTO<ExportRetireesDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_EXPORT_RETIREES_DTO_