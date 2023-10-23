#include "stdafx.h"
#include "JobTitleInformationController.h"
#include "../../service/certificate-information/jobtitle-information/JobTitleInformationService.h"
//����ְ�Ʒ�ҳ��ѯ�ӿں���execQueryJobTitleInformation
JobTitleInformationPageJsonVO::Wrapper JobTitleInformationController::execQueryJobTitleInformation(const JobTitleInformationPageQuery::Wrapper& query, const PayloadDTO& payload)
{
	// ����һ��Service
	JobTitleInformationService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = JobTitleInformationPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}




