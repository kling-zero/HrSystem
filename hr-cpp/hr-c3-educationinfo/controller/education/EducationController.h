/*
 Copyright Zero One Star. All rights reserved.

 @Author: Chen J
 @Date: 2023/05/18 9:45:52
*/
#ifndef _EDUCATIOCONTROLLER_H_
#define _EDUCATIONCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "SimpleDateTimeFormat.h"
#include "domain/query/educationPage/EducationPageQuery.h"
#include "domain/query/educationSingle/EducationSingleQuery.h"
#include "domain/query/educationExport/EducationExportQuery.h"
#include "domain/dto/education/EducationDTO.h"
#include "domain/dto/educationDelete/EducationDeleteDTO.h"
#include "domain/dto/educationImport/EducationImportDTO.h"
#include "domain/vo/education/EducationJsonVO.h"
#include "domain/vo/educationImport/EducationImportVO.h"
#include "CharsetConvertHepler.h"
#include "domain/dto/educationAdd/EducationAddDTO.h"


//�ļ��ϴ�
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"




using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;
#include OATPP_CODEGEN_BEGIN(ApiController)

class EducationController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(EducationController);
public: // �ӿ�
	// ����1 ��ҳ��ѯָ��Ա���Ľ�����Ϣ���ӿ�����
	ENDPOINT_INFO(gueryEducationPage) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("gueryEducationPage");//�����ֵ�zh-dict.yaml
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(EducationPageJsonVO);
		//API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		// �����ҳ��������//��ҳ�б�+��ҳ��� + Ա����� pimpersonid
		API_DEF_ADD_PAGE_PARAMS();
		// ������������������������Ա��id��ѯ
		info->queryParams.add<String>("PIMPERSONID").description = ZH_WORDS_GETTER("education.PIMPERSONID");
		info->queryParams["PIMPERSONID"].addExample("default", String("5F8310F7-6E69-4D28-901F-97FFAB32E721"));
		info->queryParams["PIMPERSONID"].required = false;
		/*info->queryParams.add<String>("pimpersonid").description = ZH_WORDS_GETTER("education.id");
		info->queryParams["pimpersonid"].addExample("default", String("02A0F00B-506C-4F02-B4A1-9524F4043CF9"));
		info->queryParams["pimpersonid"].required = false;
		info->queryParams.add<String>("pimpersonname").description = ZH_WORDS_GETTER("gueryEducationPage");
		info->queryParams["pimpersonname"].addExample("default", String(""));
		info->queryParams["pimpersonname"].required = false;
		info->queryParams.add<String>("sort").description = ZH_WORDS_GETTER("t_pimperson.sort");
		info->queryParams["sort"].addExample("default", String("asc"));
		info->queryParams["sort"].required = false;*/
	}
	// ����1 ��ҳ��ѯָ��Ա���Ľ�����Ϣ���ӿڴ���
	ENDPOINT(API_M_GET, "/c3-education-info/guery-education-page", gueryEducationPage, API_HANDLER_AUTH_PARAME,  QUERIES(QueryParams, queryParams)) {
		// ������ѯ����
		API_HANDLER_QUERY_PARAM(educationQuery, EducationPageQuery, queryParams);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execQueryEducationPage(educationQuery, authObject->getPayload()));
	}
	
	// ����2 ������ѯָ��Ա���Ľ�����Ϣ���ӿ�����
	ENDPOINT_INFO(queryEducationSingle) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("queryEducationSingle");//�����ֵ�zh-dict.yaml
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(EducationSingleJsonVO);
		//API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		// �����������������������ݽ�����ʶ��ѯ
		info->queryParams.add<String>("PIMPERSONID").description = ZH_WORDS_GETTER("education.PIMPERSONID");
		info->queryParams["PIMPERSONID"].addExample("default", String("5F8310F7-6E69-4D28-901F-97FFAB32E721"));
		info->queryParams["PIMPERSONID"].required = false;
		//info->queryParams.add<String>("pimpersonname").description = ZH_WORDS_GETTER("getEducationPageQuery");
		//info->queryParams["pimpersonname"].addExample("default", String("ChenJun"));
	}
	// ����2 ������ѯָ��Ա���Ľ�����Ϣ���ӿڴ���
	ENDPOINT(API_M_GET, "/c3-education-info/query-education-single", queryEducationSingle, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// ������ѯ����
		API_HANDLER_QUERY_PARAM(educationSingle, EducationSingleQuery, queryParams);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execQueryEducationSingle(educationSingle, authObject->getPayload()));
	}
	
	// ����3 ��������ָ��Ա���Ľ�����Ϣ���ӿ�����
	ENDPOINT_INFO(addEducationSingle) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("addEducationSingle");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
		//API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		//// ������Ϣ��ʶ �����
		//info->queryParams.add<String>("PIMEDUCATIONID").description = ZH_WORDS_GETTER("education.PIMEDUCATIONID");
		//info->queryParams["PIMEDUCATIONID"].addExample("default", String("114514114514"));
		//info->queryParams["PIMEDUCATIONID"].required = false;
		//// ѧ��
		//info->queryParams.add<String>("XL").description = ZH_WORDS_GETTER("education.XL");
		//info->queryParams["XL"].addExample("default", String(u8"��ר"));
		//info->queryParams["XL"].required = false;
		//// ��ѧʱ��
		//info->queryParams.add<UInt64>("QSSJ").description = ZH_WORDS_GETTER("education.QSSJ");
		//info->queryParams["QSSJ"].addExample("default", UInt64(19210606));
		//info->queryParams["QSSJ"].required = false;
		//// ��ҵʱ��
		//info->queryParams.add<UInt64>("JSSJ").description = ZH_WORDS_GETTER("education.JSSJ");
		//info->queryParams["JSSJ"].addExample("default", UInt64(19780606));
		//info->queryParams["JSSJ"].required = false;
		//// ��ҵԺУ
		//info->queryParams.add<String>("BYYX").description = ZH_WORDS_GETTER("education.BYYX");
		//info->queryParams["BYYX"].addExample("default", String(u8"�������Ƽ���ѧ"));
		//info->queryParams["BYYX"].required = false;
		//// һ��ѧ��
		//info->queryParams.add<String>("XKML").description = ZH_WORDS_GETTER("education.XKML");
		//info->queryParams["XKML"].addExample("default", String(u8"����ѧ"));
		//info->queryParams["XKML"].required = false;
		//// ��ѧרҵ
		//info->queryParams.add<String>("SXZY").description = ZH_WORDS_GETTER("education.SXZY");
		//info->queryParams["SXZY"].addExample("default", String(u8"ĸ��Ĳ�����"));
		//info->queryParams["SXZY"].required = false;
		//// ѧϰ��ʽ
		//info->queryParams.add<String>("XLLX").description = ZH_WORDS_GETTER("education.XLLX");
		//info->queryParams["XLLX"].addExample("default", String(u8"ȫ����"));
		//info->queryParams["XLLX"].required = false;
		//// ѧУ����
		//info->queryParams.add<String>("XXXZ").description = ZH_WORDS_GETTER("education.XXXZ");
		//info->queryParams["XXXZ"].addExample("default", String(u8"˫��"));
		//info->queryParams["XXXZ"].required = false;
		//// �Ƿ��һѧ��
		//info->queryParams.add<Int16>("SFDYXL").description = ZH_WORDS_GETTER("education.SFDYXL");
		//info->queryParams["SFDYXL"].addExample("default", Int16(1));
		//info->queryParams["SFDYXL"].required = false;
		////�Ƿ����ѧ��
		//info->queryParams.add<Int16>("SFZGXL").description = ZH_WORDS_GETTER("education.SFZGXL");
		//info->queryParams["SFZGXL"].addExample("default", Int16(1));
		//info->queryParams["SFZGXL"].required = false;
		//// ��ҵ֤
		//info->queryParams.add<String>("BTZ").description = ZH_WORDS_GETTER("education.BTZ");
		//info->queryParams["BTZ"].addExample("default", String(u8"�ļ�"));
		//info->queryParams["BTZ"].required = false;
		//// ѧλ֤
		//info->queryParams.add<String>("XWZ").description = ZH_WORDS_GETTER("education.XWZ");
		//info->queryParams["XWZ"].addExample("default", String(u8"�ļ�"));
		//info->queryParams["XWZ"].required = false;
		//// ѧ����֤
		//info->queryParams.add<String>("XLCX").description = ZH_WORDS_GETTER("education.XLCX");
		//info->queryParams["XLCX"].addExample("default", String(u8"�ļ�"));
		//info->queryParams["XLCX"].required = false;
		//// ��������
		//info->queryParams.add<String>("FJ").description = ZH_WORDS_GETTER("education.FJ");
		//info->queryParams["FJ"].addExample("default", String(u8"�ļ�"));
		//info->queryParams["FJ"].required = false;
	}
	// ����3 ��������ָ��Ա���Ľ�����Ϣ���ӿڴ���
	ENDPOINT(API_M_POST, "/c3-education-info/add-education-single", addEducationSingle, API_HANDLER_AUTH_PARAME, BODY_DTO(EducationAddDTO::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execAddEducationSingle(dto, authObject->getPayload()));
	}

	// ����4 �����޸�ָ��Ա���Ľ�����Ϣ���ӿ�����
	ENDPOINT_INFO(modifyEducationSingle) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("modifyEducationSingle");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
		//API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		//		// ������Ϣ��ʶ �����
		//info->queryParams.add<String>("PIMEDUCATIONID").description = ZH_WORDS_GETTER("education.PIMEDUCATIONID");
		//info->queryParams["PIMEDUCATIONID"].addExample("default", String("114514114514"));
		//info->queryParams["PIMEDUCATIONID"].required = false;
		//// ѧ��
		//info->queryParams.add<String>("XL").description = ZH_WORDS_GETTER("education.XL");
		//info->queryParams["XL"].addExample("default", String(u8"��ר"));
		//info->queryParams["XL"].required = false;
		//// ��ѧʱ��
		//info->queryParams.add<UInt64>("QSSJ").description = ZH_WORDS_GETTER("education.QSSJ");
		//info->queryParams["QSSJ"].addExample("default", UInt64(19210606));
		//info->queryParams["QSSJ"].required = false;
		//// ��ҵʱ��
		//info->queryParams.add<UInt64>("JSSJ").description = ZH_WORDS_GETTER("education.JSSJ");
		//info->queryParams["JSSJ"].addExample("default", UInt64(19780606));
		//info->queryParams["JSSJ"].required = false;
		//// ��ҵԺУ
		//info->queryParams.add<String>("BYYX").description = ZH_WORDS_GETTER("education.BYYX");
		//info->queryParams["BYYX"].addExample("default", String(u8"�������Ƽ���ѧ"));
		//info->queryParams["BYYX"].required = false;
		//// һ��ѧ��
		//info->queryParams.add<String>("XKML").description = ZH_WORDS_GETTER("education.XKML");
		//info->queryParams["XKML"].addExample("default", String(u8"����ѧ"));
		//info->queryParams["XKML"].required = false;
		//// ��ѧרҵ
		//info->queryParams.add<String>("SXZY").description = ZH_WORDS_GETTER("education.SXZY");
		//info->queryParams["SXZY"].addExample("default", String(u8"ĸ��Ĳ�����"));
		//info->queryParams["SXZY"].required = false;
		//// ѧϰ��ʽ
		//info->queryParams.add<String>("XLLX").description = ZH_WORDS_GETTER("education.XLLX");
		//info->queryParams["XLLX"].addExample("default", String(u8"ȫ����"));
		//info->queryParams["XLLX"].required = false;
		//// ѧУ����
		//info->queryParams.add<String>("XXXZ").description = ZH_WORDS_GETTER("education.XXXZ");
		//info->queryParams["XXXZ"].addExample("default", String(u8"˫��"));
		//info->queryParams["XXXZ"].required = false;
		//// �Ƿ��һѧ��
		//info->queryParams.add<Int16>("SFDYXL").description = ZH_WORDS_GETTER("education.SFDYXL");
		//info->queryParams["SFDYXL"].addExample("default", Int16(1));
		//info->queryParams["SFDYXL"].required = false;
		////�Ƿ����ѧ��
		//info->queryParams.add<Int16>("SFZGXL").description = ZH_WORDS_GETTER("education.SFZGXL");
		//info->queryParams["SFZGXL"].addExample("default", Int16(1));
		//info->queryParams["SFZGXL"].required = false;
		//// ��ҵ֤
		//info->queryParams.add<String>("BTZ").description = ZH_WORDS_GETTER("education.BTZ");
		//info->queryParams["BTZ"].addExample("default", String(u8"�ļ�"));
		//info->queryParams["BTZ"].required = false;
		//// ѧλ֤
		//info->queryParams.add<String>("XWZ").description = ZH_WORDS_GETTER("education.XWZ");
		//info->queryParams["XWZ"].addExample("default", String(u8"�ļ�"));
		//info->queryParams["XWZ"].required = false;
		//// ѧ����֤
		//info->queryParams.add<String>("XLCX").description = ZH_WORDS_GETTER("education.XLCX");
		//info->queryParams["XLCX"].addExample("default", String(u8"�ļ�"));
		//info->queryParams["XLCX"].required = false;
		//// ��������
		//info->queryParams.add<String>("FJ").description = ZH_WORDS_GETTER("education.FJ");
		//info->queryParams["FJ"].addExample("default", String(u8"�ļ�"));
		//info->queryParams["FJ"].required = false;
	}
	// ����4 �����޸�ָ��Ա���Ľ�����Ϣ���ӿڴ���
	ENDPOINT(API_M_PUT, "/c3-education-info/modify-education-single", modifyEducationSingle, API_HANDLER_AUTH_PARAME, BODY_DTO(EducationAddDTO::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execModifyEducationSingle(dto, authObject->getPayload()));
	}
	

	
	// ����5 ɾ��ָ��Ա���Ľ�����Ϣ���ӿ�����
	ENDPOINT_INFO(removeEducation) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("removeEducation");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
		//API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		

	}
	// ����5 ɾ��ָ��Ա���Ľ�����Ϣ���ӿڴ���
	//ENDPOINT(API_M_DEL, "/education/remove-Education-Single", removeEducation, API_HANDLER_AUTH_PARAME,PATH(String, deleteId)) {
	ENDPOINT(API_M_DEL, "/c3-education-info/remove-education-single", removeEducation, API_HANDLER_AUTH_PARAME,BODY_DTO(EducationDeleteSingleDTO::Wrapper, dto)) {
		//auto dto = EducationDeleteSingleDTO::createShared();
		//dto->deleteId = deleteId;
		//// ��Ӧ���
		//API_HANDLER_RESP_VO(execRemoveEducation(dto, authObject->getPayload()));
		API_HANDLER_RESP_VO(execRemoveEducation(dto, authObject->getPayload()));
	}


	//// ����6 ����ɾ������Ա���Ľ�����Ϣ���ӿ�����
	//ENDPOINT_INFO(removeEducationNotSingle) {
	//	// ����ӿڱ���
	//	info->summary = ZH_WORDS_GETTER("removeEducationNotSingle");
	//	// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
	//	API_DEF_ADD_AUTH();
	//	// ������Ӧ������ʽ
	//	API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	//	//API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	//}
	//// ����6 ����ɾ������Ա���Ľ�����Ϣ���ӿڴ���
	////ENDPOINT(API_M_DEL, "/education/remove-Education-Not-Single", removeEducationNotSingle, API_HANDLER_AUTH_PARAME, BODY_STRING(String, jsonPayload)) {
	//ENDPOINT(API_M_DEL, "/employee-info/remove-education-not-single", removeEducationNotSingle, API_HANDLER_AUTH_PARAME, BODY_DTO(EducationDeleteNotSingleDTO::Wrapper, dto)) {
	//	//const std::shared_ptr<ObjectMapper>& objectMapper = oatpp::parser::json::mapping::ObjectMapper::createShared();
	//	// ������ѯ����
	//	//auto dto = EducationDeleteNotSingleDTO::createShared();
	//	//dto->deleteIds = objectMapper->readFromString<oatpp::List<String>>(jsonPayload);
	//	////����
	//	//for (const auto& item : *dto->deleteIds) {
	//	//	/*OATPP_LOGD("testEndpoint", "Item: %s", item->c_str());*/
	//	//	cout << item->c_str() << endl;
	//	//}
	//	// ��Ӧ���
	//	API_HANDLER_RESP_VO(execRemoveEducationNotSingle(dto, authObject->getPayload()));
	//}

	// ����7 �����ļ��ϴ�������Ϣ���ӿ�����
		//* ����ǰ������������ݱ������ļ���ʽ������ļ������浽����
		//* ʹ�ñ���ļ��е�����ִ����������������������װ������id��List��Ϣ
	ENDPOINT_INFO(importEducation) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("importEducation.summary");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(EudacationImportJsonVO);
		//API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		// �����ҳ��������
		info->queryParams.add<String>("/Education/file-type").description = ZH_WORDS_GETTER("importEducation.fileType");
		info->queryParams["fileType"].addExample("default", String("xlsx"));
		info->queryParams["fileType"].required = false;
		info->queryParams.add<String>("/Education/sheet-name").description = ZH_WORDS_GETTER("importEducation.sheetName");
		info->queryParams["sheetName"].addExample("default", String("Sheet1"));
		info->queryParams["sheetName"].required = false;
		info->queryParams.add<String>("/Education/file").description = ZH_WORDS_GETTER("importEducation.file");
		info->queryParams["file"].required = true;
	}
	// ����7 �����ļ��ϴ�������Ϣ���ӿڴ���
	ENDPOINT(API_M_POST, "/c3-education-info/upload-education", importEducation, API_HANDLER_AUTH_PARAME,REQUEST(std::shared_ptr<IncomingRequest>, request)) {
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
		filePath->append("EducationSet.xlsx");
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
		if (fileType != "csv" && fileType != "xls" && fileType != "xlsx")
		{
			return createResponse(Status::CODE_400, "error in params");
		}

		/* ��ȡ�ļ����� */
		auto filePart = multipartContainer->getNamedPart("file");
		/* �����ļ��Ƿ��ȡ�� */
		OATPP_ASSERT_HTTP(filePart, Status::CODE_400, "file upload error");
		/* ��ӡ�ļ����� */
		OATPP_LOGD("Multipart", "file='%s'", filePart->getFilename()->c_str());

		auto dto = EducationImportDTO::createShared(String(fileType), String(sheetName), filePath);
		//atuo dto = EducationImportDTO::createShared();
		//
		//// ��Ӧ���
		API_HANDLER_RESP_VO(execImportEducation(dto, authObject->getPayload()));

	}


	//����8 ����������Ϣ�ļ�
		/* ����ǰ�����󲢽��������ֶΣ��������ݲ�ѯ�����5000����
		* �Բ�ѯ�������ݷ�װ�ɱ���ļ����ϴ�fastdfs�ļ�������
		* ����ֵ��StringJsonVO - ����һ������url�ַ���
		* �����ˣ�Andrew
		*/
	//����8 ����������Ϣ�ļ� �ӿ�����
	ENDPOINT_INFO(exportEducation) {
		info->summary = ZH_WORDS_GETTER("sample.field.id");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		info->queryParams.add<String>("id").description = ZH_WORDS_GETTER("employee.field.id");
		info->queryParams["id"].addExample("default", String("0000001"));
		info->queryParams["id"].required = true;
	}
	//����8 ����������Ϣ�ļ� �ӿڴ���
	ENDPOINT(API_M_GET, "/c3-education-info/export-eudaction", exportEducation, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, qps)) {
		API_HANDLER_QUERY_PARAM(query, EducationExportQuery, qps);
		API_HANDLER_RESP_VO(execExportEducation(query));
	}


