#pragma once


#ifndef _J_PATENT_DTO_
#define _J_PATENT_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ר����Ϣ�������
 */
class J_PatentinfoDTO : public oatpp::DTO
{

public:
	J_PatentinfoDTO() {};
	J_PatentinfoDTO(String zlh, String pimpatentname) :zlh(zlh), pimpatentname(pimpatentname) {};

    DTO_INIT(J_PatentinfoDTO, DTO);

	//CREATEDATE : ����ʱ��
	DTO_FIELD(String, createdate);
	DTO_FIELD_INFO(createdate) {
		info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.createdate");
	}
	//CREATEMAN : ������
	DTO_FIELD(String, createman);
	DTO_FIELD_INFO(createman) {
		info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.createman");
	}
	//ENABLE : 
	DTO_FIELD(String, enable);
	DTO_FIELD_INFO(enable) {
		info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.enable");
	}
	//ENCLOLURE : ����
	DTO_FIELD(String, enclolure);
	DTO_FIELD_INFO(enclolure) {
		info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.enclolure");
	}
	//JLCZZ : ��¼������
	DTO_FIELD(String, jlczz);
	DTO_FIELD_INFO(jlczz) {
		info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.jlczz");
	}
	//JLGLBH : ��¼������
	DTO_FIELD(String, jlglbh);
	DTO_FIELD_INFO(jlglbh) {
		info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.jlglbh");
	}
	//JLSPZT : ����״̬
	DTO_FIELD(String, jlspzt);
	DTO_FIELD_INFO(jlspzt) {
		info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.jlspzt");
	}
	//JLSS : ��¼����
	DTO_FIELD(String, jlss);
	DTO_FIELD_INFO(jlss) {
		info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.jlss");
	}
	//ORGID : ��֯��ʶ1
	DTO_FIELD(String, orgid);
	DTO_FIELD_INFO(orgid) {
		info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.orgid");
	}
	//ORGSECTORID : ���ű�ʶ1
	DTO_FIELD(String, orgsectorid);
	DTO_FIELD_INFO(orgsectorid) {
		info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.orgsectorid");
	}
	//ORMORGID : ��֯��ʶ2
	DTO_FIELD(String, ormorgid);
	DTO_FIELD_INFO(ormorgid) {
		info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.ormorgid");
	}
	//ORMORGSECTORID : ���ű�ʶ2
	DTO_FIELD(String, ormorgsectorid);
	DTO_FIELD_INFO(ormorgsectorid) {
		info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.ormorgsectorid");
	}
	//PIMPATENTID : ר����Ϣ����
	DTO_FIELD(String, pimpatentid);
	DTO_FIELD_INFO(pimpatentid) {
		info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.pimpatentid");
	}
	//PIMPATENTNAME : ר������
	DTO_FIELD(String, pimpatentname);
	DTO_FIELD_INFO(pimpatentname) {
		info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.pimpatentname");
	}
	//PIMPERSONID : ��Ա��Ϣ��ʶ
	DTO_FIELD(String, pimpersonid);
	DTO_FIELD_INFO(pimpersonid) {
		info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.pimpersonid");
	}
	//PIMPERSONNAME : Ա������
	DTO_FIELD(String, pimpersonname);
	DTO_FIELD_INFO(pimpersonname) {
		info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.pimpersonname");
	}
	//REASON : �ܾ�ԭ��
	DTO_FIELD(String, reason);
	DTO_FIELD_INFO(reason) {
		info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.reason");
	}
	//UPDATEDATE : ����ʱ��
	DTO_FIELD(String, updatedate);
	DTO_FIELD_INFO(updatedate) {
		info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.updatedate");
	}
	//UPDATEMAN : ������
	DTO_FIELD(String, updateman);
	DTO_FIELD_INFO(updateman) {
		info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.updateman");
	}
	//YGBH : Ա�����
	DTO_FIELD(String, ygbh);
	DTO_FIELD_INFO(ygbh) {
		info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.ygbh");
	}
	//ZLH:ר����
	DTO_FIELD(String, zlh);
	DTO_FIELD_INFO(zlh) {
		info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.zlh");
	}
	//ZLHQSJ : ר����ȡʱ��
	DTO_FIELD(String, zlhqsj);
	DTO_FIELD_INFO(zlhqsj) {
		info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.zlhqsj");
	}
	//ZLPZGB : ר����׼����
	DTO_FIELD(String, zlpzgb);
	DTO_FIELD_INFO(zlpzgb) {
		info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.zlpzgb");
	}

};

/**
 * �޸�ר����Ϣ�������
 */
	class ModifyPatentinfoDTO : public oatpp::DTO
{

public:

	DTO_INIT(ModifyPatentinfoDTO, DTO);

	//PIMPATENTID : ר����Ϣ����
	DTO_FIELD(String, pimpatentid);
	DTO_FIELD_INFO(pimpatentid) {
		info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.pimpatentid");
	}
	//ZLH:ר����
	DTO_FIELD(String, zlh);
	DTO_FIELD_INFO(zlh) {
		info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.zlh");
	}
	//PIMPATENTNAME : ר������
	DTO_FIELD(String, pimpatentname);
	DTO_FIELD_INFO(pimpatentname) {
		info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.pimpatentname");
	}
	//ZLHQSJ : ר����ȡʱ��
	DTO_FIELD(String, zlhqsj);
	DTO_FIELD_INFO(zlhqsj) {
		info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.zlhqsj");
	}
	//ZLPZGB : ר����׼����
	DTO_FIELD(String, zlpzgb);
	DTO_FIELD_INFO(zlpzgb) {
		info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.zlpzgb");
	}
	//ENCLOLURE : ����
	DTO_FIELD(String, enclolure);
	DTO_FIELD_INFO(enclolure) {
		info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.enclolure");
	}
	//UPDATEDATE : ����ʱ��
	DTO_FIELD(String, updatedate);
	DTO_FIELD_INFO(updatedate) {
		info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.updatedate");
	}
	//UPDATEMAN : ������
	DTO_FIELD(String, updateman);
	DTO_FIELD_INFO(updateman) {
		info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.updateman");
	}

};







/**
 * ��ҳ�������
 */
class J_PatentinfoPageDTO : public PageDTO<J_PatentinfoDTO::Wrapper>
{
    DTO_INIT(J_PatentinfoPageDTO, PageDTO<J_PatentinfoDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_
