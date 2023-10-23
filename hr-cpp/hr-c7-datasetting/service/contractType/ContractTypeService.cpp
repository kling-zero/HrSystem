#include "stdafx.h"
#include "ContractTypeService.h"
#include"../../dao/contractType/ContractTypeDAO.h"

ContractTypePageDTO::Wrapper ContractTypeService::listAll(const ContractTypeQuery::Wrapper& query)
{
	// �������ض���
	auto pages = ContractTypePageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	ContractTypeDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<ContractTypeDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (ContractTypeDO sub : result)
	{
		auto dto = ContractTypeDTO::createShared();
		dto->id = sub.getId();
		dto->name = sub.getName();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, Id, name, Name);
		pages->addData(dto);

	}
	return pages;
}

uint64_t ContractTypeService::saveData(const ContractTypeDTO::Wrapper& dto)
{
	// ��װDO����
	ContractTypeDO data;
	/*data.setId(dto->id.getValue({}));
	data.setName(dto->name.getValue({}));*/
	data.setId(dto->id.getValue({}));
	data.setName(dto->name.getValue(""));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Id, id, Name, name)
	ContractTypeDAO dao;
	return dao.insert(data);
}

bool ContractTypeService::updateData(const ContractTypeDTO::Wrapper& dto)
{
	ContractTypeDO data;
	data.setId(dto->id.getValue(""));
	data.setName(dto->name.getValue(""));
	//ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Id, id, Name, name)
	// ִ�������޸�
	ContractTypeDAO dao;
	return dao.update(data) == 1;
}

bool ContractTypeService::removeData(uint64_t id)
{
	ContractTypeDAO dao;
	return dao.deleteById(id) == 1;
}

