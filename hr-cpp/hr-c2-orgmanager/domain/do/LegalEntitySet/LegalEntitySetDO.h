#pragma once
/*
��֯���� ������������ ���� ������������  -- cpt

�����������������б� `LegalEntitySetPullDownList`

����ָ������������Ϣ  `UpdateLegalerSettingMessage`

������������ `LegalEntitySet`

�����������ã�֧������������** `LegalEntitySet`
*/

#ifndef _LEGALENTITYSET_DO_
#define _LEGALENTITYSET_DO_
#include "../DoInclude.h"

class LegalEntitySetDO {
	public:
	// ǩԼ���嵥λ����
	CC_SYNTHESIZE(string, contractsignorgname, CONTRACTSIGNORGNAME);
	// ǩԼ���嵥λ��ʶ
	CC_SYNTHESIZE(string, contractsignorgid, CONTRACTSIGNORGID);
	// ������
	CC_SYNTHESIZE(string, updateman, UPDATEMAN);
	// ������
	CC_SYNTHESIZE(string, createman, CREATEMAN);
	// ����ʱ��
	CC_SYNTHESIZE(string, createdate, CREATEDATE);
	// ����ʱ��
	CC_SYNTHESIZE(string, updatedate, UPDATEDATE);
	// ����λ��ʶ
	CC_SYNTHESIZE(string, ormorgid, ORMORGID);
	// ���������ʶ
	CC_SYNTHESIZE(string, signorgid, SIGNORGID);
	// Ĭ��ǩԼ���� 
	CC_SYNTHESIZE(string, isdefaultsignorg, ISDEFAULTSIGNORG);
	// ���������ʶ 
	CC_SYNTHESIZE(string, ormsignorgid, ORMSIGNORGID);
	
	LegalEntitySetDO() {
		contractsignorgname = "";
		contractsignorgid = "";
		updateman = "";
		createman = "";
		createdate = "";
		updatedate = "";
		ormorgid = "";
		signorgid = "";
		isdefaultsignorg = "";  
		ormsignorgid = "";
	};

	/*Lecontractsignorgid, galEntitySetDO(std::vector<std::string> vec) {
		int i = 0;
		updateman, UPDATEMAsetORMSIGNORGNAME(vec[i++]);
		setCONTRACTSIGNORGNAME(vec[i++]);
		createman, CREATEMAsetISDEFAULTSIGNORG(vec[i++]);
	}*/
		
};
#endif // !_LEGALENTITYSET_DO_

		