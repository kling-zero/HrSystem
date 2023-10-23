#pragma once
#ifndef _TRAININGRECORDCONTROLLER_H_
#define _TRAININGRECORDCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/query/trainingrecord/TrainingRecordQuery.h"
#include "domain/vo/trainingrecord/TrainingRecordVO.h"
#include "domain/dto/trainingrecord/TrainingRecordDTO.h"
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController)

class TrainingRecordController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(TrainingRecordController);
public: // ����ӿ�

	ENDPOINT_INFO(queryTrainingRecord) {

		//����ӿڱ���
		info->summary = ZH_WORDS_GETTER("trainingrecord.get.summary");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(TrainingRecordPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();

	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/trainingrecord/query", queryTrainingRecord, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// ������ѯ����
		API_HANDLER_QUERY_PARAM(userQuery, TrainingRecordPageQuery, queryParams);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execQueryTrainingRecord(userQuery, authObject->getPayload()));
	}

private: // ����ӿ�ִ�к���
	TrainingRecordPageJsonVO::Wrapper execQueryTrainingRecord(const TrainingRecordPageQuery::Wrapper& query, const PayloadDTO& payload);

};

#include OATPP_CODEGEN_END(ApiController)

#endif