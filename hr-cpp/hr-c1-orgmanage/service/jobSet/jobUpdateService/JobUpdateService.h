//2023��5��31��
//���ߣ���Ƥ�����
//��λ���µ�Service
#pragma once
#ifndef  _JOB_UPDATE_SERVICE_
#define _JOB_UPDATE_SERVICE_

#include <list>
#include "domain/vo/jobUpdate/JobUpdateVO.h"
#include "domain/do/postSet/PostDetailDO.h"
#include "domain/dto/postSet/PostDetailDTO.h"
#include "dao/jobSet/jobUpdateDAO/JobUpdteDAO.h"
#include "domain/dto/jobSet/jobUpdateDto/JobUpdateDTO.h"

class JobUpdateService
{
public:
	bool updateJobInfo(const JobUpdateDTO::Wrapper& dto, const PayloadDTO& payload);
};

#endif // ! _JOB_UPDATE_SERVICE_



