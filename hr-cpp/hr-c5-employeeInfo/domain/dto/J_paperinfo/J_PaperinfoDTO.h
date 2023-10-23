#pragma once


#ifndef _J_PAPERINFO_DTO_
#define _J_PAPERINFO_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ������Ϣ�������
 */
class J_PaperinfoDTO : public oatpp::DTO
{

public:
	J_PaperinfoDTO() {};

    DTO_INIT(J_PaperinfoDTO, DTO);

	//CBS:������
	DTO_FIELD(String, cbs);
	DTO_FIELD_INFO(cbs) {
		info->description = ZH_WORDS_GETTER("paperInformation.pimpaper.cbs");
	}
	//CBSHKWMC:�������������
	DTO_FIELD(String, cbshkwmc);
	DTO_FIELD_INFO(cbshkwmc) {
		info->description = ZH_WORDS_GETTER("paperInformation.pimpaper.cbshkwmc");
	}
	//CREATEDATE:����ʱ��
	DTO_FIELD(String, createdate);
	DTO_FIELD_INFO(createdate) {
		info->description = ZH_WORDS_GETTER("paperInformation.pimpaper.createdate");
	}
	//CREATEMAN:������
	DTO_FIELD(String, createman);
	DTO_FIELD_INFO(createman) {
		info->description = ZH_WORDS_GETTER("paperInformation.pimpaper.createman");
	}
	//ENABLE
	DTO_FIELD(String, enable);
	DTO_FIELD_INFO(enable) {
		info->description = ZH_WORDS_GETTER("paperInformation.pimpaper.enable");
	}
	//FBSJ:����ʱ��
	DTO_FIELD(String, fbsj);
	DTO_FIELD_INFO(fbsj) {
		info->description = ZH_WORDS_GETTER("paperInformation.pimpaper.fbsj");
	}
	//FJ:����
	DTO_FIELD(String, fj);
	DTO_FIELD_INFO(fj) {
		info->description = ZH_WORDS_GETTER("paperInformation.pimpaper.fj");
	}
	//GRZLWZZZDPM:���������������е�����
	DTO_FIELD(String, grzlwzzzdpm);
	DTO_FIELD_INFO(grzlwzzzdpm) {
		info->description = ZH_WORDS_GETTER("paperInformation.pimpaper.grzlwzzzdpm");
	}
	//JLCZZ:��¼������
	DTO_FIELD(String, jlczz);
	DTO_FIELD_INFO(jlczz) {
		info->description = ZH_WORDS_GETTER("paperInformation.pimpaper.jlczz");
	}
	//JLGLBH:��¼������
	DTO_FIELD(String, jlglbh);
	DTO_FIELD_INFO(jlglbh) {
		info->description = ZH_WORDS_GETTER("paperInformation.pimpaper.jlglbh");
	}
	//JLSPZT:����״̬
	DTO_FIELD(String, jlspzt);
	DTO_FIELD_INFO(jlspzt) {
		info->description = ZH_WORDS_GETTER("paperInformation.pimpaper.jlspzt");
	}
	//JLSS:��¼����
	DTO_FIELD(String, jlss);
	DTO_FIELD_INFO(jlss) {
		info->description = ZH_WORDS_GETTER("paperInformation.pimpaper.jlss");
	}
	//KWMC:��������
	DTO_FIELD(String, kwmc);
	DTO_FIELD_INFO(kwmc) {
		info->description = ZH_WORDS_GETTER("paperInformation.pimpaper.kwmc");
	}
	//KWQS:��������
	DTO_FIELD(String, kwqs);
	DTO_FIELD_INFO(kwqs) {
		info->description = ZH_WORDS_GETTER("paperInformation.pimpaper.kwqs");
	}
	//ORGID:��֯��ʶ1
	DTO_FIELD(String, orgid);
	DTO_FIELD_INFO(orgid) {
		info->description = ZH_WORDS_GETTER("paperInformation.pimpaper.orgid");
	}
	//ORGSECTORID:���ű�ʶ1
	DTO_FIELD(String, orgsectorid);
	DTO_FIELD_INFO(orgsectorid) {
		info->description = ZH_WORDS_GETTER("paperInformation.pimpaper.orgsectorid");
	}
	//ORMORGID:��֯��ʶ2
	DTO_FIELD(String, ormorgid);
	DTO_FIELD_INFO(ormorgid) {
		info->description = ZH_WORDS_GETTER("paperInformation.pimpaper.ormorgid");
	}
	//ORMORGSECTORID:���ű�ʶ2
	DTO_FIELD(String, ormorgsectorid);
	DTO_FIELD_INFO(ormorgsectorid) {
		info->description = ZH_WORDS_GETTER("paperInformation.pimpaper.ormorgsectorid");
	}
	//PIMPAPERID:������Ϣ��ʶ
	DTO_FIELD(String, pimpaperid);
	DTO_FIELD_INFO(pimpaperid) {
		info->description = ZH_WORDS_GETTER("paperInformation.pimpaper.pimpaperid");
	}
	//PIMPAPERNAME:��������
	DTO_FIELD(String, pimpapername);
	DTO_FIELD_INFO(pimpapername) {
		info->description = ZH_WORDS_GETTER("paperInformation.pimpaper.pimpapername");
	}
	//PIMPERSONID:��Ա��Ϣ��ʶ
	DTO_FIELD(String, pimpersonid);
	DTO_FIELD_INFO(pimpersonid) {
		info->description = ZH_WORDS_GETTER("paperInformation.pimpaper.pimpersonid");
	}
	//PIMPERSONNAME:Ա������
	DTO_FIELD(String, pimpersonname);
	DTO_FIELD_INFO(pimpersonname) {
		info->description = ZH_WORDS_GETTER("paperInformation.pimpaper.pimpersonname");
	}
	//REASON:�ܾ�ԭ��
	DTO_FIELD(String, reason);
	DTO_FIELD_INFO(reason) {
		info->description = ZH_WORDS_GETTER("paperInformation.pimpaper.reason");
	}
	//UPDATEDATE:����ʱ��
	DTO_FIELD(String, updatedate);
	DTO_FIELD_INFO(updatedate) {
		info->description = ZH_WORDS_GETTER("paperInformation.pimpaper.updatedate");
	}
	//UPDATEMAN:������
	DTO_FIELD(String, updateman);
	DTO_FIELD_INFO(updateman) {
		info->description = ZH_WORDS_GETTER("paperInformation.pimpaper.updateman");
	}
	//YGBH:Ա�����
	DTO_FIELD(String, ygbh);
	DTO_FIELD_INFO(ygbh) {
		info->description = ZH_WORDS_GETTER("paperInformation.pimpaper.ygbh");
	}

};

