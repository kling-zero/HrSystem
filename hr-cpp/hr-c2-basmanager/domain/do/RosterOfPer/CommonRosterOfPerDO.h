#pragma once
#ifndef _COMMONROSTEROFPER_DO_
#define _COMMONROSTEROFPER_DO_
#include "../DoInclude.h"

/**
 * ��Ա�����ṫ��DO--(��Ա������)--luoluo
 */
class CommonRosterOfPerDO
{
	// ��ְ��ϢID���������������������
	CC_SYNTHESIZE(uint64_t, leavingAnalysis_ID, leavingAnalysis_ID);
	// Ա��������Ϣ��ID,ͬԱ��ID
	CC_SYNTHESIZE(uint64_t, pimperSonName, pimperSonName);
	//Ա������
	CC_SYNTHESIZE(string, name, name);
	// �Ա�
	CC_SYNTHESIZE(string, sex, sex);
	// ����
	CC_SYNTHESIZE(string, nj, nj);
	//Ա����š�����
	CC_SYNTHESIZE(string, ygbh, ygbh);
	// ��֯
	CC_SYNTHESIZE(string, organizationName, organizationName);
	// ����
	CC_SYNTHESIZE(string, bm, bm);
	// ְ��
	CC_SYNTHESIZE(string, rank, rank);
	// ��λ
	CC_SYNTHESIZE(string, gw, gw);
	//�ֻ�����
	CC_SYNTHESIZE(string, lxdh, lxdh);
	// ��ͥ��ϵ��
	CC_SYNTHESIZE(string, jtlxr, jtlxr);
	// ��ͥ��ϵ�˵绰
	CC_SYNTHESIZE(string, jtlxrdh, jtlxrdh);
	
public:
	CommonRosterOfPerDO() {
		
	}
};

#endif // !_COMMONROSTEROFPER_DO_
