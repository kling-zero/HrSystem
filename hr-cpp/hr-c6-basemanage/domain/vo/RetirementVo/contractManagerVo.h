#pragma once
#ifndef  _CONTRACTMANAGERVO_H_
#define  _CONTRACTMANAGERVO_H_


#include "stdafx.h"
#include "../../GlobalInclude.h"
#include "domain/dto/retirement/contractManagerDto.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class contractManagerJsonVO : public JsonVO<contractmanagerDTO::Wrapper> {
	DTO_INIT(contractManagerJsonVO, JsonVO<contractmanagerDTO::Wrapper>);
};

// ��ҳ��ѯ���ص�JsonVO
class contractManagerQueryPageJsonVO :public JsonVO<contractmanagerPageDTO::Wrapper> {
	DTO_INIT(contractManagerQueryPageJsonVO, JsonVO<contractmanagerPageDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)


#endif // ! _CONTRACTMANAGERVO_H_
