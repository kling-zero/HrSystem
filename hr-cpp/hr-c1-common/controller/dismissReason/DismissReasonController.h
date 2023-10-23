#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: yuanxiang
 @Date: 2023/05/20 22:27:31

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
#ifndef _DISMISSREASONCONTROLLER_H_
#define _DISMISSREASONCONTROLLER_H_

#include "ApiHelper.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/pullList/PullListVO.h"
#include "domain/dto/pullList/PullListDTO.h"
#include "service/dismissReason/DismissReasonService.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

/**
 * ��ְԭ��Controller
 * ����ǰ�����󣬲�ѯ��ְԭ����װ���б���
 * �����ˣ�Զ��
 */
class DismissReasonController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(DismissReasonController);
public: // ����ӿ�
	ENDPOINT_INFO(queryDismissReason) {
		info->summary = ZH_WORDS_GETTER("common.controller.dismissReason");
		API_DEF_ADD_RSP_JSON_WRAPPER(PullListVO);
		API_DEF_ADD_AUTH();
	}

	ENDPOINT(API_M_GET, PATH_TO_PULLIST("/dismiss-reason"), queryDismissReason, API_HANDLER_AUTH_PARAME) {
		API_HANDLER_RESP_VO(execQueryDismissReason());
	}
private: // ����ӿ�ִ�к���
	PullListVO::Wrapper execQueryDismissReason();
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_DISMISSREASONCONTROLLER_H_