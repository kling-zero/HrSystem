/*
 Copyright Zero One Star. All rights reserved.

 @Author: Chen J
 @Date: 2023/05/29 10:38:26
*/
#ifndef _EDUCATIONMAPPER_H_
#define _EDUCATIONMAPPER_H_
#include "BaseDAO.h"
#include "Mapper.h"
#include "domain/do/education/EducationDO.h"

class EducationMapper : public Mapper<EducationDO>
{
public:
	EducationDO mapper(ResultSet* resultSet) const override
	{
		EducationDO data;
		data.setFunPIMEDUCATIONID(resultSet->getString(3));	// ������Ϣ��ʶ ��������
		data.setFunXL(resultSet->getString(19));	// ѧ��
		data.setFunQSSJ(resultSet->getString(14));	// ��ѧʱ��
		data.setFunJSSJ(resultSet->getString(7));	// ��ҵʱ��
		data.setFunBYYX(resultSet->getString(12));	// ��ҵԺУ
		data.setFunXKML(resultSet->getString(37));	// 	// һ��ѧ��
		data.setFunSXZY(resultSet->getString(6));		// ��ѧרҵ
		data.setFunXLLX(resultSet->getString(9));	// ѧϰ��ʽ
		data.setFunXXXZ(resultSet->getString(10));	// ѧУ����
		data.setFunSFDYXL(resultSet->getUInt64(1));		// �Ƿ��һѧ��
		data.setFunSFZGXL(resultSet->getUInt64(17));		//�Ƿ����ѧ��
		data.setFunBTZ(resultSet->getString(38));		// ��ҵ֤
		data.setFunXWZ(resultSet->getString(39));		// ѧλ֤
		data.setFunXLCX(resultSet->getString(40));		// ѧ����֤
		data.setFunFJ(resultSet->getString(19));// ��������
		data.setFunPIMPERSONID(resultSet->getString(20));// ���
		return data;
	}
};

#endif // !_EDUCATIONMAPPER_H_#pragma once

