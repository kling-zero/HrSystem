#pragma once
#ifndef _J_PAPERINFO_DO_
#define _J_PAPERINFO_DO_
#include "../DoInclude.h"

/**
 * ר�����ݿ�ʵ����
 */
class J_PaperinfoDO
{
    //GRZLWZZZDPM:���������������е�����
    CC_SYNTHESIZE(string, grzlwzzzdpm, GRZLWZZZDPM);
	//UPDATEMAN:������
	CC_SYNTHESIZE(string, updateman, UPDATEMAN);
	//PIMPAPERID:������Ϣ��ʶ
	CC_SYNTHESIZE(string, pimpaperid, PIMPAPERID);
	//CREATEDATE:����ʱ��
	CC_SYNTHESIZE(string, createdate, CREATEDATE);
	//UPDATEDATE:����ʱ��
	CC_SYNTHESIZE(string, updatedate, UPDATEDATE);
	//CREATEMAN:������
	CC_SYNTHESIZE(string, createman, CREATEMAN);
	//FBSJ:����ʱ��
	CC_SYNTHESIZE(string, fbsj, FBSJ);
	//PIMPAPERNAME:��������
	CC_SYNTHESIZE(string, pimpapername, PIMPAPERNAME);
	//CBSHKWMC:�������������
	CC_SYNTHESIZE(string, cbshkwmc, CBSHKWMC);
	//PIMPERSONID:��Ա��Ϣ��ʶ
	CC_SYNTHESIZE(string, pimpersonid, PIMPERSONID);
	//FJ:����
	CC_SYNTHESIZE(string, fj, FJ);
	//JLSPZT:����״̬
	CC_SYNTHESIZE(string, jlspzt, JLSPZT);
	//JLGLBH:��¼������
	CC_SYNTHESIZE(string, jlglbh, JLGLBH);
	//JLCZZ:��¼������
	CC_SYNTHESIZE(string, jlczz, JLCZZ);
	//JLSS:��¼����
	CC_SYNTHESIZE(string, jlss, JLSS);
	//CBS:������
	CC_SYNTHESIZE(string, cbs, CBS);
	//KWMC:��������
	CC_SYNTHESIZE(string, kwmc, KWMC);
	//KWQS:��������
	CC_SYNTHESIZE(string, kwqs, KWQS);
	//REASON:�ܾ�ԭ��
	CC_SYNTHESIZE(string, reason, REASON);

	//ENABLE : 
	CC_SYNTHESIZE(string, enable, ENABLE);
	//ORGID : ��֯��ʶ1
	CC_SYNTHESIZE(string, orgid, ORGID);
	//ORGSECTORID : ���ű�ʶ1
	CC_SYNTHESIZE(string, orgsectorid, ORGSECTORID);
	//ORMORGID : ��֯��ʶ2
	CC_SYNTHESIZE(string, ormorgid, ORMORGID);
	//ORMORGSECTORID : ���ű�ʶ2
	CC_SYNTHESIZE(string, ormorgsectorid, ORMORGSECTORID);
	//PIMPERSONNAME : Ա������
	CC_SYNTHESIZE(string, pimpersonname, PIMPERSONNAME);
	//YGBH : Ա�����
	CC_SYNTHESIZE(string, ygbh, YGBH);


public:
	J_PaperinfoDO() {

		grzlwzzzdpm = "";
		updateman = "";
		pimpaperid = "";
		createdate = "";
		updatedate = "";
		createman = "";
		fbsj = "";
		pimpapername = "";
		cbshkwmc = "";
		pimpersonid = "";
		fj = "";
		jlspzt = "";
		jlglbh = "";
		jlczz = "";
		jlss = "";
		cbs = "";
		kwmc = "";
		kwqs = "";
		reason = "";
 
		enable = "";
		orgid = "";
		orgsectorid = "";
		ormorgid = "";
		ormorgsectorid = "";
		pimpersonname = "";
		ygbh = "";

    }
};

#endif // !_SAMPLE_DO_


