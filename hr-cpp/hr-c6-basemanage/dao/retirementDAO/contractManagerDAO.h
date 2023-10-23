#pragma once
#ifndef  _CONTRACTMANAGERDAO_H_
#define  _CONTRACTMANAGERDAO_H_

#include "BaseDAO.h"
#include "domain/query/RetirementQuery/contractManagerQuery.h"
#include "domain/do/retirement/contractManagerDO.h"
#include <string>

class ContractManagerDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const contractManagerQuery::Wrapper& query);
	//��ҳ��ѯ����
	list<contractManagerDO> selectWithPage(const contractManagerQuery::Wrapper& query);

};

#endif // ! _CONTRACTMANAGERDAO_H_
