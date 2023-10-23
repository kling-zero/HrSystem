/*
 Copyright Zero One Star. All rights reserved.

 @Author: Chen J
 @Date: 2023/05/29 10:12:37
*/
#ifndef _EDUCATIONDAO_H_
#define _EDUCATIONDAO_H_
#include "BaseDAO.h"
#include "domain/do/education/EducationDO.h"
#include "domain/query/educationPage/EducationPageQuery.h"
#include "domain/query/educationSingle/EducationSingleQuery.h"
#include "domain/dto/education/EducationDTO.h"
#include "domain/dto/educationAdd/EducationAddDTO.h"

class EducationDAO : public BaseDAO
{
public:
	//����1 ����ҳ��ѯ������ϢDAOʵ��
	std::list<EducationDO> selectEducationPage(const EducationPageQuery::Wrapper& query);
	uint64_t count(const EducationPageQuery::Wrapper& query);

	//����2 ��������ѯ������ϢDAOʵ��
	list<EducationDO> selectEducationSingle(const EducationSingleQuery::Wrapper& query);

	//����3 ���������������ϢDAOʵ��
	int insertEducation(const EducationDO& iObj);

	//����4 �������޸Ľ�����ϢDAOʵ��
	bool updateEducaiton(const EducationDO& data);

	//����5 ������ɾ��������ϢDAOʵ��
	int deleteEducaiton(std::string id);

	//����6 ������ɾ��������ϢDAOʵ��
	//int deleteEducaitonNotSingle(string id);

};

#endif // !_EDUCATIONDAO_H_