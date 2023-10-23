#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: xubuxi
 @Date: 2023/05/19 21:18:10

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
#ifndef _HTLX_CONTROLLER_
#define _HTLX_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "Macros.h"
#include "ServerInfo.h"
#include "domain/vo/pullList/PullListVO.h"
#include "domain/vo/contractType/ContractTypeVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)
/**
 * ��ͬ��������б������
 * �����ˣ��첻ϴ
 */
class ContractTypeController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(ContractTypeController);
public: // ����ӿ�
	ENDPOINT_INFO(queryHtlx) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("htlx.query-list.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(ContractTypeVO);
		API_DEF_ADD_AUTH();
	}
	ENDPOINT(API_M_GET, PATH_TO_PULLIST("/contract-type"), queryHtlx, API_HANDLER_AUTH_PARAME) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execQueryContractType());
	}
	
private: // ����ӿ�ִ�к���
	ContractTypeVO::Wrapper execQueryContractType();
};

#include OATPP_CODEGEN_END(ApiController)
#endif // !_HTLX_CONTROLLER_