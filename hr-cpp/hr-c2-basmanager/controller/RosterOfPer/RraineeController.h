#pragma once
#ifndef _PAGEQUERYEMPLOYEELIST_CONTROLLER_
#define _PAGEQUERYEMPLOYEELIST_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/do/RosterOfPer/RraineeDO.h"
#include "domain/dto/RosterOfPer/RraineeDTO.h"
#include "domain/vo/RosterOfPer/RraineeVO.h"
#include "domain/query/RosterOfPer/RraineeQuery.h"

#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"

/**
 *  �������� ���� ��Ա������ ���� ��ϰԱ��  ����Cpt
 */

using namespace oatpp;

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

namespace multipart = oatpp::web::mime::multipart;

class RraineeController : public oatpp::web::server::api::ApiController {
	API_ACCESS_DECLARE(RraineeController); // ����������������
public:

	// �����ѯ�ӿ�����
	ENDPOINT_INFO(queryRrainee) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("RosterOfPer.query.summary");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(RraineePageJsonVO);
		// �����ҳ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ������������������
		/*info->queryParams.add<String>("ygbh").description = ZH_WORDS_GETTER("RosterOfPer.field.ygbh");
		info->queryParams["ygbh"].addExample("default", String("li ming"));
		info->queryParams["ygbh"].required = false;
		info->queryParams.add<String>("pcmjxszzkhjgjlname").description = ZH_WORDS_GETTER("RosterOfPer.field.pcmjxszzkhjgjlname");
		info->queryParams["pcmjxszzkhjgjlname"].addExample("default", String(""));
		info->queryParams["pcmjxszzkhjgjlname"].required = false;*/
	}
	// �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/bas/query-RraineePageQueryEmployeeList", queryRrainee, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// ������ѯ����
		API_HANDLER_QUERY_PARAM(userQuery, RraineeQuery, queryParams);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execRraineeQuery(userQuery, authObject->getPayload()));
	} 

	ENDPOINT_INFO(exportRrainee) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("RosterOfPer.export.summary");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(RraineePageJsonVO);
		// �����ҳ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ������������������
	}

	// �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/bas/export-RraineeExportEmployee", exportRrainee, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// ������ѯ����
		API_HANDLER_QUERY_PARAM(userQuery, RraineeQuery, queryParams);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execRraineeExport(userQuery, authObject->getPayload()));
	}


	// �ļ�����
	//ENDPOINT_INFO(exportLEM) {
	//	// ����ӿڱ���
	//	info->summary = ZH_WORDS_GETTER("LegalEntitySet.export.summary");
	//	// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
	//	API_DEF_ADD_AUTH();
	//	// ������Ӧ������ʽ
	//	API_DEF_ADD_RSP_JSON_WRAPPER(BooleanJsonVO);
	//	// �����ҳ��������
	//	API_DEF_ADD_PAGE_PARAMS();
	//	// ����������ѯ��������
	//	info->queryParams.add<String>("ORMSIGNORGID").description = ZH_WORDS_GETTER("LegalEntitySet.field.id");
	//	info->queryParams["ORMSIGNORGID"].addExample("default", String("11F28C41-1D50-4503-B925-D86D1F70A1D2"));
	//	info->queryParams.add<String>("UPDATEMAN").description = ZH_WORDS_GETTER("LegalEntitySet.field.updateman");
	//	info->queryParams["UPDATEMAN"].addExample("default", String("guest"));
	//	info->queryParams.add<String>("CREATEMAN").description = ZH_WORDS_GETTER("LegalEntityM	ai.field.createman");
	//	info->queryParams["CREATEMAN"].addExample("default", String("1944DE89-8E28-4D10-812C-CAEEAAE8A927"));
	//	info->queryParams.add<String>("CREATEDATE").description = ZH_WORDS_GETTER("LegalEntitySet.field.createdate");
	//	info->queryParams["CREATEDATE"].addExample("default", String("2019-09-10 20:45:00"));
	//	info->queryParams.add<String>("ORMSIGNORGNAME").description = ZH_WORDS_GETTER("LegalEntitySet.field.name");
	//	info->queryParams["ORMSIGNORGNAME"].addExample("default", String(ZH_WORDS_GETTER("LegalEntitySet.sample.name")));
	//	info->queryParams.add<String>("UPDATEDATE").description = ZH_WORDS_GETTER("LegalEntitySet.field.updatedate");
	//	info->queryParams["UPDATEDATE"].addExample("default", String("2020-05-29 10:49:53"));
	//	info->queryParams.add<String>("ORGCODE").description = ZH_WORDS_GETTER("LegalEntitySet.field.orgcode");
	//	info->queryParams["ORGCODE"].addExample("default", String("104"));
	//}
	//ENDPOINT(API_M_GET, "/ExportLEM", exportLEM, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
	//	// ������ѯ����
	//	API_HANDLER_QUERY_PARAM(legalEntityMaiQuery, LegalEntityMaiQuery, queryParams);
	//	// ��Ӧ���
	//	API_HANDLER_RESP_VO(execExportLEM(legalEntityMaiQuery));
	//}


private:
	// ��ʾ��ҳ��ѯ����
	RraineePageJsonVO::Wrapper execRraineeQuery(const RraineeQuery::Wrapper& query, const PayloadDTO& payload);
	RraineePageJsonVO::Wrapper execRraineeExport(const RraineeQuery::Wrapper& query, const PayloadDTO& payload);
};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _PAGEQUERYEMPLOYEELIST_CONTROLLER_