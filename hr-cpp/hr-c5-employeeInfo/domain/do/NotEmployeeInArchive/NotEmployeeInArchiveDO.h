#pragma once
#ifndef _NOT_EMPLOYEE_IN_ARCHIVE_DO_
#define _NOT_EMPLOYEE_IN_ARCHIVE_DO_
#include "../DoInclude.h"

/**
 * ��Ա���ڵ�ʵ����
 */
class NotEmployeeInArchiveDO
{
	// �������
	CC_SYNTHESIZE(string, dabh, Dabh);
	// ����λ
	CC_SYNTHESIZE(string, gldw, Gldw);
	// ���ܵ�
	CC_SYNTHESIZE(string, bgd, Bgd);
	// ������
	CC_SYNTHESIZE(string, archivescentername, Archivescentername);
	//����״̬
	CC_SYNTHESIZE(string, dazt, Dazt);
	//Ա�����
	CC_SYNTHESIZE(string, ygbh, Ygbh);
	//Ա������
	CC_SYNTHESIZE(string, pimpersonname, Pimpersonname);
	//������λ
	CC_SYNTHESIZE(string, ormorgname, Ormorgname);
	//Ա��״̬
	CC_SYNTHESIZE(string, ygzt, Ygzt);

public:
	NotEmployeeInArchiveDO() {
		dabh = "";
		gldw = "";
		bgd = "";
		archivescentername = "";
		dazt = "";
		pimpersonname = "";
		ormorgname = "";
		ygzt = "";
	}
};

#endif // !_NOT_EMPLOYEE_IN_ARCHIVE_DO_