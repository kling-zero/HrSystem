/*
 Copyright Zero One Star. All rights reserved.

 @Author: yuanxiang
 @Date: 2023/05/23 17:01:55

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#include "stdafx.h"
#include "ProjTagService.h"
#include "domain/do/projTag/ProjTagDO.h"
#include "domain/dto/projTag/AddProjTagDTO.h"
#include "dao/projTag/ProjTagDAO.h"
#include "SimpleDateTimeFormat.h"
#include "ExcelComponent.h"
#include "domain/vo/projTag/ImportTagVO.h"
#include "uselib/excel/ExportExcel.h"
#include "uselib/fastdfs/UseFastDfs.h"
#include "SnowFlake.h"
// �ļ���DO��
#define FILE_TO_DO(target, src, f1, f2) target.set##f1(src.f2);
#define INDEX(x, y) at(x).at(y)
#define ZO_STAR_FILE_TO_DO(target, src, ...) \
ZO_STAR_EXPAND(ZO_STAR_PASTE(target, src, FILE_TO_DO, __VA_ARGS__))

std::string ProjTagService::saveData(ProjTagDO& data)
{
	// ����ѩ��ID
	SnowFlake f(1, 1);
	auto id = std::to_string(f.nextId());
	data.setId(id);
	// ִ�в������
	ProjTagDAO dao;
	if (dao.insert(data)) {
		return id;
	}
	else {
		return "-1";
	}
}

OrgListPageDTO::Wrapper ProjTagService::listOrgList(const OrgListQuery::Wrapper& query)
{
	// �������ض���
	auto dto = OrgListPageDTO::createShared();
	dto->pageIndex = query->pageIndex;
	dto->pageSize = query->pageSize;

	// ��ȡ��ѯ������
	ProjTagDAO dao;
	uint64_t cnt = dao.count(query);
	if (cnt <= 0)
	{
		return dto;
	}

	// ��ҳ��ѯ����
	dto->total = cnt;
	dto->calcPages();
	list<OrgListDO> res = dao.selectOrgList(query);
	// ��DOת��DTO
	for (OrgListDO item : res)
	{
		auto to_dto = OrgListDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(to_dto, item, regionSubsidy, RegionSubsidy, flag, Flag, createby, CreateTime, updater, Updater, updateTime, UpdateTime, erpOrgId, ErpOrgId, belongRegion, BelongRegion, legalEntity, LegalEntity, levelCode, LevelCode, orgCode, OrgCode, orgId, OrgId, orgName, OrgName, porgId, PorgId, porgName, PorgName, shortname, Shortname, belongou, Belongou, sign, Sign, orgAddrCode, OrgAddrCode, orgAddrOne, OrgAddrOne, orgAddrTwo, OrgAddrTwo, orgCreateTime, OrgCreateTime, name, Name, orgType, OrgType, correspondou, Correspondou);
		dto->addData(to_dto);
	}
	return dto;
}

bool ProjTagService::updateProjTag(const ModifyTagDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// ��װDO����
	ProjTagDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Id, tagId, OrgId, orgId, TagName, tagName);
	data.setUpdater(payload.getUsername());
	data.setUpdateTime(SimpleDateTimeFormat::format());
	// TODO: ����dao�������ݿ�
	ProjTagDAO dao;
	return dao.updateProjTag(data);
}

ImportTagVO::Wrapper ProjTagService::addMultiTag(const ImportTagDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// ����Excel����
	ExcelComponent excel;
	// ���ļ����ݶ�ȡ����
	auto data = excel.readIntoVector(std::string(dto->filePath), std::string(dto->sheetName));
	
	// �������ض���
	auto vo = ImportTagVO::createShared();
	
	// �ж��������Ƿ񳬹�ָ��ֵ
	//if (data.size() > 5000) {
	//	// ���������󣬷��� -1
	//	vo->newId->push_back("-1");
	//	return vo;
	//}

	// �����ֶ�����ӳ��
	unordered_map<string, int> hash;
	for (size_t i = 0; i < data[0].size(); i++)
	{
		hash[data[0][i]] = i;
	}

	string name = payload.getUsername();
	string day = SimpleDateTimeFormat::format();

	// ����ѩ��ID
	SnowFlake f(1,1);
	auto f_id = std::to_string(f.nextId());
	// �ļ����ݵ�DO
	list<ProjTagDO> all;
	list<string> res;
	// ����DAO�������ݿ�
	ProjTagDAO dao;
	auto sqlsession = dao.getSqlSession();
	// ��������
	sqlsession->beginTransaction();
	// ���úò������ݺ󣬶��ִ�е������ݲ���
	for (size_t i = 1; i < data.size() && i <= 5000; i++)
	{
		ProjTagDO tmp;
		ZO_STAR_FILE_TO_DO(tmp, data, 
			/*Id, INDEX(i, hash["ORMXMBQID"]),*/
			TagName, INDEX(i, hash["ORMXMBQNAME"]),
			OrgId, INDEX(i, hash["ORMORGID"])
		);
		tmp.setId(f_id);
		tmp.setUpdateTime(day);
		tmp.setCreateTime(day);
		tmp.setUpdater(name);
		tmp.setCreator(name);
		// ִ�е�������
		auto ret = dao.insert(tmp);
		if (ret == 0) {
			// ĳ��ִ��ʧ�ܣ�����ع�
			sqlsession->rollbackTransaction();
			res.clear();
			// �ļ������ݲ��������ݿ��������������� -2
			vo->newId->push_back("-2");
			return vo;
		}
		else {
			// ִ�гɹ�����id���뷵���б���
			res.push_back(f_id);
		}
		// �����µ�ѩ��id
		f_id = std::to_string(f.nextId());
	}

	// ȫ��ִ�гɹ����ύ����
	sqlsession->commitTransaction();

	if (res.size())
	{
		for (const auto& item : res)
			vo->newId->push_back(item);
	}
	return vo;
}

