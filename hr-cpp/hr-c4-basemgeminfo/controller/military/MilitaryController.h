#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/05/15 21:03:55

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
#ifndef _MILITARYCONTROLLER_H_
#define _MILITARYCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/query/military/MilitaryQuery.h"
#include "domain/vo/military/MilitaryVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class MilitaryController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(MilitaryController);
public: // ����ӿ�
	//�鿴ָ��Ա����ת�ɲ�(ָ����ת�ɲ�����)
	ENDPOINT_INFO(queryMilitary) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("military.get.summary");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ��������
		API_DEF_ADD_RSP_JSON_WRAPPER(MilitaryJsonVO);
		// ���������ѯ����
		info->queryParams.add<String>("PIMARMYCADRESID").description = ZH_WORDS_GETTER("military.PIMARMYCADRESID");
		info->queryParams["PIMARMYCADRESID"].addExample("default", String("0453FC72-E19C-43E0-984C-4406706EB79E"));
	}
	ENDPOINT(API_M_GET, "/military/select", queryMilitary, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, qps)) {
		// ������ѯ����������������ģ�Ͷ���
		API_HANDLER_QUERY_PARAM(query, MilitaryDetailQuery, qps);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execQueryMilitary(query));
	}
	//�޸�ָ��Ա����ת�ɲ�(�����޸�)
	ENDPOINT_INFO(modifyMilitary) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("military.put.summary");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	ENDPOINT(API_M_PUT, "/military/modify", modifyMilitary, API_HANDLER_AUTH_PARAME, BODY_DTO(MilitaryDTO::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execModifyMilitary(dto, authObject->getPayload()));
	}
	//����ָ��Ա����ת�ɲ�(������ҳ��ǰ�����)
	ENDPOINT_INFO(downloadMilitary) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("military.download.summary");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		// ���������ѯ����
		info->queryParams.add<String>("PIMPERSONID").description = ZH_WORDS_GETTER("military.PIMPERSONID");
		info->queryParams["PIMPERSONID"].addExample("default", String("66958E87-91A4-4DA8-8124-060E93B47EBE"));
	}
	ENDPOINT(API_M_POST, "/military/download", downloadMilitary, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, qps)) {
		// ������ѯ����������������ģ�Ͷ���
		API_HANDLER_QUERY_PARAM(query, MilitaryDownloadQuery, qps);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execDownloadMilitary(query));
	}
private: // ����ӿ�ִ�к���
	MilitaryJsonVO::Wrapper execQueryMilitary(const MilitaryDetailQuery::Wrapper& query);
	StringJsonVO::Wrapper execModifyMilitary(const MilitaryDTO::Wrapper& dto, const PayloadDTO& payload);
	StringJsonVO::Wrapper execDownloadMilitary(const MilitaryDownloadQuery::Wrapper& query);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_MILITARYCONTROLLER_H_