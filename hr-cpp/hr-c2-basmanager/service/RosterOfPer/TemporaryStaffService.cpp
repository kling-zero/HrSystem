#include "stdafx.h"
#include "TemporaryStaffService.h"
#include "../../dao/RosterOfPer/TemporaryStaffDAO.h"

#include "CharsetConvertHepler.h"
#include "ExcelComponent.h"
#include <cstdio>
#include "FastDfsClient.h"

#ifdef LINUX
#include "../../ServerInfo.h"
#include "NacosClient.h"
#include "YamlHelper.h"
#endif
/**
* ��ְ��Աservice--(��Ա������-��ְ��Ա-��ҳ��ѯԱ���б�)--weixiaoman
*/
TemporaryStaffPageDTO::Wrapper TemporaryStaffService::listAll(const TempStaffQuery::Wrapper& query)
{
	// �������ض���
	auto pages = TemporaryStaffPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	TemporaryStaffDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<TemporaryStaffDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (TemporaryStaffDO sub : result)
	{
		auto dto = TemporaryStaffDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, ygbh, name, pimPersonName, empStatus,
			ygzt,tempStatus, gzzt, tempOrg, gzzz,
			tempDept, gzbm, tempStartTime, gzkssj,tempEndTime, gzjssj, pimpersonId, pimpersonId);
		pages->addData(dto);
	}
	return pages;
}

std::string TemporaryStaffService::exportData(const TempStaffQuery::Wrapper& query)
{
	//��ѯ���ݲ�����page�Ĵ�С��
	TemporaryStaffDAO dao;
	auto count = dao.count(query);
	//if (count > 5000) query->pageSize = 5000;
	//else query->pageSize = count ;
	//query->pageIndex = 1;
	list<TemporaryStaffDO> result = dao.selectExportDatas(query);

	//����excel����
	std::vector<std::vector<std::string>> datas;
	//����excel��ͷ
	std::vector<std::string> head_datas;
	head_datas.push_back(CharsetConvertHepler::ansiToUtf8("Ա�����"));
	head_datas.push_back(CharsetConvertHepler::ansiToUtf8("Ա������"));
	head_datas.push_back(CharsetConvertHepler::ansiToUtf8("Ա��״̬"));
	head_datas.push_back(CharsetConvertHepler::ansiToUtf8("��ְ״̬"));
	head_datas.push_back(CharsetConvertHepler::ansiToUtf8("��ְ��֯"));
	head_datas.push_back(CharsetConvertHepler::ansiToUtf8("��ְ����"));
	head_datas.push_back(CharsetConvertHepler::ansiToUtf8("��ְ��ʼʱ��"));
	head_datas.push_back(CharsetConvertHepler::ansiToUtf8("��ְ����ʱ��"));
	datas.push_back(head_datas);

	//�������
	for (auto data : result) {
		std::vector<std::string> row;
		row.push_back(data.getygbh());
		row.push_back(data.getpimPersonName());
		row.push_back(data.getygzt());
		row.push_back(data.getgzzt());
		row.push_back(data.getgzzz());
		row.push_back(data.getgzbm());
		row.push_back(data.getgzkssj());
		row.push_back(data.getgzjssj());
		datas.push_back(row);
	}

	//�����ļ�����ҳǩ����
	std::string fileName = "./TempStaffExport.xlsx";
	std::string sheetName = CharsetConvertHepler::ansiToUtf8("��ְԱ����");
	// ���浽�ļ�
	ExcelComponent excel;
	excel.writeVectorToFile(fileName, sheetName, datas);

	// ��������ǰ׺
	std::string urlPrefix;
#ifdef LINUX
	// ����һ��Nacos�ͻ��˶������ڻ�ȡ����
	NacosClient ns(ServerInfo::getInstance().getNacosAddr(), ServerInfo::getInstance().getNacosNs());
	// ����urlǰ׺
	auto thirdServerConfig = ns.getConfig("third-services.yaml");
	urlPrefix = "http://" + YamlHelper().getString(&thirdServerConfig, "fastdfs.nginx-servers") + "/";
	// ��Nacos�������Ļ�ȡFastDFS�ͻ�����������
	std::string config = ns.getConfigText("client.conf");
	// ����ͻ��˶���
	FastDfsClient client(config, false);
#else
	// ����urlǰ׺
	urlPrefix = "http://8.130.87.15:8888/";
	// ����ͻ��˶���
	FastDfsClient client("8.130.87.15");
#endif
	// �ϴ��ļ�
	std::string fieldName = client.uploadFile(fileName);
	//ɾ�������ļ�
	remove(fileName.c_str());
	// ��������·��
	std::string downloadUrl = urlPrefix + fieldName;
	// �������·��
	//std::cout << "download url: " << downloadUrl << std::endl;
	return downloadUrl;
}
