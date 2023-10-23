#pragma once
/*
* ������������--ɾ����������(֧������ɾ��)--pine
*/
#ifndef _DELETE_LEGAL_ENTITY_VO_
#define _DELETE_LEGAL_ENTITY_VO_

#include "../../GlobalInclude.h"
#include "../../dto/LegalEntitySet/DeleteLegalEntityDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class DeleteLegalEntityJsonVO : public JsonVO<DeleteLegalEntityDTO::Wrapper> {
	DTO_INIT(DeleteLegalEntityJsonVO, JsonVO<DeleteLegalEntityDTO::Wrapper>);
};

class DeleteLegalEntityPageJsonVO : public JsonVO<DeleteLegalEntityPageDTO::Wrapper> {
	DTO_INIT(DeleteLegalEntityPageJsonVO, JsonVO<DeleteLegalEntityPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif 