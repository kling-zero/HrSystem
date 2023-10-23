#pragma once
#ifndef _LEGALENTITYMAICONTROLLER_H_
#define _LEGALENTITYMAICONTROLLER_H_

#include "domain/query/LegalEntityMai/LegalEntityMaiQuery.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/LegalEntityMai/LegalEntityMaiDTO.h"
#include "domain/vo/LegalEntityMai/LegalEntityMaiVO.h"
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"
#include "ExcelComponent.h"
#include "oatpp-swagger/Types.hpp"
#include "domain/dto/LegalEntityMai/LegalEntityMaiDelDTO.h"
#include "domain/dto/LegalEntityMai/LegalEntityMaiAddDTO.h"

using namespace oatpp;

#include OATPP_CODEGEN_BEGIN(ApiController)
namespace multipart = oatpp::web::mime::multipart;

/* ��������ά�����������--����֯����-��������-��������ά����--TripleGold */
class LegalEntityMaiController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(LegalEntityMaiController);
public: // ����ӿ�
	// �����ѯ����������Ϣ�ӿ�����
	ENDPOINT_INFO(queryLEM) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("LegalEntityMai.query.summary");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(LegalEntityMaiPageJsonVO);
		// �����ҳ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		/*info->queryParams.add<String>("ORMSIGNORGID").description = ZH_WORDS_GETTER("LegalEntityMai.field.id");
		info->queryParams["ORMSIGNORGID"].addExample("default", String("11F28C41-1D50-4503-B925-D86D1F70A1D2"));
		info->queryParams.add<String>("UPDATEMAN").description = ZH_WORDS_GETTER("LegalEntityMai.field.updateman");
		info->queryParams["UPDATEMAN"].addExample("default", String("guest"));
		info->queryParams.add<String>("CREATEMAN").description = ZH_WORDS_GETTER("LegalEntityMai.field.createman");
		info->queryParams["CREATEMAN"].addExample("default", String("1944DE89-8E28-4D10-812C-CAEEAAE8A927"));
		info->queryParams.add<String>("CREATEDATE").description = ZH_WORDS_GETTER("LegalEntityMai.field.createdate");
		info->queryParams["CREATEDATE"].addExample("default", String("2019-09-10 20:45:00"));*/
		info->queryParams.add<String>("ORMSIGNORGNAME").description = ZH_WORDS_GETTER("LegalEntityMai.field.name");
		info->queryParams["ORMSIGNORGNAME"].addExample("default", String(ZH_WORDS_GETTER("LegalEntityMai.sample.name")));
		info->queryParams["ORMSIGNORGNAME"].required = false;
		/*info->queryParams.add<String>("UPDATEDATE").description = ZH_WORDS_GETTER("LegalEntityMai.field.updatedate");
		info->queryParams["UPDATEDATE"].addExample("default", String("2020-05-29 10:49:53"));
		info->queryParams.add<String>("ORGCODE").description = ZH_WORDS_GETTER("LegalEntityMai.field.orgcode");
		info->queryParams["ORGCODE"].addExample("default", String("104"));*/
	}
	// �����ѯ����������Ϣ�ӿڴ���
	ENDPOINT(API_M_GET, "/org/query-LEM", queryLEM, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// ������ѯ����
		API_HANDLER_QUERY_PARAM(legalEntityMaiQuery, LegalEntityMaiQuery, queryParams);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execQueryLEM(legalEntityMaiQuery));
	}

	/* ������·����������ƣ���֯��� */
	ENDPOINT_INFO(updateLEM) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("LegalEntityMai.put.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	// ������½ӿڴ���
	ENDPOINT(API_M_PUT, "/org/update-LEM", updateLEM, BODY_DTO(LegalEntityMaiDTO::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execUpdateLEM(dto));
	}

	// ����������������ӿ�����
	ENDPOINT_INFO(addLEM) {
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("LegalEntityMai.post.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	ENDPOINT(API_M_POST, "/org/add-LEM", addLEM, API_HANDLER_AUTH_PARAME, BODY_DTO(List<LegalEntityMaiAddDTO::Wrapper>, dtoList)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execAddLEM(dtoList, authObject->getPayload()));
	}

	// ����ɾ����������ӿ�����
	ENDPOINT_INFO(removeLEM) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("LegalEntityMai.delete.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	ENDPOINT(API_M_DEL, "/org/remove-LEM", removeLEM, BODY_DTO(LegalEntityMaiDelDTO::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execRemoveLEM(dto));
	}

	// �ļ�����
	// �ļ�����
	ENDPOINT_INFO(importLEM) {
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("LegalEntityMai.import.summary");
		info->addConsumes<oatpp::swagger::Binary>("application/octet-stream");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON(StringJsonVO::Wrapper);
		info->queryParams["suffix"].description = ZH_WORDS_GETTER("LegalEntityMai.import.suffix");
		info->queryParams["suffix"].addExample("xlsx", String(".xlsx"));
	}
	ENDPOINT(API_M_POST, "/org/import-LEM", importLEM, API_HANDLER_AUTH_PARAME, 
		BODY_STRING(String, body), QUERY(String, suffix)) {
		// ִ���ļ������߼�
		API_HANDLER_RESP_VO(execImportLEM(body, suffix, authObject->getPayload()));
	}

	// �ļ�����
	ENDPOINT_INFO(exportLEM) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("LegalEntityMai.export.summary");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		// �����ҳ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		info->queryParams.add<String>("ORMSIGNORGNAME").description = ZH_WORDS_GETTER("LegalEntityMai.field.name");
		info->queryParams["ORMSIGNORGNAME"].addExample("default", String(ZH_WORDS_GETTER("LegalEntityMai.sample.name")));
		info->queryParams["ORMSIGNORGNAME"].required = false;
		info->queryParams.add<String>("ORGCODE").description = ZH_WORDS_GETTER("LegalEntityMai.field.orgcode");
		info->queryParams["ORGCODE"].addExample("default", String("104"));
		info->queryParams["ORGCODE"].required = false;
	}
	ENDPOINT(API_M_GET, "/org/export-LEM", exportLEM, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// ������ѯ����
		API_HANDLER_QUERY_PARAM(query, LegalEntityMaiQuery, queryParams);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execExportLEM(query));
	}
	
private: // ����ӿ�ִ�к���
	// ��ҳ��ѯ����
	LegalEntityMaiPageJsonVO::Wrapper execQueryLEM(const LegalEntityMaiQuery::Wrapper& query);
	// ��������
	StringJsonVO::Wrapper execUpdateLEM(const LegalEntityMaiDTO::Wrapper& dto);
	// ������������
	Uint64JsonVO::Wrapper execAddLEM(const List<LegalEntityMaiAddDTO::Wrapper>& dtoList, const PayloadDTO& payload);
	// ɾ������
	Uint64JsonVO::Wrapper execRemoveLEM(const LegalEntityMaiDelDTO::Wrapper& dto);
	// ��������
	StringJsonVO::Wrapper execImportLEM(const String& body, const String& suffix, const PayloadDTO& payload);
	// ��������
	StringJsonVO::Wrapper execExportLEM(const LegalEntityMaiQuery::Wrapper& query);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_LEGALENTITYMAICONTROLLER_H_