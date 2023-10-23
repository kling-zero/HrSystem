#pragma once
#ifndef _PATENTINFO_DO_
#define _PATENTINFO_DO_
#include "../DoInclude.h"

/**
 * ר�����ݿ�ʵ����
 */
class PatentinfoDO
{
    //ZLH:ר����
    CC_SYNTHESIZE(string, zlh, ZLH);
    //UPDATEDATE : ����ʱ��
    CC_SYNTHESIZE(string, updatedate, UPDATEDATE);
    //PIMPATENTID : ר����Ϣ����
    CC_SYNTHESIZE(string, pimpatentid, PIMPATENTID);
    //ZLHQSJ : ר����ȡʱ��
    CC_SYNTHESIZE(string, zlhqsj, ZLHQSJ);
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
public:
    PatentinfoDO() {

        zlh = "";
        updatedate = "";
        pimpatentid = "";
        zlhqsj = "";
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
    }
};

#endif // !_SAMPLE_DO_

