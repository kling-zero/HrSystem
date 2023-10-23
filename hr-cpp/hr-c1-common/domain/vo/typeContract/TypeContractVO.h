#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: xubuxi
 @Date: 2023/05/20 21:38:26

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
#ifndef _HTLXVO_H_
#define _HTLXVO_H_
#include "../../GlobalInclude.h"
#include "../../dto/typeContract/TypeContractDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * ����һ����ͬ�����ʾJsonVO����������Ӧ��ǰ��
 */
class TypeContractJsonVO : public JsonVO<TypeContractListDTO::Wrapper>
{
	DTO_INIT(TypeContractJsonVO, JsonVO<TypeContractListDTO::Wrapper>);
public:
	// �ڹ��캯����ʵ����data�б�
	TypeContractJsonVO() {
		this->data = {};
	}

};
#include OATPP_CODEGEN_END(DTO)
#endif // !_HTLXVO_H_
