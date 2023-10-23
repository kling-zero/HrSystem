#include "stdafx.h"
#include "LegalEntityMaiController.h"
#include "service/LegalEntityMai/LegalEntityMaiService.h"
#include "oatpp/core/utils/ConversionUtils.hpp"
#include <iostream>
#include <sstream>
#include <chrono>
#include <iomanip>
#include "FastDfsClient.h"
#include "tree/TreeUtil.h"
#include "../include/ExcelComponent.h"
#include "CommonMacros.h"

/* ��������ά������������ʵ��--����֯����-��������-��������ά����--TripleGold */

LegalEntityMaiPageJsonVO::Wrapper LegalEntityMaiController::execQueryLEM(const LegalEntityMaiQuery::Wrapper& query)
{
	// ����һ��Service
	LegalEntityMaiService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = LegalEntityMaiPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

StringJsonVO::Wrapper LegalEntityMaiController::execUpdateLEM(const LegalEntityMaiDTO::Wrapper& dto)
{
	//// ���巵�����ݶ���
	//auto jvo = Uint64JsonVO::createShared();
	//// ����У��
	//if (dto->ORMSIGNORGID == "") {

	//}
	// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();
	// ����У��
	if (!dto->ORMSIGNORGID || dto->ORMSIGNORGID == "") {
		jvo->init(String(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	LegalEntityMaiService service;
	// ִ�������޸�
	if (service.updateData(dto)) {
		jvo->success(dto->ORMSIGNORGID);
	}
	else {
		jvo->fail(dto->ORMSIGNORGID);
	}
	// ��Ӧ���
	return jvo;
}

Uint64JsonVO::Wrapper LegalEntityMaiController::execAddLEM(const List<LegalEntityMaiAddDTO::Wrapper>& dtoList, const PayloadDTO& payload)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();

	int length = dtoList->size();
	// ��������
	if (length <= 0) {
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	for (auto it = dtoList->begin(); it != dtoList->end(); it++)
	{
		if (!(*it)) {
			jvo->init(UInt64(-1), RS_PARAMS_INVALID);
			return jvo;
		}
	}
	// ����һ��Service
	LegalEntityMaiService service;
	bool res = true;
	for (auto it = dtoList->begin(); it != dtoList->end(); it++)
	{
		if (!service.saveData(*it, payload)) {
			res = false;
		}
	}
	// ֻҪ��һ������ʧ�ܼ�����fail
	if (res) jvo->success(1);
	else jvo->fail(1);

	// ��Ӧ���
	return jvo;
}

Uint64JsonVO::Wrapper LegalEntityMaiController::execRemoveLEM(const LegalEntityMaiDelDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();

	int length = dto->Ids->size();
	// ��������
	if (length <= 0) {
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	for (auto it = dto->Ids->begin(); it != dto->Ids->end(); it++)
	{
		if (!(*it)) {
			jvo->init(UInt64(-1), RS_PARAMS_INVALID);
			return jvo;
		}
	}

	// ����һ��Service
	LegalEntityMaiService service;
	if (service.deleteById(dto)) {
		jvo->success(1);
	}
	else {
		jvo->fail(1);
	}
	// ��Ӧ���
	return jvo;
}

void directory(const string fileName) {
	//�ж�Ŀ¼�Ƿ���ڣ������ڴ���Ŀ¼
	auto dir = fileName.substr(0, fileName.find_last_of("/") + 1);
	const size_t dirLen = dir.length();
	if (dirLen > MAX_DIR_LEN)
	{
		std::cout << "ExcelComponent 135: excel save fail(file path too long)" << std::endl;
		return;
	}
	char tmpDirPath[MAX_DIR_LEN] = { 0 };
	for (size_t i = 0; i < dirLen; i++)
	{
		tmpDirPath[i] = dir[i];
		if (tmpDirPath[i] == '/')
		{
			if (ACCESS(tmpDirPath, 0) != 0)
			{
				if (MKDIR(tmpDirPath) != 0)
				{
					std::cout << "ExcelComponent 148: excel save fail(create dir " << tmpDirPath << " fail)" << std::endl;
					return;
				}
			}
		}
	}
}

StringJsonVO::Wrapper LegalEntityMaiController::execImportLEM(const String& body, const String& suffix, const PayloadDTO& payload)
{
	// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();
	// ����У��
	if (!body || body->empty() || !suffix || suffix->empty()) {
		jvo->fail("fail to import");
	}

	// ����ʱ�������һ����ʱ�ļ�����
	std::stringstream ss;
	ss << "public/excel/";

	// ����ʱ���
	auto now = std::chrono::system_clock::now();
	auto tm_t = std::chrono::system_clock::to_time_t(now);
	ss << std::put_time(std::localtime(&tm_t), "%Y%m%d%H%M%S");
	// ��ȡ����
	auto tSeconds = std::chrono::duration_cast<std::chrono::seconds>(now.time_since_epoch());
	auto tMilli = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch());
	auto ms = tMilli - tSeconds;
	ss << std::setfill('0') << std::setw(3) << ms.count();
	// ƴ�Ӻ�׺��
	ss << suffix.getValue("");

	// ��ʱ�ļ�����
	std::string fileName = ss.str();
	// ����ļ�Ŀ¼�����ڣ����Ŀ¼
	directory(fileName);
	// �����ļ�����ʱĿ¼
	body.saveToFile(fileName.c_str());

	// ����һ��Service
	LegalEntityMaiService service;
	service.savaBatchDataWithFile(fileName, payload);
	// ��Ӧ���
	jvo->success(String(ss.str().c_str()));
	return jvo;
}

StringJsonVO::Wrapper LegalEntityMaiController::execExportLEM(const LegalEntityMaiQuery::Wrapper& query)
{
	// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();
	// ����һ��Service
	LegalEntityMaiService service;
	// ִ���ļ�����
	std::string fileName = service.exportFile(query);
	if (fileName.empty()) {
		jvo->fail("fail to export");
	}
	else {
		jvo->success(fileName);
	}
	// ��Ӧ���
	return jvo;
}