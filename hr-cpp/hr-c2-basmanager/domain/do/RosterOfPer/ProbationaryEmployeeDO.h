#pragma once
/**
 * ��Ա������ - ������Ա���ݿ�ʵ��ʵ�� - ������
 */

#ifndef _PROBATIONARY_EMPLOYEE_DO_H_
#define _PROBATIONARY_EMPLOYEE_DO_H_

#include "../DoInclude.h"

/* ����Ա�����ݿ�ʵ�� */
/* ���ݱ�t_pimperson  t_pcmsgqmgr */
class ProbationaryEmployeeDO
{	
	
	// Ա�����
	CC_SYNTHESIZE(string, YGBH, YGBH);
	// Ա������
	CC_SYNTHESIZE(string, PIMPERSONNAME, PIMPERSONNAME);
	// ��֯
	CC_SYNTHESIZE(string, ORMORGNAME, ORMORGNAME);
	// ����
	CC_SYNTHESIZE(string, ORMORGSECTORNAME, ORMORGSECTORNAME);
	// ְ��
	CC_SYNTHESIZE(string, ZW, ZW);
	// ��λ
	CC_SYNTHESIZE(string, ORMPOSTNAME, ORMPOSTNAME);
	// ��ְʱ��
	CC_SYNTHESIZE(string, RZSJ, RZSJ);
	// ���õ���ʱ�� 
	CC_SYNTHESIZE(string, SYDQ, SYDQ);
	// ����Ϊ��ѯʹ�ã���ǰ�˴���
	// ��Ա��Ϣ��ʶ  REFERENCES `t_pimperson`
	CC_SYNTHESIZE(string, pimPersonId, pimPersonId);
	// �Ը��ڹ����ʶ PRIMARY KEY
	CC_SYNTHESIZE(string, PCMSGQMGRID, PCMSGQMGRID);

public:
	ProbationaryEmployeeDO() {};
	// �вι��캯��
	ProbationaryEmployeeDO(string id, string name, string zz, string bm, string zw, string gw, string rzsj, string time)
		: YGBH(id)
		, PIMPERSONNAME(name)
		, ORMORGNAME(zz)
		, ORMORGSECTORNAME(bm)
		, ZW(zw)
		, ORMPOSTNAME(gw)
		, RZSJ(rzsj)
		, SYDQ(time)
		, pimPersonId(pimPersonId)
		, PCMSGQMGRID(PCMSGQMGRID)
	{}
	std::vector<std::string> ProbationaryEmployeetoVector()
	{
		std::vector<std::string> vec{this->getYGBH(), this->getPIMPERSONNAME(), this->getORMORGNAME(),\
			this->getORMORGSECTORNAME(), this->getZW(), this->getORMPOSTNAME(), this->getRZSJ(),\
			this->getSYDQ()};
		return vec;
	}
};

#endif 