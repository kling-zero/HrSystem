#pragma once
/*
* ������������--ɾ����������(֧������ɾ��)--pine
*/
#ifndef _DELETE_LEGAL_ENTITY_DTO_
#define _DELETE_LEGAL_ENTITY_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class DeleteLegalEntityDTO : public oatpp::DTO
{
public:
	//�޲ι���
	DeleteLegalEntityDTO() {};
	DTO_INIT(DeleteLegalEntityDTO, DTO);
	//ǩԼ���嵥λ��ʶ
	DTO_FIELD(List<String>, contractsignorgid);
	DTO_FIELD_INFO(contractsignorgid) {
		info->description = ZH_WORDS_GETTER("LegalEntitySet.field.contractsignorgid");
	}

};

class DeleteLegalEntityPageDTO : public PageDTO<DeleteLegalEntityDTO::Wrapper>
{
	DTO_INIT(DeleteLegalEntityPageDTO, PageDTO<DeleteLegalEntityDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // 