#pragma once
/**
 *  ֤����� ���� ֤����Ϣ ���� ��ѯ������ָ��֤�� ���� ������
 */

#ifndef __UPDATECERTIFIDATE_CONTROLLER_
#define __UPDATECERTIFIDATE_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/CertificateManage/SpercificCertificateQuery.h"
#include "domain/dto/CertificateManage/SpercificCertificateDTO.h"
#include "domain/vo/CertificateManage/SpercificCertificateVO.h"
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"

using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

// ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

// ʵ�ֲ�ѯָ��֤����ϸ��Ϣ�͸���ָ��֤�鹦��
class UpdateCertificateController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// ����������������
	API_ACCESS_DECLARE(UpdateCertificateController);
	// ����ӿ�
public:
	// �������ָ��֤��ӿ�����
	ENDPOINT_INFO(updateCertificate) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("spercificcertificate.get.update");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		// ���������
		/*info->queryParams.add<String>("PIMVOCATIONALID").description = ZH_WORDS_GETTER("spercificcertificate.field.PIMVOCATIONALID");
		info->queryParams["PIMVOCATIONALID"].addExample("default", String("1"));

		info->queryParams.add<String>("name").description = ZH_WORDS_GETTER("spercificcertificate.field.pimperSonName");
		info->queryParams["name"].addExample("default", String("li ming"));

		info->queryParams.add<String>("zgzsbh").description = ZH_WORDS_GETTER("spercificcertificate.field.zgzsbh");
		info->queryParams["zgzsbh"].addExample("default", String("1111"));

		info->queryParams.add<String>("zslx").description = ZH_WORDS_GETTER("spercificcertificate.field.zgzsbh");
		info->queryParams["zslx"].addExample("default", String("��λ�����ܣ�֤��"));

		info->queryParams.add<String>("pimVocationalName").description = ZH_WORDS_GETTER("spercificcertificate.field.pimVocationalName");
		info->queryParams["pimVocationalName"].addExample("default", String("��ȫԱ"));

		info->queryParams.add<String>("zghqrq").description = ZH_WORDS_GETTER("spercificcertificate.field.pimVocationalName");
		info->queryParams["zghqrq"].addExample("default", String("2002-5-15"));



		info->queryParams.add<String>("pimVocationalName").description = ZH_WORDS_GETTER("spercificcertificate.field.pimVocationalName");
		info->queryParams["pimVocationalName"].addExample("default", String("��ȫԱ"));
		info->queryParams["zgzsbh"].required = false;*/
	}
	// �����޸Ľӿڴ���
	ENDPOINT(API_M_PUT, "/bas/update-Certificater", updateCertificate, BODY_DTO(SpercificCertificateDTO::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execUpdateSpercificCertificate(dto));
	}

	// �����ѯָ��֤����Ϣ�ӿ�����
	ENDPOINT_INFO(getSpercificCertificate) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("spercificcertificate.get.query");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(SpercificCertificateJsonVO);
		info->queryParams.add<String>("PIMVOCATIONALID").description = ZH_WORDS_GETTER("spercificcertificate.field.PIMVOCATIONALID");
		info->queryParams["PIMVOCATIONALID"].addExample("default", String("1"));
	}


	// �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/bas/query-Certificater", getSpercificCertificate, QUERIES(QueryParams, queryParams)) {
		// ������ѯ����
		API_HANDLER_QUERY_PARAM(Query, SpercificCertificateQuery, queryParams);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execGetSpercificCertificate(Query));
	}
private:
	// ����֤����Ϣ
	StringJsonVO::Wrapper execUpdateSpercificCertificate(const SpercificCertificateDTO::Wrapper& dto);
	// ��ѯ֤����Ϣ
	SpercificCertificateJsonVO::Wrapper execGetSpercificCertificate(const SpercificCertificateQuery::Wrapper& query);
};

// ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // __UPDATECERTIFIDATE_CONTROLLER_