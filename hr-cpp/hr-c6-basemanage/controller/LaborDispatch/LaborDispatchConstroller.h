#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: mengHuan
 @Date: 2023/05/15 15:25:13

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
#ifndef _MHCONSTROLLER_H_
#define _MHCONSTROLLER_H_

#include "ApiHelper.h"
#include "domain/query/PageQuery.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/query/LaborDispatch/LaborDispatchQuery.h"
#include "domain/vo/LaborDispatch/LaborDispatchVO.h"
#include "domain/dto/LaborDispatch/LaborDispatchDTO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController)

// 1 �̳п�����
class LaborDispatchConstroller : public oatpp::web::server::api::ApiController
{
	// 2 ����������������
	API_ACCESS_DECLARE(LaborDispatchConstroller);
public:
	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(queryLDCorlist) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("ldcompany.get.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(LaborDispatchPageJsonVO);
		//�����ҳ��������
		API_DEF_ADD_PAGE_PARAMS();
		info->queryParams.add<String>("name").description = ZH_WORDS_GETTER("ldcompany.field.PIMLABOURCAMPANYNAME");
		info->queryParams["name"].required = false;

		info->queryParams.add<String>("lxfs").description = ZH_WORDS_GETTER("ldcompany.field.LXFS");
		info->queryParams["lxfs"].required = false;
	}
	// 3.2 ����ӿڶ˵�
	ENDPOINT(API_M_GET, "/contract-management/queryPages-laborDispatch-Information", queryLDCorlist, QUERIES(QueryParams, queryParams)) {
		//������ѯ����
		API_HANDLER_QUERY_PARAM(labordispatchquery, LaborDispatchQuery, queryParams);
		//��Ӧ���
		API_HANDLER_RESP_VO(executeQueryAll_ld(labordispatchquery));
	}

	// 3.1 ���������ӿ�����
	ENDPOINT_INFO(addLDCor) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("ldcompany.post.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 ���������ӿڴ���
	ENDPOINT(API_M_POST, "/contract-management/add-laborDispatchInformation", addLDCor, BODY_DTO(LaborDispatchModifyDTO::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execAddLaborDispatch_ld(dto));
	}

	// 3.1 ����ɾ���ӿ�����
	ENDPOINT_INFO(removeCor) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("ldcompany.delete.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	// 3.2 ����ɾ���ӿڴ���
	ENDPOINT(API_M_DEL, "/contract-management/remove-laborDispatchInformation", removeCor, BODY_DTO(LaborDispatchRemoveDTO::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execRemoveLaborDispatch_ld(dto));
	}

	// 3.1 ���嵼���ӿ�����
	ENDPOINT_INFO(exportCor) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("ldcompany.export.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		info->queryParams.add<String>("name").description = ZH_WORDS_GETTER("ldcompany.field.PIMLABOURCAMPANYNAME");
		info->queryParams["name"].required = false;

		info->queryParams.add<String>("lxfs").description = ZH_WORDS_GETTER("ldcompany.field.LXFS");
		info->queryParams["lxfs"].required = false;
	}
	// 3.2 ���嵼���ӿڴ���
	ENDPOINT(API_M_POST, "/contract-management/export-laborDispatchInformation", exportCor, QUERIES(QueryParams, queryExport),BODY_DTO(LaborDispatchExportDTO::Wrapper, dto)) {
		//������ѯ����
		API_HANDLER_QUERY_PARAM(query, LaborDispatchQuery, queryExport);
		//��Ӧ���
		API_HANDLER_RESP_VO(execExportLaborDispatch_ld(query,dto));
	}

private: //  ����ӿ�ִ�к���
	// 3.3 ��ҳ��ѯ����
	LaborDispatchPageJsonVO::Wrapper executeQueryAll_ld(const LaborDispatchQuery::Wrapper& query);
	// 3.3 ��������
	Uint64JsonVO::Wrapper execAddLaborDispatch_ld(const LaborDispatchModifyDTO::Wrapper& dto);
	//3.3 ɾ������
	StringJsonVO::Wrapper execRemoveLaborDispatch_ld(const LaborDispatchRemoveDTO::Wrapper& dto);
	//3.3 ��������
	StringJsonVO::Wrapper execExportLaborDispatch_ld(const LaborDispatchQuery::Wrapper& query, const LaborDispatchExportDTO::Wrapper& dto);

};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_MHCONSTROLLER_H_