#pragma once

#ifndef _REWARDANDPUNISHCONTROLLER_H_
#define _REWARDANDPUNISHCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "../../domain/query/rewardandpunish/RewardAndPunishQuery.h"
#include "../../domain/vo/rewardandpunish/RewardAndPunishVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class RewardAndPunishController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(RewardAndPunishController);
public: // ����ӿ�

	//�鿴ָ��
	ENDPOINT_INFO(queryRewardAndPunish) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("rewardandpunish.get.summary");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ��������
		API_DEF_ADD_RSP_JSON_WRAPPER(RewardAndPunishJsonVO);
		// ���������ѯ����
		info->queryParams.add<String>("pimrewardpunishmentid").description = ZH_WORDS_GETTER("rewardandpunish.pimrewardpunishmentid");
		info->queryParams["pimrewardpunishmentid"].addExample("default", String("123456789"));
	}
	ENDPOINT(API_M_GET, "/rewardandpunish/select", queryRewardAndPunish, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, qps)) {
		// ������ѯ����������������ģ�Ͷ���
		API_HANDLER_QUERY_PARAM(query, RewardAndPunishDetailQuery, qps);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execQueryRewardAndPunish(query));
	}

	//�޸�ָ�����ͼ�¼(�����޸�)
	ENDPOINT_INFO(modifyRewardAndPunish) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("rewardandpunish.put.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	ENDPOINT(API_M_PUT, "/rewardandpunish/modify", modifyRewardAndPunish, BODY_DTO(RewardAndPunishDTO::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execModifyRewardAndPunish(dto));
	}

	//����
	ENDPOINT_INFO(downloadRewardAndPunish) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("rewardandpunish.download.summary");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		// ���������ѯ����
		info->queryParams.add<String>("pimpersonid").description = ZH_WORDS_GETTER("rewardandpunish.pimpersonid");
		info->queryParams["pimpersonid"].addExample("default", String("0002CC75-F8EB-45B3-A359-0310EC7F6D5B"));
	}
	ENDPOINT(API_M_POST, "/rewardandpunish/download", downloadRewardAndPunish, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, qps)) {
		// ������ѯ����������������ģ�Ͷ���
		API_HANDLER_QUERY_PARAM(query, RewardAndPunishDownloadQuery, qps);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execDownloadRewardAndPunish(query));
	}
private: // ����ӿ�ִ�к���
	RewardAndPunishJsonVO::Wrapper execQueryRewardAndPunish(const RewardAndPunishDetailQuery::Wrapper& query);
	StringJsonVO::Wrapper execModifyRewardAndPunish(const RewardAndPunishDTO::Wrapper& dto);
	StringJsonVO::Wrapper execDownloadRewardAndPunish(const RewardAndPunishDownloadQuery::Wrapper& query);
};

#include OATPP_CODEGEN_END(ApiController)

#endif