#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: arui
 @Date: 2023/05/22 15:35:55

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
#ifndef _REWARDANDPUNISHMENTINFORMATIONCONTROLLER_H_
#define _REWARDANDPUNISHMENTINFORMATIONCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "./Macros.h"
#include"domain/query/rewardandpunishmentinformation/RewardAndPunishmentInformationPageQuery.h"
#include "domain/vo/rewardandpunishmentinformation/RewardAndPunishmentInformationVO.h"
#include"domain/dto/rewardandpunishmentinformation/AddRewardAndPunishmentInformationDTO.h"
#include"domain/dto/rewardandpunishmentinformation/DelRewardAndPunishmentInformationDTO.h"
#include"domain/dto/rewardandpunishmentinformation/RewardAndPunishmentInformationDTO.h"
#include"domain/dto/rewardandpunishmentinformation/RewardAndPunishmentInformationIntoDTO.h"
#include <oatpp-swagger/Types.hpp>
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"
#include "oatpp-swagger/Model.hpp"


using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

#include OATPP_CODEGEN_BEGIN(ApiController)//0

//������Ϣ������

class RewardAndPunishmentInformationController : public oatpp::web::server::api::ApiController //1
{
	// 2����������������
	API_ACCESS_DECLARE(RewardAndPunishmentInformationController);
public: // ����ӿ�
		//3.����ӿ�����
		ENDPOINT_INFO(Information) {
			// ����ӿڱ���
			info->summary = ZH_WORDS_GETTER("rewardandpunishmentinformation.get.summary");
			// ������Ӧ��������
			API_DEF_ADD_RSP_JSON_WRAPPER(RewardAndPunishmentInformationJsonVO);
			// �����ҳ��ѯ��������
			API_DEF_ADD_PAGE_PARAMS();
			// ���������ѯ����
			info->queryParams.add<String>("pimpersonid").description = ZH_WORDS_GETTER("rewardandpunishmentinformation.field.pimpersonid");
			info->queryParams["pimpersonid"].addExample("default", String("1002"));
			info->queryParams["pimpersonid"].required = false;
		}
		//4.����˵�ӿ�
		ENDPOINT(API_M_GET, "/rewardandpunishmentinformation/select", Information, QUERIES(QueryParams, qps)) {
			// ������ѯ����������������ģ�Ͷ���
			API_HANDLER_QUERY_PARAM(query, RewardAndPunishmentInformationPageQuery, qps);
			// ��Ӧ���
			API_HANDLER_RESP_VO(execQueryRewardAndPunishmentInformation(query));
		}

		//����ָ��Ա��������Ϣ������������
		ENDPOINT_INFO(AddRewardAndPunishmentInformation)
		{
			// ����ӿڱ���
			info->summary = ZH_WORDS_GETTER("rewardandpunishmentinformation.post.summary");
			API_DEF_ADD_AUTH();
			// ������Ӧ������ʽ
			API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
		}
		//���������ӿڴ���
		ENDPOINT(API_M_POST, "/rewardandpunishmentinformation/add", AddRewardAndPunishmentInformation,API_HANDLER_AUTH_PARAME, BODY_DTO(AddRewardAndPunishmentInformationDTO::Wrapper, dto,))
		{
			//��Ӧ���
			API_HANDLER_RESP_VO(execAddRewardAndPunishmentInformation(dto, authObject->getPayload()));
		}

		//ɾ��Ա��������Ϣ(֧������ɾ��)
		ENDPOINT_INFO(DelRewardAndPunishmentInformation)
		{
			//����ӿڱ���
			info->summary = ZH_WORDS_GETTER("rewardandpunishmentinformation.delete.summary");
			// ������Ӧ������ʽ
			API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
		}
		// ��������ɾ���ӿڴ���
		ENDPOINT(API_M_POST, "/rewardandpunishmentinformation/del", DelRewardAndPunishmentInformation, BODY_DTO(DelRewardAndPunishmentInformationDTO::Wrapper, dto))
		{
			// ��Ӧ���
			API_HANDLER_RESP_VO(execDelRewardAndPunishmentInformation(dto));
		}

		//����ָ��Ա��������Ϣ
		ENDPOINT_INFO(postFile)
		{
			info->summary = ZH_WORDS_GETTER("rewardandpunishmentinformation.file.summary");
			API_DEF_ADD_AUTH();
			info->addConsumes<oatpp::swagger::Binary>("application/octet-stream");
			API_DEF_ADD_RSP_JSON(StringJsonVO::Wrapper);
			info->queryParams["suffix"].description = ZH_WORDS_GETTER("rewardandpunishmentinformation.file.suffix");
			info->queryParams["suffix"].addExample("xlsx", String(".xlsx"));

			// ������������������
			info->queryParams.add<String>("pimpersonid").description = ZH_WORDS_GETTER("rewardandpunishmentinformation.file.pimpersionid");
			info->queryParams["pimpersonid"].addExample("default", String("0002CC75-F8EB-45B3-A359-0310EC7F6D5B"));
			//info->queryParams["pimpersonid"].required = true;
		}
		// �����ļ��ϴ��˵㴦��
		ENDPOINT(API_M_POST, "/rewardandpunishmentinformation/file", postFile, API_HANDLER_AUTH_PARAME, BODY_STRING(String, body), QUERY(String, suffix), QUERY(String, pimpersonid))
		{
			// ִ���ļ������߼�
			API_HANDLER_RESP_VO(execRewardAndPunishmentInformationInto(body, suffix, pimpersonid, authObject->getPayload()));
		}

private: //����ӿ�ִ�к���
		//����ӿڵ�ִ�к���
	//�����ѯִ�к���
	RewardAndPunishmentInformationPageJsonVO::Wrapper execQueryRewardAndPunishmentInformation(const RewardAndPunishmentInformationPageQuery::Wrapper& query);
	//��������ִ�к���
	Uint64JsonVO::Wrapper execAddRewardAndPunishmentInformation(const AddRewardAndPunishmentInformationDTO::Wrapper& dto, const PayloadDTO& payload);
	//����ɾ��ִ�к���
	Uint64JsonVO::Wrapper execDelRewardAndPunishmentInformation(const DelRewardAndPunishmentInformationDTO::Wrapper& dto);
	//���嵼��ִ�к���
	StringJsonVO::Wrapper execRewardAndPunishmentInformationInto(const String& body, const String& suffix, const String& pimpersonid, const PayloadDTO& payload);
};

#include OATPP_CODEGEN_END(ApiController)//0

#endif // !_REWARDANDPUNISHMENTINFORMATIONCONTROLLER_H_