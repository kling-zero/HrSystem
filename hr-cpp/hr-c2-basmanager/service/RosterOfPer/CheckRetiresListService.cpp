/*
��Ա������-��������Ա-��ҳ��ѯԱ���б�--pine
*/
#include "stdafx.h"
#include "CheckRetiresListService.h"
#include "../../dao/RosterOfPer/CheckRetiresListDAO.h"

CheckRetiresListPageDTO::Wrapper CheckRetiresListService::listAll(const CheckRetiresListQuery::Wrapper& query)
{
	// �������ض���
	auto pages = CheckRetiresListPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	CheckRetiresListDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<RetiredEmployeesDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (RetiredEmployeesDO sub : result)
	{
		auto dto = CheckRetiresListDTO::createShared();
		// 		dto->id = sub.getId();
		// 		dto->name = sub.getName();
		// 		dto->sex = sub.getSex();
		// 		dto->age = sub.getAge();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, ygbh, ygbh,idAndName, idAndName, pimpersonname, pimpersonname, xb, xb, nj, nj, postaladdress, postaladdress, retiPlace, retiPlace, jtlxr, jtlxr, jtlxrdh, jtlxrdh, zz, zz, bm, bm,
			rank, rank, yzw, yzw, ygw, ygw, txdq, txdq, sjtxrq, sjtxrq, lxdh, lxdh, spdylje, spdylje, pimpersonid, pimpersonid)
		pages->addData(dto);
	}
	return pages;
}


