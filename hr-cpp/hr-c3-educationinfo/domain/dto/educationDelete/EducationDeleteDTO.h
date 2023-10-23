/*
 Copyright Zero One Star. All rights reserved.

 @Author: Chen J
 @Date: 2023/05/20 19:45:08
*/
#ifndef _EDUCATIONDELETEDTO_H_
#define _EDUCATIONDELETEDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/*
* ɾ�������ݽ�����Ϣ������PIMEDUCATIONIDɾ������
*/
class EducationDeleteSingleDTO : public oatpp::DTO
{
	DTO_INIT(EducationDeleteSingleDTO, DTO);
	// ������Ϣ��ʶ �����
	DTO_FIELD(List<String>, PIMEDUCATIONID);
	DTO_FIELD_INFO(PIMEDUCATIONID) {
		info->description = ZH_WORDS_GETTER("education.PIMEDUCATIONID");
	}

	//// �����pimpersonid
	//DTO_FIELD(String, PIMPERSONID);
	//DTO_FIELD_INFO(PIMPERSONID) {
	//	info->description = ZH_WORDS_GETTER("education.PIMPERSONID");
	//}



};

/*
* ����ɾ��
*/
//class EducationDeleteNotSingleDTO : public oatpp::DTO
//{
//	DTO_INIT(EducationDeleteNotSingleDTO, DTO);
//	// ����������Ϣ
//	DTO_FIELD(oatpp::List<String>, deleteIds);
//	DTO_FIELD_INFO(deleteIds) {
//		info->description = ZH_WORDS_GETTER("deleteIds");
//	}
//
//};




#include OATPP_CODEGEN_END(DTO)

#endif // !_EDUCATIONDELETEDTO_H_#pragma once
