#pragma once
#ifndef _EXPENSELEDGER_SERVICE_
#define _EXPENSELEDGER_SERVICE_
#include "domain/dto/ExpenseLedger/ExpenseLedgerDTO.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/do/expenseLedger/ExpenseLedgerDO.h"
#include "dao/expenseLedger/ExpenseLedgerDAO.h"

class ExpenseLedgerService
{
public:
	std::string listAllExpense(const ExpenseLedgerDTO::Wrapper& query);
	// ��ѯָ��������ϸ
	ExpenseLedgerDTO::Wrapper queryDataDetail(const ExpenseLedgerDTO::Wrapper& query);
	// �޸�����
	bool updateData(const ExpenseLedgerDTO::Wrapper& dto);
protected:
private:
};
#endif