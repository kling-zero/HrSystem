#pragma once
#ifndef _JOB_TITLE_INFO_DAO_H_
#define _JOB_TITLE_INFO_DAO_H_
#include "BaseDAO.h"
#include "../../domain/do/JobTitle/JobTitleDo.h"
#include "../../domain/dto/JobTitle/JobTitleDTO.h"
#include "./domain/query/JobTitle/JobTitleQuery.h"

class JobTitleInfoDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const JobTitleQuery::Wrapper& query);
	// �����������ݣ���ѯ�������ݣ�
	std::list<JobTitleDO> selectAll(const JobTitleDTO::Wrapper& query);
	// �õ���ͷ
	std::vector<std::string> getHead(const JobTitleDTO::Wrapper& query);
	// ��������
	int update(const JobTitleDO& uObj);
};

#endif // !_JOB_TITLE_INFO_DAO_H_
