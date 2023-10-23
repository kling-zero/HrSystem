#pragma once
/*
��֤�����-֤����Ϣ-ɾ��֤�飨֧������ɾ������--����
*/
#ifndef _CERTIFIDELETE_CONTROLLER_
#define _CERTIFIDELETE_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"

#include "domain/dto/CertificateManage/RemoveCertifDTO.h"

#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"

using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

// ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class CertifDeleteController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// ����������������
	API_ACCESS_DECLARE(CertifDeleteController);
	// ����ӿ�
public:

	// ����ɾ���ӿ�����
	API_DEF_ENDPOINT_INFO(ZH_WORDS_GETTER("certif.delete.summary"), removeCertif, StringJsonVO);
	// ����ɾ���ӿڴ���
	ENDPOINT(API_M_DEL, "/bas/remove-certif", removeCertif, BODY_DTO(RemoveCertifDTO::Wrapper, dto)) {
	 // ��Ӧ���
	 API_HANDLER_RESP_VO(execRemoveCertif(dto));
	}
private:
	// ��ʾɾ������
	StringJsonVO::Wrapper execRemoveCertif(const RemoveCertifDTO::Wrapper& dto);
};

// ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _CERTIFIDELETE_CONTROLLER_