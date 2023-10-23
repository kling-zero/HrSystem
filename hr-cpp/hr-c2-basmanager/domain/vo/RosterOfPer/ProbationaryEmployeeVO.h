#pragma once
/**
 * ��Ա������ - ������Ա��Ӧ����ʵ�� - ������
 */

#ifndef _PROBATIONARY_EMPLOYEE_VO_
#define _PROBATIONARY_EMPLOYEE_VO_
#include "../../GlobalInclude.h"
#include "../../dto/RosterOfPer/ProbationaryEmployeeDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)

class ProbationaryEmployeeJsonVO : public JsonVO<ProbationaryEmployeeDTO::Wrapper>
{
	DTO_INIT(ProbationaryEmployeeJsonVO, JsonVO<ProbationaryEmployeeDTO::Wrapper>);
};

/**
 * ��ְԱ����ҳ�������
 */
class ProbationaryEmployeePageJsonVO : public JsonVO<ProbationaryEmployeePageDTO::Wrapper>
{
	DTO_INIT(ProbationaryEmployeePageJsonVO, JsonVO<ProbationaryEmployeePageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_PROBATIONARY_EMPLOYEE_VO_
