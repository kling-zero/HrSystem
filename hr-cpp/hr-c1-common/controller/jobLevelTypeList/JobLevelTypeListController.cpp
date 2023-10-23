/*
 Copyright Zero One Star. All rights reserved.

 @Author: ���֮��
 @Date: 2023/05/17 23:35:42

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
#include "stdafx.h"
#include "JobLevelTypeListController.h"
#include "service/jobLevelTypeList/JobLevelTypeListService.h"

PullListVO::Wrapper JobLevelTypeListController::execQueryJobLevelType()
{
	// ����
	/*auto dto = PullListDTO::createShared();
	auto a = ItemDTO::createShared(1, "A");
	dto->pullList->push_back(a);
	auto b = ItemDTO::createShared(2, "B");
	dto->pullList->push_back(b);*/

	// �������ض���
	auto vo = PullListVO::createShared();

	// TODO: ����service
	JobLevelTypeListService service;
	auto dto = service.listAll();
	vo->success(dto);

	// ��Ӧ���ض���
	return vo;
}