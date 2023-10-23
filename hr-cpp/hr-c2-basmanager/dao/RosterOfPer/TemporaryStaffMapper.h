#pragma once

#ifndef _TEMPORARYSTAFF_MAPPER_
#define _TEMPORARYSTAFF_MAPPER_
#include "Mapper.h"
#include "../../domain/do/RosterOfPer/TemporaryStaffDO.h"
/**
 * ��ְ��Ա���ֶ�ƥ��ӳ��--(��Ա������-��ְ��Ա-��ҳ��ѯԱ���б�)--weixiaoman
 */
class TempStaffMapper :public Mapper<TemporaryStaffDO>
{
public:
	TemporaryStaffDO mapper(ResultSet* resultSet) const override
	{
		TemporaryStaffDO data;
		data.setygbh(resultSet->getString(1));
		data.setpimPersonName(resultSet->getString(2));
		data.setygzt(resultSet->getString(3));
		data.setgzzt(resultSet->getString(4));
		data.setgzzz(resultSet->getString(5));
		data.setgzbm(resultSet->getString(6));
		data.setgzkssj(resultSet->getString(7));
		data.setgzjssj(resultSet->getString(8));
		data.setpimpersonId(resultSet->getString(9));
		return data;
	}
};
#endif // !_TEMPORARYSTAFF_MAPPER_
