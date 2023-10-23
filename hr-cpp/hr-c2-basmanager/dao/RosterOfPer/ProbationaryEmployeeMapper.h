#pragma once
#ifndef _PROBATIONARY_EMPLOYEE_MAPPER_
#define _PROBATIONARY_EMPLOYEE_MAPPER_

#include "Mapper.h"
#include "../../domain/do/RosterOfPer/ProbationaryEmployeeDO.h"
/**
 * ��Ա������ - ����Ա�� - ����Ա��������ֶ�ƥ��ӳ�� - ������
 */
class ProbationaryEmployeeMapper : public Mapper<ProbationaryEmployeeDO>
{
public:
	ProbationaryEmployeeDO mapper(ResultSet* resultSet) const override
	{
		ProbationaryEmployeeDO data;
		data.setYGBH(resultSet->getString(1));
		data.setPIMPERSONNAME(resultSet->getString(2));
		data.setORMORGNAME(resultSet->getString(3));
		data.setORMORGSECTORNAME(resultSet->getString(4));
		data.setZW(resultSet->getString(5));
		data.setORMPOSTNAME(resultSet->getString(6));
		data.setRZSJ(resultSet->getString(7));
		data.setSYDQ(resultSet->getString(8));
		data.setpimPersonId(resultSet->getString(9));
		return data;
	}
};

#endif 