#pragma once
#pragma once
#ifndef _UPDATE_ARCHIVE_INFO_DO_
#define _UPDATE_ARCHIVE_INFO_DO_
#include "../DoInclude.h"

/**
 * ���µ���ʵ����
 */
class NotEmployeeInArchiveDO
{
	// �������
	CC_SYNTHESIZE(string, dabh, Dabh);
	// ����λ
	CC_SYNTHESIZE(string, gldw, Gldw);
	// �Ƿ��½���
	CC_SYNTHESIZE(string, sfxjd, sfxjd);
	// ���ܵ�
	CC_SYNTHESIZE(string, bgd, Bgd);
	// ������
	CC_SYNTHESIZE(string, archivescentername, Archivescentername);
	//Ա�����
	CC_SYNTHESIZE(string, ygbh, Ygbh);
	//Ա������
	CC_SYNTHESIZE(string, pimpersonname, Pimpersonname);
	//������λ
	CC_SYNTHESIZE(string, ormorgname, Ormorgname);
	//����ѧ��
	CC_SYNTHESIZE(string, education, Education);
	//������������
	CC_SYNTHESIZE(string, dateofbirth, dateofbirth);
	// �����뵳ʱ��
	CC_SYNTHESIZE(string, joinpartydate, Joinpartydate);
	// �����μӹ���ʱ��
	CC_SYNTHESIZE(string, startworkdate, startworkdate);
	// ����״̬
	CC_SYNTHESIZE(string, dastate, dastate);
	//��ע
	CC_SYNTHESIZE(string, bz, bz);
	//����
	CC_SYNTHESIZE(string, fj, fj);
public:
	NotEmployeeInArchiveDO() {
		dabh = "";
		gldw = "";
		sfxjd = "";
		bgd = "";
		archivescentername = "";
		ygbh = "";
		pimpersonname = "";
		ormorgname = "";
		education = "";
		dateofbirth = "";
		joinpartydate = "";
		startworkdate = "";
		dastate = "";
		bz = "";
		fj = "";
	}
};

#endif // !_UPDATE_ARCHIVE_INFO_DO_