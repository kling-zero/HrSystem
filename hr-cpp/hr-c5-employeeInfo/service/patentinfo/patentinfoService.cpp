
#include "stdafx.h"
#include "service/patentinfo/patentinfoService.h"
#include "controller/patentinfo/PatentinfoController.h"
#include "domain/do/patentinfo/t_pimpatentDO.h"
#include "domain/dto/patentinfo/AddPatentDTO.h"
#include "domain/dto/patentinfo/DelPatentDTO.h"
#include "domain/dto/patentinfo/PatentinfoDTO.h"
#include "domain/query/patentinfo/PatentinfoQuery.h"
#include "dao/patentinfo/t_pimpatentDAO.h"
#include "SnowFlake.h"
#include "SimpleDateTimeFormat.h"

#include "../../dao/paperinfo/t_pimpaperDAO.h"

//// ��ҳ��ѯר����Ϣ 
//PatentinfoPageDTO::Wrapper PatentinfoService::listAll(const PatentinfoQuery::Wrapper& query)
//{ 
//	// �������ض���
//	auto pages = PatentinfoPageDTO::createShared();
//	pages->pageIndex = query->pageIndex;
//	pages->pageSize = query->pageSize;
//
//	// ��ѯ����������
//	t_pimpaperDAO dao;
//	uint64_t count = dao.count(query);
//	if (count <= 0)
//	{
//		return pages;
//	}
//
//	// ��ҳ��ѯ����
//	pages->total = count;
//	pages->calcPages();
//	list<t_pimpaperDO> result = dao.selectWithPage(query);
//	// ��DOת����DTO
//	for (t_pimpaperDO sub : result)
//	{
//		auto dto = PatentinfoPageDTO::createShared();
//		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, fbsj, Fbsj, cbs, Cbs, kwqs, Kwqs,
//			fj, Fj, grzlwzzzdpm, Grzlwzzzdpm, kwmc, Kwmc, pimpapername, Pimpapername);
//			pages->addData(dto);
//	}
//	return pages;
//}


// ����һ��ר����Ϣ
int PatentinfoService::saveData(const AddPatentDTO::Wrapper& dto)
{
	//SnowFlake sf(1, 4);
	// ��װDO����
	//SimpleDateTimeFormat times;
	PatentinfoDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto,
		ZLH, zlh,
		PIMPATENTNAME, pimpatentname,
		ZLHQSJ, zlhqsj,
		ZLPZGB, zlpzgb,
		PIMPATENTID, pimpatentid)
		//ENCLOLURE, enclolure,
		//CREATEDATE, creatdate,
		//UPDATEDATE, updatedate,
		//CREATEMAN, createman,
		//UPDATEMAN, updateman,

	//ѩ���㷨��������id
	SnowFlake snowFlake(1, 5);
	uint64_t id = snowFlake.nextId();
	string idStr = to_string(id);

	// ���ɵ�ǰʱ��
	time_t rawtime;
	struct tm* info;
	char buffer[80];
	time(&rawtime);
	info = localtime(&rawtime);
	strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", info);
	string datetime(buffer);


	// ִ���������
	t_pimpatentDAO dao;
	return dao.insert(data, idStr, datetime);
}



// ɾ��ר����Ϣ��֧������ɾ����
bool PatentinfoService::removeData(const oatpp::List<oatpp::String>& dto)
{
	t_pimpatentDAO dao;
	dao.getSqlSession()->beginTransaction();
	int row = 0;
	for (auto it = dto->begin(); it != dto->end(); ++it)
	{
		row += dao.deleteById((*it).getValue({}));
	}
	if (row == dto->size())
	{
		dao.getSqlSession()->commitTransaction();
		return true;
	}
	else
	{
		dao.getSqlSession()->rollbackTransaction();
		return false;
	}
}