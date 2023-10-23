#pragma once
#ifndef _CERTIFICATECONTROLLLER_
#define _CERTIFICATECONTROLLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/Certificate/CertificateQuery.h"
#include "domain/dto/Certificate/CertificateDTO.h"
#include "domain/vo/Certificate/CertificateVO.h"
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"

using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
class CertificateController : public oatpp::web::server::api::ApiController // �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(CertificateController);
	// 3 ����ӿ�
public:
	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(queryCertificate) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("certificate.get.summary");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(CertificatePageJsonVO);
		// �����ҳ��������
		API_DEF_ADD_PAGE_PARAMS();
	}
	ENDPOINT(API_M_GET, "/certificate/query-certificate", queryCertificate, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// ������ѯ����
		API_HANDLER_QUERY_PARAM(CertificateQuery, CertificateQuery, queryParams);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execQueryCertificate(CertificateQuery, authObject->getPayload()));
	}
	// 3.1 ���������ӿ�����
	ENDPOINT_INFO(addCertificate) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("certificate.post.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 ���������ӿڴ���
	ENDPOINT(API_M_POST, "/certificate/add-certificate", addCertificate, BODY_DTO(CertificateDTO::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execAddCertificate(dto));
	}
	// 3.1 �����޸Ľӿ�����
	ENDPOINT_INFO(modifyCertificate) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("certificate.put.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 �����޸Ľӿڴ���
	ENDPOINT(API_M_PUT, "/certificate/modify-certificate", modifyCertificate, BODY_DTO(CertificateDTO::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execModifyCertificate(dto));
	}
	// 3.1 ����ɾ���ӿ�����
	ENDPOINT_INFO(removeCertificate) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("certificate.delete.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 ����ɾ���ӿڴ���
	ENDPOINT(API_M_DEL, "/certificate/remove-certificate", removeCertificate, BODY_DTO(CertificateDTO::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execRemoveCertificate(dto));
	}
private:
	// 3.3 ��ʾ��ҳ��ѯ����
	CertificatePageJsonVO::Wrapper execQueryCertificate(const CertificateQuery::Wrapper& query, const PayloadDTO& payload);
	// 3.3 ��ʾ��������
	Uint64JsonVO::Wrapper execAddCertificate(const CertificateDTO::Wrapper& dto);
	// 3.3 ��ʾ�޸�����
	Uint64JsonVO::Wrapper execModifyCertificate(const CertificateDTO::Wrapper& dto);
	// 3.3 ��ʾɾ������
	Uint64JsonVO::Wrapper execRemoveCertificate(const CertificateDTO::Wrapper& dto);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // 