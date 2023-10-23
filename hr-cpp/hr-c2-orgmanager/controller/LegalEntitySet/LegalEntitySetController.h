#pragma once
/*
��֯���� ������������ ���� ������������  -- cpt

�����������������б� `LegalEntitySetPullDownList`

����ָ������������Ϣ  `UpdateLegalerSettingMessage`

������������ `LegalEntitySet`

�����������ã�֧������������** `LegalEntitySet`
*/ 

// LegalEntitySetController

#pragma once

#ifndef _LEGALENTITYSET_CONTROLLER_
#define _LEGALENTITYSET_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/do/LegalEntitySet/LegalEntitySetDO.h"
#include "domain/dto/LegalEntitySet/LegalEntitySetDTO.h"
#include "domain/dto/LegalEntitySet/LegalEntityAddSetDTO.h"
#include "domain/vo/LegalEntitySet/LegalEntitySetVO.h"
#include "domain/query/LegalEntitySet/LegalEntitySetQuery.h"
#include "domain/dto/LegalEntitySet/LegalEntitySetUpdateDTO.h"

#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"
#include "ApiHelper.h"

using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class LegalEntitySetController : public oatpp::web::server::api::ApiController {
	API_ACCESS_DECLARE(LegalEntitySetController); // 2 ����������������
public:
	
	ENDPOINT_INFO(addLegalEntitySet) {
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("LegalEntitySet.post.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	ENDPOINT(API_M_POST, "/org/add-LegalEntitySet", addLegalEntitySet, API_HANDLER_AUTH_PARAME, BODY_DTO(List<LegalEntitySetAddDTO::Wrapper>, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execAddLegalEntitySet(dto, authObject->getPayload()));
	}

	ENDPOINT_INFO(exportLegalEntitySet) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("LegalEntitySet.export.summary");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(LegalEntitySetPageJsonVO);
		// �����ҳ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ������������������
	}
	// �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/org/export-LegalerSeting", exportLegalEntitySet, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// ������ѯ����
		API_HANDLER_QUERY_PARAM(userQuery, LegalEntitySetQuery, queryParams);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execExportLegalEntitySet(userQuery, authObject->getPayload()));
	}

	// �����ѯ�ӿ�����
	ENDPOINT_INFO(queryLegalEntitySetPullDownList) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("LegalEntitySet.query.summary3");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(LegalEntitySetPageJsonVO);
		// �����ҳ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ������������������
		info->queryParams.add<String>("ormsignorgid").description = ZH_WORDS_GETTER("LegalEntitySet.field.ormsignorgname");
		info->queryParams["ormsignorgid"].addExample("default", String(ZH_WORDS_GETTER("LegalEntitySet.sample.name1")));
		info->queryParams["ormsignorgid"].required = false;
	}
	// �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/org/query-LegalEntitySetPullDownList", queryLegalEntitySetPullDownList, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// ������ѯ����
		API_HANDLER_QUERY_PARAM(userQuery, LegalEntitySetQuery, queryParams);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execLegalEntitySetPullDownList());
	}

	// �����޸Ľӿ�����
	ENDPOINT_INFO(modifyLegalEntitySet) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("LegalEntitySet.put.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
		info->queryParams.add<String>("name").description = ZH_WORDS_GETTER("EmpInfo.field.name");
		info->queryParams["name"].addExample("default", String("li ming"));
	}
	// �����޸Ľӿڴ���
	ENDPOINT(API_M_PUT, "/org/update-LegalEntitySet", modifyLegalEntitySet, BODY_DTO(LegalEntitySetUpdateDTO::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execModifyLegalEntitySet(dto));
	}

	/* ---------------------------�����������ÿ��������--����֯����-��������-�����������ã�--TripleGold ----------------------------*/
	// �����ѯ����������Ϣ�ӿ�����
	ENDPOINT_INFO(queryLES) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("LegalEntitySet.query.summary");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(LegalEntitySetQueryPageJsonVO);
		// �����ҳ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		// ǩԼ���嵥λ����,����λ��ʶ
		info->queryParams.add<String>("contractsignorgname").description = ZH_WORDS_GETTER("LegalEntitySet.field.ormsignorgname");
		info->queryParams["contractsignorgname"].addExample("default", String(ZH_WORDS_GETTER("LegalEntitySet.sample.name1")));
		info->queryParams["contractsignorgname"].required = false;
	}
	// �����ѯ����������Ϣ�ӿڴ���
	ENDPOINT(API_M_GET, "/org/query-LES", queryLES, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// ������ѯ����
		API_HANDLER_QUERY_PARAM(legalEntitySetQuery, LegalEntitySetQuery, queryParams);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execQueryLES(legalEntitySetQuery));
	}

private:
	// ���ӷ�����������
	Uint64JsonVO::Wrapper execAddLegalEntitySet(const List<LegalEntitySetAddDTO::Wrapper> & dto, const PayloadDTO& payload);
	// ����������������
	LegalEntitySetPageJsonVO::Wrapper execExportLegalEntitySet(const LegalEntitySetQuery::Wrapper& query, const PayloadDTO& payload);
	// �����������������б�
	LegalEntitySetPullDownJsonVO::Wrapper execLegalEntitySetPullDownList();
	// ���·�����������
	StringJsonVO::Wrapper execModifyLegalEntitySet(const LegalEntitySetUpdateDTO::Wrapper& dto);
	// ��ҳ��ѯ����
	LegalEntitySetQueryPageJsonVO::Wrapper execQueryLES(const LegalEntitySetQuery::Wrapper& query);
};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _LEGALENTITYSET_CONTROLLER_

