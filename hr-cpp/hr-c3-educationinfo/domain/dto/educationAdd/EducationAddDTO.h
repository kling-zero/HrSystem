/*
 Copyright Zero One Star. All rights reserved.

 @Author: Chen J
 @Date: 2023/05/31 0:04:18
*/
#ifndef _EDUCATIONADDDTO_H_
#define _EDUCATIONADDDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class EducationAddDTO : public oatpp::DTO
{
	DTO_INIT(EducationAddDTO, DTO);
	
	// ������Ϣ��ʶ �����              ��̨����
	DTO_FIELD(String, PIMEDUCATIONID);
	DTO_FIELD_INFO(PIMEDUCATIONID) {
		info->description = ZH_WORDS_GETTER("education.PIMEDUCATIONID");
	}
	// ѧ��
	DTO_FIELD(String, XL);
	DTO_FIELD_INFO(XL) {
		info->description = ZH_WORDS_GETTER("education.XL");
	}
	// ��ѧʱ��
	//DTO_FIELD(UInt64, QSSJ);
	DTO_FIELD(String, QSSJ);
	DTO_FIELD_INFO(QSSJ) {
		info->description = ZH_WORDS_GETTER("education.QSSJ");
	}
	// ��ҵʱ��
	//DTO_FIELD(UInt64, JSSJ);
	DTO_FIELD(String, JSSJ);
	DTO_FIELD_INFO(JSSJ) {
		info->description = ZH_WORDS_GETTER("education.JSSJ");
	}
	// ��ҵԺУ
	DTO_FIELD(String, BYYX);
	DTO_FIELD_INFO(BYYX) {
		info->description = ZH_WORDS_GETTER("education.BYYX");
	}
	// һ��ѧ��
	DTO_FIELD(String, XKML);
	DTO_FIELD_INFO(XKML) {
		info->description = ZH_WORDS_GETTER("education.XKML");
	}
	// ��ѧרҵ
	DTO_FIELD(String, SXZY);
	DTO_FIELD_INFO(SXZY) {
		info->description = ZH_WORDS_GETTER("education.SXZY");
	}
	// ѧϰ��ʽ
	DTO_FIELD(String, XLLX);
	DTO_FIELD_INFO(XLLX) {
		info->description = ZH_WORDS_GETTER("education.XLLX");
	}
	// ѧУ����
	DTO_FIELD(String, XXXZ);
	DTO_FIELD_INFO(XXXZ) {
		info->description = ZH_WORDS_GETTER("education.XXXZ");
	}
	// �Ƿ��һѧ��
	DTO_FIELD(UInt64, SFDYXL);
	DTO_FIELD_INFO(SFDYXL) {
		info->description = ZH_WORDS_GETTER("education.SFDYXL");
	}
	//�Ƿ����ѧ��
	DTO_FIELD(UInt64, SFZGXL);
	DTO_FIELD_INFO(SFZGXL) {
		info->description = ZH_WORDS_GETTER("education.SFZGXL");
	}
	// ��ҵ֤
	DTO_FIELD(String, BTZ);
	DTO_FIELD_INFO(BTZ) {
		info->description = ZH_WORDS_GETTER("education.BTZ");
	}
	// ѧλ֤
	DTO_FIELD(String, XWZ);
	DTO_FIELD_INFO(XWZ) {
		info->description = ZH_WORDS_GETTER("education.XWZ");
	}
	// ѧ����֤
	DTO_FIELD(String, XLCX);
	DTO_FIELD_INFO(XLCX) {
		info->description = ZH_WORDS_GETTER("education.XLCX");
	}
	// ��������
	DTO_FIELD(String, FJ);
	DTO_FIELD_INFO(FJ) {
		info->description = ZH_WORDS_GETTER("education.FJ");
	}

	// �����pimpersonid
	DTO_FIELD(String, PIMPERSONID);
	DTO_FIELD_INFO(PIMPERSONID) {
		info->description = ZH_WORDS_GETTER("education.PIMPERSONID");
	}
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_EDUCATIONADDDTO_H_#pragma once
