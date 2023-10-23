#pragma once
#ifndef _LOANEDPERPAGE_SERVICE_
#define _LOANEDPERPAGE_SERVICE_
#include <list>
#include "domain/query/RosterOfPer/LoanedPerPageQuery.h"
#include "domain/dto/RosterOfPer/LoanedPerPageDTO.h"
#include "domain/vo/RosterOfPer/LoanedPerPageVO.h"

/*
����Ա������-�����Ա-��ҳ��ѯԱ���б�������ҳ��ǰ����ɣ���--luoluo
*/
class LoanedPerPageService
{
public:
	// ��ҳ��ѯ��������
	LoanedPerPageDTO::Wrapper listAll(const LoanedPerPageQuery::Wrapper& query);
	//�������ܣ�����fastdfs·��
	std::string exportData(const LoanedPerPageQuery::Wrapper& query);
};

#endif // !_LOANEDPERPAGE_SERVICE_

