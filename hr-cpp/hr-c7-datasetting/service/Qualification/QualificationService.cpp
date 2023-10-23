#include "stdafx.h"
#include "QualificationService.h"
#include "../../dao/Qualification/QualificationDAO.h"
QualificationPageDTO::Wrapper QualificationService::listAll(const QualificationQuery::Wrapper& query)
{
	// �������ض���
	auto pages = QualificationPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	QualificationDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<QualificationDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (QualificationDO sub : result)
	{
		auto dto = QualificationDTO::createShared();
		dto->pimqualmajorid = sub.getpimQualMajorId();
		dto->qualevel = sub.getquaLevel();
		dto->pimqualmajorname = sub.getpimQualMajorName();
		dto->quamajor = sub.getquaMajor();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, pimqualmajorid, pimQualMajorId, qualevel, quaLevel, pimqualmajorname, pimQualMajorName,
			quamajor, quaMajor);
		pages->addData(dto);

	}
	return pages;
}

uint64_t QualificationService::saveData(const QualificationDTO::Wrapper& dto)
{
	// ��װDO����
	QualificationDO data;
	data.setpimQualMajorId(dto->pimqualmajorid.getValue(""));
	data.setquaLevel(dto->qualevel.getValue(""));
	data.setpimQualMajorName(dto->pimqualmajorname.getValue(""));
	data.setquaMajor(dto->quamajor.getValue(""));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, pimQualMajorId, pimqualmajorid, quaLevel, qualevel, pimQualMajorName, pimqualmajorname,
		quaMajor, quamajor);
	// ִ���������
	QualificationDAO dao;
	return dao.insert(data);
}

bool QualificationService::updateData(const QualificationDTO::Wrapper& dto)
{
	// ��װDO����
	QualificationDO data;
	data.setpimQualMajorId(dto->pimqualmajorid.getValue(""));
	data.setquaLevel(dto->qualevel.getValue(""));
	data.setpimQualMajorName(dto->pimqualmajorname.getValue(""));
	data.setquaMajor(dto->quamajor.getValue(""));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, pimQualMajorId, pimqualmajorid, quaLevel, qualevel, pimQualMajorName, pimqualmajorname,
		quaMajor, quamajor);
	// ִ�������޸�
	QualificationDAO dao;
	return dao.update(data) == 1;
}

bool QualificationService::removeData(uint64_t id)
{
	QualificationDAO dao;
	return dao.deleteById(std::to_string(id)) == 1;
}
