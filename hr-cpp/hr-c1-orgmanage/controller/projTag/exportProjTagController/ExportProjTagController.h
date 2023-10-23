#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/05/18 16:32:02

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
#ifndef _EXPORTPROJTAGCONTROELLER_H_
#define _EXPORTPROJTAGCONTROELLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "Macros.h"
#include "ServerInfo.h"
#include "domain/query/projTag/ExportProjTagQuery.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

/**
 * ������Ŀ��ǩ������
 * ����ǰ�����󲢽��������ֶΣ��������ݲ�ѯ�����5000����
 * �Բ�ѯ�������ݷ�װ�ɱ���ļ����ϴ�fastdfs�ļ�������
 * ����ֵ��StringJsonVO - ����һ������url�ַ���
 * �����ˣ�Andrew
 */
class ExportProjTagController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(ExportProjTagController);
public: // ����ӿ�
	ENDPOINT_INFO(exportProjTag) {
		info->summary = ZH_WORDS_GETTER("projTag.export.summary");
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		API_DEF_ADD_AUTH();
		/*info->queryParams.add<UInt8>("rows").description = ZH_WORDS_GETTER("projTag.export.rows");
		info->queryParams["rows"].addExample("default", UInt8(1));
		info->queryParams["rows"].required = true;
		info->queryParams.add<String>("sequence").description = ZH_WORDS_GETTER("projTag.export.sequence");
		info->queryParams["sequence"].addExample("default", String("ASC"));
		info->queryParams["sequence"].required = true;*/
		API_DEF_ADD_QUERY_PARAMS(UInt32, "line", ZH_WORDS_GETTER("projTag.export.line"), 1, true);
		API_DEF_ADD_QUERY_PARAMS(String, "order", ZH_WORDS_GETTER("projTag.export.order"), "ASC", true);
	}

	ENDPOINT(API_M_GET, PATH_TO_PROJTAG("/export-project-tag"), exportProjTag, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, qps)) {
		API_HANDLER_QUERY_PARAM(query, ExportProjTagQuery, qps);
		API_HANDLER_RESP_VO(execExportProjTag(query));
	}
private: // ����ӿ�ִ�к���
	StringJsonVO::Wrapper execExportProjTag(const ExportProjTagQuery::Wrapper& query);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_EXPORTPROJTAGCONTROELLER_H_