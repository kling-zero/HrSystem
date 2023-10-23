#include "stdafx.h"
#include "retirementService.h"
#include "dao/retirementDAO/retirementDAO.h"
#include "domain/dto/retirement/RetiremetDto.h"
#include "domain/do/retirement/retirementDO.h"

RetirementPageDTO::Wrapper retirementService::listAll(const RetirementQuery_gan::Wrapper& query)
{
	//�������ض���
	auto pages = RetirementPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	//��ѯ����������
	RetirementDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	//��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<retirementDO> result = dao.selectWithPage(query);

	//��DOת����DTO
	for (retirementDO sub : result)
	{
		auto dto = RetirementDTO::createShared();
		dto->name = sub.getName();
		dto->id = sub.getId();
		dto->age = sub.getAge();
		dto->mailing_address = sub.getMailing_address();
		dto->retire_address = sub.getRetire_address();
		dto->Family_contact = sub.getFamily_Contact();
		dto->organization = sub.getOrganization();
		dto->department = sub.getDepartment();
		dto->rank = sub.getRank();
		dto->before_retire_rank = sub.getBefore_retire_rank();
		dto->before_retire_post = sub.getBefore_retire_post();
		dto->retire_time = sub.getRetire_time();
		dto->read_retire_time = sub.getRead_retire_time();
		dto->tel = sub.getTel();
		dto->Approved_pension_amount = sub.getApproved_Pension_amount();
		pages->addData(dto);
	}
	return pages;
}