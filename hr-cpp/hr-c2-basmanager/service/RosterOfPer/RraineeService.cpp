#include "stdafx.h"
#include "RraineeService.h"
#include "dao/RosterOfPer/RraineeDAO.h"
/*
  �������� ������Ա������ ������ϰԱ�� -- cpt
*/

RraineePageDTO::Wrapper RraineeService::listAll(const RraineeQuery::Wrapper& query)
{
	// �������ض���
	auto pages = RraineePageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	RraineeDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0) {
		return pages;
	}
	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<RraineeDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (RraineeDO sub : result) {
		auto dto = RraineeDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, ygbh, Ygbh, pcmjxszzkhjgjlname, Pcmjxszzkhjgjlname, 
			zz, Zz, bm, Bm, zw, Zw, gw, Gw, duration, Duration, ksrq, Ksrq, jsrq, Jsrq)
			pages->addData(dto);
	}
	return pages;
}


