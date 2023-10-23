#include "stdafx.h"
#include "CertificateTypeService.h"
#include "../../dao/CertificateManage/CertificateTypeDAO.h"
/**
* ֤�����Ͳ�ѯ�������--(֤�����-��ѯ֤�������б�)--weixiaoman
*/
CertificateTypePageDTO::Wrapper CertificateTypeService::listAll(const CertificateTypeQuery::Wrapper& query)
{
	// �������ض���
	auto pages = CertificateTypePageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	CertificateTypeDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<CertificateTypeDO> result = dao.selectWithPage(query);
	//list<EmployeeInfoDO> result = dao.selectByName(query->name);
	// ��DOת����DTO
	for (CertificateTypeDO sub : result)
	{
		auto dto = CertificateTypeDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, certype, CerType,id,Id);
		pages->addData(dto);
	}
	return pages;
}
