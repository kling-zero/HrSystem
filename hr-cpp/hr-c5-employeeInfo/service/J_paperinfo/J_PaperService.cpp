
#include "stdafx.h"
#include "J_PaperService.h"
#include "../../dao/J_paperinfo/J_PaperinfoDAO.h"



// ��ѯָ��������Ϣ����
J_PaperinfoDTO::Wrapper PaperService::listAll(const string& st)
{
	// �������ض���
	PaperinfoDAO dao;
	//��ѯ����
	list<J_PaperinfoDO> result = dao.selectBypimpaperid(st);
	//��DOת����DTO
	auto dto = J_PaperinfoDTO::createShared();
	for (J_PaperinfoDO sub : result)
	{
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub,
			grzlwzzzdpm, GRZLWZZZDPM,
			updateman, UPDATEMAN,
			pimpaperid, PIMPAPERID,
			createdate, CREATEDATE,
			updatedate, UPDATEDATE,
			createman, CREATEMAN,
			fbsj, FBSJ,
			pimpapername, PIMPAPERNAME,
			cbshkwmc, CBSHKWMC,
			pimpersonid, PIMPERSONID,
			fj, FJ,
			jlspzt, JLSPZT,
			jlglbh, JLGLBH,
			jlczz, JLCZZ,
			jlss, JLSS,
			cbs, CBS,
			kwmc, KWMC,
			kwqs, KWQS,
			reason, REASON,
		
			enable,ENABLE,
			orgid, ORGID,
			orgsectorid, ORGSECTORID,
			ormorgid, ORMORGID,
			ormorgsectorid, ORMORGSECTORID,
			pimpapername,PIMPERSONNAME,
			ygbh,YGBH
		)
	}
	return dto;
}

// �޸�����
bool PaperService::updateData(const ModifyPaperinfoDTO::Wrapper& dto)
{
	// ��װDO����
	J_PaperinfoDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, PIMPAPERNAME, pimpapername, CBS, cbs, KWMC, kwmc, KWQS, kwqs, FBSJ, fbsj, GRZLWZZZDPM, grzlwzzzdpm, FJ, fj, PIMPAPERID, pimpaperid,UPDATEDATE,updatedate,UPDATEMAN,updateman)
		// ִ�������޸�
		PaperinfoDAO dao;
	return dao.update(data) == 1;
}


