#pragma once

#ifndef _BLACKLIST_VO_
#define _BLACKLIST_VO_

#include "../../GlobalInclude.h"
#include "../../dto/Blacklist/BlacklistDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * ������������ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class BlacklistJsonVO : public JsonVO<BlacklistDTO::Wrapper> {
	DTO_INIT(BlacklistJsonVO, JsonVO<BlacklistDTO::Wrapper>);
};


/**
 * ���������ݷ�ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class BlacklistPageJsonVO : public JsonVO<BlacklistPageDTO::Wrapper> {
	DTO_INIT(BlacklistPageJsonVO, JsonVO<BlacklistPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // 