#include "stdafx.h"
#include "ArchivesService.h"
#include "../../dao/archives/ArchivesDAO.h"

ArchivesPageDTO::Wrapper ArchivesService::listAll(const ArchivesQuery::Wrapper& query)
{
	// �������ض���
	auto pages = ArchivesPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	ArchivesDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����DABH,ORMORGID3,DABGD,ARCHIVESCENTERID,EDUCATION,DATEOFBIRTH,JOINPARTYDATE,STARTWORKDATAE,DAZT
	pages->total = count;
	pages->calcPages();
	list<ArchivesDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (ArchivesDO sub : result)
	{
		auto dto = ArchivesDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, dabh, Dabh, ormorgid3, Ormorgid3, dabgd, Dabgd, archivescentername, Archivescentername, education, Education, dateofbirth, Dateofbirth, joinpartydate, Joinpartydate, startworkdatae, Startworkdatae, dazt, Dazt);
		pages->addData(dto);

	}
	return pages;
}
