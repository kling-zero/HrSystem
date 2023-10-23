#include "stdafx.h"
#include "contractManagerService.h"
#include "dao/retirementDAO/contractManagerDAO.h"
#include "domain/dto/retirement/contractManagerDto.h"
#include "domain/do/retirement/contractManagerDO.h"

contractmanagerPageDTO::Wrapper contractManagerService::listAll(const contractManagerQuery::Wrapper& query)
{
	//�������ض���
	auto pages = contractmanagerPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	//��ѯ����������
	ContractManagerDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	//��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<contractManagerDO> result = dao.selectWithPage(query);

	//��DOת����DTO
	for (contractManagerDO sub : result)
	{
		auto dto = contractmanagerDTO::createShared();
		dto->name = sub.getName();
		dto->id = sub.getId();
		dto->Employee_unit = sub.getEmployee_Unit();
		dto->employee_state = sub.getEmployee_state();
		dto->Time_unit = sub.getTime_Unit();
		dto->contract_id = sub.getContract_id();
		dto->Contract_unit = sub.getContract_Unit();
		dto->Class_contract = sub.getClass_Contract();
		dto->contract_type = sub.getcontract_Type();
		dto->start_date = sub.getStart_date();
		dto->stop_date = sub.getStop_date();
		dto->Operation_column = sub.getOperation_Column();
		pages->addData(dto);
	}
	return pages;
}