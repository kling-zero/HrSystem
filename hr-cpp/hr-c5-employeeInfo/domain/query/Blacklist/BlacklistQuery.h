#pragma once
#ifndef _BLACKLIST_QUERY_
#define _BLACKLIST_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 *��Ա����Ż�Ա��������ѯ
 */
class BlacklistQuery : public PageQuery {
	DTO_INIT(BlacklistQuery, PageQuery);
	//Ա�����
	DTO_FIELD(String, ygbh);
	DTO_FIELD_INFO(ygbh) {
		info->description = ZH_WORDS_GETTER("patentInformation.field.ygbh");
	}
	
	//Ա������
	DTO_FIELD(String, ygxm);
	DTO_FIELD_INFO(ygxm) {
		info->description = ZH_WORDS_GETTER("patentInformation.field.ygxm");
	}

};


#include OATPP_CODEGEN_END(DTO)
#endif // !_NOT_EMPLOYEE_IN_ARCHIVE_QUERY_