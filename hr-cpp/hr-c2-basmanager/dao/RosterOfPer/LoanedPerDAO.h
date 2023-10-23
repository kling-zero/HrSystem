#pragma once
#ifndef _LOANEDPER_DAO_
#define _LOANEDPER_DAO_
#include "BaseDAO.h"
#include "../../domain/do/RosterOfPer/SecondedPersonnelDO.h"
#include "../../domain/query/RosterOfPer/LoanedPerPageQuery.h"

/**
 * �����Ա���ݿ����ʵ��--(��Ա������-�����Ա-��ҳ��ѯԱ���б�)--luoluo
 */
class LoanedPerDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const LoanedPerPageQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<SecondedPersonnelDO> selectWithPage(const LoanedPerPageQuery::Wrapper& query);
	// ������ѯ
	list<SecondedPersonnelDO> selectExportDatas(const LoanedPerPageQuery::Wrapper& query);
};
#endif // !_LOANEDPER_DAO_