#pragma once
#ifndef _EMPLOYEEINFO_QUERY_
#define _EMPLOYEEINFO_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * ��Ա��Ϣ��ҳ��ѯ����--(֤�����-��ҳ��ѯԱ����Ϣ�б�)--weixiaoman
 */

class EmployeeInfoQuery : public PageQuery
{
	DTO_INIT(EmployeeInfoQuery, PageQuery);
	// ����
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("EmpInfo.field.name");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_EMPLOYEEINFO_QUERY_