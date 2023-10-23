#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 0:27:04

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
#ifndef _AwardLevelCONTROLLER_H_
#define _AwardLevelCONTROLLER_H_
#include "ServerInfo.h"
#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/vo/pullList/PullListVO.h"
#include "Macros.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class AwardLevelController : public oatpp::web::server::api::ApiController // 1
{
	// 2 ����������������
	API_ACCESS_DECLARE(AwardLevelController);
public: // ����ӿ�
	// 3 ����ӿ�����
	ENDPOINT_INFO(queryAwardLevel) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("common.dto.level");
		// ������Ӧ��������
		API_DEF_ADD_RSP_JSON_WRAPPER(PullListVO);
		API_DEF_ADD_AUTH();
	}
	// 4 ����ӿڶ˵�
	ENDPOINT(API_M_GET, PATH_TO_PULLIST("/award-level"), queryAwardLevel, API_HANDLER_AUTH_PARAME) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execQueryAwardLevel());
	}
private: // ����ӿ�ִ�к���
	// 5 ����ӿڵ�ִ�к���
	PullListVO::Wrapper execQueryAwardLevel();
};

#include OATPP_CODEGEN_END(ApiController) // 0

#endif // !_TESTCONTROLLER_H_