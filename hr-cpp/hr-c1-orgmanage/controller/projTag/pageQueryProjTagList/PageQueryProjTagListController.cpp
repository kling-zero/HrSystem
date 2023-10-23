/*
 Copyright Zero One Star. All rights reserved.

 @Author: ���֮��
 @Date: 2023/05/24 17:58:45

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
#include "PageQueryProjTagListController.h"
#include "service/projTag/ProjTagService.h"

PageQueryProjTagVO::Wrapper PageQueryProjTagListController::execPageQueryProjTag(const PageProjTagQuery::Wrapper& query)
{
	// �������ض���
	auto vo = PageQueryProjTagVO::createShared();

	// ����service
	ProjTagService service;
	auto dto = service.listProjTagList(query);
	vo->success(dto);
	return vo;
}