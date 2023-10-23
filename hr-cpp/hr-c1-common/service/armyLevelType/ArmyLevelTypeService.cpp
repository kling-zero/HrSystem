/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
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
#include "ArmyLevelTypeService.h"
#include "uselib/pullListRedis/UseLibRedis.h"
#include "dao/armyLevelType/ArmyLevelTypeDAO.h"

PullListDTO::Wrapper ArmyLevelTypeService::listAll()
{
	// �������ض���
	auto dto = PullListDTO::createShared();

	// TODO: ��ѯ����
	// �ӻ����л�ȡ��ת�б�
	auto hash = UseLibRedis::queryRedis("army-level-type");

	// ���Ϊ�������dao��ѯ���ݿ�
	if (hash.empty())
	{
		// TODO: ����dao��ѯ���ݿ�
		ArmyLevelTypeDAO dao;
		auto res = dao.selectAll();
		
		// ��װ��DTO����
		for (const auto& item : res)
		{
			string code = item.getCode();
			dto->pullList->push_back(ItemDTO::createShared(atoi(code.c_str()), item.getArmyLevelType()));
		}

		if (res.size())
			// TODO: ����ȡ�����ݸ��µ�Redis����
			UseLibRedis::updateRedis("army-level-type", dao.getMapList());
	}
	// ������װ�������ݵ�DTO
	else
	{
		for (const auto& item : hash)
		{
			int code = atoi(item.first.c_str());
			dto->pullList->push_back(ItemDTO::createShared(code, item.second));
		}
	}
	return dto;
}

