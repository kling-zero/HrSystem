#pragma once

#ifndef _LEGALENTITYMAIVO_H_
#define _LEGALENTITYMAIVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/LegalEntityMai/LegalEntityMaiDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/* ��������ά��VO������--����֯����-��������-��������ά����--TripleGold */

/* ����һ���û���Ϣ��ʾJsonVO����������Ӧ���ͻ��� */
class LegalEntityMaiJsonVO : public JsonVO<LegalEntityMaiDTO::Wrapper>
{
	DTO_INIT(LegalEntityMaiJsonVO, JsonVO<LegalEntityMaiDTO::Wrapper>);
};

/* ����һ���û���Ϣ��ҳ��ʾJsonVO����������Ӧ���ͻ��� */
class LegalEntityMaiPageJsonVO : public JsonVO<LegalEntityMaiPageDTO::Wrapper>
{
	DTO_INIT(LegalEntityMaiPageJsonVO, JsonVO<LegalEntityMaiPageDTO::Wrapper>)
};
#include OATPP_CODEGEN_END(DTO)

#endif // !_LEGALENTITYMAIVO_H_