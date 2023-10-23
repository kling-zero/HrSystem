#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: jun
 @Date: 2023/05/18 23:03:24

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
#ifndef _LANGUAGECOMPETENCECONTROLLER_H_
#define _LANGUAGECOMPETENCECONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/query/language/LanguageQuery.h"
#include "domain/dto/language/LanguageDTO.h"
#include "domain/vo/language/LanguageVO.h"
#include "domain/query/languagePage/LanguagePageQuery.h"
#include "domain/dto/importLanguage/ImportLanguageDTO.h"
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"
#include "domain/dto//deleteLanguage/DeleteLanguageDTO.h"
using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

#include OATPP_CODEGEN_BEGIN(ApiController)

class LanguageCompetenceController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(LanguageCompetenceController);
public: // ����ӿ�
	// �����ҳ��ѯ�ӿ�����
	ENDPOINT_INFO(queryLanguage) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("language.get.summarys");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(LanguagePageJsonVO);
		// �����ҳ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ������������������
		API_DEF_ADD_QUERY_PARAMS(String, "personID", ZH_WORDS_GETTER("sample.field.id"), "66958E87-91A4-4DA8-8124-060E93B47EBE", true);
	}
	//�����ҳ��ѯ�ӿڴ���
	//API_HANDLER_ENDPOINT_QUERY_AUTH(API_M_GET, "/user/query-langugae", queryLanguage, LanguagePageQuery, execQueryLanguage(query, authObject->getPayload()));
	ENDPOINT(API_M_GET, "/c3-language-info/query-langugae", queryLanguage, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		//������ѯ����
		API_HANDLER_QUERY_PARAM(userQuery, LanguagePageQuery, queryParams);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execQueryLanguage(userQuery, authObject->getPayload()));
	}
	// �����ѯ�ӿ�����
	ENDPOINT_INFO(queryOneLanguage) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("language.get.summary");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(LanguageJsonVO);
		// ������������������
		API_DEF_ADD_QUERY_PARAMS(String, "languageAbilityID", ZH_WORDS_GETTER("language.field.id"), "3A1F9BF1-2C9A-4249-80C2-A1F0E8B367B0", true);
	}
	//�����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/c3-language-info/query-one-langugae", queryOneLanguage, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		//������ѯ����
		API_HANDLER_QUERY_PARAM(userQuery, LanguageQuery, queryParams);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execQueryOneLanguage(userQuery, authObject->getPayload()));
	}
	//���������ӿ�����
	ENDPOINT_INFO(addLanguage) {
		//����ӿڱ���
		info->summary = ZH_WORDS_GETTER("language.post.summary");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Int32JsonVO);
		//API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	//���������ӿڴ���
	ENDPOINT(API_M_POST, "/c3-language-info/add-language", addLanguage, API_HANDLER_AUTH_PARAME, BODY_DTO(LanguageDTO::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execAddLanguage(dto, authObject->getPayload()));
	}
	//����ɾ���ӿ�����(֧������ɾ����
	ENDPOINT_INFO(deleteLanguage) {
		//����ӿڱ���
		info->summary = ZH_WORDS_GETTER("language.delete.summary");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Int32JsonVO);
		//API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	//����ɾ���ӿڴ���(֧������ɾ����
	ENDPOINT(API_M_DEL, "/c3-language-info/delete-language", deleteLanguage, API_HANDLER_AUTH_PARAME, BODY_DTO(DeleteLanguageDTO::Wrapper, dto)) {
		//��Ӧ���
		API_HANDLER_RESP_VO(execDeleteLanguage(dto, authObject->getPayload()));
	}
	//�����޸Ľӿ�����
	ENDPOINT_INFO(updateLanguage) {
		//����ӿڱ���
		info->summary = ZH_WORDS_GETTER("language.put.summary");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(BooleanJsonVO);
		//API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	//�����޸Ľӿڴ���
	ENDPOINT(API_M_PUT, "/c3-language-info/update-language", updateLanguage, API_HANDLER_AUTH_PARAME, BODY_DTO(LanguageDTO::Wrapper, dto)) {
		//��Ӧ���
		API_HANDLER_RESP_VO(execUpdateLanguage(dto, authObject->getPayload()));
	}
private: // ����ӿ�ִ�к���
	//�����ҳ��ѯ�ӿ�ִ�к���
	LanguagePageJsonVO::Wrapper execQueryLanguage(const LanguagePageQuery::Wrapper& query, const PayloadDTO& payload);
	//�����ѯ�ӿڽӿ�ִ�к���
	LanguageJsonVO::Wrapper execQueryOneLanguage(const LanguageQuery::Wrapper& query, const PayloadDTO& payload);
	//���������ӿ�ִ�к���
	Int32JsonVO::Wrapper execAddLanguage(const LanguageDTO::Wrapper& dto, const PayloadDTO& payload);
	//����ɾ���ӿ�ִ�к���
	Int32JsonVO::Wrapper execDeleteLanguage(const DeleteLanguageDTO::Wrapper& dto, const PayloadDTO& payload);
	//�����޸Ľӿ�ִ�к���
	BooleanJsonVO::Wrapper execUpdateLanguage(const LanguageDTO::Wrapper& dto, const PayloadDTO& payload);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_LANGUAGECOMPETENCECONTROLLER_H_