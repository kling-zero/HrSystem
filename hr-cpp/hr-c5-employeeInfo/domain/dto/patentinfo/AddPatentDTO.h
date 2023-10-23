#pragma once


#ifndef _ADDPATENT_DTO_
#define _ADDPATENT_DTO_
#define DTO_INIT_(type, field, name) DTO_FIELD(type, field); \
DTO_FIELD_INFO(field) { \
	info->description = ZH_WORDS_GETTER(name); \
}

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ���ר����Ϣ�������
 */
class AddPatentDTO : public oatpp::DTO
{

public:
    AddPatentDTO() {};
    DTO_INIT(AddPatentDTO, DTO);

    //ZLH:ר����
    DTO_FIELD(String, zlh);
    DTO_FIELD_INFO(zlh) {
        info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.ZLH");
    }

    //PIMPATENTNAME : ר������
    DTO_FIELD(String, pimpatentname);
    DTO_FIELD_INFO(pimpatentname) {
        info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.PIMPATENTNAME");
    }

    //ZLHQSJ : ר����ȡʱ��
    DTO_FIELD(String, zlhqsj);
    DTO_FIELD_INFO(zlhqsj) {
        info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.ZLHQSJ");
    }

    //ZLPZGB : ר����׼����
    DTO_FIELD(String, zlpzgb);
    DTO_FIELD_INFO(zlpzgb) {
        info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.ZLPZGB");
    }

    //ENCLOLURE : ����
    DTO_FIELD(String, enclolure);
    DTO_FIELD_INFO(enclolure) {
        info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.ENCLOLURE");
    }

    ////����ʱ��
    //DTO_INIT_(String, creatdate, "patentInformation.pimpatent.CREATEDATE")

    ////����ʱ��
    //DTO_INIT_(String, updatedate, "patentInformation.pimpatent.UPDATEDATE")

    ////������
    //DTO_INIT_(String, createman, "patentInformation.pimpatent.CREATEMAN")

    ////����ʱ��
    //DTO_INIT_(String, updateman, "patentInformation.pimpatent.UPDATEMAN")

    //ר����Ϣ����
    DTO_INIT_(String, pimpatentid, "patentInformation.pimpatent.PIMPATENTID")
};


#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_
