#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: rice
 @Date: 2023/5/17 16:37:51

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
#ifndef _POSTDELETE_CONTROLLER_
#define _POSTDELETE_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/postSet/PostDeleteDTO.h"
#include "domain/vo/postSet/PostDeleteBatchVO.h"
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"

using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ��λ���� - ɾ����λ������
 * ����ֵ : StringJsonVO or PostDeleteBatchJsonVO 
 * ������ : rice
 */
class PostDeleteController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(PostDeleteController);
	// 3 ����ӿ�
public:
	// ɾ����������
	ENDPOINT_INFO(deleteByOrmPostId) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("orgmanage.controller.postDeleteOne");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	ENDPOINT(API_M_DEL, PATH_TO_JOBSET("/delete-one-post-by-ormpostid"), deleteByOrmPostId, API_HANDLER_AUTH_PARAME, BODY_DTO(PostDeleteDTO::Wrapper, dto)) {
		// ������ѯ����
		/*auto postDeleteDTO = PostDeleteDTO::createShared();
		postDeleteDTO->ormPostId = ormPostId;*/
		// ��Ӧ���
		//API_HANDLER_RESP_VO(execDeleteByOrmPostId(postDeleteDTO, authObject->getPayload()));
		API_HANDLER_RESP_VO(execDeleteByOrmPostId(dto, authObject->getPayload()));
	}

	// ɾ����������
	ENDPOINT_INFO(deleteBatchByOrmPostId) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("orgmanage.controller.postDeleteBatch");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(PostDeleteBatchJsonVO);
	}
	ENDPOINT(API_M_DEL, PATH_TO_JOBSET("/delete-batch-post-by-ormpostid"), deleteBatchByOrmPostId, API_HANDLER_AUTH_PARAME, BODY_DTO(PostDeleteBatchDTO::Wrapper, dto)) {
		//const std::shared_ptr<ObjectMapper>& objectMapper = oatpp::parser::json::mapping::ObjectMapper::createShared();
		// ������ѯ����
		/*auto postDeleteBatchDTO = PostDeleteBatchDTO::createShared();
		postDeleteBatchDTO->ormPostIds = objectMapper->readFromString<oatpp::List<String>>(jsonPayload);*/
		//����
		//for (const auto& item : *postDeleteBatchDTO->ormPostIds) {
		//	/*OATPP_LOGD("testEndpoint", "Item: %s", item->c_str());*/
		//	cout << item->c_str() << endl;
		//}
		// ��Ӧ���
		//API_HANDLER_RESP_VO(exeDeleteBatchByOrmPostId(postDeleteBatchDTO, authObject->getPayload()));
		API_HANDLER_RESP_VO(exeDeleteBatchByOrmPostId(dto, authObject->getPayload()));
	}
private:
	// ��ѯָ����λ����
	StringJsonVO::Wrapper execDeleteByOrmPostId(const PostDeleteDTO::Wrapper& postDeleteDTO, const PayloadDTO& payload);
	PostDeleteBatchJsonVO::Wrapper exeDeleteBatchByOrmPostId(const PostDeleteBatchDTO::Wrapper& postDeleteBatchDTO, const PayloadDTO& payload);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _POSTDELETE_CONTROLLER_