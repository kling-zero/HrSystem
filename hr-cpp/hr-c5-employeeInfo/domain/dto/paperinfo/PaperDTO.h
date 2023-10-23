#pragma once
#ifndef _PAPAER_DTO_
#define _PAPAER_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ������Ϣ�������
 */
class PaperDTO : public oatpp::DTO
{
	DTO_INIT(PaperDTO, DTO);
	
	// ������
	DTO_FIELD(String, cbs);
	DTO_FIELD_INFO(cbs) {
		info->description = ZH_WORDS_GETTER("paperinfo.field.cbs");
	}
	// ����ʱ��
	DTO_FIELD(String, fbsj);
	DTO_FIELD_INFO(fbsj) {
		info->description = ZH_WORDS_GETTER("paperinfo.field.fbsj");
	}
	// ��������
	DTO_FIELD(Int32, kwqs);
	DTO_FIELD_INFO(kwqs) {
		info->description = ZH_WORDS_GETTER("paperinfo.field.kwqs");
	}
	// ����
	DTO_FIELD(String, fj);
	DTO_FIELD_INFO(fj) {
		info->description = ZH_WORDS_GETTER("paperinfo.field.fj");
	}
	// ���������������е�����
	DTO_FIELD(Int32, grzlwzzzdpm);
	DTO_FIELD_INFO(grzlwzzzdpm) {
		info->description = ZH_WORDS_GETTER("paperinfo.field.grzlwzzzdpm");
	}
	// ��������
	DTO_FIELD(String, kwmc);
	DTO_FIELD_INFO(kwmc) {
		info->description = ZH_WORDS_GETTER("paperinfo.field.kwmc");
	}
	// ��������
	DTO_FIELD(String, pimpapername);
	DTO_FIELD_INFO(pimpapername) {
		info->description = ZH_WORDS_GETTER("paperinfo.field.pimpapername");
	}
	// ���
	DTO_FIELD(List<String>, pimpaperid);
	DTO_FIELD_INFO(pimpaperid) {
		info->description = ZH_WORDS_GETTER("paperinfo.field.PIMPAPERID");
	}
public:
	PaperDTO() {}
	/*PaperDTO(String cbs, String fbsj, String kwqs, String fj, Int32 grzlwzzzdpm, String kwmc) :
		cbs(cbs), fbsj(fbsj), kwqs(kwqs), fj(fj), grzlwzzzdpm(grzlwzzzdpm), kwmc(kwmc){}
	*/
};

/**
 * ������Ϣ��ҳ�������
 */
class PaperPageDTO : public PageDTO<PaperDTO::Wrapper>
{
	DTO_INIT(PaperPageDTO, PageDTO<PaperDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif