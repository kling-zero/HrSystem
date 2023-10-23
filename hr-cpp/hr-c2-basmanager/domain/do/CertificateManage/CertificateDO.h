#pragma once

#ifndef _CERTIFICATE_DO_
#define _CERTIFICATE_DO_
#include "../DoInclude.h"

class CertificateDO
{
	/**
	 * ֤��������ݿ�ʵ����
	 */
	 // Ա��������Ϣ��ID,ͬԱ��ID
	CC_SYNTHESIZE(string, ygbh, Ygbh);
	// ֤������Ա������ģ�����ң�
	CC_SYNTHESIZE(string, nameOfPAndV, NameOfPAndV);
	// ����
	CC_SYNTHESIZE(string, pimperSonName, PimperSonName);
	// Ա��״̬ 
	CC_SYNTHESIZE(string, ygzt, Ygzt);
	// ��֯   t_srforg ��Ҫ���������ȡ��֯����
	CC_SYNTHESIZE(string, zz, ZZ);
	// ֤��Ψһ��ʶ
	CC_SYNTHESIZE(string, pimvocationalid, Pimvocationalid);
	// һ������B֤���
	CC_SYNTHESIZE(string, bcardNumber, BcardNumber);
	// ֤������
	CC_SYNTHESIZE(string, pimVocationalName, PimVocationalName);
	// ֤������
	CC_SYNTHESIZE(string, zslx, Zslx);
	// ǩ������
	CC_SYNTHESIZE(string, zghqrq, Zghqrq);
	// ǩ������
	CC_SYNTHESIZE(string, zgsydw, Zgsydw);
	// ע�ᵥλ
	CC_SYNTHESIZE(string, zcdw, Zcdw);
	// ��֤��Ч��
	CC_SYNTHESIZE(string, fzyxq, Fzyxq);
	// ʧЧ����
	CC_SYNTHESIZE(string, sxrq, Sxrq);
	/*�½�֤�����������ֶ�*/
	//�������
	CC_SYNTHESIZE(string, nsqk, NSQK);
	// ʹ�����
	CC_SYNTHESIZE(string, syqk, SYQK);
	// ������
	CC_SYNTHESIZE(string, alteration, ALTERATION);

	//Ա��Ψһ��ʶ
	CC_SYNTHESIZE(string, pimpersonid, PIMPERSONID);
	//֤����
	CC_SYNTHESIZE(string, zgzsbh, ZGZSBH);
	//ע����
	CC_SYNTHESIZE(string, regisnumber, REGISNUMBER);
	//�籣���ɵ�λ
	CC_SYNTHESIZE(string, socsecpayunit, SOCSECPAYUNIT);
	//��ʼע��ʱ��
	CC_SYNTHESIZE(string, cszcsj, CSZCSJ);
	// ��ע��ʱ��
	CC_SYNTHESIZE(string, xzcsj, XZCSJ);

	// ֤��ʣ������ ����û��
	//////////////////////////////////////////////////////////////
	// ����Ϊ��ǰ����ʾ�ֶ�
	// ��Ա��Ϣ��ʶ FOREIGN KEY (`PIMPERSONID`) REFERENCES `t_pimperson` (`PIMPERSONID`),
	CC_SYNTHESIZE(string, pimPersonID, pimPersonID);
	// ��֯��ʶ FOREIGN KEY (`ORMORGID`) REFERENCES `t_srforg` (`ORGID`),
	CC_SYNTHESIZE(string, ORMORGID, ORMORGID);


public:
	CertificateDO() {
		ygbh = "";
		nameOfPAndV = "";
		pimperSonName = "";
		ygzt = "";
		zz = "";
		pimvocationalid = "";
		bcardNumber = "";
		pimVocationalName = "";
		zslx = "";
		zghqrq = "";
		zgsydw = "";
		zcdw = "";
		fzyxq = "";
		sxrq = "";

		pimpersonid = "";
		zgzsbh = "";
		regisnumber = "";
		socsecpayunit = "";
		cszcsj = "";
		xzcsj = "";

	}
};

#endif // !_FPRMERRMPLOYEES_DO_