#pragma once
/**
 *  �������� ���� ��Ա������ ���� ��ְԱ�� ���� ������
 */

#ifndef __FORMER_EMPLOYEES_CONTROLLER_
#define __FORMER_EMPLOYEES_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/RosterOfPer/FormerEmployeesQuery.h"
#include "domain/dto/RosterOfPer/FormerEmployeesDTO.h"
#include "domain/vo/RosterOfPer/FormerEmployeesVO.h"
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"
#include <boost/throw_exception.hpp>

using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

// ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class FormerEmployeesController : public oatpp::web::server::api::ApiController // �̳п�����
{
	// ����������������
	API_ACCESS_DECLARE(FormerEmployeesController);
	// ����ӿ�
public:
	// �����ѯ�ӿ����� ѯ��������ְԱ������
	ENDPOINT_INFO(queryFormerEmployees) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("formeremployees.get.summary");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(FormerEmployeesPageJsonVO);
		// �����ҳ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ������������������
		info->queryParams.add<String>("id_or_name").description = ZH_WORDS_GETTER("formeremployees.field.id_or_name");
		info->queryParams["id_or_name"].addExample("default", String("1"));
		info->queryParams["id_or_name"].required = false;
	}
	// �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/bas/query-all-FormerEmployees", queryFormerEmployees, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// ������ѯ����
		API_HANDLER_QUERY_PARAM(userQuery, FormerEmployeesQuery, queryParams);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execQueryFormerEmployees(userQuery, authObject->getPayload()));
	}

	// ���嵼���ӿ�����
	ENDPOINT_INFO(exportFormerEmployees) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("formeremployees.get.out");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		// �����ҳ��������
		//API_DEF_ADD_PAGE_PARAMS();
		//// ������������������
		//info->queryParams.add<UInt64>("outbenye").description = ZH_WORDS_GETTER("formeremployees.field.outbenye");
		//info->queryParams["outbenye"].addExample("default", String("1"));
		//info->queryParams["outbenye"].required = false;
		//info->queryParams.add<UInt64>("outall").description = ZH_WORDS_GETTER("formeremployees.field.outall");
		//info->queryParams["outall"].addExample("default", String("0"));
		//info->queryParams["outall"].required = false;
	}
	// �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/bas/get-FormerEmployees", exportFormerEmployees, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// ������ѯ����
		API_HANDLER_QUERY_PARAM(Query, FormerEmployeesQuery, queryParams);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execExportFormerEmployees(Query, authObject->getPayload()));
	}
private:
	// ��ʾ��ҳ��ѯ����
	FormerEmployeesPageJsonVO::Wrapper execQueryFormerEmployees(const FormerEmployeesQuery::Wrapper& query, const PayloadDTO& payload);
	// ������ְԱ��Excel���
	StringJsonVO::Wrapper execExportFormerEmployees(const FormerEmployeesQuery::Wrapper& query, const PayloadDTO& payload);
};

// ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // __FORMER_EMPLOYEES_CONTROLLER_