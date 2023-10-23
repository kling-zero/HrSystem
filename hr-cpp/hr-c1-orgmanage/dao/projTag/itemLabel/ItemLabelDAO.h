#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: yuanchen
 @Date: 2023/05/31 21:23:16

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
#ifndef _ITEMLABELDAO_H_
#define _ITEMLABELDAO_H_
#include "BaseDAO.h"
#include "domain/do/projTag/ProjTagDO.h"
#include "domain/query/itemlabel/ItemlabelQuery.h"

/**
 * ��Ŀ��ǩ - ��ѯָ����ǩ����
 * �����ˣ�Ե��
 */
class ItemLabelDAO : public BaseDAO
{
public:
	std::list<ProjTagDO> selectItemLabelList(const ItemLabelQuery::Wrapper& query);
};

#endif // !_ITEMLABELDAO_H_