#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: jun
 @Date: 2023/06/03 16:52:19

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
#ifndef _DELETELANGUAGEDTO_H_
#define _DELETELANGUAGEDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class DeleteLanguageDTO : public oatpp::DTO
{
	DTO_INIT(DeleteLanguageDTO, DTO);
	//���Ա�ʶ�����б�
	DTO_FIELD(List<String>, languageAbilityID, u8"���Ա�ʶ����Id�б�");
	DTO_FIELD_INFO(languageAbilityID) {
		info->description = ZH_WORDS_GETTER("sample.field.id");
	}
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_DELETELANGUAGEDTO_H_