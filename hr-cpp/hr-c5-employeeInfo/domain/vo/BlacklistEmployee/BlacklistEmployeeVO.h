#pragma once
#ifndef _BLACKLIST_EMPLOYEE_VO_
#define _BLACKLIST_EMPLOYEE_VO_

#include "../../GlobalInclude.h"
#include "../../dto/Blacklist/BlacklistDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * ������Ա����ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class BlacklistEmployeeJsonVO : public JsonVO<BlacklistDTO::Wrapper> {
	DTO_INIT(BlacklistEmployeeJsonVO, JsonVO<BlacklistDTO::Wrapper>);
};


/**
 * ������Ա����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class BlacklistEmployeePageJsonVO : public JsonVO<BlacklistPageDTO::Wrapper> {
	DTO_INIT(BlacklistEmployeePageJsonVO, JsonVO<BlacklistPageDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)

#endif // 