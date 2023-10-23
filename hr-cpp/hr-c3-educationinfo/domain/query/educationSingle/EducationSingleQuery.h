/*
 Copyright Zero One Star. All rights reserved.

 @Author: Chen J
 @Date: 2023/05/19 17:10:02
*/
#ifndef _EDUCATIONSINGLEQUERY_H_
#define _EDUCATIONSINGLEQUERY_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class EducationSingleQuery : public oatpp::DTO
{
	DTO_INIT(EducationSingleQuery, DTO);
	//// ������ʶ PIMEDUCATIONID
	//DTO_FIELD(String, PIMEDUCATIONID);
	//DTO_FIELD_INFO(PIMEDUCATIONID) {
	//	info->description = ZH_WORDS_GETTER("t_pimperson.PIMEDUCATIONID");
	//}

	// ��Ա��ʶ PIMEDUCATIONID
	// �����pimpersonid
	DTO_FIELD(String, PIMPERSONID);
	DTO_FIELD_INFO(PIMPERSONID) {
		info->description = ZH_WORDS_GETTER("education.PIMPERSONID");
	}

	//// Ա������pimpersonname
	//DTO_FIELD(String, pimpersonname);
	//DTO_FIELD_INFO(pimpersonname) {
	//	info->description = ZH_WORDS_GETTER("t_pimperson.pimpersonname");
	//}

};

#include OATPP_CODEGEN_END(DTO)

#endif // !_EDUCATIONSINGLEQUERY_H_#pragma once
