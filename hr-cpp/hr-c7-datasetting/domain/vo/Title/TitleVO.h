#pragma once
#ifndef _TITLEVO_H_
#define _TITLEVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/Title/TitleDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����һ��ְ��Ŀ¼��Ϣ��ʾJsonVO����������Ӧ���ͻ���
 */
class TitleJsonVO : public JsonVO<TitleDTO::Wrapper>
{
	DTO_INIT(TitleJsonVO, JsonVO<TitleDTO::Wrapper>);
};

/**
 * ����һ��ְ��Ŀ¼��Ϣ��ҳ��ʾJsonVO����������Ӧ���ͻ���
 */
class TitlePageJsonVO : public JsonVO<TitlePageDTO::Wrapper>
{
	DTO_INIT(TitlePageJsonVO, JsonVO<TitlePageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif