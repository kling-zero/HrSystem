#pragma once


#ifndef _PIMARMYCADRESINTODO_H_
#define _PIMARMYCADRESINTODO_H_

#include "../DoInclude.h"

class PimarmycadresIntoDO {
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

	CC_SYNTHESIZE(string, PIMARMYCADRESID, pIMARMYCADRESID);



};

#endif