/*
 Copyright Zero One Star. All rights reserved.

 @Author: guyier
 @Date: 2023/05/25 15:38:37

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
#include "EmployeeInformationServicer.h"
#include "dao/EmployeeInformation/EmployeeInformationDAO.h"
#include "SnowFlake.h"
#include "SimpleDateTimeFormat.h"
#include "CustomerAuthorizeHandler.h"
#include "ExcelComponent.h"
#include "domain/do/EmployeeInformationPage/EmployeeInformationPageDO.h"
#include "uselib/excel/ExportExcel.h"
#include <uselib/fastdfs/UseFastDfs.h>

// �ļ���DO��
#define FILE_TO_DO(target, src, f1, f2) target.set##f1(src.f2);
#define INDEX(x, y) at(x).at(y)
#define ZO_STAR_FILE_TO_DO(target, src, ...) \
ZO_STAR_EXPAND(ZO_STAR_PASTE(target, src, FILE_TO_DO, __VA_ARGS__))

// ��ҳ��ѯ��������
EmployeeInformationPageDTO::Wrapper EmployeeInformationServicer::listAll(const EmployeeInformationPageQuery::Wrapper& query)
{
	// �������ض���
	auto pages = EmployeeInformationPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	EmployeeInformationDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<EmployeeInformationPageDO> result = dao.selectWithPage(query);
	
	// ��DOת����DTO
	for (EmployeeInformationPageDO sub : result)
	{
		auto dto = EmployeeInformationDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, name, Name, age, Age, id, Id, \
	    organize, Organize, depart, Depart, job, Job, post, Post, idMum, IdMum,\
		birthday, Birthday, phone, Phone, state, State);
		pages->addData(dto);

	}
	return pages;
}
//����Ա����Ϣ
uint64_t EmployeeInformationServicer::saveData(const EmployeeInformationDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// ��װDO����
	EmployeeInformationPageDO data;

	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, PersonId, personId, CreateMan, createMan, CreateDate, createDate,\
	Name, name, Age, age, Id, id, Organize, organize, Depart, depart,\
		Job, job, Post, post, IdMum, idMum, Birthday, birthday, Phone, phone,\
		State, state);

	// ��������
	SnowFlake sf(1, 3);//ѩ���㷨
	data.setPersonId(to_string(sf.nextId()));
	//������
	data.setCreateMan(payload.getId());
	//����ʱ��
	SimpleDateTimeFormat sdtf;//��ȡ��ǰʱ���ʽ�ַ���
	data.setCreateDate(sdtf.format());

	// ��Ҫ�ٷ��������ɵ�����
	data.setName(dto->name);
	data.setAge(dto->age);
	data.setId(dto->id);
	data.setOrganize(dto->organize);
	data.setDepart(dto->depart);
	data.setJob(dto->job);
	data.setPost(dto->post);
	data.setIdMum(dto->idMum);
	data.setBirthday(dto->birthday);
	data.setPhone(dto->phone);
	data.setState(dto->state);
	// ִ���������
	EmployeeInformationDAO dao;
	return dao.insert(data);
}
//����Ա����Ϣ(��������)
importInfoVO::Wrapper EmployeeInformationServicer::addMultiEmployee(const ImportInfoDTO::Wrapper& dto, const PayloadDTO& payload) {

	// ����Excel����
	ExcelComponent excel;
	// ���ļ����ݶ�ȡ����
	auto data = excel.readIntoVector(std::string(dto->filePath), std::string(dto->sheetName));

	// �����ֶ�����ӳ��
	unordered_map<string, int> hash;
	for (int i = 0; i < static_cast<int>(data[0].size()); i++)
	{
		hash[data[0][i]] = i;
	}

	// ����SnowFlake����
	SnowFlake sf(1, 3);//ѩ���㷨
	string name = payload.getId();
	string day = SimpleDateTimeFormat::format();//��ȡ��ǰʱ���ʽ�ַ���
	// �ļ����ݵ�DO
	list<EmployeeInformationPageDO> all;
	for (int i = 1; i < static_cast<int>(data.size()); i++)
	{
		EmployeeInformationPageDO tmp;
		ZO_STAR_FILE_TO_DO(tmp, data,
			Name,INDEX(i,hash["NAME"]),
			Id,INDEX(i,hash["ID"]),
			Organize,INDEX(i,hash["ORGANIZE"]),
			Depart,INDEX(i,hash["DEPART"]),
			Job,INDEX(i,hash["JOB"]),
			Post,INDEX(i,hash["POST"]),
			IdMum,INDEX(i,hash["IDMUN"]),
			Birthday,INDEX(i,hash["BIRTHDAY"]),
			Phone,INDEX(i,hash["PHONE"]),
			State,INDEX(i,hash["STATE"])
		);
		//����
		tmp.setAge(atoi(data[i][hash["AGE"]].c_str()));
		//��������
		tmp.setPersonId(to_string(sf.nextId()));
		//������
		tmp.setCreateMan(name);
		//����ʱ��
		tmp.setCreateDate(day);
		all.push_back(tmp);
	}

	// ����DAO�������ݿ�
	EmployeeInformationDAO dao;
	SqlSession* ss = dao.getSqlSession();
	// ����������
	ss->beginTransaction();

	std::list<std::string> res;
	for (auto item : all)
	{
		long long line = dao.insert(item);
		// �����ɹ������һ���µ�id
		if (line == 1)
		{
			res.push_back(item.getPersonId());
		}
		// �����������id�����б��ع�
		else
		{
			ss->rollbackTransaction();
			res.clear();
			break;
		}
	}

	// �ύ����
	ss->commitTransaction();

	// �������ض���
	auto vo = importInfoVO::createShared();
	if (res.size())
	{
		for (auto item : res)
			vo->newId->push_back(item);
	}

	return vo;
}
//����Ա����Ϣ(������ҳ��ǰ�����)
std::string EmployeeInformationServicer::exportEmpInfomation(const PostDetailQuery::Wrapper& query)
{
	EmployeeInformationDAO dao;
	auto res = dao.exportEmpInfo(query);

	ExportExcel excel;

	vector<vector<string>> data;
	for (auto item : res)
	{
		vector<string> tmp;
		tmp.push_back(item.getName());
		tmp.push_back(to_string(item.getAge()));
		tmp.push_back(item.getId());
		tmp.push_back(item.getOrganize());
		tmp.push_back(item.getDepart());
		tmp.push_back(item.getJob());
		tmp.push_back(item.getPost());
		tmp.push_back(item.getIdMum());
		tmp.push_back(item.getBirthday());
		tmp.push_back(item.getPhone());
		tmp.push_back(item.getState());
		data.push_back(tmp);
	}

	// �������ݱ��ͷ
	vector<string> head = dao.getEmpInfoHead();

	// ������Excel�ļ�
	data.insert(data.begin(), head);
	string fileName = excel.exportExcel(data);

	// TODO: �ϴ���FastDFS�ļ�������, ������������
	UseFastDfs dfs;
	string url = dfs.uploadWithNacos(fileName);

	return url;
}
