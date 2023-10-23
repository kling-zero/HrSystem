#pragma once
#ifndef _PATENT_VO_
#define _PATENT_VO_

#include "../../GlobalInclude.h"
#include "../../dto/patentinfo/PatentinfoDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ������Ϣ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class PatentinfoJsonVO : public JsonVO<PatentinfoDTO::Wrapper> {
	DTO_INIT(PatentinfoJsonVO, JsonVO<PatentinfoDTO::Wrapper>);
};

/**
 * ������Ϣ��ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class PatentinfoPageJsonVO : public JsonVO<PatentinfoPageDTO::Wrapper> {
	DTO_INIT(PatentinfoPageJsonVO, JsonVO<PatentinfoPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif 