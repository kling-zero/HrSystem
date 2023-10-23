#include "stdafx.h"
#include "ContractCategoryService.h"
#include "../../dao/contractcategory/ContractCategoryDAO.h"

#include "../../../lib-common/include/SnowFlake.h"

ContractCategoryPageDTO::Wrapper ContractCategoryService::listAll(const ContractCategoryQuery::Wrapper& query)
{
	// �������ض���
	auto pages = ContractCategoryPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	ContractCategoryDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<ContractCategoryDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (ContractCategoryDO sub : result)
	{
		auto dto = ContractCategoryDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, Id, name, Name)
			pages->addData(dto);
	}
	return pages;
}

uint64_t ContractCategoryService::addContractCategory(const ContractCategoryDTO::Wrapper& dto)
{
	// ��װDO����
	ContractCategoryDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Name, name)

		// ʹ��ѩ���㷨����ȫ��ΨһID
		SnowFlake sf(1, 1);
	data.setId(std::to_string(sf.nextId()));

	// ִ���������
	ContractCategoryDAO dao;
	return dao.insert(data);
}

bool ContractCategoryService::modifyContractCategory(const ContractCategoryDTO::Wrapper& dto)
{
	// ��װDO����
	ContractCategoryDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Name, name)
		// ִ�������޸�
		ContractCategoryDAO dao;
	return dao.update(data) == 1;
}

bool ContractCategoryService::removeContractCategory(uint64_t id)
{
	ContractCategoryDAO dao;
	return dao.deleteById(std::to_string(id)) == 1;
}
