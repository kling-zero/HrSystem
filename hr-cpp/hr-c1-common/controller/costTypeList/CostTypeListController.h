#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: ���֮��
 @Date: 2023/05/17 23:35:42

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
#ifndef _COSTTYPELISTCONTROLLER_H_
#define _COSTTYPELISTCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "Macros.h"
#include "ServerInfo.h"
#include "domain/vo/pullList/PullListVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)
/**
 * ������������б������
 * ����ǰ�����󣬲�ѯ���������װ���б���
 * �����ˣ����֮��
 */
class CostTypeListController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(CostTypeListController);
public: // ����ӿ�
	ENDPOINT_INFO(queryCostType) {
		info->summary = ZH_WORDS_GETTER("common.controller.costType");
		API_DEF_ADD_RSP_JSON_WRAPPER(PullListVO);
		API_DEF_ADD_AUTH();
	}

	ENDPOINT(API_M_GET, "/pull-list/cost-type", queryCostType, API_HANDLER_AUTH_PARAME) {
		API_HANDLER_RESP_VO(execQueryCostType());
	}
private: // ����ӿ�ִ�к���
	PullListVO::Wrapper execQueryCostType();
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_COSTTYPELISTCONTROLLER_H_