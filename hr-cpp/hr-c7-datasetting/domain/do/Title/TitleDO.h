#pragma once
#ifndef _TITLEDO_H_
#define _TITLEDO_H_

#include "../DoInclude.h"
/**
 * ְ��Ŀ¼��Ϣʵ��
 */
class TitleDO
{
	//�����
	CC_SYNTHESIZE(uint32_t, id, Id);
	//ְ�ƴ���
	CC_SYNTHESIZE(string, num, Num);
	//ְ��Ŀ¼����
	CC_SYNTHESIZE(string, name, Name);
	//ְ��Ŀ¼����
	CC_SYNTHESIZE(string, dtype, Dtype);
	//ְ������
	CC_SYNTHESIZE(string, Ttype, TTtype);

public:
	TitleDO() {
		id = 0;
		num = "";
		name = "";
		dtype = "";
		Ttype = "";
	}
	TitleDO(uint32_t Id, string Num, string Name, string Dtype, string TTtype)
	{
		this->id = Id;
		this->num = Num;
		this->name = Name;
		this->dtype = Dtype;
		this->Ttype = TTtype;
		// ����Ը�����Ҫ�����������
	}
};

#endif
