#include "stdafx.h"
#include "CertificateInformationService.h"
#include"../../../dao/certificate-information/certificate-information/CertificateInformationDAO.h"
#include "../../../domain/do/certificate-information/CertificateInformationDO.h"
//�����ҳ��ѯ����֤�����ݵĺ���listAll
CertificateInformationPageDTO::Wrapper CertificateInformationService::listAll(const CertificateInformationPageQuery::Wrapper& query)
{
	// �������ض���
	auto pages = CertificateInformationPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;
	// ��ѯ����������,���ݵ�dao��
	CertificateInformationDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}
	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<CertificateInformationDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (CertificateInformationDO sub : result)
	{
		auto dto = CertificateInformationDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, zgzsbh, Zgzsbh, pimvocationalname, Pimvocationalname, zslx, Zslx, zghqrq, Zghqrq, zgsydw, Zgsydw, fzyxq, Fzyxq,pimpersonid, Pimpersonid );
		pages->addData(dto);
	}
	return pages;
}