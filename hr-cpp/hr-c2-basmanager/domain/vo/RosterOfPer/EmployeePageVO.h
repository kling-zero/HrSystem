#pragma once
/*
����Ա������-��Ա������-��ҳ��ѯԱ���б�--����
*/
#ifndef _EMPLOYEE_PAGE_VO_
#define _EMPLOYEE_PAGE_VO_

#include "../../GlobalInclude.h"
#include "../../dto/RosterOfPer/EmployeePageDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class EmployeePageJsonVO : public JsonVO<EmployeePageDTO::Wrapper> {
	DTO_INIT(EmployeePageJsonVO, JsonVO<EmployeePageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_EMPLOYEE_PAGE_VO_