#pragma once
#ifndef _PAPER_QUERY_
#define _PAPER_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)



/**
 * ר����Ϣ��ѯ����
 */
class PatentinfoQuery : public PageQuery
{
	DTO_INIT(PatentinfoQuery, PageQuery);


	//// ��Ա��Ϣ��ʶ
	//DTO_FIELD(String, PIMPERSONID);
	//DTO_FIELD_INFO(PIMPERSONID) {
	//	info->description = ZH_WORDS_GETTER("patentInformation.field.PIMPERSONID");
	//}

	// ר����Ϣ����
	DTO_FIELD(String, PIMPATENTID);
	DTO_FIELD_INFO(PIMPATENTID) {
		info->description = ZH_WORDS_GETTER("patentInformation.field.PIMPATENTID");
	}



};



#include OATPP_CODEGEN_END(DTO)
#endif
