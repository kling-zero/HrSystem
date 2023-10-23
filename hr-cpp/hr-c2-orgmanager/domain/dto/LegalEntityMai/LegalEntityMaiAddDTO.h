#pragma once

#ifndef _LEGALENTITYMAI_ADD_DTO_H_
#define _LEGALENTITYMAI_ADD_DTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/* ������������ά����������DTO--����֯����-��������-��������ά����--TripleGold */
class LegalEntityMaiAddDTO : public oatpp::DTO
{
public:
	LegalEntityMaiAddDTO() {};
	// �вι��캯��
	LegalEntityMaiAddDTO(String name, String orgcode) : ORMSIGNORGNAME(name), ORGCODE(orgcode) {};

	DTO_INIT(LegalEntityMaiAddDTO, DTO);
	// ������������
	DTO_FIELD(String, ORMSIGNORGNAME);
	DTO_FIELD_INFO(ORMSIGNORGNAME) {
		info->description = ZH_WORDS_GETTER("LegalEntityMai.field.name");
	}
	// ��֯���
	DTO_FIELD(String, ORGCODE);
	DTO_FIELD_INFO(ORGCODE) {
		info->description = ZH_WORDS_GETTER("LegalEntityMai.field.orgcode");
	}
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_LEGALENTITYMAI_ADD_DTO_H_