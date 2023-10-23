#pragma once
#ifndef _ARCHIVESCONTROLLER_H_
#define _ARCHIVESCONTROLLER_H_
#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/query/archives/ArchivesQuery.h"
#include "domain/vo/archives/ArchivesVO.h"
#include OATPP_CODEGEN_BEGIN(ApiController) // 0

/**
 * ������ѯ������
 */
class ArchivesController :public oatpp::web::server::api::ApiController {//1
	// 2 ����������������
	API_ACCESS_DECLARE(ArchivesController);
public://����ӿ�
	// 3 ����ӿ�����
	ENDPOINT_INFO(queryArchives) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("archives.get.summary");
		// ������Ӧ��������
		API_DEF_ADD_RSP_JSON_WRAPPER(ArchivesPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ���������ѯ����
		info->queryParams.add<String>("pimpersonid").description = ZH_WORDS_GETTER("sample.field.id");
		info->queryParams["pimpersonid"].addExample("default", String("DE3C6578-C046-4911-838D-7C95BCD9231F"));
		info->queryParams["pimpersonid"].required = false;
	}

	// 4 ����ӿڶ˵�
	ENDPOINT(API_M_GET, "/archives/select", queryArchives, QUERIES(QueryParams, qps)) {
		// ������ѯ����������������ģ�Ͷ���
		API_HANDLER_QUERY_PARAM(query, ArchivesQuery, qps);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execQueryTest(query));
	}
private:
	// 5 ����ӿڵ�ִ�к���
	ArchivesPageJsonVO::Wrapper execQueryTest(const ArchivesQuery::Wrapper& query);
};

#include OATPP_CODEGEN_END(ApiController) // 0
#endif // !_ARCHIVESCONTROLLER_H_

