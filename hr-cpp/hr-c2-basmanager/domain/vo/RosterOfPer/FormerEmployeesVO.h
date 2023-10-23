#pragma once
/**
 * ��Ա������ - ��ְ��Ա��Ӧ����ʵ�� - ������
 */

#ifndef _FORMER_EMPLOYEES_VO_
#define _FORMER_EMPLOYEES_VO_
#include "../../GlobalInclude.h"
#include "../../dto/RosterOfPer/FormerEmployeesDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)

class FormerEmployeesJsonVO : public JsonVO<FormerEmployeesDTO::Wrapper>
{
	DTO_INIT(FormerEmployeesJsonVO, JsonVO<FormerEmployeesDTO::Wrapper>);
};

/**
 * ��ְԱ����ҳ�������
 */
class FormerEmployeesPageJsonVO : public JsonVO<FormerEmployeesPageDTO::Wrapper>
{
	DTO_INIT(FormerEmployeesPageJsonVO, JsonVO<FormerEmployeesPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif 
