#pragma once
#ifndef _TITLEQUERY_
#define _TITLEQUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ��ְ��Ŀ¼��ѯ����
 */
class TitleQuery : public PageQuery
{
	DTO_INIT(TitleQuery, PageQuery);

	// Ա������
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("title.field.name");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif //