//2023��6��6��
//���ߣ���Ƥ�����
//��λ������Ϣ��service
#pragma once
#ifndef _JOB_OUTPUT_SERVICE_H_
#define _JOB_OUTPUT_SERVICE_H_
#include "domain/dto/postSet/PostDetailDTO.h"
#include "domain/query/postSet/PostDetailQuery.h"
class JobOutputService
{
public:
	std::string exportJobInfomation(const PostDetailQuery::Wrapper& query);
};

#endif // !_JOB_OUTPUT_SERVICE_H_



