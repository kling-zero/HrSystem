#include "stdafx.h"
#include "LegalEntitySetService.h"
#include "dao/LegalEntitySet/LegalEntitySetDAO.h"
#include "CharsetConvertHepler.h"
#include "ExcelComponent.h"
#include "FastDfsClient.h"
#include "SnowFlake.h"
#include "SimpleDateTimeFormat.h"
/*
��֯���� ������������ ���� ������������  -- cpt

�����������������б� `LegalEntitySetPullDownList`
����ָ������������Ϣ  `UpdateLegalerSettingMessage`
������������ `LegalEntitySet`
�����������ã�֧������������ `LegalEntitySet`
*/


LegalEntitySetPullDownDTO::Wrapper LegalEntitySetService::legalEntityPulldownList() {
	LegalEntitySetDAO dao;
	std::list<LegalEntitySetDO> date = dao.legalerNamePullDownList();
	auto dto = LegalEntitySetPullDownDTO::createShared();
	for (auto it : date) {
		string str = it.getORMSIGNORGID();
		dto->legalEntitySetPullDownList->push_back(LegalEntitySetDTO::createShared(str));
	}
	return dto;
}

uint64_t LegalEntitySetService::insertData(const LegalEntitySetAddDTO::Wrapper& dto, const PayloadDTO& payload) {
	//ѩ���㷨 ����Ψһ��ʶ
	SnowFlake snowid(1, 2); 
	// ��װDO����
	LegalEntitySetDO data; 
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, CONTRACTSIGNORGNAME, contractsignorgname, ORMORGID, ormorgid, ORMSIGNORGID, ormsignorgid, ISDEFAULTSIGNORG, isdefaultsignorg)
	SimpleDateTimeFormat time;
	data.setCONTRACTSIGNORGID(to_string(snowid.nextId()));
	data.setCREATEDATE(time.format());
	data.setCREATEMAN(payload.getUsername());
	data.setUPDATEDATE(time.format());
	data.setUPDATEMAN(payload.getUsername());
	//data.setSIGNORGID(payload->getId());
	// ִ���������
	LegalEntitySetDAO dao;
	return dao.insert(data);
}

bool LegalEntitySetService::updateData(const LegalEntitySetUpdateDTO::Wrapper& dto) {
	// ��װDO����
	LegalEntitySetDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, CONTRACTSIGNORGNAME, contractsignorgname,  ORMORGID, ormorgid, ORMSIGNORGID, ormsignorgid, ISDEFAULTSIGNORG, isdefaultsignorg)
	// ִ�������޸�
	LegalEntitySetDAO dao;
	return dao.update(data);
}

// ɾ������ 
//bool LegalEntitySetService::removeData(uint64_t id)
//{
//	LegalEntitySetDAO dao;
//	return dao.deleteById(id) == 1;
//}


/* ----------------------------------��������ά��Service�����ʵ��--����֯����-��������-��������ά����--TripleGold ------------------------------------------------*/
LegalEntitySetQueryPageDTO::Wrapper LegalEntitySetService::listAll(const LegalEntitySetQuery::Wrapper& query)
{
	// �������ض���
	auto pages = LegalEntitySetQueryPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	LegalEntitySetDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0) {
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<LegalEntitySetDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (LegalEntitySetDO sub : result)
	{
		auto dto = LegalEntitySetQueryDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, contractsignorgid, CONTRACTSIGNORGID, contractsignorgname, CONTRACTSIGNORGNAME, ormsignorgid, ORMSIGNORGID, ormorgid, ORMORGID, isdefaultsignorg, ISDEFAULTSIGNORG);
		pages->addData(dto);
	}
	return pages;
}