#pragma once

#ifndef _LEGALENTITYSET_VO_
#define _LEGALENTITYSET_VO_
/*
��֯���� ������������ ���� ������������  -- cpt

�����������������б� `LegalEntitySetPullDownList`

����ָ������������Ϣ  `UpdateLegalerSettingMessage`

������������ `LegalEntitySet`

�����������ã�֧������������** `LegalEntitySet`
*/
#include "../../GlobalInclude.h"
#include "domain/dto/LegalEntitySet/LegalEntitySetDTO.h"
#include "../../dto/LegalEntitySet/LegalEntitySetQueryDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)

class LegalEntitySetJsonVO : public JsonVO<LegalEntitySetDTO::Wrapper> {
	DTO_INIT(LegalEntitySetJsonVO, JsonVO<LegalEntitySetDTO::Wrapper>);
};

class LegalEntitySetPullDownJsonVO : public JsonVO<LegalEntitySetPullDownDTO::Wrapper> {
	DTO_INIT(LegalEntitySetPullDownJsonVO, JsonVO<LegalEntitySetPullDownDTO::Wrapper>);
};

class LegalEntitySetPageJsonVO : public JsonVO<LegalEntitySetPageDTO::Wrapper> {
	DTO_INIT(LegalEntitySetPageJsonVO, JsonVO<LegalEntitySetPageDTO::Wrapper>);
};


// ��ѯ��JsonVO - TripleGold
class LegalEntitySetQueryJsonVO : public JsonVO<LegalEntitySetQueryDTO::Wrapper> {
	DTO_INIT(LegalEntitySetQueryJsonVO, JsonVO<LegalEntitySetQueryDTO::Wrapper>);
};

class LegalEntitySetQueryPageJsonVO : public JsonVO<LegalEntitySetQueryPageDTO::Wrapper> {
	DTO_INIT(LegalEntitySetQueryPageJsonVO, JsonVO<LegalEntitySetQueryPageDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)
#endif // !_LEGALENTITYSET_VO_
