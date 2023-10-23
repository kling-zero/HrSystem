#pragma once

#ifndef JOBTITLEYCONTROLLER_H
#define JOBTITLEYCONTROLLER_H

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/JobTitle/JobTitleDTO.h"
#include "domain/vo/JobTitle/JobTitleJsonVO.h"
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"

using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * JobTitleInfo����������������
 */
class JobTitleInfoController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(JobTitleInfoController);
	// 3 ����ӿ�
public:
	// ��ѯְ��
	ENDPOINT_INFO(queryJobTitle) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("jobtitle.get.summary");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(JTQueryJsonVO);
		// ������������������
		info->queryParams.add<String>("id").description = ZH_WORDS_GETTER("title.field.id");
		info->queryParams["id"].addExample("default", String("04CE5FCB-0581-4EA9-9A01-7B88A01A0027"));
		info->queryParams["id"].required = true;
		info->queryParams.add<String>("employee_id").description = ZH_WORDS_GETTER("jobtitle.field.employee_id");
		info->queryParams["employee_id"].addExample("default", String("123321"));
		info->queryParams["employee_id"].required = true;
	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/job-title-management/query-job-title", queryJobTitle, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// ������ѯ����
		API_HANDLER_QUERY_PARAM(userQuery, JobTitleDTO, queryParams);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execQueryJobTitle(userQuery, authObject->getPayload()));
	}

	// ����ְ��
	ENDPOINT_INFO(getJobTitle) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("jobtitle.export.summary");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		// ������������������
		info->queryParams.add<String>("employee_id").description = ZH_WORDS_GETTER("jobtitle.field.employee_id");
		info->queryParams["employee_id"].addExample("default", String("123321"));
		info->queryParams["employee_id"].required = false;
		info->queryParams.add<String>("employee_name").description = ZH_WORDS_GETTER("jobtitle.field.employee_name");
		info->queryParams["employee_name"].addExample("default", String(u8"������"));
		info->queryParams["employee_name"].required = false;
		info->queryParams.add<String>("org_name").description = ZH_WORDS_GETTER("jobtitle.field.org_name");
		info->queryParams["org_name"].addExample("default", String(""));
		info->queryParams["org_name"].required = false;
		info->queryParams.add<String>("jobtitle_name").description = ZH_WORDS_GETTER("jobtitle.field.jobtitle_name");
		info->queryParams["jobtitle_name"].addExample("default", String(""));
		info->queryParams["jobtitle_name"].required = false;
		info->queryParams.add<String>("jobtitle_grades").description = ZH_WORDS_GETTER("jobtitle.field.professor_grades");
		info->queryParams["jobtitle_grades"].addExample("default", String(""));
		info->queryParams["jobtitle_grades"].required = false;
		info->queryParams.add<String>("b_highest_professional_title").description = ZH_WORDS_GETTER("jobtitle.field.b_highest_professional_title");
		info->queryParams["b_highest_professional_title"].addExample("default", String(""));
		info->queryParams["b_highest_professional_title"].required = false;
		
	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/job-title-management/export-job-title", getJobTitle, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// ������ѯ����
		API_HANDLER_QUERY_PARAM(userQuery, JobTitleDTO, queryParams);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execGetJobTitle(userQuery, authObject->getPayload()));
	}
	
	// 3.1 �����޸Ľӿ�����
	ENDPOINT_INFO(modifyJobTitle) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("jobtitle.update.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 �����޸Ľӿڴ���
	ENDPOINT(API_M_PUT, "/job-title-management/modify-job-title", modifyJobTitle, BODY_DTO(JobTitleDTO::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execModifyJobTitle(dto));
	}
private:
	// 3.3 ��ʾ��ѯ����
	JTQueryJsonVO::Wrapper execQueryJobTitle(const JobTitleDTO::Wrapper& query, const PayloadDTO& payload);
	StringJsonVO::Wrapper execGetJobTitle(const JobTitleDTO::Wrapper& query, const PayloadDTO& payload);
	Uint64JsonVO::Wrapper execModifyJobTitle(const JobTitleDTO::Wrapper& dto);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_