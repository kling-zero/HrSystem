#pragma once
/*
 (������������-���뷨������)--����
*/
#ifndef _IMPORTLEAGALPERSETTING_CONTROLLER_
#define _IMPORTLEAGALPERSETTING_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"

#include "domain/dto/LegalEntitySet/ImportLeagalPerSettingDTO.h"

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
class ImportLeagalPerSettingController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(ImportLeagalPerSettingController);
	// 3 ����ӿ�
public:
	// 3.1 ���������ӿ�����
	ENDPOINT_INFO(addLeagalPerSetting) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("LegalEntitySet.import.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 ���������ӿڴ���
	ENDPOINT(API_M_POST, "/org-import/legalEntitySet", addLeagalPerSetting, BODY_DTO(ImportLeagalPerSettingDTO::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execAddLeagalPerSetting(dto));
	}
	/*
	// [����] ����һ�����ļ��ϴ��ӿ�
	ENDPOINT(API_M_POST, "/upload", uploadFile, REQUEST(std::shared_ptr<IncomingRequest>, request)) {
		// ����multipart����
		auto multipartContainer = std::make_shared<multipart::PartList>(request->getHeaders());
		// ����multipart��ȡ��
		multipart::Reader multipartReader(multipartContainer.get());
		// ���ö�ȡ����ȡ���ֶ�3
		multipartReader.setPartReader("nickname", multipart::createInMemoryPartReader(-1 ));// max-data-size
		multipartReader.setPartReader("age", multipart::createInMemoryPartReader(-1));// max-data-size
		// ���ö�ȡ����ȡ�ļ����ļ�
		multipartReader.setPartReader("file", multipart::createFilePartReader("public/static/file/test.png"));
		// ��ȡ�������е�����
		request->transferBody(&multipartReader);
		// ��ӡpart����
		OATPP_LOGD("Multipart", "parts_count=%d", multipartContainer->count());
		// ��ȡ������
		auto nickname = multipartContainer->getNamedPart("nickname");
		auto age = multipartContainer->getNamedPart("age");
		// ���Ա������Ƿ���ȷ
		OATPP_ASSERT_HTTP(nickname, Status::CODE_400, "nickname is null");
		OATPP_ASSERT_HTTP(age, Status::CODE_400, "age is null");
		// ��ӡӦ������
		OATPP_LOGD("Multipart", "nickname='%s'", nickname->getPayload()->getInMemoryData()->c_str());
		OATPP_LOGD("Multipart", "age='%s'", age->getPayload()->getInMemoryData()->c_str());
		// ��ȡ�ļ�����
		auto filePart = multipartContainer->getNamedPart("file");
		// �����ļ��Ƿ��ȡ��
		OATPP_ASSERT_HTTP(filePart, Status::CODE_400, "file is null");
		// ��ӡ�ļ�����
		OATPP_LOGD("Multipart", "file='%s'", filePart->getFilename()->c_str());
		// ��ӦOK
		return createResponse(Status::CODE_200, "OK");
	}
	*/
	/*
	// [����] ����һ�����ļ��ϴ��ӿ�
	ENDPOINT(API_M_POST, "/upload-more", uploadFileMore, REQUEST(std::shared_ptr<IncomingRequest>, request)) {
		//����multipart����
		auto multipartContainer = std::make_shared<multipart::PartList>(request->getHeaders());
		// ����multipart��ȡ��
		multipart::Reader multipartReader(multipartContainer.get());
		// ���ö�ȡ����ȡ�ļ����ļ�
		multipartReader.setPartReader("file0", multipart::createFilePartReader("public/static/file/test1.png"));
		multipartReader.setPartReader("file1", multipart::createFilePartReader("public/static/file/test2.png"));
		// ��ȡ�������е�����
		request->transferBody(&multipartReader);
		// ��ȡ�ļ�����
		auto file0 = multipartContainer->getNamedPart("file0");
		auto file1 = multipartContainer->getNamedPart("file1");
		// �����ļ��Ƿ��ȡ��
		OATPP_ASSERT_HTTP(file0, Status::CODE_400, "file0 is null");
		OATPP_ASSERT_HTTP(file1, Status::CODE_400, "file1 is null");
		// ��ӦOK
		return createResponse(Status::CODE_200, "OK");
	*/

private:
	// 3.3 ��ʾ��������
	Uint64JsonVO::Wrapper execAddLeagalPerSetting(const ImportLeagalPerSettingDTO::Wrapper& dto);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _IMPORTLEAGALPERSETTING_CONTROLLER_