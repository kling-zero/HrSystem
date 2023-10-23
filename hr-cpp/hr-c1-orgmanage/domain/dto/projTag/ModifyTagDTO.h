#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/05/20 18:00:49

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
#ifndef _MODIFYTAGDTO_H_
#define _MODIFYTAGDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ������Ŀ��ǩ����ģ��
 * �����ˣ�Andrew
 */
class ModifyTagDTO : public oatpp::DTO
{
	DTO_INIT(ModifyTagDTO, DTO);
	// ��Ŀ��ǩΨһ��ʶ
	DTO_FIELD(String, tagId);
	DTO_FIELD_INFO(tagId) {
		info->description = ZH_WORDS_GETTER("projTag.field.tagId");
	}
	// ��Ŀ��ǩ��
	DTO_FIELD(String, tagName);
	DTO_FIELD_INFO(tagName) {
		info->description = ZH_WORDS_GETTER("projTag.field.tagName");
	}
	// ��֯ID
	DTO_FIELD(String, orgId);
	DTO_FIELD_INFO(orgId) {
		info->description = ZH_WORDS_GETTER("projTag.field.orgId");
	}
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_MODIFYTAGDTO_H_