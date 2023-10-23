#pragma once
/**
 * (֤�����-��ҳ��ѯԱ����Ϣ�б�)--weixiaoman
 */
#ifndef _EMPLOYEEINFO_VO_
#define _EMPLOYEEINFO_VO_

#include "../../GlobalInclude.h"
#include "../../dto/CertificateManage/EmployeeInfoDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��Ա��Ϣ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class EmployeeInfoJsonVO : public JsonVO<EmployeeInfoDTO::Wrapper> {
	DTO_INIT(EmployeeInfoJsonVO, JsonVO<EmployeeInfoDTO::Wrapper>);
};

/**
 * ��Ա��Ϣ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class EmployeeInfoPageJsonVO : public JsonVO<EmployeeInfoPageDTO::Wrapper> {
	DTO_INIT(EmployeeInfoPageJsonVO, JsonVO<EmployeeInfoPageDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)
#endif // !_EMPLOYEEINFO_VO_