#pragma once
#ifndef _EXPORT_RETIREES_CONTROLLER_
#define _EXPORT_RETIREES_CONTROLLER_

#include "ApiHelper.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/query/RosterOfPer/ExportRetireesQuery.h"
#include "domain/dto/RosterOfPer/ExportRetireesDTO.h"
#include "domain/vo/RosterOfPer/ExportRetireesVO.h"
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
 * ��Ա������-��������Ա��-����Ա����--pine
 */
class ExportRetireesController : public oatpp::web::server::api::ApiController // �̳п�����
{
	// ����������������
	API_ACCESS_DECLARE(ExportRetireesController);

public://  ����ӿڣ�����ӿ�������ӿڶ˵㣩
	// ���������ӿ�����
	ENDPOINT_INFO(queryExportRetirees) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("rosterofper.get.outinfo");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ��������
		API_DEF_ADD_RSP_JSON_WRAPPER(ExportRetireesPageJsonVO);
		//�����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		//���������ѯ������required��ʾ�Ƿ����
		info->queryParams.add<String>("name").description = ZH_WORDS_GETTER("rosterofper.field.name");
		info->queryParams["name"].addExample("default", String("li ming"));
		info->queryParams["name"].required = false;
		info->queryParams.add<String>("sex").description = ZH_WORDS_GETTER("rosterofper.field.sex");
		info->queryParams["sex"].addExample("default", String("N"));
		info->queryParams["sex"].required = false;
	}
	// ���������ӿڴ���
	ENDPOINT(API_M_GET, "/bas/query-ExportRetirees", queryExportRetirees, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		API_HANDLER_QUERY_PARAM(query, ExportRetireesQuery, queryParams);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execQueryExportRetirees(query));
	}

private://����ִ�к���
	// ��ҳ��ѯ����
	ExportRetireesPageJsonVO::Wrapper execQueryExportRetirees(const PageQuery::Wrapper& query);

};

// ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController)
#endif // _ExportRetirees_CONTROLLER_