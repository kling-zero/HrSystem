#pragma once
/*
��Ա������-��������Ա-��ҳ��ѯԱ���б�--pine
*/
#ifndef _CHECK_RETIRES_LIST_SERVICE_
#define _CHECK_RETIRES_LIST_SERVICE_
#include <list>
#include "domain/query/RosterOfPer/CheckRetiresListQuery.h"
#include "domain/dto/RosterOfPer/CheckRetiresListDTO.h"
#include "domain/vo/RosterOfPer/CheckRetiresListVO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class CheckRetiresListService
{
public:
	// ��ҳ��ѯ��������
	CheckRetiresListPageDTO::Wrapper listAll(const CheckRetiresListQuery::Wrapper& query);

};

#endif // !_CHECK_RETIRES_LIST_SERVICE_