private: // �ӿ�ִ�к���
// ����1 ��ҳ��ѯָ��Ա���Ľ�����Ϣ���ӿ�ִ�к���
	EducationPageJsonVO::Wrapper execQueryEducationPage(const EducationPageQuery::Wrapper& query, const PayloadDTO& payload);
	//StringJsonVO::Wrapper execQueryEducationPage(const EducationPageQuery::Wrapper& query, const PayloadDTO& payload);
// ����2 ������ѯָ��Ա���Ľ�����Ϣ���ӿ�ִ�к���
	EducationSingleJsonVO::Wrapper execQueryEducationSingle(const EducationSingleQuery::Wrapper& query, const PayloadDTO& payload);
	//StringJsonVO::Wrapper execQueryEducationSingle(const EducationSingleQuery::Wrapper& query, const PayloadDTO& payload);
// ����3 ��������ָ��Ա���Ľ�����Ϣ���ӿ�ִ�к���
	//StringJsonVO::Wrapper execAddEducationSingle(const EducationSingleDTO::Wrapper& dto, const PayloadDTO& payload);
	Uint64JsonVO::Wrapper execAddEducationSingle(const EducationAddDTO::Wrapper& dto, const PayloadDTO& payload);
// ����4 �޸�ָ��Ա���Ľ�����Ϣ���ӿ�ִ�к���
	//StringJsonVO::Wrapper execModifyEducationSingle(const EducationSingleDTO::Wrapper& dto, const PayloadDTO& payload);
	Uint64JsonVO::Wrapper execModifyEducationSingle(const EducationAddDTO::Wrapper& dto, const PayloadDTO& payload);
