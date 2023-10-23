#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: yuanxiang
 @Date: 2023/05/22 20:38:39

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
#ifndef _SECTORDO_H_
#define _SECTORDO_H_
#include "../DoInclude.h"
/**
 * ���Ʋ�ѯDO
 * �����ˣ�Զ��
 */
class SectorDO
{
	// ��Ŀ�������
	CC_SYNTHESIZE(string, projBasicInfo, ProjBasicInfo);

	// ������
	CC_SYNTHESIZE(string, updateMan, UpdateMan);

	// ��������
	CC_SYNTHESIZE(string, areaClassify, AreaClassify);

	// �汾
	CC_SYNTHESIZE(double, edition, Edition);

	// �ϰ�ʱ��
	CC_SYNTHESIZE(string, officeTime, OfficeTime);

	// �°�ʱ��
	CC_SYNTHESIZE(string, leaveTime, LeaveTime);

	// ��ͣ��ʶ
	CC_SYNTHESIZE(string, startStopSign, StartStopSign);

	// ����ʱ��
	CC_SYNTHESIZE(string, createTime, CreateTime);

	// �������Ƽ�����
	CC_SYNTHESIZE(string, projNameAndId, ProjNameAndId);

	// ��Ŀ��ǩ
	CC_SYNTHESIZE(string, projId, ProjId);

	// ԭ��¼ID
	CC_SYNTHESIZE(string, oldId, OldId);

	// �ϰ࿼��ʱ��
	CC_SYNTHESIZE(string, officeAttendTime, OfficeAttendTime);

	// ������֯���
	CC_SYNTHESIZE(string, orgCode, OrgCode);

	// �ƻ�����
	CC_SYNTHESIZE(double, planManMonth, PlanManMonth);

	// ����״̬
	CC_SYNTHESIZE(string, approvalStatus, ApprovalStatus);

	// �°࿼��ʱ��
	CC_SYNTHESIZE(string, leaveAttendTime, LeaveAttendTime);

	// ����ʱ��
	CC_SYNTHESIZE(string, updateTime, UpdateTime);

	// ��Ŀ����
	CC_SYNTHESIZE(string, projClassify, ProjClassify);

	// ��֯����
	CC_SYNTHESIZE(string, orgType, OrgType);

	// ERP����ID
	CC_SYNTHESIZE(string, erpOrgId, ErpOrgId);

	// �򿨷�ʽ
	CC_SYNTHESIZE(string, punchingMode, PunchingMode);

	// ��Ŀ����
	CC_SYNTHESIZE(string, projType, ProjType);

	// ��������
	CC_SYNTHESIZE(string, orgSectorName, OrgSectorName);

	// ��Ŀ��ģ
	CC_SYNTHESIZE(string, projScale, ProjScale);
	
	// ����Ŀ�����Ҫ��
	CC_SYNTHESIZE(string, demondOfProjectManager, DemondOfProjectManager);
	
	// ����Ŀ�ܹ���Ҫ��
	CC_SYNTHESIZE(string, demondOfChiefEngineer, DemondOfChiefEngineer);
	
	// ͷ��
	CC_SYNTHESIZE(string, title, Title);
	
	// ����ְ��㼶
	CC_SYNTHESIZE(string, referJobLevel, ReferJobLevel);
	
	// ����OU
	CC_SYNTHESIZE(string, belongOU, BelongOU);
	
	// ���
	CC_SYNTHESIZE(string, shortName, ShortName);
	
	// ���ڰ���
	CC_SYNTHESIZE(string, projTimePlan, ProjTimePlan);
	
	// �ƻ��ɱ�����
	CC_SYNTHESIZE(double, planCost, PlanCost);
	
	// ��������
	CC_SYNTHESIZE(string, depType, DepType);
	
	// ��Ŀ������
	CC_SYNTHESIZE(string, projDepType, ProjDepType);
	
	// ���ű�ʶ  �ǿ�
	CC_SYNTHESIZE(string, orgSectorId, OrgSectorId);
	
	// �ܿػ���
	CC_SYNTHESIZE(string, mechanism, Mechanism);
	
	// �汾״̬
	CC_SYNTHESIZE(string, editionState, EditionState);
	
	// ������
	CC_SYNTHESIZE(string, createMan, CreateMan);
	
	// ʵ�ʳɱ�����
	CC_SYNTHESIZE(double, realCost, RealCost);
	
	// ʵ������
	CC_SYNTHESIZE(double, realManMonth, RealManMonth);
	
	// ��������
	CC_SYNTHESIZE(string, belongRegion, BelongRegion);
	
	// ���Ÿ�����ID
	CC_SYNTHESIZE(string, pimPersonId, PimPersonId);
	
	// ��ĿID
	CC_SYNTHESIZE(string, orgProjId, OrgProjId);
	
	// ��Ŀ��ID
	CC_SYNTHESIZE(string, proDepId, ProDepId);
	
	// ��Ŀ������ID
	CC_SYNTHESIZE(string, proLeaderId, ProLeaderId);
	
	// �ϼ�����
	CC_SYNTHESIZE(string, pOrgSectorId, POrgSectorId);
	
	// ��֯����ID
	CC_SYNTHESIZE(string, orgId, OrgId);
	
	// ���ߴ���
	CC_SYNTHESIZE(string, bizCode, BizCode);
	
	// �û�����
	CC_SYNTHESIZE(string, userData, Userdata);
	
	// �������
	CC_SYNTHESIZE(string, levelCode, LevelCode);
	
	// �û�����2
	CC_SYNTHESIZE(string, userdata2, Userdata2);
	
	// ��ע
	CC_SYNTHESIZE(string, memo, Memo);
	
	// ��֯����
	CC_SYNTHESIZE(string, orgName, OrgName);
	
	// �ϼ�����
	CC_SYNTHESIZE(string, pOrgSectorName, POrgSectorName);
	
	// �㱨��������
	CC_SYNTHESIZE(string, repOrgSectorName, RepOrgSectorName);
	
	// �㱨����ID
	CC_SYNTHESIZE(string, repOrgSectorId, RepOrgSectorId);

	// ����Ա��ʶ
	CC_SYNTHESIZE(string, pimPersonId, PimPersonId);

	// �������ñ�ʶ
	CC_SYNTHESIZE(string, attendenceSetUpId, AttendenceSetUpId);

public:
	SectorDO() {
		orgSectorId = "";
	}
	SectorDO(string secid) {
		orgSectorId = secid;
	}

};

#endif // !_SECTORDO_H_