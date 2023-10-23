#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/05/16 18:28:33

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
#ifndef _IMPORTJOBCONTROLLER_H_
#define _IMPORTJOBCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "SimpleDateTimeFormat.h"
#include "ServerInfo.h"
#include "Macros.h"
#include "domain/dto/jobSet/ImportJobDTO.h"
#include "CharsetConvertHepler.h"
#include "domain/vo/jobSet/ImportJobVO.h"
#include "../lib-common/include/CommonMacros.h"
#include <iostream>

// �ļ��ϴ�
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"


using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

#include OATPP_CODEGEN_BEGIN(ApiController)

/**
 * ��λ���� - �����λ
 * ����ǰ������������ݱ������ļ���ʽ������ļ������浽����
 * ʹ�ñ���ļ��е�����ִ����������������������װ������id��List��Ϣ
 * �����ˣ�Andrew
 */
class ImportJobController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(ImportJobController);
public: // ����ӿ�
	ENDPOINT_INFO(importJob) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("jobSet.import.summary");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(ImportJobJsonVO);
		// �����������
		info->queryParams.add<String>("fileType").description = ZH_WORDS_GETTER("jobSet.import.fileType");
		info->queryParams["fileType"].addExample("default", String("xlsx"));
		info->queryParams["fileType"].required = false;
		info->queryParams.add<String>("sheetName").description = ZH_WORDS_GETTER("jobSet.import.sheetName");
		info->queryParams["sheetName"].addExample("default", String("Sheet1"));
		info->queryParams["sheetName"].required = true;
		info->queryParams.add<String>("file").description = ZH_WORDS_GETTER("jobSet.import.file");
		info->queryParams["file"].required = true;
	}

	ENDPOINT(API_M_POST, PATH_TO_JOBSET("/import-job"), importJob, API_HANDLER_AUTH_PARAME, REQUEST(std::shared_ptr<IncomingRequest>, request)) {
		/* ����multipart���� */
		auto multipartContainer = std::make_shared<multipart::PartList>(request->getHeaders());
		/* ����multipart��ȡ�� */
		multipart::Reader multipartReader(multipartContainer.get());
		/* ���ö�ȡ����ȡ���ֶ� */
		multipartReader.setPartReader("fileType", multipart::createInMemoryPartReader(-1 /* max-data-size */));
		multipartReader.setPartReader("sheetName", multipart::createInMemoryPartReader(-1 /* max-data-size */));
		/* ���ö�ȡ����ȡ�ļ����ļ� */
		String filePath = "public/static/file/";
		filePath->append(SimpleDateTimeFormat::format("%Y-%m-%d_%H-%M-%S_"));
		filePath->append("JobSet.xlsx");
		multipartReader.setPartReader("file", multipart::createFilePartReader(filePath));

		//�ж�Ŀ¼�Ƿ���ڣ������ڴ���Ŀ¼
		string fileName = std::string(filePath);
		auto dir = fileName.substr(0, fileName.find_last_of("/") + 1);
		const size_t dirLen = dir.length();
		if (dirLen > MAX_DIR_LEN)
		{
			std::cout << "ExcelComponent 135: excel save fail(file path too long)" << std::endl;
			return createResponse(Status::CODE_401, "");
		}
		char tmpDirPath[MAX_DIR_LEN] = { 0 };
		for (size_t i = 0; i < dirLen; i++)
		{
			tmpDirPath[i] = dir[i];
			if (tmpDirPath[i] == '/')
			{
				if (ACCESS(tmpDirPath, 0) != 0)
				{
					if (MKDIR(tmpDirPath) != 0)
					{
						std::cout << "ExcelComponent 148: excel save fail(create dir " << tmpDirPath << " fail)" << std::endl;
						return createResponse(Status::CODE_401, "");
					}
				}
			}
		}

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
		auto sheet = multipartContainer->getNamedPart("sheetName");
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

		auto dto = ImportJobDTO::createShared(String(fileType), String(sheetName), filePath);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execImportJob(dto, authObject->getPayload()));
	}
private: // ����ӿ�ִ�к���
	ImportJobJsonVO::Wrapper execImportJob(const ImportJobDTO::Wrapper& dto, const PayloadDTO& payload);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_IMPORTJOBCONTROLLER_H_