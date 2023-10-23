#pragma once
#ifndef _JOBTITLE_INFO_H_
#define _JOBTITLE_INFO_H_
#include "domain/vo/JobTitle/JobTitleJsonVO.h"
#include "domain/do/JobTitle/JobTitleDo.h"
#include "domain/dto/JobTitle/JobTitleDTO.h"
#include "domain/vo/BaseJsonVO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class JobTitleInfoService
{
public:
	// ��ѯ����ְ����Ϣ
	std::string listAllJobTitle(const JobTitleDTO::Wrapper& query);
	// ��ѯָ��������ϸ
	JobTitleDTO::Wrapper queryDataDetail(const JobTitleDTO::Wrapper& query);
	// �޸�����
	bool updateData(const JobTitleDTO::Wrapper& dto);
};

#endif // !_SAMPLE_SERVICE_