#pragma once

#ifndef _T_PIMPAPER_DO_
#define _T_PIMPAPER_DO_
#include "../DoInclude.h"

/**
 * ������Ϣʵ����
 */
class t_pimpaperDO
{
	// ����ʱ��
	CC_SYNTHESIZE(string, fbsj, Fbsj);
	// ������
	CC_SYNTHESIZE(string, cbs, Cbs);
	// ��������
	CC_SYNTHESIZE(int, kwqs, Kwqs);
	// ����
	CC_SYNTHESIZE(string, fj, Fj);
	// ���������������е�����
	CC_SYNTHESIZE(int, grzlwzzzdpm, Grzlwzzzdpm);
	// ��������
	CC_SYNTHESIZE(string, kwmc, Kwmc);
	// ��������
	CC_SYNTHESIZE(string, pimpapername, Pimpapername);
public:
	t_pimpaperDO() {
		fbsj = "";
		cbs = "";
		kwqs = 0;
		fj = "";
		grzlwzzzdpm = 0;
		kwmc = "";
		pimpapername = "";
	}
};

#endif 