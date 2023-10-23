#pragma once
/*
����Ա������-�����Ա-��ҳ��ѯԱ���б�������ҳ��ǰ����ɣ���--luoluo
*/
#ifndef _LOANEDPERPAGE_DTO_
#define _LOANEDPERPAGE_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
class LoanedPerDTO : public oatpp::DTO
{
	DTO_INIT(LoanedPerDTO, DTO);
	// �����Ա��ʶ
	DTO_FIELD(String, PIMDISTIRBUTIONID);
	DTO_FIELD_INFO(PIMDISTIRBUTIONID) {
		info->description = ZH_WORDS_GETTER("loanedperpage.field.PIMDISTIRBUTIONID");
	}
	// ��ź�������ģ����ѯ��
	DTO_FIELD(String, idAndName);
	DTO_FIELD_INFO(idAndName) {
		info->description = ZH_WORDS_GETTER("loanedperpage.field.idAndName");
	}
	// Ա�����
	DTO_FIELD(String, ygbh);
	DTO_FIELD_INFO(ygbh) {
		info->description = ZH_WORDS_GETTER("loanedperpage.field.ygbh");
	}
	// Ա������
	DTO_FIELD(String, pimPersonName);
	DTO_FIELD_INFO(pimPersonName) {
		info->description = ZH_WORDS_GETTER("loanedperpage.field.pimPersonName");
	}
	// ԭ��֯
	DTO_FIELD(String, zz);
	DTO_FIELD_INFO(zz) {
		info->description = ZH_WORDS_GETTER("loanedperpage.field.zz");
	}
	// ԭ����
	DTO_FIELD(String, bm);
	DTO_FIELD_INFO(bm) {
		info->description = ZH_WORDS_GETTER("loanedperpage.field.bm");
	}
	// ԭְ��
	DTO_FIELD(String, yzw);
	DTO_FIELD_INFO(yzw) {
		info->description = ZH_WORDS_GETTER("loanedperpage.field.yzw");
	}
	// ԭ��λ
	DTO_FIELD(String, ygw);
	DTO_FIELD_INFO(ygw) {
		info->description = ZH_WORDS_GETTER("loanedperpage.field.ygw");
	}
	// ����֯
	DTO_FIELD(String, ormName);
	DTO_FIELD_INFO(ormName) {
		info->description = ZH_WORDS_GETTER("loanedperpage.field.ormName");
	}
	// �²���
	DTO_FIELD(String, ormOrgSectorName);
	DTO_FIELD_INFO(ormOrgSectorName) {
		info->description = ZH_WORDS_GETTER("loanedperpage.field.ormOrgSectorName");
	}
	// ��ְ��
	DTO_FIELD(String, ormDutyName);
	DTO_FIELD_INFO(ormDutyName) {
		info->description = ZH_WORDS_GETTER("loanedperpage.field.ormDutyName");
	}
	// �¸�λ
	DTO_FIELD(String, ormPostName);
	DTO_FIELD_INFO(ormPostName) {
		info->description = ZH_WORDS_GETTER("loanedperpage.field.ormPostName");
	}
	// ���״̬���춯�����ϸ��ʶ��
	DTO_FIELD(String, pcmydjdmxId);
	DTO_FIELD_INFO(pcmydjdmxId) {
		info->description = ZH_WORDS_GETTER("loanedperpage.field.pcmydjdmxId");
	}
	// �����ʼʱ��
	DTO_FIELD(String, jdksrq);
	DTO_FIELD_INFO(jdksrq) {
		info->description = ZH_WORDS_GETTER("loanedperpage.field.jdksrq");
	}
	// �������ʱ��
	DTO_FIELD(String, jdjsrq);
	DTO_FIELD_INFO(jdjsrq) {
		info->description = ZH_WORDS_GETTER("loanedperpage.field.jdjsrq");
	}
};

class LoanedPerPageDTO : public PageDTO<LoanedPerDTO::Wrapper>
{
	DTO_INIT(LoanedPerPageDTO, PageDTO<LoanedPerDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_LOANEDPERPAGE_DTO_