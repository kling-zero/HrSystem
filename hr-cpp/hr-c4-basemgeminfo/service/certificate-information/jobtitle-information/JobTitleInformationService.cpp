#include "stdafx.h"
#include "JobTitleInformationService.h"
#include"../../../dao/certificate-information/jobtitle-information/JobTitleInformationDAO.h"
//�����ҳ��ѯ����ְ�����ݵĺ���listAll
JobTitleInformationPageDTO::Wrapper JobTitleInformationService::listAll(const JobTitleInformationPageQuery::Wrapper& query)
{
	// �������ض���
	auto pages = JobTitleInformationPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;
	// ��ѯ����������,���ݵ�dao��
	JobTitleInformationDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}
	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<JobTitleInformationDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (JobTitleInformationDO sub : result)
	{
		auto dto = JobTitleInformationDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, professoranalysis_name, Professoranalysis_name, credentials_num, Credentials_num, professor_grades, Professor_grades, major, Major, zchqrq, Zchqrq, reviewbody, Reviewbody, lssuingagency, Lssuingagency, employtime, Employtime, enable, Enable, employeeid, Employeeid);
		pages->addData(dto);
	}
	return pages;
}