#pragma once
#ifndef _ARCHIVES_CENTER_CONTROLLER_H_
#define _ARCHIVES_CENTER_CONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/query/archivesCenter/ArchivesCenterQuery.h"
#include "domain/vo/archivesCenter/ArchivesCenterVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController) // 0

class ArchivesCenterController
	: public oatpp::web::server::api::ApiController // 1
{
	// 2 ����������������
	API_ACCESS_DECLARE(ArchivesCenterController);
public: // ����ӿ�
	// 3 �����ѯ�ӿ�����
	ENDPOINT_INFO(queryArchivesCenter) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("archivesCenter.get.summary");
		// ����Ĭ����Ȩ����
		//API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(ArchivesCenterPageJsonVO);
		// �����ҳ��������
		API_DEF_ADD_PAGE_PARAMS();
	}
	// 4 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/archivesCenter/queryArchivesCenter", queryArchivesCenter, /*API_HANDLER_AUTH_PARAME,*/ QUERIES(QueryParams, qps)) {
		API_HANDLER_QUERY_PARAM(query, ArchivesCenterQuery, qps);
		API_HANDLER_RESP_VO(execQueryArchivesCenter(query/*, authObject->getPayload()*/));
	}
private:
	ArchivesCenterPageJsonVO::Wrapper execQueryArchivesCenter(const PageQuery::Wrapper& query);
};

#endif // !_ARCHIVES_CENTER_CONTROLLER_H_


