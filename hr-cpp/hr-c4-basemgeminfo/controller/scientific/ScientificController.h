#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/05/15 21:03:55

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
#ifndef _SCIENTIFICCONTROLLER_H_
#define _SCIENTIFICCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/query/scientific/ScientificQuery.h"
#include "domain/vo/scientific/ScientificVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class ScientificController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(ScientificController);
public: // ����ӿ�
	//�鿴ָ��Ա�����гɹ�(ָ�����гɹ�����)
	ENDPOINT_INFO(queryScientific) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("scientific.get.summary");
		// ������Ӧ��������
		API_DEF_ADD_RSP_JSON_WRAPPER(ScientificJsonVO);
		// ���������ѯ����
		info->queryParams.add<String>("pimresearchfindingsid").description = ZH_WORDS_GETTER("scientific.pimresearchfindingsid");
		info->queryParams["pimresearchfindingsid"].addExample("default", String("167CEAAD-F15E-45E1-B1C4-50DAD227B3BF"));
	}
	ENDPOINT(API_M_GET, "/scientific/select", queryScientific, QUERIES(QueryParams, qps)) {
		// ������ѯ����������������ģ�Ͷ���
		API_HANDLER_QUERY_PARAM(query, ScientificViewQuery, qps);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execQueryScientific(query));
	}
	//�޸�ָ�����гɹ�(�����޸�)
	ENDPOINT_INFO(modifyScientific) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("scientific.put.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	ENDPOINT(API_M_PUT, "/scientific/modify", modifyScientific, BODY_DTO(ScientificDTO::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execModifyScientific(dto));
	}
	//����ָ��Ա�����гɹ�(������ҳ��ǰ�����)
	ENDPOINT_INFO(downloadScientific) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("scientific.download.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		// ���������ѯ����
		info->queryParams.add<String>("pimpersonid").description = ZH_WORDS_GETTER("scientific.pimpersonid");
		info->queryParams["pimpersonid"].addExample("default", String("EA3AE5AA-2318-4C84-AAF7-99CBDE9BA27B"));
	}
	ENDPOINT(API_M_POST, "/scientific/download", downloadScientific, QUERIES(QueryParams, qps)) {
		// ������ѯ����������������ģ�Ͷ���
		API_HANDLER_QUERY_PARAM(query, ScientificDownloadQuery, qps);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execDownloadScientific(query));
	}
private: // ����ӿ�ִ�к���
	ScientificJsonVO::Wrapper execQueryScientific(const ScientificViewQuery::Wrapper& query);
	StringJsonVO::Wrapper execModifyScientific(const ScientificDTO::Wrapper& dto);
	StringJsonVO::Wrapper execDownloadScientific(const ScientificDownloadQuery::Wrapper& query);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_SCIENTIFICCONTROLLER_H_