#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: guyier
 @Date: 2023/05/19 14:44:00

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
#ifndef _EMPLOYEE_INFOMATION_CONTROLLER
#define _EMPLOYEE_INFOMATION_CONTROLLER

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/query/EmployeeInformationPageQuery/EmployeeInformationPageQuery.h"
#include "domain/vo/EmployeeInformation/EmployeeInformationVO.h"
//#include "domain/dto/AddEmployeeAssignInfo/AddEmployeeAssignInfo.h"
#include "domain/dto/EmployeeInformationPageQuery/EmployeeInformationPageQueryDTO.h"
#include "CustomerAuthorizeHandler.h"
#include "../../../lib-oatpp/include/domain/dto/PayloadDTO.h"
#include "domain/dto/importInfo/ImportInfoDTO.h"
#include "domain/vo/importInfo/importInfoVO.h"
#include "iostream"

#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"
#include "SimpleDateTimeFormat.h"
#include "CommonMacros.h"
#include "CharsetConvertHepler.h"
#include "domain/query/postSet/PostDetailQuery.h"

using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

//����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController)
/*
Ա����Ϣ������
*/
class EmployeeInformationController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(EmployeeInformationController);
public: // ����ӿ�

	//�����ҳ��ѯԱ���б�ӿڶ˵�����
	ENDPOINT_INFO(PageQueryInfo) {
		//����ӿڱ���
		info->summary = ZH_WORDS_GETTER("member.field.summarypage");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		//������Ӧ��������
		API_DEF_ADD_RSP_JSON_WRAPPER(EmployeeInformationPageJsonVO);
		//�����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ������������������
		//���
		info->queryParams.add<String>("id").description = ZH_WORDS_GETTER("employee.field.id");
		info->queryParams["id"].addExample("default", String("1921****"));
		info->queryParams["id"].required = false;
		//����
		info->queryParams.add<String>("name").description = ZH_WORDS_GETTER("employee.field.name");
		info->queryParams["name"].addExample("default", String("��**"));
		info->queryParams["name"].required = false;
		//��֯
		info->queryParams.add<String>("organize").description = ZH_WORDS_GETTER("employee.field.organize");
		info->queryParams["organize"].addExample("default", String("N"));
		info->queryParams["organize"].required = false;
		//����
		info->queryParams.add<String>("depart").description = ZH_WORDS_GETTER("employee.field.depart");
		info->queryParams["depart"].addExample("default", String("N"));
		info->queryParams["depart"].required = false;
		//ְ��
		info->queryParams.add<String>("job").description = ZH_WORDS_GETTER("employee.field.job");
		info->queryParams["job"].addExample("default", String("N"));
		info->queryParams["job"].required = false;
		//��λ
		info->queryParams.add<String>("post").description = ZH_WORDS_GETTER("employee.field.post");
		info->queryParams["post"].addExample("default", String("N"));
		info->queryParams["post"].required = false;
		//֤����
		info->queryParams.add<String>("idMum").description = ZH_WORDS_GETTER("employee.field.idMum");
		info->queryParams["idMum"].addExample("default", String("2665643635********"));
		info->queryParams["idMum"].required = false;
		//��������
		info->queryParams.add<String>("birthday").description = ZH_WORDS_GETTER("employee.field.birthday");
		info->queryParams["birthday"].addExample("default", String("1992-10-18 00:00:00"));
		info->queryParams["birthday"].required = false;
		// ����
		info->queryParams.add<UInt32>("age").description = ZH_WORDS_GETTER("employee.field.age");
		info->queryParams["age"].addExample("default", UInt32(20));
		info->queryParams["age"].required = false;
		//�ֻ�����
		info->queryParams.add<String>("phone").description = ZH_WORDS_GETTER("employee.field.phone");
		info->queryParams["phone"].addExample("default", String("159182*****"));
		info->queryParams["phone"].required = false;
		//Ա��״̬
		info->queryParams.add<String>("state").description = ZH_WORDS_GETTER("employee.field.state");
		info->queryParams["state"].addExample("default", String("50"));
		info->queryParams["state"].required = false;

	}
	//�����ҳ��ѯԱ���б�ӿڶ˵㴦��
	ENDPOINT(API_M_GET, "/c3-employee-info/page-query", PageQueryInfo, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		//������ѯ����������������ģ�Ͷ���
		API_HANDLER_QUERY_PARAM(query, EmployeeInformationPageQuery, queryParams);
		//��Ӧ���
		API_HANDLER_RESP_VO(execEmployeeInformation(query, authObject->getPayload()));
	}

	//���嵼��Ա����Ϣ�ӿڶ˵�����	
	ENDPOINT_INFO(importEmployeeInfo) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("importInfo.import.summary");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(ImportJobJsonVO);
		// �����������
		info->queryParams.add<String>("fileType").description = ZH_WORDS_GETTER("importInfo.import.fileType");
		info->queryParams["fileType"].addExample("default", String("xlsx"));
		info->queryParams["fileType"].required = false;
		info->queryParams.add<String>("sheetName").description = ZH_WORDS_GETTER("importInfo.import.sheetName");
		info->queryParams["sheetName"].addExample("default", String("Sheet1"));
		info->queryParams["sheetName"].required = true;
		info->queryParams.add<String>("file").description = ZH_WORDS_GETTER("importInfo.import.file");
		info->queryParams["file"].required = true;
	}
	//���嵼��Ա����Ϣ�ӿڶ˵㴦��
	ENDPOINT(API_M_POST, "/c3-employee-info/import-info", importEmployeeInfo, API_HANDLER_AUTH_PARAME, REQUEST(std::shared_ptr<IncomingRequest>, request)) {
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

		auto dto = ImportInfoDTO::createShared(String(fileType), String(sheetName), filePath);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execImportEmployeeInfo(dto, authObject->getPayload()));
	}

	//���嵼��Ա����Ϣ(������ҳ��ǰ�����)�ӿڶ˵�����	
	ENDPOINT_INFO(exportEmployeeInfo) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("importInfo.export.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		// ���Ĭ����Ȩ����
		API_DEF_ADD_AUTH();
	}
	//���嵼��Ա����Ϣ(������ҳ��ǰ�����)�ӿڶ˵㴦��
	ENDPOINT(API_M_GET, PATH_TO_STAFFING("/c3-employee-info/export-info"), exportEmployeeInfo, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// ������ѯ����
		API_HANDLER_QUERY_PARAM(query, PostDetailQuery, queryParams);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execExportEmployeeInfo(query));
	}

	//��������Ա����Ϣ�ӿڶ˵�����
	ENDPOINT_INFO(addEmployee) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("orgsector.field.summary");
		// ���Ĭ����Ȩ����
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	//��������Ա����Ϣ�ӿڶ˵㴦��
	ENDPOINT(API_M_POST, "/c3-employee-info/add-new-info", addEmployee, API_HANDLER_AUTH_PARAME, BODY_DTO(EmployeeInformationDTO::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execAddEmployee(dto, authObject->getPayload()));
	}
private:// ����ӿ�ִ�к���

	//��ҳ��ѯԱ���б�
	EmployeeInformationPageJsonVO::Wrapper execEmployeeInformation(const EmployeeInformationPageQuery::Wrapper& query, const PayloadDTO& payload);
	//����Ա����Ϣ
	ImportJobJsonVO::Wrapper execImportEmployeeInfo(const ImportInfoDTO::Wrapper& dto, const PayloadDTO& payload);
	//����Ա����Ϣ(������ҳ��ǰ�����)
	StringJsonVO::Wrapper execExportEmployeeInfo(const PostDetailQuery::Wrapper& query);
	//����Ա����Ϣ
	Uint64JsonVO::Wrapper execAddEmployee(const EmployeeInformationDTO::Wrapper& dto, const PayloadDTO& payload);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_EMPLOYEE_INFOMATION_CONTROLLER
