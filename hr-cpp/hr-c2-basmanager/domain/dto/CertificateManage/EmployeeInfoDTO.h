#pragma once
#ifndef _EMPLOYEEINFO_DTO_
#define _EMPLOYEEINFO_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
*  ��Ա��Ϣ��ѯ������������ʹ��--(֤�����-��ҳ��ѯԱ����Ϣ�б�)--weixiaoman
*/
class EmployeeInfoDTO : public oatpp::DTO
{
	DTO_INIT(EmployeeInfoDTO, DTO);
	//Ա������
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("EmpInfo.field.name");
	}
	//Ψһ��ʶ
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("EmpInfo.field.pimpersonId");
	}

};

/**
 * ��Ա��Ϣ��ҳ�������
 */
class EmployeeInfoPageDTO : public PageDTO<EmployeeInfoDTO::Wrapper>
{
	DTO_INIT(EmployeeInfoPageDTO, PageDTO<EmployeeInfoDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)
#endif // !_EMPLOYEEINFO_DTO_