#pragma once
/**
* ֤�������Ա��Ϣ��ѯ��������ʹ��--(֤�����-��ҳ��ѯԱ����Ϣ)-weixiaoman
*/

#ifndef _EMPLOYEEINFO_CONTROLLER_
#define _EMPLOYEEINFO_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/CertificateManage/EmployeeInfoQuery.h"
#include "domain/dto/CertificateManage/EmployeeInfoDTO.h"
#include "domain/vo/CertificateManage/EmployeeInfoVO.h"
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"

using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

// ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ��Ա��Ϣ��ѯ���ܿ�����
 */
class EmployeeInfoController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(EmployeeInfoController);

	// ����ӿ�
public:
	// �����ѯ�ӿ�����
	ENDPOINT_INFO(queryEmpInfo) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("EmpInfo.get.summary");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(EmployeeInfoPageJsonVO);
		// �����ҳ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ������������������
		info->queryParams.add<String>("name").description = ZH_WORDS_GETTER("EmpInfo.field.name");
		info->queryParams["name"].addExample("default", String("li ming"));
		//info->queryParams["name"].required = false;
	}
	// �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/bas/query-employeeinfo", queryEmpInfo, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// ������ѯ����
		API_HANDLER_QUERY_PARAM(userQuery, EmployeeInfoQuery, queryParams);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execQueryEmpInfo(userQuery, authObject->getPayload()));
	}
private:
	// ��Ա��Ϣ��ҳ��ѯ����
	EmployeeInfoPageJsonVO::Wrapper execQueryEmpInfo(const EmployeeInfoQuery::Wrapper& query, const PayloadDTO& payload);

};

// ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // !_EMPLOYEEINFO_CONTROLLER_