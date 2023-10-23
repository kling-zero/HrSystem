#pragma once
#ifndef _TEMPORARYSTAFF_QUERY_
#define _TEMPORARYSTAFF_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��ְ��Ա��ҳ��ѯ����--(��Ա������-��ְ��Ա-��ҳ��ѯԱ���б�)--weixiaoman
 */
class TempStaffQuery : public PageQuery
{
	DTO_INIT(TempStaffQuery, PageQuery);
	// ����
	DTO_FIELD(String, idandname);
	DTO_FIELD_INFO(idandname) {
		info->description = ZH_WORDS_GETTER("TempStaff.field.idandname");
	}
	//// ���
	//DTO_FIELD(String, id);
	//DTO_FIELD_INFO(id) {
	//	info->description = ZH_WORDS_GETTER("TempStaff.field.id");
	//}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_TEMPORARYSTAFF_QUERY_