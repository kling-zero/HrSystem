//2023��5��23��
//��ͬ��������б��DO
//���ߣ���Ƥ�����
#pragma once
#ifndef _PRIM_TYPE_DO_
#define _PRIM_TYPE_DO_
#include "../DoInclude.h"

class PimTypeDO 
{
	CC_SYNTHESIZE(string, createDate, CreateDate);
	CC_SYNTHESIZE(string, pimcontractID, PimContractIdentity);
	CC_SYNTHESIZE(string, pimcontractName, PimContractName);
	CC_SYNTHESIZE(string, createrName, CreaterName);
	CC_SYNTHESIZE(string, updaterName, UpdaterName);
	CC_SYNTHESIZE(string, updateDate, UpdateDate);
	CC_SYNTHESIZE(string, typeCode, TypeCode);
	CC_SYNTHESIZE(string, type, pimType);
	CC_SYNTHESIZE(string, ormorgID, OrmorgID);
public:
	PimTypeDO() {
		createDate = "����ʱ��";
		pimcontractID = "��ͬ���ͱ�ʶ";
		pimcontractName = "��ͬ��������";
		createrName = "������";
		updaterName = "������";
		updateDate = "����ʱ��";
		typeCode = "��ͬ���ʹ���";
		type = "����";
		ormorgID = "��֯��ʶ";
	}
};


#endif // !_PRIM_TYPE_DO_