std::string ProjTagService::exportProjTag(const ExportProjTagQuery::Wrapper& query)
{
	// TODO: ����DAO��ѯ��������
	ProjTagDAO dao;
	auto res = dao.exportProjTag(query);

	// TODO: ��װ���ݵ�Excel�ļ�
	ExportExcel excel;

	// ��ȡ���ݵ���ά����
	vector<vector<string>> data;
	for (const auto& item : res)
	{
		vector<string> tmp;
		tmp.push_back(item.getId());
		tmp.push_back(item.getCreator());
		tmp.push_back(item.getTagName());
		tmp.push_back(item.getUpdater());
		tmp.push_back(item.getCreateTime());
		tmp.push_back(item.getUpdateTime());
		tmp.push_back(item.getOrgId());
		data.push_back(tmp);
	}

	// �������ݱ��ͷ
	vector<string> head = dao.getHead();
	head.erase(head.begin() + 6);
	// ������Excel�ļ�
	data.insert(data.begin(), head);
	string fileName = excel.exportExcel(data);

	// TODO: �ϴ���FastDFS�ļ�������, ������������
	UseFastDfs dfs;
	string url = dfs.uploadWithNacos(fileName);

	return url;
}

ProjTagPageDTO::Wrapper ProjTagService::listProjTagList(const PageProjTagQuery::Wrapper& query) {
	// �������ض���
	auto dto = ProjTagPageDTO::createShared();
	dto->pageIndex = query->pageIndex;
	dto->pageSize = query->pageSize;

	// ��ȡ��ѯ������
	ProjTagDAO dao;
	uint64_t cnt = dao.count(query);
	if (cnt <= 0)
	{
		return dto;
	}

	// ��ҳ��ѯ����
	dto->total = cnt;
	dto->calcPages();
	list<ProjTagDO> res = dao.selectProjTag(query);
	// ��DOת��DTO
	for (ProjTagDO item : res)
	{
		auto to_dto = ProjTagDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(to_dto, item, ormxmbqid, Id, createman, Creator, ormxmbqname, TagName, updateman, Updater, createdate, CreateTime, updatedate, UpdateTime, ormorgid, OrgId);
		dto->addData(to_dto);
	}
	return dto;
}
