/*
 Copyright Zero One Star. All rights reserved.

 @Author: Chen J
 @Date: 2023/05/17 21:30:53
*/
#ifndef _GETEDUCATIONPAGEQUERY_H_
#define _GETEDUCATIONPAGEQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)
//����1������Ա������ ��ҳ��ѯ ������Ϣ
class EducationPageQuery : public PageQuery
{
	DTO_INIT(EducationPageQuery, PageQuery);
	// Ա��id pimpersonid
	DTO_FIELD(String, PIMPERSONID);
	DTO_FIELD_INFO(PIMPERSONID) {
		info->description = ZH_WORDS_GETTER("education.PIMPERSONID");
	}
	// Ա������pimpersonname
	/*DTO_FIELD(String, pimpersonname);
	DTO_FIELD_INFO(pimpersonname) {
		info->description = ZH_WORDS_GETTER("t_pimperson.pimpersonname");
	}*/
	// �������:����ʽ,(asc/desc)
	//DTO_FIELD(String, sort);
	//DTO_FIELD_INFO(sort) {
	//	info->description = ZH_WORDS_GETTER("t_pimperson.sort");
	//}
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_GETEDUCATIONPAGEQUERY_H_