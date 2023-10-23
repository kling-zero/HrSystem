#pragma once
#ifndef _T_ORMSIGNORGDO_H_
#define _T_ORMSIGNORGDO_H_

#include "../DoInclude.h"

/* ��������ά�����ݿ��t_ormsignorgʵ��--����֯����-��������-��������ά����--TripleGold */

class OrmsignorgDO
{
	// ���������ʶ
	CC_SYNTHESIZE(string, id, Id);
	// ������������
	CC_SYNTHESIZE(string, name, Name);
	// ��֯���
	CC_SYNTHESIZE(string, orgcode, Code);
	// ������
	CC_SYNTHESIZE(string, updateman, Updateman);
	// ������
	CC_SYNTHESIZE(string, createman, Createman);
	// ����ʱ��
	CC_SYNTHESIZE(string, createdate, CreateDate);
	// ����ʱ��
	CC_SYNTHESIZE(string, updatedate, Updatedate);
	// ���
	CC_SYNTHESIZE(string, shortForm, Zzjc);
public:
	OrmsignorgDO() {
		id = "";
		name = "";
		orgcode = "";
	}
	OrmsignorgDO(std::vector<std::string> vec)
	{
		int i = 0;
		setName(vec[i++]);
		setCode(vec[i++]);
	}
	/*OrmsignorgDO(string id, string updateman, string createman, string createdate,
		string name, string updatedate, string orgcode, string shortForm) {
		this->id = id;
		this->updateman = updateman;
		this->createman = createman;
		this->createdate = createdate;
		this->name = name;
		this->updatedate = updatedate;
		this->orgcode = orgcode;
		this->shortForm = shortForm;
	}*/
};
#endif // !_T_ORMSIGNORGDO_H_