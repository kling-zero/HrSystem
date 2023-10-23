#pragma once
#ifndef _RETIREMENTDAO_H_
#define _RETIREMENTDAO_H_

#include "BaseDAO.h"
#include "domain/query/RetirementQuery/RetirementQuery.h"
#include "domain/do/retirement/retirementDO.h"
#include <string>

class RetirementDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const RetirementQuery_gan::Wrapper& query);
	//��ҳ��ѯ����
	list<retirementDO> selectWithPage(const RetirementQuery_gan::Wrapper& query);

};


#endif // !_RETIREMENTDAO_H_
