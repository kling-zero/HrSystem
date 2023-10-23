
/*
 Copyright Zero One Star. All rights reserved.

 @Author: yuanchen
 @Date: 2023/05/29 20:35:55

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
#include "AwardLevelService.h"
#include "uselib/pullListRedis/UseLibRedis.h"
#include "dao/awardLevel/AwardLevelDAO.h"
PullListDTO::Wrapper AwardLevelService::listAll()
{
	// �������ض���
	auto dto = PullListDTO::createShared();

	// TODO: �ӻ����в�ѯ�����б�
	auto hash = UseLibRedis::queryRedis("award-level");

	// ���������û������
	if (hash.empty())
	{
		// TODO: ����DAO��ѯ���ݿ�
		AwardLevelDAO dao;
		auto res = dao.selectAll();

		// ��DOת��ΪDTO����װ��ϣ��
		for (const auto& item : res)
		{
			string code = item.getPcmawardswonsid();
			dto->pullList->push_back(ItemDTO::createShared(atoi(code.c_str()), item.getAwardlevel()));
		}
		
		if (res.size())
			// TODO: ����ȡ�����ݸ��µ�Redis����
			UseLibRedis::updateRedis("award-level", dao.getAwardLevel());
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

