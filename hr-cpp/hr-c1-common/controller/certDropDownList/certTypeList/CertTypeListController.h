#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: rice
 @Date: 2023/5/17 8:27:04

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
#ifndef _CERTTYPELIST_CONTROLLER_
#define _CERTTYPELIST_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/pullList/PullListDTO.h"
#include "domain/vo/pullList/PullListVO.h"
#include "domain/dto/certs/CertTypeDTO.h"
#include "domain/vo/certs/CertTypeVO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ֤�����������б������
 * ����ֵ : PullListVO
 * ������ : rice
 */
class CertTypeListController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(CertTypeListController);
	// 3 ����ӿ�
public:
	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(queryCertTypeList) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("common.controller.certTypeList");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(CertTypeListJsonVO);
		API_DEF_ADD_AUTH();
	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, PATH_TO_PULLIST("/cert-type"), queryCertTypeList, API_HANDLER_AUTH_PARAME) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execQueryCertTypeList());
	}
private:
	CertTypeListJsonVO::Wrapper execQueryCertTypeList();
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _CERTTYPELIST_CONTROLLER_