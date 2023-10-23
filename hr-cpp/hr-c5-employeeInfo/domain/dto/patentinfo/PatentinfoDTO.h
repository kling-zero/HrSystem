#pragma once


#ifndef _SAMPLE_DTO_
#define _SAMPLE_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ר����Ϣ�������
 */
class PatentinfoDTO : public oatpp::DTO
{

public:
    PatentinfoDTO() {};
    PatentinfoDTO(String ZLH, String PIMPATENTNAME) :zlh(zlh), pimpatentname(pimpatentname) {};

    DTO_INIT(PatentinfoDTO, DTO);
    //ZLH:ר����
    DTO_FIELD(String, zlh);
    DTO_FIELD_INFO(zlh) {
        info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.ZLH");
    }

    //UPDATEDATE : ����ʱ��
    DTO_FIELD(String, UPDATEDATE);
    DTO_FIELD_INFO(UPDATEDATE) {
        info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.UPDATEDATE");
    }

    //PIMPATENTID : ר����Ϣ����
    DTO_FIELD(String, PIMPATENTID);
    DTO_FIELD_INFO(PIMPATENTID) {
        info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.PIMPATENTID");
    }

    //ZLHQSJ : ר����ȡʱ��
    DTO_FIELD(String, zlhqsj);
    DTO_FIELD_INFO(zlhqsj) {
        info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.ZLHQSJ");
    }
    
    //PIMPATENTNAME : ר������
    DTO_FIELD(String, pimpatentname);
    DTO_FIELD_INFO(pimpatentname) {
        info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.PIMPATENTNAME");
    }

    //UPDATEMAN : ������
    DTO_FIELD(String, UPDATEMAN);
    DTO_FIELD_INFO(UPDATEMAN) {
        info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.UPDATEMAN");
    }
    
    //CREATEMAN : ������
    DTO_FIELD(String, CREATEMAN);
    DTO_FIELD_INFO(CREATEMAN) {
        info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.CREATEMAN");
    }
    
    //CREATEDATE : ����ʱ��
    DTO_FIELD(String, CREATEDATE);
    DTO_FIELD_INFO(CREATEDATE) {
        info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.CREATEDATE");
    }
    
    //ZLPZGB : ר����׼����
    DTO_FIELD(String, ZLPZGB);
    DTO_FIELD_INFO(ZLPZGB) {
        info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.ZLPZGB");
    }
    
    //PIMPERSONID : ��Ա��Ϣ��ʶ
    DTO_FIELD(String, PIMPERSONID);
    DTO_FIELD_INFO(PIMPERSONID) {
        info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.PIMPERSONID");
    }
    
    //JLSS : ��¼����
    DTO_FIELD(String, JLSS);
    DTO_FIELD_INFO(JLSS) {
        info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.JLSS");
    }
    
    //JLSPZT : ����״̬
    DTO_FIELD(String, JLSPZT);
    DTO_FIELD_INFO(JLSPZT) {
        info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.JLSPZT");
    }
    
    //JLGLBH : ��¼������
    DTO_FIELD(String, JLGLBH);
    DTO_FIELD_INFO(JLGLBH) {
        info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.JLGLBH");
    }
    
    //JLCZZ : ��¼������
    DTO_FIELD(String, JLCZZ);
    DTO_FIELD_INFO(JLCZZ) {
        info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.JLCZZ");
    }
    
    //ENCLOLURE : ����
    DTO_FIELD(String, enclolure);
    DTO_FIELD_INFO(enclolure) {
        info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.ENCLOLURE");
    }
    
    //REASON : �ܾ�ԭ��
    DTO_FIELD(String, REASON);
    DTO_FIELD_INFO(REASON) {
        info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.REASON");
    }

};

/**
 * ��ҳ�������
 */
class PatentinfoPageDTO : public PageDTO<PatentinfoDTO::Wrapper>
{
    DTO_INIT(PatentinfoPageDTO, PageDTO<PatentinfoDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_
