#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: rice
 @Date: 2023/5/21 16:52:22

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
#ifndef _PROFCERTS_DO_
#define _PROFCERTS_DO_
#include "../DoInclude.h"

/**
 * ִ(ְ)ҵ�ʸ�֤�������б��ѯDO
 * �����ˣ��׷�
 */
class ProfCertsDO
{
	// ִҵ�ʸ�רҵ����
	CC_SYNTHESIZE(string, pimQualMajorId, PimQualMajorId);
	// ִҵ�ʸ�
	CC_SYNTHESIZE(string, pimQualMajorName, PimQualMajorName);
	// ������
	CC_SYNTHESIZE(string, createMan, CreateMan);
	// ����ʱ��
	CC_SYNTHESIZE(string, createDate, CreateDate);
	// ENABLE
	CC_SYNTHESIZE(uint64_t, enable, Enable);
	// ������
	CC_SYNTHESIZE(string, upDateMan, UpDateMan);
	// ����ʱ��
	CC_SYNTHESIZE(string, upDateDate, UpDateDate);
	// ִҵ�ʸ�����ʶ
	CC_SYNTHESIZE(string, pimQualTypeId, PimQualTypeId);
	// ��֯��ʶ
	CC_SYNTHESIZE(string, ormOrgId, OrmOrgId);
	// ִҵ�ʸ����
	CC_SYNTHESIZE(string, professionalType, ProfessionalType);
	// רҵ����ְ��
	CC_SYNTHESIZE(string, zyjszw, Zyjszw);
	// ����
	CC_SYNTHESIZE(string, quaLevel, QuaLevel);
	// רҵ
	CC_SYNTHESIZE(string, quaMajor, QuaMajor);
	// ��λ����
	CC_SYNTHESIZE(string, gwlx, Gwlx);
	// ��λ����
	CC_SYNTHESIZE(string, gwType, GwType);
	// ��λ����
	CC_SYNTHESIZE(string, gwzs, Gwzs);
	// ��λ�����ܣ�֤��
	CC_SYNTHESIZE(string, pimQualTypeName, PimQualTypeName);

public:
	ProfCertsDO() {
		pimQualMajorId = "";
		pimQualMajorName = "";
		createMan = "";
		createDate = "";
		enable = 0;
		upDateMan = "";
		upDateDate = "";
		pimQualTypeId = "";
		ormOrgId = "";
		professionalType = "";
		zyjszw = "";
		quaLevel = "";
		quaMajor = "";
		gwlx = "";
		gwType = "";
		gwzs = "";
		pimQualTypeName = "";
	}
};

#endif // !_PROFCERTS_DO_
