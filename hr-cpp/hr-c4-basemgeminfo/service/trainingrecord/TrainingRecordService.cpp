#include "stdafx.h"
#include "TrainingRecordService.h"
#include"../../dao/trainingrecord/TrainingRecordDAO.h"
#include "../../domain/do/trainingrecord/TrainingRecordDO.h"

TrainingRecordPageDTO::Wrapper TrainingRecordService::listAll(const TrainingRecordPageQuery::Wrapper& query)
{
	// �������ض���
	auto pages = TrainingRecordPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;
	// ��ѯ����������,���ݵ�dao��
	TrainingRecordDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}
	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<TrainingRecordDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (TrainingRecordDO sub : result)
	{
		auto dto = TrainingRecordDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, TRMTRIANPERSONID, _TRMTRIANPERSONID, PXBJ, _PXBJ, TRAINBEGIN, _TRAINBEGIN, TRAINEND, _TRAINEND, PXKC, _PXKC, TRMTRAINAGENCYNAME, _TRMTRAINAGENCYNAME, TRAINRES, _TRAINRES, FS, _FS);
		pages->addData(dto);
	}
	return pages;
}