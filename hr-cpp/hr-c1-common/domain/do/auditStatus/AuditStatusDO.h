#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: ���֮��
 @Date: 2023/05/23 16:58:16

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
#ifndef _AUDITSTATUSDO_H_
#define _AUDITSTATUSDO_H_

#include "../DoInclude.h"

/**
 * ���״̬�����б�DO
 * �����ˣ����֮��
 */
class AuditStatusDO
{
	// ����������
	CC_SYNTHESIZE(string, auditStatus, AuditStatus);
	// ������ֵ
	CC_SYNTHESIZE(string, code, Code);
public:
	AuditStatusDO()
	{
		code = "";
		auditStatus = "";
	}

	AuditStatusDO(string code_, string level_)
	{
		code = code_;
		auditStatus = level_;
	}
};

#endif // !_AUDITSTATUSDO_H_