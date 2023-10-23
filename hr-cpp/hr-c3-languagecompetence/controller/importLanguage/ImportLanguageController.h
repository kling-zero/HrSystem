#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: jun
 @Date: 2023/05/24 20:04:52

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#ifndef _IMPORTLANGUAGECONTROLLER_H_
#define _IMPORTLANGUAGECONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "SimpleDateTimeFormat.h"
#include "CharsetConvertHepler.h"
#include "domain/dto/importLanguage/ImportLanguageDTO.h"

// �ļ��ϴ�
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"

using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

#include OATPP_CODEGEN_BEGIN(ApiController)
/**
 * �������������� - ��������
 * ����ǰ������������ݱ������ļ���ʽ������ļ������浽����
 * ʹ�ñ���ļ��е�����ִ��������������
 * �����ˣ���
 */
class ImportLanguageController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(ImportLanguageController);
public: // ����ӿ�
	//����һ�����ļ��ϴ��ӿ�����
	ENDPOINT_INFO(importLanguage)
	{
		//����ӿڱ���
		info->summary = ZH_WORDS_GETTER("language.post.file");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		//API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		//API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		// ������������������
		API_DEF_ADD_QUERY_PARAMS(String, "fireType", ZH_WORDS_GETTER("language.post.fileType"), "xlsx", false);
		API_DEF_ADD_QUERY_PARAMS(String, "sheetName", ZH_WORDS_GETTER("language.post.sheetName"), "Sheet1", true);
		API_DEF_ADD_QUERY_PARAMS(String, "file", ZH_WORDS_GETTER("language.post.path"), "", true);
		API_DEF_ADD_QUERY_PARAMS(String, "personID", ZH_WORDS_GETTER("sample.field.id"), "66958E87-91A4-4DA8-8124-060E93B47EBE", false);
	};
	//����һ�����ļ��ϴ��ӿڴ���
	ENDPOINT(API_M_POST, "/c3-language-info/upload-language", importLanguage, /*API_HANDLER_AUTH_PARAME,*/ REQUEST(std::shared_ptr<IncomingRequest>, request)) {
		/* ����multipart���� */
		auto multipartContainer = std::make_shared<multipart::PartList>(request->getHeaders());
		/* ����multipart��ȡ�� */
		multipart::Reader multipartReader(multipartContainer.get());
		/* ���ö�ȡ����ȡ���ֶ� */
		multipartReader.setPartReader("fileType", multipart::createInMemoryPartReader(-1 /* max-data-size */));
		multipartReader.setPartReader("sheetName", multipart::createInMemoryPartReader(-1 /* max-data-size */));
		/* ���ö�ȡ����ȡ�ļ����ļ� */
		String filePath = "public/static/file";
		filePath->append(SimpleDateTimeFormat::format("%Y-%m-%d_%H-%M-%S_"));
		filePath->append("LanguageSet.xlsx");
		multipartReader.setPartReader("file", multipart::createFilePartReader(filePath));
		/* ��ȡ�������е����� */
		request->transferBody(&multipartReader);
		if (multipartContainer->count() != 3)
		{
			/* ��ӡpart���� */
			OATPP_LOGD("Multipart", "parts_count=%d", multipartContainer->count());
			return createResponse(Status::CODE_400, "error in params");
		}

		/* ��ȡ������ */
		auto type = multipartContainer->getNamedPart("fileType");
		auto sheet = multipartContainer->getNamedPart("SheetName");
		/* ���Ա������Ƿ���ȷ */
		OATPP_ASSERT_HTTP(type, Status::CODE_400, "fileType is null");
		OATPP_ASSERT_HTTP(sheet, Status::CODE_400, "sheetName is null");

		string fileType = CharsetConvertHepler::utf8ToAnsi(type->getPayload()->getInMemoryData()->c_str());
		string sheetName = CharsetConvertHepler::utf8ToAnsi(sheet->getPayload()->getInMemoryData()->c_str());
		if (fileType != "csv" && fileType != "xls" && fileType != "xlsx" && sheetName != "")
		{
			return createResponse(Status::CODE_400, "error in params");
		}


		/* ��ȡ�ļ����� */
		auto filePart = multipartContainer->getNamedPart("file");
		/* �����ļ��Ƿ��ȡ�� */
		OATPP_ASSERT_HTTP(filePart, Status::CODE_400, "file upload error");
		/* ��ӡ�ļ����� */
		OATPP_LOGD("Multipart", "file='%s'", filePart->getFilename()->c_str());
		
		auto dto = ImportLanguageDTO::createShared();
		/* ��ӦOK */
		API_HANDLER_RESP_VO(execImportLanguage(dto/*, authObject->getPayload()*/));
	}
private: // ����ӿ�ִ�к���
	//�����޸Ľӿ�ִ�к���
	//Uint64JsonVO::Wrapper execUpdateLanguage(const LanguageDTO::Wrapper& dto, const PayloadDTO& payload);
	StringJsonVO::Wrapper execImportLanguage(const ImportLanguageDTO::Wrapper & dto/*, const PayloadDTO & payload*/);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_IMPORTLANGUAGECONTROLLER_H_