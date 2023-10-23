/*
 Copyright Zero One Star. All rights reserved.

 @Author: Chen J
 @Date: 2023/05/29 10:01:46
*/
#ifndef _EDUCATIONSERVICE_H_
#define _EDUCATIONSERVICE_H_

#include "domain/dto/education/EducationDTO.h"
#include "domain/query/educationPage/EducationPageQuery.h"
#include "domain/query/educationSingle/EducationSingleQuery.h"
#include "domain/dto/educationDelete/EducationDeleteDTO.h"
#include "domain/dto/educationAdd/EducationAddDTO.h"
#include "domain/dto/educationAdd/EducationAddDTO.h"
class EducationService 
{
public:
	/**
	 * ��ҳ��ѯָ��Ա��������Ϣ
	 * �����ˣ�chen jun
	 */
	EducationPageDTO::Wrapper listEducationPage(const EducationPageQuery::Wrapper& query);
	/**
	 * ������ѯָ��Ա��������Ϣ
	 * �����ˣ�chen jun
	 */
	EducationSingleDTO::Wrapper listEducationSingle(const EducationSingleQuery::Wrapper& query);
	/**
	 * ���ָ��Ա��������Ϣ
	 * �����ˣ�chen jun
	 */
	int saveEducation(const EducationAddDTO::Wrapper& dto);
	/**
	 * �޸�
	 * �����ˣ�Chen jun
	 */
	bool updateEducation(const EducationAddDTO::Wrapper& dto);
	/**
	* ɾ������
	* ������ : Chen jun
	*/
	bool removeEducation(const EducationDeleteSingleDTO::Wrapper& dto);
	/**
	* ɾ������
	* ������ : Chen jun
	*/
	//bool removeEducationNotSingle(const EducationDeleteNotSingleDTO::Wrapper& dto);
};



#endif // !_EDUCATIONSERVICE_H_#pragma once




