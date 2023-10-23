#pragma once
#ifndef _ARCHIVESQUERY_H_
#define _ARCHIVESQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ������Ϣ��ҳ��ѯ����
 */
class ArchivesQuery : public PageQuery
{
	DTO_INIT(ArchivesQuery, PageQuery);

	// Ա������
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("sample.field.name");
	}

	//��Ա��Ϣid
	DTO_FIELD(String, pimpersonid);
	DTO_FIELD_INFO(pimpersonid) {
		info->description = ZH_WORDS_GETTER("sample.field.pimpersionid");
	}

};

#include OATPP_CODEGEN_END(DTO)
#endif // !_ARCHIVESQUERY_H_

