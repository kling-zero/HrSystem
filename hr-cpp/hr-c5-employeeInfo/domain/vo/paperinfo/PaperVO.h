#pragma once
#ifndef _PAPER_VO_
#define _PAPER_VO_

#include "../../GlobalInclude.h"
#include "../../dto/paperinfo/PaperDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ������Ϣ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class PaperJsonVO : public JsonVO<PaperDTO::Wrapper> {
	DTO_INIT(PaperJsonVO, JsonVO<PaperDTO::Wrapper>);
};

/**
 * ������Ϣ��ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class PaperPageJsonVO : public JsonVO<PaperPageDTO::Wrapper> {
	DTO_INIT(PaperPageJsonVO, JsonVO<PaperPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif 