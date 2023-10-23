#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/05/08 21:23:08

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
#ifndef _SCIRESULTCONTROLLER_H_
#define _SCIRESULTCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/query/sciresult/SciResultQuery.h"
#include "domain/vo/sciresult/SciResultVO.h"
#include "domain/dto/sciresult/DelSciResultDTO.h"
#include "domain/dto/sciresult/SciResultDTO.h"
#include "domain/dto/sciresult/AddSciResultDTO.h"
#include "domain/dto/sciresult/Add2SciResultDTO.h"
#include "domain/dto/sciresult/IntoSciResultDTO.h"
#include <oatpp-swagger/Types.hpp>
#include OATPP_CODEGEN_BEGIN(ApiController) // 0

using namespace oatpp;

/**
 * ��ѯ������
 */
class SciResultController : public oatpp::web::server::api::ApiController // 1
{
	// 2 ����������������
	API_ACCESS_DECLARE(SciResultController);
public: // ����ӿ�
	// 3 ����ӿ�����
	ENDPOINT_INFO(querySciResult) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("sample.get.summary");
		// ������Ӧ��������
		API_DEF_ADD_RSP_JSON_WRAPPER(SciResultPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ���������ѯ����
		info->queryParams.add<String>("pimpersonid").description = ZH_WORDS_GETTER("sample.field.pimpersonid");
		info->queryParams["pimpersonid"].addExample("default", String("111"));
		info->queryParams["pimpersonid"].required = true;
	}
	// 4 ����ӿڶ˵�
	ENDPOINT(API_M_GET, "/sciresult/pagecheck", querySciResult, QUERIES(QueryParams, qps)) {
		// ������ѯ����������������ģ�Ͷ���
		API_HANDLER_QUERY_PARAM(query, SciResultQuery, qps);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execQueryTest(query));
	}

	//����ָ��Ա�����гɹ�(��������)
	ENDPOINT_INFO(AddSciResult) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("sample.post.summary");
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 ���������ӿڴ���
	ENDPOINT(API_M_POST, "/sciresult/add", AddSciResult, API_HANDLER_AUTH_PARAME, BODY_DTO(Add2SciResultDTO::Wrapper, dto,)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execAddSciResult(dto,authObject->getPayload()));
	}


	// ɾ��Ա�����гɹ�(֧������ɾ��)
	ENDPOINT_INFO(DelSciResult) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("sample.delete.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// ��������ɾ���ӿڴ���
	ENDPOINT(API_M_POST, "/sciresult/del", DelSciResult, BODY_DTO(DelSciResultDTO::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execDelSciResult(dto));
	}

	//����ָ��Ա�����гɹ�
	ENDPOINT_INFO(postFile) {
		info->summary = ZH_WORDS_GETTER("sciresult.into.summary");
		API_DEF_ADD_AUTH();
		info->addConsumes<oatpp::swagger::Binary>("application/octet-stream");
		API_DEF_ADD_RSP_JSON(StringJsonVO::Wrapper);
		info->queryParams["suffix"].description = ZH_WORDS_GETTER("sciresult.into.suffix");
		info->queryParams["suffix"].addExample("xlsx", String(".xlsx"));

		// ������������������
		info->queryParams.add<String>("pimpersonid").description = ZH_WORDS_GETTER("sciresult.field.PIMPERSONID");
		info->queryParams["pimpersonid"].addExample("default", String("111"));
		info->queryParams["pimpersonid"].required = true;

	}
	// �����ļ��ϴ��˵㴦��
	ENDPOINT(API_M_POST, "/sciresult/fileinto", postFile, API_HANDLER_AUTH_PARAME, BODY_STRING(String, body), QUERY(String, suffix), QUERY(String, pimpersonid)) {
		// ִ���ļ������߼�
		API_HANDLER_RESP_VO(execIntoSciResult(body, suffix, pimpersonid, authObject->getPayload()));
	}






private: // ����ӿ�ִ�к���
	// 5 ����ӿڵ�ִ�к���
	//�����ѯִ�к���
	SciResultPageJsonVO::Wrapper execQueryTest(const SciResultQuery::Wrapper& query);
	//�����������к���
	Uint64JsonVO::Wrapper execAddSciResult(const Add2SciResultDTO::Wrapper& dto, const PayloadDTO& payload);
	//����ɾ��ִ�к���
	Uint64JsonVO::Wrapper execDelSciResult(const DelSciResultDTO::Wrapper& dto);
	//���嵼��ִ�к���
	StringJsonVO::Wrapper execIntoSciResult(const String& body, const String& suffix, const String& pimpersonid, const PayloadDTO& payload);
};

#include OATPP_CODEGEN_END(ApiController) // 0

#endif // !_CONTRACTCONTROLLER_H_