#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: huilai
 @Date: 2023/05/15 11:14:40

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
#ifndef _WORKHISTORYCONTROLLER_H_
#define _WORKHISTORYCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"
#include "domain/query/work-history/WorkHistoryPageQuery.h"
#include "domain/vo/work-history/WorkHistoryFindVO.h"
#include "domain/dto/work-history/AddWorkHistoryDTO.h"
#include "domain/dto/work-history/DelWorkHistoryDTO.h"
#include "domain/vo/work-history/WorkHistoryExportVO.h"
#include "domain/query/work-history/WorkHistoryExportQuery.h"
#include "oatpp-swagger/Model.hpp"
#include "oatpp-swagger/Types.hpp"


#include "domain/query/work-history/WorkHistoryQuery.h"
#include "domain/dto/work-history/ModWorkHistoryDTO.h"
#include "domain/vo/work-history/ModWorkHistoryVO.h"
#include "domain/vo/work-history/WorkHistoryVO.h"
#include "domain/dto/work-history/WorkHistoryIntoDTO.h"
#include "uselib/rocketmq/TestRocket.h"


using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

#include OATPP_CODEGEN_BEGIN(ApiController)



class WorkHistoryController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(WorkHistoryController);
	//void init(){   }
public: // ����ӿ�
	//  �����ѯ�ӿ�����
	ENDPOINT_INFO(queryPageWorkHistory) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("workhistory.get.summary");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		//API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(WorkHistoryFindVO);
		// �����ҳ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ������������������
		info->queryParams.add<String>("pimpersonid").description = ZH_WORDS_GETTER("workhistory.field.pimpersonid");
		info->queryParams["pimpersonid"].addExample("default", String("1002"));
		info->queryParams["pimpersonid"].required = false;
	}
	// �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/workhistory/select", queryPageWorkHistory, QUERIES(QueryParams, qps)) {
		//������ѯ����������������ģ�Ͷ���
		API_HANDLER_QUERY_PARAM(query, WorkHistoryPageQuery, qps);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execQueryPageWorkHistory(query));
	}

	// ���������ӿ�����
	ENDPOINT_INFO(addWorkHistory) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("workhistory.post.summary");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// ���������ӿڴ���
	ENDPOINT(API_M_POST, "/workhistory/add", addWorkHistory, API_HANDLER_AUTH_PARAME, BODY_DTO(AddWorkHistoryDTO::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execAddWorkHistory(dto, authObject->getPayload()));
	}

	// ��������ɾ���ӿ�����
	ENDPOINT_INFO(delWorkHistory) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("workhistory.delete.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// ��������ɾ���ӿڴ���
	ENDPOINT(API_M_POST, "/workhistory/delete", delWorkHistory, BODY_DTO(DelWorkHistoryDTO::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execDelWorkHistory(dto));
	}

	// ����һ�����ļ�����ӿ�
	ENDPOINT_INFO(postFile) {
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		info->summary = ZH_WORDS_GETTER("workhistory.file.summary");
		info->addConsumes<oatpp::swagger::Binary>("application/octet-stream");
		API_DEF_ADD_RSP_JSON(StringJsonVO::Wrapper);
		/*info->queryParams["suffix"].description = ZH_WORDS_GETTER("workhistory.file.suffix");
		info->queryParams["suffix"].addExample("xlsx", String(".xlsx"));
		info->queryParams["suffix"].required = false;*/
		// ������������������
		info->queryParams.add<String>("pimpersonid").description = ZH_WORDS_GETTER("workhistory.field.pimpersonid");
		info->queryParams["pimpersonid"].addExample("default", String("1002"));
		//info->queryParams["pimpersonid"].required = true;
		
	}
	// �����ļ��ϴ��˵㴦��
	ENDPOINT(API_M_POST, "/workhistory/file", postFile, API_HANDLER_AUTH_PARAME, BODY_STRING(String, body), QUERY(String, pimpersonid)) {

		// ִ���ļ������߼�
		API_HANDLER_RESP_VO(execIntoWorkHistory(body,pimpersonid, authObject->getPayload()));
	}

	//�ļ������ӿ�
	ENDPOINT_INFO(exportWorkHistory) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("workhistory.export.summary");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		//API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		// �����ҳ��������
		//API_DEF_ADD_PAGE_PARAMS();
		// ������������������
		info->queryParams.add<String>("pimpersonid").description = ZH_WORDS_GETTER("workhistory.field.pimpersonid");
		info->queryParams["pimpersonid"].addExample("default", String("1002"));
		info->queryParams["pimpersonid"].required = false;
	}
	// ���嵼���ӿڴ���
	ENDPOINT(API_M_GET, "/workhistory/export", exportWorkHistory, QUERIES(QueryParams, qps)) {
		//������������������������ģ�Ͷ���
		API_HANDLER_QUERY_PARAM(query, WorkHistoryExportQuery, qps);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execExportWorkHistory(query));
	}








	/************************************************************************/
	/* ������                                                                     */
	/************************************************************************/
	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(queryWorkHistory) {
		// ����ӿڱ���,�õ���Ӣ���ֵ亯�����ù�zh-dict.yamlȷ������
		info->summary = ZH_WORDS_GETTER("workhistory.select.summary");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(WorkHistoryJsonVO);
		
		// ������������������
		info->queryParams.add<String>("pimworkhistoryid").description = ZH_WORDS_GETTER("workhistory.field.pimworkhistoryid");
		info->queryParams["pimworkhistoryid"].addExample("default", String("01AE11A5-8997-46F1-A56D-3F17DFEF5149"));
		info->queryParams["pimworkhistoryid"].required = false;


	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/workhistory/specify-details", queryWorkHistory, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// ������ѯ����
		API_HANDLER_QUERY_PARAM(userQuery, WorkHistoryQuery, queryParams);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execQueryWorkHistory(userQuery));
	}
	// �����޸�ָ��Ա����������(�����޸�)�ӿ�
	ENDPOINT_INFO(modifyWorkHistory) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("workhistory.put.summary");
		//����Ĭ����Ȩ����
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	
	ENDPOINT(API_M_PUT, "/workhistory/update", modifyWorkHistory, API_HANDLER_AUTH_PARAME, BODY_DTO(ModWorkHistoryDTO::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execModifyWorkHistory(dto,authObject->getPayload()));
	}

private: 
	
	// �����ҳ��ѯִ�к���
	WorkHistoryFindVO::Wrapper execQueryPageWorkHistory(const WorkHistoryPageQuery::Wrapper& query);

	//��������ִ�к���
	Uint64JsonVO::Wrapper execAddWorkHistory(const AddWorkHistoryDTO::Wrapper& dto, const PayloadDTO& payload);

	//����ɾ��ִ�к���
	Uint64JsonVO::Wrapper execDelWorkHistory(const DelWorkHistoryDTO::Wrapper& dto);

	//���嵼��ִ�к���
	StringJsonVO::Wrapper execIntoWorkHistory(const String&, const String&, const PayloadDTO& payload);

	//���嵼��ִ�к���
	StringJsonVO::Wrapper execExportWorkHistory(const WorkHistoryExportQuery::Wrapper& query);






	/**
	 * ������
	 */
	//�����ѯ���麯��
	WorkHistoryJsonVO::Wrapper execQueryWorkHistory(const WorkHistoryQuery::Wrapper& query);
	//�����޸�ִ�к���
	StringJsonVO::Wrapper execModifyWorkHistory(const ModWorkHistoryDTO::Wrapper& dto, const PayloadDTO& payload);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_WORKHISTORYCONTROLLER_H_
