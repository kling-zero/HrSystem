#pragma once
#ifndef _RETIREMENTSERVICE_H_
#define _RETIREMENTSERVICE_H_

#include <list>
#include "domain/vo/RetirementVo/contractManagerVo.h"
#include "domain/query/RetirementQuery/contractManagerQuery.h"
#include "domain/dto/retirement/contractManagerDto.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class contractManagerService
{
public:
	// ��ҳ��ѯ��������
	contractmanagerPageDTO::Wrapper listAll(const contractManagerQuery::Wrapper& query);

};

#endif // !_RETIREMENTSERVICE_H_
