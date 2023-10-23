﻿#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: ahao
 @Date: 2023/06/07 10:58:45

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
#ifndef _MUL_DELETE_ASSIGN_INFO_DTO_
#define _MUL_DELETE_ASSIGN_INFO_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)


/**
 * 删除多条分配信息传输对象
 */
class MulDeleteAssignInfoDTO : public oatpp::DTO
{
	DTO_INIT(MulDeleteAssignInfoDTO, DTO);
	// 分配标识集
	DTO_FIELD(oatpp::List<String>, assignIds);
	DTO_FIELD_INFO(assignIds) {
		info->description = ZH_WORDS_GETTER("employee.t_pimperson.assignIds");
	}
};
#include OATPP_CODEGEN_END(DTO)
#endif // !_MUL_DELETE_ASSIGN_INFO_DTO_