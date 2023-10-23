#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: xubuxi
 @Date: 2023/05/31 0:46:24

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
#ifndef _PAGEQUERYBZDO_H_
#define _PAGEQUERYBZDO_H_
#include "../DoInclude.h"
class PageQueryBzDO
{
	// ��֯����id
	CC_SYNTHESIZE(string, orgId, OrgId);
	// ��֯��������
	CC_SYNTHESIZE(string, orgName, OrgName);
	// ���ű�ʶ
	CC_SYNTHESIZE(string, orgSectorId, OrgSectorId);
	// ��������
	CC_SYNTHESIZE(string, orgSectorName, OrgSectorName);
	// ������֯���
	CC_SYNTHESIZE(string, orgCode, OrgCode);
	// ��֯����
	CC_SYNTHESIZE(string, orgType, OrgType);
	// ��������
	CC_SYNTHESIZE(string, sectorType, SectorType);
	// ��������
	CC_SYNTHESIZE(string, createTime, CreateTime);
	// ������
	CC_SYNTHESIZE(string, createBy, CreateBy);
	// ��������
	CC_SYNTHESIZE(string, updateTime, UpdateTime);
	// ������
	CC_SYNTHESIZE(string, updateBy, UpdateBy);
	// ��������`BMBZRS`
	CC_SYNTHESIZE(string, bzrs, Bzrs);
	// ʵ�ʱ�������`BMSJBZRS`
	CC_SYNTHESIZE(string, sjbzrs, Sjbzrs);

public:
	PageQueryBzDO()
	{
		orgId = "";
		orgName = "";
		orgSectorId = "";
		orgSectorName = "";
		orgCode = "";
		orgType = "";
		sectorType = "";
		createBy = "";
		createTime = "";
		updateBy = "";
		updateTime = "";
		bzrs = "";
		sjbzrs = "";
	}
};

#endif // !_PAGEQUERYBZDO_H_