#pragma once
#ifndef _SECONDED_PERSONNEL_DO_
#define _SECONDED_PERSONNEL_DO_
#include "../DoInclude.h"

/*
 ���Ա��DO--����Ա�����ᣩ--pine
 (��Ӧ���ݿ��t_pcmydjdmx���춯�����ϸ �� t_pcmydmx���춯��ϸ)
 */
class SecondedPersonnelDO
{
	// �����Ա��ʶ
	CC_SYNTHESIZE(string, PIMDISTIRBUTIONID, PIMDISTIRBUTIONID);
	// ��ź����� ģ����ѯ
	CC_SYNTHESIZE(string, idAndName, idAndName);
	// Ա�����
	CC_SYNTHESIZE(string, ygbh, ygbh);
	// Ա������
	CC_SYNTHESIZE(string, pimPersonName, pimPersonName);
	// ԭ��֯
	CC_SYNTHESIZE(string, zz, zz);
	// ԭ����
	CC_SYNTHESIZE(string, bm, bm);
	// ԭְ��
	CC_SYNTHESIZE(string, yzw, yzw);
	// ԭ��λ
	CC_SYNTHESIZE(string, ygw, ygw);
	// ����֯
	CC_SYNTHESIZE(string, ormName, ormName);
	// �²���
	CC_SYNTHESIZE(string, ormOrgSectorName, ormOrgSectorName);
	// ��ְ��
	CC_SYNTHESIZE(string, ormDutyName, ormDutyName);
	// �¸�λ
	CC_SYNTHESIZE(string, ormPostName, ormPostName);
	// ���״̬���춯�����ϸ��ʶ��
	CC_SYNTHESIZE(string, pcmydjdmxId, pcmydjdmxId);
	//�����ʼʱ��
	CC_SYNTHESIZE(string, jdksrq, jdksrq);
	//�������ʱ��
	CC_SYNTHESIZE(string, jdjsrq, jdjsrq);

public:
	SecondedPersonnelDO() {
		PIMDISTIRBUTIONID = "";
		idAndName = "";
		ygbh = "";
		pimPersonName = "";
		zz = "";
		bm = "";
		yzw = "";
		ygw = "";
		ormName = "";
		ormOrgSectorName = "";
		ormDutyName = "";
		ormPostName = "";
		pcmydjdmxId = "";
		jdksrq = "";
		jdjsrq = "";
	}
};

#endif // !_SAMPLE_DO_
