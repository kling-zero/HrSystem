#pragma once
#ifndef _RRAINEE_DO_
#define _RRAINEE_DO_
#include "../DoInclude.h"
/**
 *  �������� ���� ��Ա������ ���� ��ϰԱ��ʵ����  ����Cpt
 */

class RraineeDO {
	// Ա�����
	CC_SYNTHESIZE(string, ygbh, Ygbh);
	// Ա������            
	CC_SYNTHESIZE(string, pcmjxszzkhjgjlname, Pcmjxszzkhjgjlname);
	// ��֯
	CC_SYNTHESIZE(string, zz, Zz);
	// ����
	CC_SYNTHESIZE(string, bm, Bm);
	// ְ��
	CC_SYNTHESIZE(string, zw, Zw);
	// ��λ
	CC_SYNTHESIZE(string, gw, Gw);
	// ��ϰ���ޣ��£�
	CC_SYNTHESIZE(string, duration, Duration);  
	// ������λʱ��
	CC_SYNTHESIZE(string, ksrq, Ksrq); 
	// ��ϰ����ʱ��
	CC_SYNTHESIZE(string, jsrq, Jsrq);  
public:
	RraineeDO() {
	
	}
};

#endif // !_RRAINEE_DO_
