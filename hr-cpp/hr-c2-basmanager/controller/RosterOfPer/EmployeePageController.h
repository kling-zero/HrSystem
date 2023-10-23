/*
����Ա������-��Ա������-��ҳ��ѯԱ���б�--����
*/
#ifndef _EMPLOYEEPAGECONTROLLER_H_
#define _EMPLOYEEPAGECONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/RosterOfPer/EmployeePageDTO.h"
#include "domain/query/RosterOfPer/EmployeePageQuery.h"
#include "domain/vo/RosterOfPer/EmployeePageVO.h"
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"
#include OATPP_CODEGEN_BEGIN(ApiController)

class EmployeePageController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(EmployeePageController);
public: // ����ӿ�
	    // �����ѯ�ӿ�����
	ENDPOINT_INFO(queryEmployeePage) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("employee.get.summary");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(EmployeePageJsonVO);
		// �����ҳ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ������������������
		info->queryParams.add<String>("idAndName").description = ZH_WORDS_GETTER("employee.field.idAndName");
		info->queryParams["idAndName"].addExample("default", String("2032****"));
		info->queryParams["idAndName"].required = false;
		
	}
	// �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/bas/query-employeePage", queryEmployeePage, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// ������ѯ����
		API_HANDLER_QUERY_PARAM(userQuery, EmployeePageQuery, queryParams);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execQueryEmployeePage(userQuery, authObject->getPayload()));
	}
private: // ����ӿ�ִ�к���
	// ��ʾ��ҳ��ѯ����
	EmployeePageJsonVO::Wrapper execQueryEmployeePage(const EmployeePageQuery::Wrapper& query, const PayloadDTO& payload);

};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_EMPLOYEEPAGECONTROLLER_H_
