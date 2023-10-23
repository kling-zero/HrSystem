#pragma once
#ifndef _PAPERINFO_QUERY_
#define _PAPERINFO_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ������Ϣ��ҳ��ѯ����
 */
class PaperQuery : public PageQuery
{
	DTO_INIT(PaperQuery, PageQuery);
	// Ա�����
	DTO_FIELD(String, pimpersonid);
	DTO_FIELD_INFO(pimpersonid) {
		info->description = ZH_WORDS_GETTER("paperinfo.field.pimpersonid");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif