#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Զ��
 @Date: 2023/05/21 21:36:32

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
#ifndef _LEAVEREASONDO_H_
#define _LEAVEREASONDO_H_
#include "../DoInclude.h"
/**
 * ��ְԭ�������б�
 * �����ˣ�Զ��
 */
class LeaveReasonDO
{
	// ��ְԭ�������б�
	CC_SYNTHESIZE(string, leavereason, Leavereason);

	// ԭ��code
	CC_SYNTHESIZE(int, code, Code);
};
#endif // !_LEAVEREASONDO_H_