#include "stdafx.h"
#include "EmployeeInfoService.h"
#include "../../dao/CertificateManage/EmployeeInfoDAO.h"
/**
 * ��Ա��Ϣ��ҳ��ѯservice--(֤�����-��ҳ��ѯԱ����Ϣ�б�)--weixiaoman
 */
EmployeeInfoPageDTO::Wrapper EmployeeInfoService::listAll(const EmployeeInfoQuery::Wrapper& query)
{
	// �������ض���
	auto pages = EmployeeInfoPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	EmployeeInfoDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<EmployeeInfoDO> result = dao.selectWithPage(query);
	//list<EmployeeInfoDO> result = dao.selectByName(query->name);
	// ��DOת����DTO
	for (EmployeeInfoDO sub : result)
	{
		auto dto = EmployeeInfoDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, name, Name,id,Id);
		pages->addData(dto);
	}
	return pages;
}
