#pragma once
#ifndef _QUALIFICATIONDO_H_
#define _QUALIFICATIONDO_H_

#include "../DoInclude.h"
/**
 * ִҵ�ʸ�֤����Ϣʵ��
 */
class QualificationDO
{
	// ִҵ�ʸ�רҵ����
	CC_SYNTHESIZE(string, pimqualmajorid, pimQualMajorId);
	// ����
	CC_SYNTHESIZE(string, qualevel, quaLevel);
	// ִҵ�ʸ�
	CC_SYNTHESIZE(string, pimqualmajorname, pimQualMajorName);
	// רҵ
	CC_SYNTHESIZE(string, quamajor, quaMajor);
public:
	QualificationDO() 
	{ 
		pimqualmajorid = "";
		qualevel = "";
		pimqualmajorname = "";
		quamajor = "";
	}
	//�ֱ�Ϊִҵ�ʸ�רҵ���룬����ִҵ�ʸ�רҵ
	QualificationDO(string pimqualmajorid, string qualevel, string pimqualmajorname, string quamajor)
	{
		this->pimqualmajorid = pimqualmajorid;
		this->qualevel = qualevel;
		this->pimqualmajorname = pimqualmajorname;
		this->quamajor = quamajor;
	}
};

#endif