//2023��5��23��
//�����������ܵ�DO
//���ߣ���Ƥ�����
#pragma once
#ifndef _PIM_ARCHIVES_DO_
#define _PIM_ARCHIVES_DO_
#include "../DoInclude.h"
class PimArchivesDO
{
	CC_SYNTHESIZE(string, pimarchivesID, PimArchivesID);
	CC_SYNTHESIZE(string, pimarchivesName, PimArchivesName);
	CC_SYNTHESIZE(string, updateDate, UpdateDate);
	CC_SYNTHESIZE(string, creatorName, CreateName);
	CC_SYNTHESIZE(string, createDate, CreateDate);
	CC_SYNTHESIZE(string, updaterName, UpdaterName);
	CC_SYNTHESIZE(string, archivesNo, ArchivesNo);
	CC_SYNTHESIZE(string, archivesState, ArchivesState);
	CC_SYNTHESIZE(string, archivesAddr, ArchivesAddr);
	CC_SYNTHESIZE(string, dispatchDate, DispatchDate);
	CC_SYNTHESIZE(string, dispatchOutDate, DispatchOutDate);
	CC_SYNTHESIZE(string, dispatchInAddr, DispatchInAddr);
	CC_SYNTHESIZE(string, dispatchOutAddr, DispatchOutAddr);
	CC_SYNTHESIZE(string, saveNo, SaveNo);
	CC_SYNTHESIZE(string, note, Note);
	CC_SYNTHESIZE(string, pimpersonID, PimPersonID);
	CC_SYNTHESIZE(string, ormorgID, OrmorgID);
	CC_SYNTHESIZE(string, ormorgID2, OrmorgID2);
	CC_SYNTHESIZE(string, attachment, Attachment);
	CC_SYNTHESIZE(string, dateOfBirth, DateOfBirth);
	CC_SYNTHESIZE(string, startWorkDate, StartWorkDate);
	CC_SYNTHESIZE(string, joinPartyDate, JoinPartyDate);
	CC_SYNTHESIZE(string, education, Education);
	CC_SYNTHESIZE(string, damu, DAMU);
	CC_SYNTHESIZE(string, custodyNow, CustodyNow);
	CC_SYNTHESIZE(string, ormorgID3, OrmorgID3);
	CC_SYNTHESIZE(string, ormorgName, OrmorgName);
	CC_SYNTHESIZE(string, state, State);
	CC_SYNTHESIZE(string, archivesCenterID, ArchivesCenterID);
	CC_SYNTHESIZE(string, operattions, Operattions);
	CC_SYNTHESIZE(string, operattionsDate, OperattionsDate);
	CC_SYNTHESIZE(string, transToOut, TransToOut);
	CC_SYNTHESIZE(string, ormorgName2, OrmorgName2);
	CC_SYNTHESIZE(string, source, Source);
	CC_SYNTHESIZE(string, save, Save);
	CC_SYNTHESIZE(string, archivesState, ArchivesState);
	CC_SYNTHESIZE(string, calloutArchives, CalloutArchives);
	CC_SYNTHESIZE(string, callinArchives, CallinArchives);
public:
	PimArchivesDO() {
		pimarchivesID = "������Ϣ��ʶ";
		pimarchivesName = "������Ϣ����";
		updateDate = "����ʱ��";
		creatorName = "������";
		createDate = "����ʱ��";
		updaterName = "������";
		archivesNo = "�������";
		archivesState = "����״̬";
		archivesAddr = "�������ܵ�";
		dispatchDate = "������������";
		dispatchOutDate = "������������";
		dispatchInAddr = "�������뵥λ";
		dispatchOutAddr = "����������λ";
		saveNo = "��Ź��";
		note = "��ע";
		pimpersonID = "Ա��";
		ormorgID = "��֯��ʶ";
		ormorgID2 = "�ֵ������ܵ�λ��ʶ";
		attachment = "����";
		dateOfBirth = "������������";
		startWorkDate = "�����μӹ���ʱ��";
		joinPartyDate = "�����뵳ʱ��";
		education = "����ѧ��";
		damu = "����Ŀ¼";
		custodyNow = "�ֵ������ܵ�λ";
		ormorgID3 = "����λ";
		ormorgName = "������λ";
		state = "��������״̬";
		archivesCenterID = "�����ҹ����ʶ";
		operattions = "��������";
		operattionsDate = "����ʱ��";
		transToOut = "���������ⵥλ��";
		ormorgName2 = "������λ";
		source = "������Դ��";
		save = "�������ܵ�";
		archivesState = "����״̬";
		calloutArchives = "��������";
		callinArchives = "���뵵��";
	}
};


#endif // !_PIM_ARCHIVES_DO_
