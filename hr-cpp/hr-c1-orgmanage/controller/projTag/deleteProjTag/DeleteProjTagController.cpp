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
#include "DeleteProjTagController.h"
#include "service/projTag/deleteProjTagService/DeleteProjTagService.h"

StringJsonVO::Wrapper DeleteProjTagController::execDeleteByTagId(const DeleteProjTagDTO::Wrapper& deleteProjTagDTO, const PayloadDTO& payload)
{
	auto vo = StringJsonVO::createShared();
	// ����У��
	if (!deleteProjTagDTO->tagId)
	{
		vo->init(String(""), RS_PARAMS_INVALID);
		return vo;
	}
	DeleteProjTagService deleteProjTagService;

	// ִ������ɾ��
	if (deleteProjTagService.removeData(deleteProjTagDTO->tagId)) {
		vo->success(deleteProjTagDTO->tagId);
	}
	else
	{
		vo->fail(deleteProjTagDTO->tagId);
	}
	return vo;
}

DeleteProjTagBatchVO::Wrapper DeleteProjTagController::execDeleteBatchByTagId(const DeleteProjTagBatchDTO::Wrapper& deleteProjTagBatchDTO, const PayloadDTO& payload)
{
	// ���巵�����ݶ���
	auto vo = DeleteProjTagBatchVO::createShared();
	// ����У��
	if (!deleteProjTagBatchDTO->tagIds)
	{
		vo->init(deleteProjTagBatchDTO, RS_PARAMS_INVALID);
		return vo;
	}
	DeleteProjTagService postDeleteService;

	// ִ������ɾ��
	if (postDeleteService.removeBatchData(deleteProjTagBatchDTO)) {
		vo->success(deleteProjTagBatchDTO);
	}
	else
	{
		vo->fail(deleteProjTagBatchDTO);
	}
	return vo;
}