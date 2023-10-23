#pragma once

#ifndef _LEGALENTITYMAIDELETEDTO_H_
#define _LEGALENTITYMAIDELETEDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/* ������������ά������ɾ��DTO--����֯����-��������-��������ά����--TripleGold */
class LegalEntityMaiDelDTO : public oatpp::DTO
{
	DTO_INIT(LegalEntityMaiDelDTO, DTO);
	// ɾ������ID����
	DTO_FIELD(List<String>, Ids) = {};
	DTO_FIELD_INFO(Ids) {
		info->description = ZH_WORDS_GETTER("LegalEntityMai.delete.cnt");
	}

	//// ���������ʶ
	//DTO_FIELD(String, ORMSIGNORGID);
	//DTO_FIELD_INFO(ORMSIGNORGID) {
	//	info->description = ZH_WORDS_GETTER("LegalEntityMai.field.id");
	//}
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_LEGALENTITYMAIDELETEDTO_H_