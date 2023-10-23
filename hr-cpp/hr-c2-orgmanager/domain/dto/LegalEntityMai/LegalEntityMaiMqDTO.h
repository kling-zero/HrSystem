#pragma once

#ifndef _LEGALENTITYMAIMQDTO_H_
#define _LEGALENTITYMAIMQDTO_H_

#define DTO_INIT_(type, field, name) DTO_FIELD(type, field); \
DTO_FIELD_INFO(field) { \
	info->description = ZH_WORDS_GETTER(name); \
}

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/* RocketMq���ݴ��������--����֯����-��������-��������ά����--TripleGold */
class LegalEntityMaiMqDTO : public oatpp::DTO
{
public:
	LegalEntityMaiMqDTO() {};
	LegalEntityMaiMqDTO(String body, String creatName) : body(body), creatName(creatName) {};
	DTO_INIT(LegalEntityMaiMqDTO, DTO);
	// �ļ�����
	DTO_FIELD(String, body);
	DTO_FIELD_INFO(body) {
		info->description = ZH_WORDS_GETTER("LegalEntityMai.field.body");
	}
	// ��������
	DTO_FIELD(String, creatName);
	DTO_FIELD_INFO(creatName) {
		info->description = ZH_WORDS_GETTER("LegalEntityMai.field.creatName");
	}
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_LEGALENTITYMAIMQDTO_H_