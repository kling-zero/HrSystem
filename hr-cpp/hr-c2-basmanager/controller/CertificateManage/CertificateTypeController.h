#pragma once
/**
 * ֤�����Ͳ�ѯ���ܵ㣬������ʹ��--(֤�����-֤������)--weixiaoman
 */
#ifndef _CERTIFICATETYPE_CONTROLLER_
#define _CERTIFICATETYPE_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/CertificateManage/CertificateTypeQuery.h"
#include "domain/dto/CertificateManage/CertificateTypeDTO.h"
#include "domain/vo/CertificateManage/CertificateTypeVO.h"
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"

using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

// ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ֤�����Ͳ�ѯ���ܿ�����
 */
class CertificateTypeController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(CertificateTypeController);

	// ����ӿ�
public:
	// �����ѯ�ӿ�����
	ENDPOINT_INFO(queryCertificateType) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("EmpInfo.get.summary1");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(CertificateTypePageJsonVO);
		// �����ҳ��������
		API_DEF_ADD_PAGE_PARAMS();
		//������������
		//// ������������������
		//info->queryParams.add<String>("name").description = ZH_WORDS_GETTER("EmpInfo.field.name");
		//info->queryParams["name"].addExample("default", String("li ming"));
		////info->queryParams["name"].required = false;
	}
	// �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/bas/query-CertificateType", queryCertificateType, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// ������ѯ����
		API_HANDLER_QUERY_PARAM(userQuery, CertificateTypeQuery, queryParams);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execQueryCertificateType(userQuery, authObject->getPayload()));
	}
private:
	// ��ְ��Ա��ҳ��ѯ����
	CertificateTypePageJsonVO::Wrapper execQueryCertificateType(const CertificateTypeQuery::Wrapper& query, const PayloadDTO& payload);
};

// ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // !_CERTIFICATETYPE_CONTROLLER_