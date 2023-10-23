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
#ifndef _PROFCERTSLIST_CONTROLLER_
#define _PROFCERTSLIST_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/certs/ProfCertsQuery.h"
#include "domain/dto/certs/ProfCertsDTO.h"
#include "domain/vo/certs/ProfCertsVO.h"


// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ְҵ�ʸ�֤�����������б������
 * ����ֵ : ProfCertsListJsonVO
 * ������ : rice
 */
class ProfCertsListController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(ProfCertsListController);
	// 3 ����ӿ�
public:
	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(queryProfCertsList) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("common.controller.profCertsList");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(ProfCertsListJsonVO);
		// �����ҳ��������
		API_DEF_ADD_PAGE_PARAMS();
		API_DEF_ADD_AUTH();
	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, PATH_TO_PULLIST("/query-prof-certs"), queryProfCertsList, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// ������ѯ����
		API_HANDLER_QUERY_PARAM(profCertsQuery, ProfCertsQuery, queryParams);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execQueryProfCertsList(profCertsQuery));
	}
private:
	ProfCertsListJsonVO::Wrapper execQueryProfCertsList(const ProfCertsQuery::Wrapper& query);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _PROFCERTSLIST_CONTROLLER_