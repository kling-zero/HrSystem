#pragma once
/*
����Ա������-�����Ա-��ҳ��ѯԱ���б�������ҳ��ǰ����ɣ���--luoluo
*/
#ifndef _LOANEDPERPAGE_QUERY_
#define _LOANEDPERPAGE_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)
class LoanedPerPageQuery : public PageQuery
{
	DTO_INIT(LoanedPerPageQuery, PageQuery);
	// �����Ա��ʶ
	DTO_FIELD(String, PIMDISTIRBUTIONID);
	DTO_FIELD_INFO(PIMDISTIRBUTIONID) {
		info->description = ZH_WORDS_GETTER("loanedperpage.field.PIMDISTIRBUTIONID");
	}
	// ��ź����� ģ����ѯ
	DTO_FIELD(String, idAndName);
	DTO_FIELD_INFO(idAndName) {
		info->description = ZH_WORDS_GETTER("loanedperpage.field.idAndName");
	}
	// ����
	DTO_FIELD(String, pimPersonName);
	DTO_FIELD_INFO(pimPersonName) {
		info->description = ZH_WORDS_GETTER("loanedperpage.field.pimPersonName");
	}
	// ���
	DTO_FIELD(String, ygbh);
	DTO_FIELD_INFO(ygbh) {
		info->description = ZH_WORDS_GETTER("loanedperpage.field.ygbh");
	}
	// ��֯
	DTO_FIELD(String, zz);
	DTO_FIELD_INFO(zz) {
		info->description = ZH_WORDS_GETTER("loanedperpage.field.zz1");
	}
	// ����
	DTO_FIELD(String, bm);
	DTO_FIELD_INFO(bm) {
		info->description = ZH_WORDS_GETTER("loanedperpage.field.bm1");
	}
	// ְ��
	DTO_FIELD(String, zw);
	DTO_FIELD_INFO(zw) {
		info->description = ZH_WORDS_GETTER("loanedperpage.field.zw1");
	}
	// ��λ
	DTO_FIELD(String, gw);
	DTO_FIELD_INFO(gw) {
		info->description = ZH_WORDS_GETTER("loanedperpage.field.gw1");
	}
	// ����
	DTO_FIELD(String, fp);
	DTO_FIELD_INFO(fp) {
		info->description = ZH_WORDS_GETTER("loanedperpage.field.fp");
	}
	// ����
	DTO_FIELD(String, lx);
	DTO_FIELD_INFO(lx) {
		info->description = ZH_WORDS_GETTER("loanedperpage.field.lx");
	}
	// ����״̬
	DTO_FIELD(String, fpzt);
	DTO_FIELD_INFO(fpzt) {
		info->description = ZH_WORDS_GETTER("loanedperpage.field.fpzt");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_LOANEDPERPAGE_QUERY_