/**
 * �޸�������Ϣ�������
 */
class ModifyPaperinfoDTO : public oatpp::DTO
{

public:
	ModifyPaperinfoDTO() {};

	DTO_INIT(ModifyPaperinfoDTO, DTO);

	//PIMPAPERID:������Ϣ��ʶ
	DTO_FIELD(String, pimpaperid);
	DTO_FIELD_INFO(pimpaperid) {
		info->description = ZH_WORDS_GETTER("paperInformation.pimpaper.pimpaperid");
	}

	//PIMPAPERNAME:��������
	DTO_FIELD(String, pimpapername);
	DTO_FIELD_INFO(pimpapername) {
		info->description = ZH_WORDS_GETTER("paperInformation.pimpaper.pimpapername");
	}
	//CBS:������
	DTO_FIELD(String, cbs);
	DTO_FIELD_INFO(cbs) {
		info->description = ZH_WORDS_GETTER("paperInformation.pimpaper.cbs");
	}
	//KWMC:��������
	DTO_FIELD(String, kwmc);
	DTO_FIELD_INFO(kwmc) {
		info->description = ZH_WORDS_GETTER("paperInformation.pimpaper.kwmc");
	}
	//KWQS:��������
	DTO_FIELD(String, kwqs);
	DTO_FIELD_INFO(kwqs) {
		info->description = ZH_WORDS_GETTER("paperInformation.pimpaper.kwqs");
	}
	//FBSJ:����ʱ��
	DTO_FIELD(String, fbsj);
	DTO_FIELD_INFO(fbsj) {
		info->description = ZH_WORDS_GETTER("paperInformation.pimpaper.fbsj");
	}
	//GRZLWZZZDPM:���������������е�����
	DTO_FIELD(String, grzlwzzzdpm);
	DTO_FIELD_INFO(grzlwzzzdpm) {
		info->description = ZH_WORDS_GETTER("paperInformation.pimpaper.grzlwzzzdpm");
	}
	//FJ:����
	DTO_FIELD(String, fj);
	DTO_FIELD_INFO(fj) {
		info->description = ZH_WORDS_GETTER("paperInformation.pimpaper.fj");
	}

	//UPDATEDATE:����ʱ��
	DTO_FIELD(String, updatedate);
	DTO_FIELD_INFO(updatedate) {
		info->description = ZH_WORDS_GETTER("paperInformation.pimpaper.updatedate");
	}
	//UPDATEMAN:������
	DTO_FIELD(String, updateman);
	DTO_FIELD_INFO(updateman) {
		info->description = ZH_WORDS_GETTER("paperInformation.pimpaper.updateman");
	}

};
/**
 * ��ҳ�������
 */
class J_PaperinfoPageDTO : public PageDTO<J_PaperinfoDTO::Wrapper>
{
    DTO_INIT(J_PaperinfoPageDTO, PageDTO<J_PaperinfoDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_
