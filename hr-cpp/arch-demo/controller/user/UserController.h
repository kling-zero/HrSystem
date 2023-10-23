#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/12/01 17:39:36

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
#ifndef _USERCONTROLLER_H_
#define _USERCONTROLLER_H_
#include "oatpp-swagger/Types.hpp"
#include "domain/query/user/UserQuery.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/user/UserVO.h"
#include "domain/vo/user/MenuVO.h"
using namespace oatpp;

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class UserController : public oatpp::web::server::api::ApiController
{
	// ��ӷ��ʶ���
	API_ACCESS_DECLARE(UserController);
public:
	// �����ѯ�����û���Ϣ�ӿڶ˵�����
	ENDPOINT_INFO(queryAllUser) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("user.query-all.summary");
		// ���Ĭ����Ȩ����
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON(UserPageJsonVO::Wrapper);
		// �����ҳ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		info->queryParams.add<String>("nickname").description = ZH_WORDS_GETTER("user.query-all.nickname");
	}
	// �����ѯ�����û���Ϣ�ӿڶ˵㴦��
	ENDPOINT(API_M_GET, "/user/query-all", queryAllUser, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// ������ѯ����
		API_HANDLER_QUERY_PARAM(userQuery, UserQuery, queryParams);
		// ��Ӧ���
		API_HANDLER_RESP_VO(executeQueryAll(userQuery));
	}
	// �����ļ��ϴ��˵�����
	ENDPOINT_INFO(postFile) {
		info->summary = ZH_WORDS_GETTER("user.file.summary");
		info->addConsumes<oatpp::swagger::Binary>("application/octet-stream");
		API_DEF_ADD_RSP_JSON(StringJsonVO::Wrapper);
		info->queryParams["suffix"].description = ZH_WORDS_GETTER("user.file.suffix");
		info->queryParams["suffix"].addExample("png", String(".png"));
		info->queryParams["suffix"].addExample("jpg", String(".jpg"));
		info->queryParams["suffix"].addExample("txt", String(".txt"));
	}
	// �����ļ��ϴ��˵㴦��
	ENDPOINT(API_M_POST, "/user/file", postFile, BODY_STRING(String, body), QUERY(String, suffix)) {
		// ִ���ļ������߼�
		API_HANDLER_RESP_VO(executePostFile(body, suffix));
	}
	// �����ѯ�û��˵��ӿڶ˵�����
	ENDPOINT_INFO(queryMenu) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("user.query-menu.summary");
		// ���Ĭ����Ȩ����
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON(MenuJsonVO::Wrapper);
	}
	// �����ѯ�����û���Ϣ�ӿڶ˵㴦��
	ENDPOINT(API_M_GET, "/user/query-menu", queryMenu, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(executeQueryMenu(authObject->getPayload()));
	}
private:
	// ��ѯ����
	UserPageJsonVO::Wrapper executeQueryAll(const UserQuery::Wrapper& userQuery);
	// �����ļ�
	StringJsonVO::Wrapper executePostFile(const String& fileBody, const String& suffix);
	// ���Բ˵�
	MenuJsonVO::Wrapper executeQueryMenu(const PayloadDTO& payload);
};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif // _USERCONTROLLER_H_