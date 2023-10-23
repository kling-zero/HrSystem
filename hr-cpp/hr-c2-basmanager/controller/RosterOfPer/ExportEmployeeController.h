#pragma once
/*
����Ա������-��Ա������-����Ա����������ҳ��ǰ����ɣ���--luoluo
*/
#ifndef _EXPORTEMPLOYEE_CONTROLLER_
#define _EXPORTEMPLOYEE_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"

#include "domain/query/RosterOfPer/ExportEmployeeQuery.h"
#include "domain/dto/RosterOfPer/ExportEmployeeDTO.h"
#include "domain/vo/RosterOfPer/ExportEmployeeJsonVO.h"

#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"

using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

// ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class ExportEmployeeController : public oatpp::web::server::api::ApiController // �̳п�����
{
	// ����������������
	API_ACCESS_DECLARE(ExportEmployeeController);
	// ����ӿ�
public:
	// �����ѯ�ӿ�����
	ENDPOINT_INFO(exportEmployee) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("employee.export.summary");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(ExportEmployeeJsonVO);
		// �����ҳ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ������������������
		info->queryParams.add<String>("name").description = ZH_WORDS_GETTER("sample.field.name");
		info->queryParams["name"].addExample("default", String("li ming"));
		info->queryParams["name"].required = false;
		info->queryParams.add<String>("sex").description = ZH_WORDS_GETTER("sample.field.sex");
		info->queryParams["sex"].addExample("default", String("N"));
		info->queryParams["sex"].required = false;
	}
	// �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/bas/export-employee", exportEmployee, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// ������ѯ����
		API_HANDLER_QUERY_PARAM(userQuery, ExportEmployeeQuery, queryParams);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execExportEmployee(userQuery, authObject->getPayload()));
	}

private:
	// ��ʾ��ҳ��ѯ����
	ExportEmployeeJsonVO::Wrapper execExportEmployee(const ExportEmployeeQuery::Wrapper& query, const PayloadDTO& payload);

};

// ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _EXPORTEMPLOYEE_CONTROLLER_