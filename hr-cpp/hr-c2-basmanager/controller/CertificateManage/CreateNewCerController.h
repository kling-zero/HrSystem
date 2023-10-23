#pragma once
#ifndef _CREATE_NEW_CER_CONTROLLER_
#define _CREATE_NEW_CER_CONTROLLER_

#include "ApiHelper.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/query/CertificateManage/CreateNewCerQuery.h"
#include "domain/dto/CertificateManage/CreateNewCerDTO.h"
#include "domain/vo/CertificateManage/CreateNewCerVO.h"
/*������δ�õ�*/
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"

using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;
// ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) 

/**
  �½�֤��--(֤�����-�½�֤��)--pine
 */
class CreateNewCerController : public oatpp::web::server::api::ApiController // �̳п�����
{
	// ����������������
	API_ACCESS_DECLARE(CreateNewCerController);

public: // ����ӿڣ�����ӿ�������ӿڶ˵㣩
        // ���������ӿ�����
	ENDPOINT_INFO(addNewCer) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("cermanage.post.addcer");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	    // ���������ӿڴ���
	ENDPOINT(API_M_POST, "/bas/add-CreateNewCer", addNewCer, BODY_DTO(CreateNewCerDTO::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execAddNewCer(dto));
	}

private:// ����ִ�к���
	// ִ����������
	Uint64JsonVO::Wrapper execAddNewCer(const CreateNewCerDTO::Wrapper& dto);

};

// ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController)
#endif // _CreateNewCer_CONTROLLER_