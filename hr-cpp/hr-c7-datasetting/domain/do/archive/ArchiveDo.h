#pragma once
#ifndef _ARCHIVEDO_H_
#define _ARCHIVEDO_H_

#include "../DoInclude.h"
/**
 * ��������Ϣʵ��
 */
class ArchiveDO
{
	// �����
	CC_SYNTHESIZE(int32_t, sortid, sortID);
	// ����������
	CC_SYNTHESIZE(string, archivename, archiveName);
	// ����
	CC_SYNTHESIZE(int32_t, cabinetnum, cabinetNum);
	// ����
	CC_SYNTHESIZE(int32_t, layernum, layerNum);
	// ���
	CC_SYNTHESIZE(int32_t, numid, numID);
public:
	ArchiveDO() {
	
		sortid = 0;
		archivename = "";
		cabinetnum = 0;
		layernum = 0;
		numid = 0;
	
	
	
	}
	//�ֱ�Ϊ����ţ����������ƣ����������������
	ArchiveDO(int sortid,string archivename ,int cabinetnum,int layernum,int numid)
	{
		this->sortid = sortid;
		this->archivename = archivename;
		this->cabinetnum = cabinetnum;
		this->layernum = layernum;
		this->numid = numid;
	}
};

#endif