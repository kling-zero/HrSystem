#pragma once
#include"stdafx.h"
#ifndef _ADDPIMARMYCADRESDO_H_
#define _ADDPIMARMYCADRESDO_H_

#include "../DoInclude.h"

class AddPimarmycadresDO {
	// ���
	CC_SYNTHESIZE(string, PIMID, pIMID);
	//	����
	CC_SYNTHESIZE(string, FORM, fORM);
	// ����
	CC_SYNTHESIZE(string, LEVEL, lEVEL);
	// ����ʱ��
	CC_SYNTHESIZE(string, OCCURTIME, oCCURTIME);
	//����·��
	CC_SYNTHESIZE(string, ANNEXPATH, aNNEXPATH);
	//��ת�ɲ���¼id
	CC_SYNTHESIZE(string, PIMARMYCADRESID,pIMARMYCADRESID);


	//������
	CC_SYNTHESIZE(std::string, CREATEMAN, cREATEMAN);

	//������
	CC_SYNTHESIZE(std::string, UPDATEMAN, uPDATEMAN);

	//����ʱ��
	CC_SYNTHESIZE(std::string, CREATEDATE, cREATEDATE);

	//����ʱ��
	CC_SYNTHESIZE(std::string, UPDATEDATE, uPDATEDATE);

	AddPimarmycadresDO() = default;

	AddPimarmycadresDO(std::vector<std::string> vec) {
		int i = 0;
		setfORM(vec[i++]);
		setlEVEL(vec[i++]);
		setoCCURTIME(vec[i++]);
		setaNNEXPATH(vec[i++]);
	}

};

#endif