#pragma once
#ifndef _CERTIFICATEDO_H_
#define _CERTIFICATEDO_H_

#include "../DoInclude.h"
/**
 * ��λ����֤����Ϣʵ��
 */
class CertificateDO
{
	// �����
	CC_SYNTHESIZE(int32_t, seialno, seialNo);
	// ��λ����֤��
	CC_SYNTHESIZE(string, pimqualtypename, pimQualTypeName);
public:
	CertificateDO() 
	{
		seialno = 0;
		pimqualtypename = "";
	}
	//�ֱ�Ϊ����ţ���λ����֤��
	CertificateDO(int seialno, string pimqualtypename)
	{
		this->seialno = seialno;
		this->pimqualtypename = pimqualtypename;
	}
};

#endif