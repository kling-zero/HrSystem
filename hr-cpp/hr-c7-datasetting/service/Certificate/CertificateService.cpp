#include "stdafx.h"
#include "CertificateService.h"
#include "../../dao/Certificate/CertificateDAO.h"
CertificatePageDTO::Wrapper CertificateService::listAll(const CertificateQuery::Wrapper& query)
{
	// �������ض���
	auto pages = CertificatePageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	CertificateDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<CertificateDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (CertificateDO sub : result)
	{
		auto dto = CertificateDTO::createShared();
		dto->seialno = sub.getseialNo();
		dto->pimqualtypename = sub.getpimQualTypeName();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, seialno, seialNo, pimqualtypename, pimQualTypeName);
		pages->addData(dto);

	}
	return pages;
}

uint64_t CertificateService::saveData(const CertificateDTO::Wrapper& dto)
{
	// ��װDO����
	CertificateDO data;
	data.setseialNo(dto->seialno.getValue(1));
	data.setpimQualTypeName(dto->pimqualtypename.getValue(""));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, seialNo, seialno, pimQualTypeName, pimqualtypename);
	// ִ���������
	CertificateDAO dao;
	return dao.insert(data);
}

bool CertificateService::updateData(const CertificateDTO::Wrapper& dto)
{
	// ��װDO����
	CertificateDO data;
	data.setseialNo(dto->seialno.getValue(1));
	data.setpimQualTypeName(dto->pimqualtypename.getValue(""));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, seialNo, seialno, pimQualTypeName, pimqualtypename);
	// ִ�������޸�
	CertificateDAO dao;
	return dao.update(data) == 1;
}

bool CertificateService::removeData(uint64_t id)
{
	CertificateDAO dao;
	return dao.deleteById(id) == 1;
}
