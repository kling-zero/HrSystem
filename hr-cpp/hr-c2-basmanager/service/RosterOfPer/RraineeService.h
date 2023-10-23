#pragma once
#ifndef _RRAINEE_SERVICE_
#define _RRAINEE_SERVICE_
/*
  �������� ������Ա������ ������ϰԱ�� -- cpt
*/

#include <list>
#include "domain/vo/RosterOfPer/RraineeVO.h"
#include "domain/query/RosterOfPer/RraineeQuery.h"
#include "domain/dto/RosterOfPer/RraineeDTO.h"
#include "domain/do/RosterOfPer/RraineeDO.h"

class RraineeService
{
public:
	// ��ҳ��ѯ��������
	RraineePageDTO::Wrapper listAll(const RraineeQuery::Wrapper& query);
};

#endif // !_RRAINEE_SERVICE_

