#pragma once
#ifndef _CERTIFICATETYPE_DO_
#define _CERTIFICATETYPE_DO_
#include "../DoInclude.h"
/**
 * ֤������DO--(֤�����-��ѯ֤������)--weixiaoman
 */
class CertificateTypeDO {
	//֤������
	CC_SYNTHESIZE(string, cerType, CerType);
	//Ψһ��ʶ
	CC_SYNTHESIZE(string, id, Id);
public:
	CertificateTypeDO() {
		cerType = "";
		id = "";
	}
};


#endif // !_CERTIFICATETYPE_DO_
