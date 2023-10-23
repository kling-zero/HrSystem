#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/05/27 11:08:45

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
#ifndef _TITLE_DAO_
#define _TITLE_DAO_
#include "BaseDAO.h"
#include "domain/do/Title/TitleDO.h"
#include "domain/query/Title/TitleQuery.h"

class TitleDAO:public BaseDAO
{
	public:
		// ͳ����������
		uint64_t count(const TitleQuery::Wrapper& query);
		// ��ҳ��ѯ����
		list<TitleDO> selectWithPage(const TitleQuery::Wrapper& query);
		// ͨ��ְ��Ŀ¼���Ʋ�ѯ����
		list<TitleDO> selectByName(const string& name);
		// ��������
		uint64_t insert(const TitleDO& iObj);
		// �޸�����
		int update(const TitleDO& uObj);
		// ͨ�������ɾ������
		int deleteById(uint32_t id);
};

#endif // !_TITLEDAO_H_