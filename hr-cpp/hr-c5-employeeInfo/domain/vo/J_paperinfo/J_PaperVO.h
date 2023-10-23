#pragma once
#ifndef _J_PAPER_VO_
#define _J_PAPER_VO_

#include "../../GlobalInclude.h"
#include "../../dto/J_paperinfo/J_PaperinfoDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ������Ϣ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class J_PaperJsonVO : public JsonVO<J_PaperinfoDTO::Wrapper> {
	DTO_INIT(J_PaperJsonVO, JsonVO<J_PaperinfoDTO::Wrapper>);
};

class J_PaperinfoJsonVO : public JsonVO<J_PaperinfoDTO::Wrapper> {
	DTO_INIT(J_PaperinfoJsonVO, JsonVO<J_PaperinfoDTO::Wrapper>);
};



/**
 * ������Ϣ��ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class J_PaperPageJsonVO : public JsonVO<J_PaperinfoPageDTO::Wrapper> {
	DTO_INIT(J_PaperPageJsonVO, JsonVO<J_PaperinfoPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif 