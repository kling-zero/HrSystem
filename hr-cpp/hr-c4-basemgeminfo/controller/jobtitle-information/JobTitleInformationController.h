#pragma once
#ifndef _JOBTITLE_INFORMATIONCONTROLLER_H_
#define _JOBTITLE_INFORMATIONCONTROLLER_H_
#include "stdafx.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/query/certificate-information/JobTitleInformationPageQuery.h"
#include "domain/dto/certificate-information/JobTitleInformationDTO.h"
#include "domain/vo/certificate-information/JobTitleInformationVO.h"
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"
#include "ApiHelper.h"
using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

// ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ְ�ƿ������������ӿڵ�ʹ��
 */
class JobTitleInformationController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// ����������������
	API_ACCESS_DECLARE(JobTitleInformationController);
	// ����ӿ�
public:
	//�����ѯ�ӿ�����
	ENDPOINT_INFO(queryJobTitleInformation) {
		// ����ӿڱ���,�õ���Ӣ���ֵ亯�����ù�zh-dict.yamlȷ������
		info->summary = ZH_WORDS_GETTER("jobtitleinformation.get.summary");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(JobTitleInformationPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ������������������
		// ���������ѯ����
		info->queryParams.add<String>("employeeid").description = ZH_WORDS_GETTER("jobtitleinformation.field.employeeid");
		info->queryParams["employeeid"].addExample("default", String("30601C0002"));
		info->queryParams["employeeid"].required = false;
		
	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/jobtitle-information/select", queryJobTitleInformation, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// ������ѯ����
		API_HANDLER_QUERY_PARAM(userQuery, JobTitleInformationPageQuery, queryParams);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execQueryJobTitleInformation(userQuery, authObject->getPayload()));
	}
private:
	// 3.3 ��ʾ��ҳ��ѯ����
	JobTitleInformationPageJsonVO::Wrapper execQueryJobTitleInformation(const JobTitleInformationPageQuery::Wrapper& query, const PayloadDTO& payload);
};
// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _DEBUG





