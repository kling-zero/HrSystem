#pragma once
#ifndef _RETIREMENTVO_H_
#define _RETIREMENTVO_H_

#include "stdafx.h"
#include "../../GlobalInclude.h"
#include "domain/dto/retirement/RetiremetDto.h"


#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class RetirementJsonVO : public JsonVO<RetirementDTO::Wrapper> {
	DTO_INIT(RetirementJsonVO, JsonVO<RetirementDTO::Wrapper>);
};

// ��ҳ��ѯ���ص�JsonVO
class RetirementQueryPageJsonVO :public JsonVO<RetirementPageDTO::Wrapper> {
	DTO_INIT(RetirementQueryPageJsonVO, JsonVO<RetirementPageDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)

#endif // !_RETIREMENTVO_H_


