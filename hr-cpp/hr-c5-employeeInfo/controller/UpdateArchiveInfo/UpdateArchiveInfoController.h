#pragma once
#pragma once
#ifndef _UPDATE_ARCHIVE_INFO_CONTROLLER_
#define _UPDATE_ARCHIVE_INFO_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/UpdateArchiveInfo/UpdateArchiveInfoDTO.h"
#include "domain/vo/UpdateArchiveInfo/UpdateArchiveInfoVO.h"
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"

using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/*
	����ָ������������
*/
class UpdateArchiveInfoController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(UpdateArchiveInfoController);
	// 3 ����ӿ�
public:
	// 3.1 �����޸Ľӿ�����
	ENDPOINT_INFO(updateArchiveInfo) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("archive.update.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 �����޸Ľӿڴ���
	ENDPOINT(API_M_PUT, "/update-archive-info", updateArchiveInfo, BODY_DTO(UpdateArchiveInfoDTO::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execUpdateArchiveInfo(dto));
	}

private:
	// 3.3 �޸�����
	Uint64JsonVO::Wrapper execUpdateArchiveInfo(const UpdateArchiveInfoDTO::Wrapper& dto);
};


#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // !_UPDATE_ARCHIVE_INFO_CONTROLLER__