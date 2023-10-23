#pragma once
#ifndef _J_PATENTINFO_DO_
#define _J_PATENTINFO_DO_
#include "../DoInclude.h"

/**
 * ר�����ݿ�ʵ����
 */
class J_PatentinfoDO
{
    //ZLH:ר����
    CC_SYNTHESIZE(string, zlh, ZLH);
    //UPDATEDATE : ����ʱ��
    CC_SYNTHESIZE(string, updatedate, UPDATEDATE);
    //PIMPATENTID : ר����Ϣ����
    CC_SYNTHESIZE(string, pimpatentid, PIMPATENTID);
    //ZLHQSJ : ר����ȡʱ��
    CC_SYNTHESIZE(string, zlhqsj, ZLHQSJ);
	//ENABLE : 
	CC_SYNTHESIZE(string, enable, ENABLE);
    //PIMPATENTNAME : ר������
    CC_SYNTHESIZE(string, pimpatentname, PIMPATENTNAME);
    //UPDATEMAN : ������
    CC_SYNTHESIZE(string, updateman, UPDATEMAN);
    //CREATEMAN : ������
    CC_SYNTHESIZE(string, createman, CREATEMAN);
    //CREATEDATE : ����ʱ��
    CC_SYNTHESIZE(string, createdate, CREATEDATE);
    //ZLPZGB : ר����׼����
    CC_SYNTHESIZE(string, zlpzgb, ZLPZGB);
    //PIMPERSONID : ��Ա��Ϣ��ʶ
    CC_SYNTHESIZE(string, pimpersonid, PIMPERSONID);
    //JLSS : ��¼����
    CC_SYNTHESIZE(string, jlss, JLSS);
    //JLSPZT : ����״̬
    CC_SYNTHESIZE(string, jlspzt, JLSPZT);
    //JLGLBH : ��¼������
    CC_SYNTHESIZE(string, jlglbh, JLGLBH);
    //JLCZZ : ��¼������
    CC_SYNTHESIZE(string, jlczz, JLCZZ);
    //ENCLOLURE : ����
    CC_SYNTHESIZE(string, enclolure, ENCLOLURE);
    //REASON : �ܾ�ԭ��
    CC_SYNTHESIZE(string, reason, REASON);




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
    J_PatentinfoDO() {

        zlh = "";
        updatedate = "";
        pimpatentid = "";
        zlhqsj = "";
		enable = "";
        pimpatentname = "";
        updateman = "";
        createman = "";
        createdate = "";
        zlpzgb = "";
        pimpersonid = "";
        jlss = "";
        jlspzt = "";
        jlglbh = "";
        jlczz = "";
        enclolure = "";
        reason = "";

		orgid = "";
		orgsectorid = "";
		ormorgid = "";
		ormorgsectorid = "";
		pimpersonname = "";
		ygbh = "";
    }
};

#endif // !_SAMPLE_DO_