// ����5 ɾ��ָ��Ա���Ľ�����Ϣ���ӿ�ִ�к���
	//Uint64JsonVO::Wrapper execRemoveEducation(const EducationDeleteSingleDTO::Wrapper& dto, const PayloadDTO& payload);
	Uint64JsonVO::Wrapper execRemoveEducation(const EducationDeleteSingleDTO::Wrapper& dto, const PayloadDTO& payload);
// ����6 ����ɾ��ָ��Ա���Ľ�����Ϣ���ӿ�ִ�к���
	//EducationDeleteNotSingleJsonVO::Wrapper execRemoveEducationNotSingle(const EducationDeleteNotSingleDTO::Wrapper& dto, const PayloadDTO& payload);
	//Uint64JsonVO::Wrapper execRemoveEducationNotSingle(const EducationDeleteNotSingleDTO::Wrapper& dto, const PayloadDTO& payload);
	//StringJsonVO::Wrapper execRemoveEducationNotSingle(const EducationDeleteNotSingleDTO::Wrapper& dto, const PayloadDTO& payload);
// ����7 �����ļ��ϴ�������Ϣ���ӿ�ִ�к���
	EudacationImportJsonVO::Wrapper execImportEducation(const EducationImportDTO::Wrapper& dto, const PayloadDTO& payload);
	//StringJsonVO::Wrapper execImportEducation(const EducationImportDTO::Wrapper& dto, const PayloadDTO& payload);
//����8 ����������Ϣ�ļ�:  �ӿ�ִ�к���
	StringJsonVO::Wrapper execExportEducation(const EducationExportQuery::Wrapper& query);

};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_GETEDUCATIONPAGECONTROLLER_H_


