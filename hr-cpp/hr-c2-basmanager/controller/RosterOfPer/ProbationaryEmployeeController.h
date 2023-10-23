#pragma once
/**
 *  �������� ���� ��Ա������ ���� ����Ա�� ���� ������
 */

#ifndef _PROBATIONARY_EMPLOYEE_CONTROLLER_
#define _PROBATIONARY_EMPLOYEE_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/RosterOfPer/ProbationaryEmployeeQuery.h"
#include "domain/dto/RosterOfPer/ProbationaryEmployeeDTO.h"
#include "domain/vo/RosterOfPer/ProbationaryEmployeeVO.h"
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"

using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

// ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class ProbationaryEmployeeController : public oatpp::web::server::api::ApiController // �̳п�����
{
	// ����������������
	API_ACCESS_DECLARE(ProbationaryEmployeeController);
	// ����ӿ�
public:
	// �����ѯ�ӿ����� ѯ����������Ա������
	ENDPOINT_INFO(queryProbationaryEmployee) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("probationaryemployee.get.summary");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(ProbationaryEmployeePageJsonVO);
		// �����ҳ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ������������������
		info->queryParams.add<String>("id_or_name").description = ZH_WORDS_GETTER("formeremployees.field.id_or_name");
		info->queryParams["id_or_name"].addExample("default", String("1"));
		info->queryParams["id_or_name"].required = false;

		info->queryParams.add<String>("id").description = ZH_WORDS_GETTER("sample.field.id");
		info->queryParams["id"].addExample("default", String(""));
		info->queryParams["id"].required = false;

		info->queryParams.add<String>("name").description = ZH_WORDS_GETTER("formeremployees.field.name");
		info->queryParams["name"].addExample("default", String("li ming"));
		info->queryParams["name"].required = false;

		info->queryParams.add<String>("zjhm").description = ZH_WORDS_GETTER("probationaryemployee.field.zjhm");
		info->queryParams["zjhm"].addExample("default", String(""));
		info->queryParams["zjhm"].required = false;

		info->queryParams.add<String>("organization").description = ZH_WORDS_GETTER("probationaryemployee.field.organization");
		info->queryParams["organization"].addExample("default", String(""));
		info->queryParams["organization"].required = false;

		info->queryParams.add<String>("bm").description = ZH_WORDS_GETTER("probationaryemployee.field.bm");
		info->queryParams["bm"].addExample("default", String(""));
		info->queryParams["bm"].required = false;

		info->queryParams.add<String>("ygzt").description = ZH_WORDS_GETTER("probationaryemployee.field.ygzt");
		info->queryParams["ygzt"].addExample("default", String(""));
		info->queryParams["ygzt"].required = false;

		info->queryParams.add<String>("zgzt").description = ZH_WORDS_GETTER("probationaryemployee.field.zgzt");
		info->queryParams["zgzt"].addExample("default", String(""));
		info->queryParams["zgzt"].required = false;

	}
	// �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/bas/query-all-ProbationaryEmployee", queryProbationaryEmployee, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// ������ѯ����
		API_HANDLER_QUERY_PARAM(Query, ProbationaryEmployeeQuery, queryParams);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execQueryProbationaryEmployee(Query, authObject->getPayload()));
	}

	// ���嵼���ӿ�����
	ENDPOINT_INFO(exportProbationaryEmployee) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("probationaryemployee.get.out");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		// ������������������
		info->queryParams.add<String>("id_or_name").description = ZH_WORDS_GETTER("formeremployees.field.id_or_name");
		info->queryParams["id_or_name"].addExample("default", String("1"));
		info->queryParams["id_or_name"].required = false;

		info->queryParams.add<String>("id").description = ZH_WORDS_GETTER("sample.field.id");
		info->queryParams["id"].addExample("default", String(""));
		info->queryParams["id"].required = false;

		info->queryParams.add<String>("name").description = ZH_WORDS_GETTER("formeremployees.field.name");
		info->queryParams["name"].addExample("default", String("li ming"));
		info->queryParams["name"].required = false;

		info->queryParams.add<String>("zjhm").description = ZH_WORDS_GETTER("probationaryemployee.field.zjhm");
		info->queryParams["zjhm"].addExample("default", String(""));
		info->queryParams["zjhm"].required = false;

		info->queryParams.add<String>("organization").description = ZH_WORDS_GETTER("probationaryemployee.field.organization");
		info->queryParams["organization"].addExample("default", String(""));
		info->queryParams["organization"].required = false;

		info->queryParams.add<String>("bm").description = ZH_WORDS_GETTER("probationaryemployee.field.bm");
		info->queryParams["bm"].addExample("default", String(""));
		info->queryParams["bm"].required = false;

		info->queryParams.add<String>("ygzt").description = ZH_WORDS_GETTER("probationaryemployee.field.ygzt");
		info->queryParams["ygzt"].addExample("default", String(""));
		info->queryParams["ygzt"].required = false;

		info->queryParams.add<String>("zgzt").description = ZH_WORDS_GETTER("probationaryemployee.field.zgzt");
		info->queryParams["zgzt"].addExample("default", String(""));
		info->queryParams["zgzt"].required = false;
	}
	// �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/bas/get-ProbationaryEmployee", exportProbationaryEmployee, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// ������ѯ����
		API_HANDLER_QUERY_PARAM(Query, ProbationaryEmployeeQuery, queryParams);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execExportProbationaryEmployee(Query, authObject->getPayload()));
	}
private:
	// ��ҳ��ѯ����Ա������
	ProbationaryEmployeePageJsonVO::Wrapper execQueryProbationaryEmployee(const ProbationaryEmployeeQuery::Wrapper& query, const PayloadDTO& payload);
	// ��������Ա��Excel���
	StringJsonVO::Wrapper execExportProbationaryEmployee(const ProbationaryEmployeeQuery::Wrapper& query, const PayloadDTO& payload);
};

// ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _PROBATIONARY_EMPLOYEE_CONTROLLER_