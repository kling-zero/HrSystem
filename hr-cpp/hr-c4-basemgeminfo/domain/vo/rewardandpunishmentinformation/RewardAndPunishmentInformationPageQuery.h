#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: arui
 @Date: 2023/05/24 19:47:39

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
#ifndef _REWARDANDPUNISHMENTINFORMATIONPAGEQUERY_H_
#define _REWARDANDPUNISHMENTINFORMATIONPAGEQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"
#include OATPP_CODEGEN_BEGIN(DTO)

class RewardAndPunishmentInformationPageQuery : public PageQuery
{
	DTO_INIT(RewardAndPunishmentInformationPageQuery, PageQuery);
	
	// Ա�����
	DTO_FIELD(String, pimpersonid);
	DTO_FIELD_INFO(pimpersonid) {
		info->description = ZH_WORDS_GETTER("rewardandpunishmentinformation.field.pimpersionid");
	}
};
class RewardAndPunishmentInformationViewQuery : public oatpp::DTO
{
	DTO_INIT(RewardAndPunishmentInformationViewQuery, DTO);

	// ������Ϣ��ʶ(����)
	DTO_FIELD(String, pimrewardpunishmentid);
	DTO_FIELD_INFO(pimrewardpunishmentid) {
		info->description = ZH_WORDS_GETTER("rewardandpunishmentinformation.field.pimrewardpunishmentid");
	}
};
class RewardAndPunishmentInformationDownloadQuery : public oatpp::DTO
{
	DTO_INIT(RewardAndPunishmentInformationDownloadQuery, DTO);

	// ���гɹ���Ա��Ϣ��ʶ
	DTO_FIELD(String, pimpersonid);
	DTO_FIELD_INFO(pimpersonid) {
		info->description = ZH_WORDS_GETTER("rewardandpunishmentinformation.field.pimpersonid");
	}
};


#include OATPP_CODEGEN_END(DTO)

#endif // !_REWARDANDPUNISHMENTINFORMATIONPAGEQUERY_H_