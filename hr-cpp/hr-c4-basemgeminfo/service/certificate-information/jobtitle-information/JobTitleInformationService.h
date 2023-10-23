#pragma once
#ifndef _JOBTITLE_INFORMATION_SERVICE_H_
#define _JOBTITLE_INFORMATION_SERVICE_H_
#include <list>
#include "domain/vo/certificate-information/JobTitleInformationVO.h"
#include "domain/query/certificate-information/JobTitleInformationPageQuery.h"
#include "domain/dto/certificate-information/JobTitleInformationDTO.h"

class JobTitleInformationService
{
public:
	//��ҳ��ѯ��������
	JobTitleInformationPageDTO::Wrapper listAll(const JobTitleInformationPageQuery::Wrapper& query);
};

#endif 
