/*
 Copyright Zero One Star. All rights reserved.

 @Author: ���֮��
 @Date: 2023/05/23 19:26:11

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
#include "Macros.h"
#include "CostTypeListService.h"
#include "uselib/pullListRedis/UseLibRedis.h"
#include "dao/costTypeList/CostTypeListDAO.h"

PullListDTO::Wrapper CostTypeListService::listAll()
{
	// �������ض���
	auto res = PullListDTO::createShared();

	// TODO: ��ѯ����
	// �ӻ����л�ȡ��������б�
	auto hash = UseLibRedis::queryRedis("cost-type");

	auto dto = PullListDTO::createShared();
	// ���Ϊ�������dao��ѯ���ݿ�
	if (hash.empty())
	{
		// TODO: ����dao��ѯ���ݿ�
		CostTypeListDAO dao;
		auto res = dao.listAll();

		// ��װ��DTO����
		for (auto item : res)
		{
			string code = item.getCode();
			dto->pullList->push_back(ItemDTO::createShared(atoi(code.c_str()), item.getCostType()));
		}

		if (res.size())
			// TODO: ����ȡ�����ݸ��µ�Redis����
			UseLibRedis::updateRedis("cost-type", dao.getMapList());
	}
	// ������װ�������ݵ�DTO
	else
	{
		for (auto item : hash)
		{
			int code = atoi(item.first.c_str());
			dto->pullList->push_back(ItemDTO::createShared(code, item.second));
		}
	}
	return dto;
}
