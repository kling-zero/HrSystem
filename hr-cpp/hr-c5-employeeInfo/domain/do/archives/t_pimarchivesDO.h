#pragma once
#ifndef _ARCHIVES_DO_
#define _ARCHIVES_DO_
#include "../DoInclude.h"

/**
* ������Ϣʵ����
*/
class t_pimarchivesDO
{
	//������Ϣ��ʶ
	CC_SYNTHESIZE(string, pimArchivesId, PimArchivesId);
	// �������
	CC_SYNTHESIZE(string, dabh, Dabh);
	// ����λ
	CC_SYNTHESIZE(string, orgName, OrgName);
	// �������ܵ�
	CC_SYNTHESIZE(string, dabgd, Dabgd);
	// ������
	CC_SYNTHESIZE(string, archivesCenterName, ArchivesCenterName);
	// ����״̬
	CC_SYNTHESIZE(string, dazt, Dazt);
	// Ա�����
	CC_SYNTHESIZE(string, ygbh, Ygbh);
	// Ա������
	CC_SYNTHESIZE(string, pimPersonName, PimPersonName);
	// Ա��״̬
	CC_SYNTHESIZE(string, ygzt, Ygzt);
	// ������λ
	CC_SYNTHESIZE(string, ormOrgName, OrmOrgName);
	// ��������״̬
	CC_SYNTHESIZE(string, zt, Zt);
	//-------------��ϸ��ѯ����ʹ�õ��ֶ�----------------
	// ����ѧ��
	CC_SYNTHESIZE(string, education, Education);
	// ��������ʱ��
	CC_SYNTHESIZE(string, dateOfBirth, DateOfBirth);
	// �����뵳ʱ��
	CC_SYNTHESIZE(string, joinPartyDate, JoinPartyDate);
	// ��ӹ���ʱ��
	CC_SYNTHESIZE(string, startWorkDatae, StartWorkDatae);
	//-------------�����Ψһ��ʶ----------------
	// t_pimperson
	CC_SYNTHESIZE(string, pimPersonId, PimPersonId);
	// t_srforg
	CC_SYNTHESIZE(string, orMorGId3, OrMorGId3);
	// t_archivescenter
	CC_SYNTHESIZE(string, archivesCenterId, ArchivesCenterId);
public:
	t_pimarchivesDO() {
		pimArchivesId = "";
		dabh = "";
		orgName = "";
		dabgd = "";
		archivesCenterName = "";
		dazt = "";
		ygbh = "";
		pimPersonName = "";
		ygzt = "";
		ormOrgName = "";
		zt = "";
		education = "";
		dateOfBirth = "";
		joinPartyDate = "";
		startWorkDatae = "";
		pimPersonId = "";
		orMorGId3 = "";
		archivesCenterId = "";
	}
};
#endif // !_ARCHIVES_DO_
