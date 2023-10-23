#pragma once
#ifndef _TEMPORARYSTAFF_SERVICE_
#define _TEMPORARYSTAFF_SERVICE_
#include <list>
#include "domain/vo/RosterOfPer/TemporaryStaffVO.h"
#include "domain/dto/RosterOfPer/TemporaryStaffDTO.h"
#include "domain/query/RosterOfPer/TemporaryStaffQuery.h"
/**
* ��ְ��Աservice--(��Ա������-��ְ��Ա-��ҳ��ѯԱ���б�)--weixiaoman
*/

class TemporaryStaffService {
public:
	//��ѯ��ҳ����
	TemporaryStaffPageDTO::Wrapper listAll(const TempStaffQuery::Wrapper& query);
	//�������ܣ�����fastdfs·��
	std::string exportData(const TempStaffQuery::Wrapper& query);
};
#endif // !_TEMPORARYSTAFF_SERVICE_

