#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/05/17 14:39:54

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
#ifndef _CONTRACTSERVICE_H_
#define _CONTRACTSERVICE_H_
#include <list>
#include "domain/vo/contract/ContractVO.h"
#include "domain/query/contract/ContractQuery.h"
#include "domain/dto/contract/ContractDTO.h"

class ContractService
{
public:
	// 分页查询所有数据
	ContractPageDTO::Wrapper listAll(const ContractQuery::Wrapper& query);
};

#endif // !_CONTRACTSERVICE_H_