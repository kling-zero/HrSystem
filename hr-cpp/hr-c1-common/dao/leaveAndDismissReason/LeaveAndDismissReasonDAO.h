#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: yuanxiang
 @Date: 2023/05/30 23:17:37

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
#ifndef _LEAVEANDDISMISSREASONDAO_H_
#define _LEAVEANDDISMISSREASONDAO_H_
#include "BaseDAO.h"
#include "domain/do/leaveAndDismissReason/LeaveAndDismissReasonDO.h"
/**
 * ��ְ/��Ƹԭ��DAO
 * �����ˣ�Զ��
 */
class LeaveAndDismissReasonDAO : public BaseDAO
{
public:
	// ��ѯ�б�
	std::list<LeaveAndDismissReasonDO> selectReasonList();
};

#endif // !_LEAVEANDDISMISSREASONDAO_H_