#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: yuanxiang
 @Date: 2023/05/19 14:56:48

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
#ifndef _ADDTAGCONTROLLER_H_
#define _ADDTAGCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/dto/projTag/ProjTagDTO.h"
#include "domain/vo/projTag/ProjTagVO.h"
#include "domain/dto/projTag/AddProjTagDTO.h"
#include OATPP_CODEGEN_BEGIN(ApiController)
/**
 * ������Ŀ��ǩController�ӿڣ�
 * ��������Ϊ ormxmbqname(��Ŀ��ǩ)��ormorgid(��֯id)��ormxmbqid(��Ŀ��ǩid��Ŀǰ�����ѩ��ID���)�������ֶ��Զ�����
 * ����ֵ����Ŀ��ǩID
 * �����ˣ�Զ��
 */
class AddTagController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(AddTagController);
public: // ����ӿ�
	ENDPOINT_INFO(addTag) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("projTag.add.summary");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	ENDPOINT(API_M_POST, PATH_TO_PROJTAG("/add-proj-tag"), addTag, API_HANDLER_AUTH_PARAME, BODY_DTO(AddProjTagDTO::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execAddProjTag(dto, authObject->getPayload()));
	}

private: // ����ӿ�ִ�к���
	StringJsonVO::Wrapper execAddProjTag(const AddProjTagDTO::Wrapper& dto, const PayloadDTO& payload);
};


#include OATPP_CODEGEN_END(ApiController)

#endif // !_ADDTAGCONTROLLER_H_