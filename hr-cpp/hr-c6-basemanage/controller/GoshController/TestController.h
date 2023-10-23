#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/05/08 21:23:08

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
#ifndef _GOSHCONTROLLER_H_
#define _GOSHCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/Gosh/ContractQuery.h"
#include "domain/dto/Gosh/ContractDTO.h"
#include "domain/vo/Gosh/ContractVO.h"
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"
#include "oatpp/codegen/api_controller/base_define.hpp"
#include "ApiHelper.h"

using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

#include OATPP_CODEGEN_BEGIN(ApiController) // 0

/**
 * ���Կ�����
 */
class GoshController : public oatpp::web::server::api::ApiController // 1
{
	// 2 ����������������
	API_ACCESS_DECLARE(GoshController);
public: 
	// 3.1 �����ѯ��ͬ�ӿ�����
	ENDPOINT_INFO(queryContract) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("contract_gosh.get.summary");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ��������
		API_DEF_ADD_RSP_JSON_WRAPPER(ContractPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		//���˲�������
		//1.Ա�����
		info->queryParams.add<String>("personid").description = ZH_WORDS_GETTER("contract_gosh.field.personid");
		//ZH_WORDS_GETTER("person_gosh.get.summary");
		info->queryParams["personid"].required = false;
		//2.Ա������
		info->queryParams.add<String>("name").description = ZH_WORDS_GETTER("contract_gosh.field.name");
		info->queryParams["name"].required = false;
		//3��Ա��״̬
		info->queryParams.add<String>("person_condition").description = ZH_WORDS_GETTER("contract_gosh.field.person_condition");
		info->queryParams["person_condition"].required = false;
		//4����ͬ���
		info->queryParams.add<String>("id").description = ZH_WORDS_GETTER("contract_gosh.field.id");
		info->queryParams["id"].required = false;
		//5����ͬ���
		info->queryParams.add<String>("type").description = ZH_WORDS_GETTER("contract_gosh.field.type");
		info->queryParams["type"].required = false;
		//6����ͬ״̬
		info->queryParams.add<String>("condition").description = ZH_WORDS_GETTER("contract_gosh.field.condition");
		info->queryParams["condition"].required = false;
		//7����ʼ����
		info->queryParams.add<String>("date").description = ZH_WORDS_GETTER("contract_gosh.field.date");
		info->queryParams["date"].required = false;
		//8����������
		info->queryParams.add<String>("date_over").description = ZH_WORDS_GETTER("contract_gosh.field.date_over");
		info->queryParams["date_over"].required = false;
		//9����ͬ����
		info->queryParams.add<String>("variety").description = ZH_WORDS_GETTER("contract_gosh.field.variety");
		info->queryParams["variety"].required = false;
		//--------------------------------------------------------------------ѡ����ʾ�ֶ���
		API_DEF_SHOW_PAGE_PARAMS();
		
	}
	 //3.2 �����ѯ��ͬ�ӿڶ˵�
	ENDPOINT(API_M_GET, "/contract-management/query-contract", queryContract, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, qps)) {
		// ������ѯ����������������ģ�Ͷ���
		API_HANDLER_QUERY_PARAM(query, ContractQuery, qps);		
		// ��Ӧ���
		API_HANDLER_RESP_VO(execQueryContract(query, authObject->getPayload()));
	}
	//3.1 �����ѯ������Ϣ�ӿ�����
	ENDPOINT_INFO(queryPerson) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("person_gosh.get.summary");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ��������
		API_DEF_ADD_RSP_JSON_WRAPPER(ContractPageJsonVO);
		// �����ҳ��ѯ��������
		info->queryParams.add<String>("name").description = ZH_WORDS_GETTER("contract_gosh.field.name");
		info->queryParams["name"].addExample("default", String("li ming"));
		info->queryParams["name"].required = true;
		API_DEF_SHOW_PAGE_PARAMS();
	}
	//3.2 �����ѯ������Ϣ�ӿڴ���
	ENDPOINT(API_M_GET, "/contract-management/query-person", queryPerson, API_HANDLER_AUTH_PARAME,QUERIES(QueryParams, qps)) {
		// ������ѯ����������������ģ�Ͷ���
		API_HANDLER_QUERY_PARAM(query, ContractQuery, qps);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execQueryPerson(query, authObject->getPayload()));
	}
	// 3.1 ����������ͬ�ӿ�����
	ENDPOINT_INFO(addContract) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("contract_gosh.post.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 ����������ͬ�ӿڴ���
	ENDPOINT(API_M_POST, "/contract-management/add-contract", addContract, BODY_DTO(ContractDTO_gs_insert::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execAddContract(dto));
	}
	// 3.1 ����ɾ����ͬ�ӿ�����
	ENDPOINT_INFO(removeContract) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("contract_gosh.delete.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 ����ɾ����ͬ�ӿڴ���
	ENDPOINT(API_M_DEL, "/contract-management/remove-contract", removeContract, BODY_DTO(ContractDTO_gs_delete::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execRemoveContract(dto));
	}

private: // ����ӿ�ִ�к���

	// 3.3 ��ʾ��ѯ��ͬ��Ϣ
	ContractPageJsonVO::Wrapper execQueryContract(const ContractQuery::Wrapper& query, const PayloadDTO& payload);
	// 3.3 ��ʾ��ѯ������Ϣ
	ContractPageJsonVO::Wrapper execQueryPerson(const ContractQuery::Wrapper& query, const PayloadDTO& payload);
	// 3.3 ��ʾ������ͬ����
	Uint64JsonVO::Wrapper execAddContract(const ContractDTO_gs_insert::Wrapper& dto);
	// 3.3 ��ʾɾ����ͬ����
	Uint64JsonVO::Wrapper execRemoveContract(const ContractDTO_gs_delete::Wrapper& dto);
};


#include OATPP_CODEGEN_END(ApiController) // 0

#endif // !_TESTCONTROLLER_H_