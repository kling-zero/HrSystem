#pragma once
#ifndef _TRAININGRECORDDO_H_
#define _TRAININGRECORDDO_H_
#include "../DoInclude.h"

class TrainingRecordDO {

	//��ѵ��Ա������ʶ
	CC_SYNTHESIZE(string, TRMTRIANPERSONID, _TRMTRIANPERSONID);
	//��ѵ�༶
	CC_SYNTHESIZE(string, PXBJ, _PXBJ);
	//��ѵ��ʼʱ��
	CC_SYNTHESIZE(string, TRAINBEGIN, _TRAINBEGIN);
	//��ѵ����ʱ��
	CC_SYNTHESIZE(string, TRAINEND, _TRAINEND);
	//��ѵ�γ�
	CC_SYNTHESIZE(string, PXKC, _PXKC);
	//��ѵ����
	CC_SYNTHESIZE(string, TRMTRAINAGENCYNAME, _TRMTRAINAGENCYNAME);
	//��ѵ���
	CC_SYNTHESIZE(string, TRAINRES, _TRAINRES);
	//����
	CC_SYNTHESIZE(string, FS, _FS);

};

#endif