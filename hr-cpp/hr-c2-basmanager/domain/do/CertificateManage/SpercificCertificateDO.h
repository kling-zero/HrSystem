#pragma once
/**
 *  �������� ���� ֤����� ���� ��ѯ������ָ��֤�� ���� ������
 */

#ifndef _SPERCIFIC_CERTIFICATE_DO_
#define _SPERCIFIC_CERTIFICATE_DO_
#include "../DoInclude.h"

class SpercificCertificateDO
{
	/**
	 * ָ��֤��������ݿ�ʵ����
	 */
	// ����
	CC_SYNTHESIZE(string, pimperSonName, PimperSonName);
	// ֤����
	CC_SYNTHESIZE(string, zgzsbh, Zgzsbh);
	// ֤������
	CC_SYNTHESIZE(string, zslx, Zslx);
	// ֤������
	CC_SYNTHESIZE(string, pimVocationalName, PimVocationalName);
	// ǩ������
	CC_SYNTHESIZE(string, zgsydw, Zgsydw);
	// ע����
	CC_SYNTHESIZE(string, REGISNUMBER, regisNumber)
	// ע�ᵥλ
	CC_SYNTHESIZE(string, zcdw, Zcdw);
	// �籣���ɵ�λ
	CC_SYNTHESIZE(string, SOCSECPAYUNIT, SOCSECPAYUNIT);
	// һ������B֤���
	CC_SYNTHESIZE(string, bcardNumber, BcardNumber);

	// ֤�������
	
	// ǩ������  required
	CC_SYNTHESIZE(string, zghqrq, Zghqrq); 
	// ��ʼע��ʱ��
	CC_SYNTHESIZE(string, CSZCSJ, CSZCSJ);
	// ��ע��ʱ��
	CC_SYNTHESIZE(string, XZCSJ, XZCSJ);
	// ʧЧ����
	CC_SYNTHESIZE(string, sxrq, Sxrq);
	// �������
	CC_SYNTHESIZE(string, NSQK, NSQK);
	// ʹ�����
	CC_SYNTHESIZE(string, SYQK, SYQK);
	// ������
	CC_SYNTHESIZE(string, ALTERATION, ALTERATION);

	//////////////////////////////////////////////////////////////
	// ����Ϊ��ǰ����ʾ�ֶ�
	// ִ��ְ��ҵ�ʸ���Ϣ��ʶ   PRIMARY KEY (`PIMVOCATIONALID`),
	CC_SYNTHESIZE(string, PIMVOCATIONALID, PIMVOCATIONALID);
	// ��Ա��Ϣ��ʶ FOREIGN KEY (`PIMPERSONID`) REFERENCES `t_pimperson` (`PIMPERSONID`),
	CC_SYNTHESIZE(string, pimPersonID, pimPersonID);
	// ��֯��ʶ FOREIGN KEY (`ORMORGID`) REFERENCES `t_srforg` (`ORGID`),
	CC_SYNTHESIZE(string, ORMORGID, ORMORGID);
	// ��λ�����ܣ�֤��Ŀ¼ID
	CC_SYNTHESIZE(string, PIMQUALTYPEID, PIMQUALTYPEID);
public:
	SpercificCertificateDO() {};

};

#endif // !_FPRMERRMPLOYEES_DO_