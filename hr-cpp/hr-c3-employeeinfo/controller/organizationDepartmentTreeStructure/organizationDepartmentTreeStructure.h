#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: guyier
 @Date: 2023/05/24 15:14:27

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/

#ifndef _ORGNAIZATION_DEPARTMENT_TREE_STRUCTURE_
#define _ORGNAIZATION_DEPARTMENT_TREE_STRUCTURE_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/vo/org/OrgTreeVO.h"
#include "service/org/OrgService.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

/*
 * �����ѯ���в��Žṹ����Ϣ�ӿڶ˵㴦��
 */
class organizationDepartmentTreeStructure : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(organizationDepartmentTreeStructure);

public: // ����ӿ�
	ENDPOINT_INFO(orgTreeQuery)
	{
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("org.field.summary");
		// ���Ĭ����Ȩ����
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON(OrgTreeVO::Wrapper);
		// ������������������
		// ��ѯSector��parent��OrmOrg����OrmOrgsector
	}
	// �����ѯ������Ϣ�ӿڶ˵㴦��
	ENDPOINT(API_M_GET, "/c3-employee-info/organization-department-tree-structure/orgtree-query", orgTreeQuery, API_HANDLER_AUTH_PARAME)
	{
		// ��Ӧ���
		API_HANDLER_RESP_VO(execOrgTreeQuery(authObject));
		// API_HANDLER_RESP_VO(execOrgTreeQuery(nullptr));
	}

private: // ����ӿ�ִ�к���
	// ��ѯ��֯�ṹ��
	OrgTreeVO::Wrapper execOrgTreeQuery(const std::shared_ptr<CustomerAuthorizeObject> &authObject);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_ORGNAIZATION_DEPARTMENT_TREE_STRUCTURE_