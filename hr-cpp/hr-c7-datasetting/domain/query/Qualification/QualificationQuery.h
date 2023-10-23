#pragma once
#ifndef _QUALIFICATIONQUERY_H_
#define _QUALIFICATIONQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class QualificationQuery :public PageQuery
{
	DTO_INIT(QualificationQuery, PageQuery);
	// ִҵ�ʸ�רҵ����
	DTO_FIELD(String, pimqualmajorid);
	DTO_FIELD_INFO(pimqualmajorid) {
		info->description = ZH_WORDS_GETTER("archive.field.pimqualmajorid");
	}
	// ����
	DTO_FIELD(String, qualevel);
	DTO_FIELD_INFO(qualevel) {
		info->description = ZH_WORDS_GETTER("archive.field.qualevel");
	}
	// ִҵ�ʸ�
	DTO_FIELD(String, pimqualmajorname);
	DTO_FIELD_INFO(pimqualmajorname) {
		info->description = ZH_WORDS_GETTER("archive.field.pimqualmajorname");
	}
	//רҵ
	DTO_FIELD(String, quamajor);
	DTO_FIELD_INFO(quamajor) {
		info->description = ZH_WORDS_GETTER("archive.field.quamajor");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif
