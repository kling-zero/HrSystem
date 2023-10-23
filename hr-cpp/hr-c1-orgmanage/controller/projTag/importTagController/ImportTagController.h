#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: yuanxiang
 @Date: 2023/05/18 11:33:06

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
#ifndef _IMPORTTAGCONTROLLER_H_
#define _IMPORTTAGCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "SimpleDateTimeFormat.h"
#include "ServerInfo.h"
#include "Macros.h"

#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"
#include "domain/dto/projTag/ImportTagDTO.h"
#include "domain/vo/projTag/ImportTagVO.h"
#include "CharsetConvertHepler.h"

using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

#include OATPP_CODEGEN_BEGIN(ApiController)

/**
 * ������Ŀ��ǩController�ӿڣ�
 * fileTypeָ���ļ���׺������test.xlsx����׺��Ϊxlsx����sheetNameΪexcel�����sheet����fileΪ�����ļ�
 * ���ļ���%Y-%m-%d_%H-%M-%S_ProjTag.xlsx��ʽ�ŵ�"public/static/file/"Ŀ¼�£�
 * ���ս��ļ����ݵ��뵽���ݿ⡣
 * ����ֵ����������Ŀ��ǩid�б�
 * �����ˣ�Զ��
 */
class ImportTagController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(ImportTagController);
public: // ����ӿ�
	// �����ļ��ϴ��˵�����
	ENDPOINT_INFO(postFile) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("projTag.import.summary");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(ImportProjTagJsonVO);
		// �����ҳ��������
		info->queryParams.add<String>("fileType").description = ZH_WORDS_GETTER("projTag.import.fileType");
		info->queryParams["fileType"].addExample("default", String("xlsx"));
		info->queryParams["fileType"].required = false;
		info->queryParams.add<String>("sheetName").description = ZH_WORDS_GETTER("projTag.import.sheetName");
		info->queryParams["sheetName"].addExample("default", String("Sheet1"));
		info->queryParams["sheetName"].required = true;
		info->queryParams.add<String>("file").description = ZH_WORDS_GETTER("projTag.import.file");
		info->queryParams["file"].required = true;
	}
	// �����ļ��ϴ��˵㴦��
	ENDPOINT(API_M_POST, PATH_TO_PROJTAG("/import-proj-tag"), postFile, API_HANDLER_AUTH_PARAME, REQUEST(std::shared_ptr<IncomingRequest>, request)) {
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
		filePath->append("ProjTag.xlsx");
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

		auto dto = ImportTagDTO::createShared(String(fileType), String(sheetName), filePath);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execImportTag(dto, authObject->getPayload()));
	}
private: // ����ӿ�ִ�к���
	ImportProjTagJsonVO::Wrapper execImportTag(const ImportTagDTO::Wrapper& dto, const PayloadDTO& payload);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_IMPORTTAGCONTROLLER_H_