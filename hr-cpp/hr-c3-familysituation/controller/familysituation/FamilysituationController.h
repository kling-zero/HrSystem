#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Marvin
 @Date: 2023/05/18 19:52:51

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
#ifndef _FAMILYSITUATIONCONTROLLER_H_
#define _FAMILYSITUATIONCONTROLLER_H_

// ����ģ��
#include "domain/vo/BaseJsonVO.h"
#include "domain/query/familysituation/FamilysituationQuery.h"
#include "domain/dto/familysituation/FamilysituationDTO.h"
#include "domain/dto/familysituation/ImportfamilysituationDTO.h"
#include "domain/vo/familysituation/FamilysituationVO.h"
#include "domain/query/familysituation/FamilysituationQuery.h"

// API����
#include "ApiHelper.h"
#include "CharsetConvertHepler.h"

// �ļ��ϴ�
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"

using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

#include OATPP_CODEGEN_BEGIN(ApiController)

/**
 * ��ͥ���������
 **/
class FamilysituationController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(FamilysituationController);
public: // ����ӿ�
	// �����ѯ����
 	ENDPOINT_INFO(queryFamilysituation)
 	{
 		//�������
 		info->summary = ZH_WORDS_GETTER("familysituation.get.summary");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
 		// ������Ӧ������ʽ
 		API_DEF_ADD_RSP_JSON_WRAPPER(FamilysituationPageJsonVO);
 		// �����ҳ��������
 		API_DEF_ADD_PAGE_PARAMS();
		info->queryParams.add<String>("personid").description = ZH_WORDS_GETTER("familysituation.field.personid");
		info->queryParams["personid"].addExample("default", String("0002CC75-F8EB-45B3-A359-0310EC7F6D5B"));
 	}
 	// �����ѯ�ӿڴ���
 	ENDPOINT(API_M_GET, "/c3-family-info/family-query", queryFamilysituation, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams))
 	{
 		// ������ѯ����
 		API_HANDLER_QUERY_PARAM(familysituationQuery, FamilysituationQuery, queryParams);
 		// ��Ӧ���
 		API_HANDLER_RESP_VO(execQueryByFamilysituation(familysituationQuery, authObject->getPayload()));
 	}
 	// �����ѯָ����ͥ����ӿ�����
 	ENDPOINT_INFO(queryOneFamilysituation)
 	{
 		// ����ӿڱ���
 		info->summary = ZH_WORDS_GETTER("familysituation.getone.summary");
 		// ������Ӧ������ʽ
 		API_DEF_ADD_RSP_JSON_WRAPPER(FamilysituationJsonVO);
		info->queryParams.add<String>("id").description = ZH_WORDS_GETTER("familysituation.field.id");
		info->queryParams["id"].addExample("default", String("12239214873271218176"));
 	}
 	// �����ѯָ����ͥ����ӿڴ���
 	ENDPOINT(API_M_GET, "/c3-family-info/family-query-one", queryOneFamilysituation, QUERIES(QueryParams, queryParams))
 	{
 		// ������ѯ����
 		API_HANDLER_QUERY_PARAM(oneQuery, FamilysituationQuery, queryParams);
 		// ��Ӧ���
 		API_HANDLER_RESP_VO(execOneQueryFamilysituation(oneQuery));
 	}
	// ������Ӽ�ͥ����ӿ�����
	ENDPOINT_INFO(addFamilysituation)
	{
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("familysituation.post.summary");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// ������ӽӿڴ���
	ENDPOINT(API_M_POST, "/c3-family-info/family-add", addFamilysituation, API_HANDLER_AUTH_PARAME, BODY_DTO(FamilysituationDTO::Wrapper, dto))
	{
		// ��Ӧ���
		API_HANDLER_RESP_VO(execAddFamilysituation(dto, authObject->getPayload()));
	}
	// �����޸Ľӿ�����
	ENDPOINT_INFO(modifyFamilysituation)
	{
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("familysituation.put.summary");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// �����޸Ľӿڴ���
	ENDPOINT(API_M_PUT, "/c3-family-info/family-modify", modifyFamilysituation, API_HANDLER_AUTH_PARAME, BODY_DTO(FamilysituationDTO::Wrapper, dto))
	{
		// ��Ӧ���
		API_HANDLER_RESP_VO(execModifyFamilysituation(dto, authObject->getPayload()));
	}
	// ����ɾ���ӿ�����
	ENDPOINT_INFO(removeFamilysituation)
	{
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("familysituation.del.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// ����ɾ���ӿڴ���
	ENDPOINT(API_M_DEL, "/c3-family-info/family-remove", removeFamilysituation, BODY_DTO(FamilyBatchDeleteDTO::Wrapper, dto))
	{
		// ��Ӧ���
		API_HANDLER_RESP_VO(execRemoveFamilysituation(dto));
	}
	// ���嵼��ӿ�����
	ENDPOINT_INFO(importFile)
	{
		info->summary = ZH_WORDS_GETTER("familysituation.import-file.summary");
		API_DEF_ADD_RSP_JSON(StringJsonVO::Wrapper);
		info->queryParams["suffix"].description = ZH_WORDS_GETTER("familysituation.import-file.suffix");
		info->queryParams["suffix"].addExample("xlsx", String(".xlsx"));
	}
	// ���嵼��ӿڴ���
	ENDPOINT(API_M_POST, "/c3-family-info/family-import", importFile, BODY_STRING(String, body), QUERY(String, suffix))
	{
		// ִ���ļ�����ͽ����߼�
		API_HANDLER_RESP_VO(executeImportFamilysituation(body, suffix));
	}
	
	// ���嵼���ӿ�����
	ENDPOINT_INFO(exportFamilysituation)
	{
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("familysituation.export.summary");
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		info->queryParams.add<String>("id").description = ZH_WORDS_GETTER("sample.field.id");
		info->queryParams["id"].addExample("default", String("0000001"));
		info->queryParams["id"].required = true;
	}
	// ���嵼���ӿڴ���
	ENDPOINT(API_M_GET, "/c3-family-info/family-export", exportFamilysituation, QUERIES(QueryParams, qps))
	{
		// ��Ӧ���
		API_HANDLER_QUERY_PARAM(query, FamilysituationQuery, qps);
		API_HANDLER_RESP_VO(execExportFamilysituation(query));
	}

private: // ����ӿ�ִ�к���
	// ��ѯ������Ӧ
	FamilysituationPageJsonVO::Wrapper execQueryByFamilysituation(const FamilysituationQuery::Wrapper& query, const PayloadDTO& payload);
	// ָ����ѯ������Ӧ
	FamilysituationJsonVO::Wrapper execOneQueryFamilysituation(const FamilysituationQuery::Wrapper& query);
	// ���������Ӧ
	Uint64JsonVO::Wrapper execAddFamilysituation(const FamilysituationDTO::Wrapper& dto, const PayloadDTO& payload);
	// �޸�������Ӧ
	Uint64JsonVO::Wrapper execModifyFamilysituation(const FamilysituationDTO::Wrapper& dto, const PayloadDTO& payload);
	// ɾ��������Ӧ
	Uint64JsonVO::Wrapper execRemoveFamilysituation(const FamilyBatchDeleteDTO::Wrapper& dto);
	// ����������Ӧ
	StringJsonVO::Wrapper executeImportFamilysituation(const String& fileBody, const String& suffix);
	// ����������Ӧ
	StringJsonVO::Wrapper execExportFamilysituation(const FamilysituationQuery::Wrapper & query);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_FAMILYSITUATIONCONTROLLER_H_