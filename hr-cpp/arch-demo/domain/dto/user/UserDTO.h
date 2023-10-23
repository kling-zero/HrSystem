#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/26 23:47:08

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
#ifndef _USERDTO_H_
#define _USERDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * ����һ���޸��û���Ϣ�����ݴ���ģ��
 */
class UserDTO : public oatpp::DTO
{
	DTO_INIT(UserDTO, DTO);
	// �ǳ�
	DTO_FIELD(String, nickname);
	DTO_FIELD_INFO(nickname) {
		info->description = ZH_WORDS_GETTER("user.field.nickname");
	}
	// ����
	DTO_FIELD(Int32, age);
	DTO_FIELD_INFO(age) {
		info->description = ZH_WORDS_GETTER("user.field.age");
	}
	// ���֤��
	DTO_FIELD(String, idCard);
	DTO_FIELD_INFO(idCard) {
		info->description = ZH_WORDS_GETTER("user.field.idCard");
	}
};

/**
 * ����һ���û���Ϣ��ҳ�������
 */
class UserPageDTO : public PageDTO<UserDTO::Wrapper>
{
	DTO_INIT(UserPageDTO, PageDTO<UserDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // _USERDTO_H_