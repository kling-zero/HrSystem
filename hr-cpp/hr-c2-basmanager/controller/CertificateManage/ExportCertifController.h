#pragma once
/*
��֤�����-֤����Ϣ-����֤�飨������ҳ��ǰ����ɣ���--����
*/
#ifndef _EXPORTCERTIF_CONTROLLER_
#define _EXPORTCERTIF_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/CertificateManage/ExportCertifQuery.h"
#include "domain/dto/CertificateManage/ExportCertifDTO.h"
#include "domain/vo/CertificateManage/ExportCertifJsonVO.h"

#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"

using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

// ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * �ļ�����
 */
class ExportCertifController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(ExportCertifController);
public: // ����ӿ�
	// �����ѯ�ӿ�����
	ENDPOINT_INFO(ExportCertif) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("certif.export.summary");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(ExportCertifJsonVO);
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
	ENDPOINT(API_M_GET, "/bas/export-certif", ExportCertif, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// ������ѯ����
		API_HANDLER_QUERY_PARAM(userQuery, ExportCertifQuery, queryParams);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execExportCertif(userQuery, authObject->getPayload()));
	}
private: // ����ӿ�ִ�к���
	// ��ʾ��ҳ��ѯ����
	ExportCertifJsonVO::Wrapper execExportCertif(const ExportCertifQuery::Wrapper& query, const PayloadDTO& payload);

};

// ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _EXPORTCERTIF_CONTROLLER_