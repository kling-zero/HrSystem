#include "stdafx.h"
#include "MilitaryController.h"
#include "../../service/military/MilitaryService.h"
#include <iostream>

MilitaryJsonVO::Wrapper MilitaryController::execQueryMilitary(const MilitaryDetailQuery::Wrapper& query) {
	// ��Ӧ���
	auto jvo = MilitaryJsonVO::createShared();
	// ����һ��Service
	MilitaryService service;
	// ��ѯ����
	auto result = service.listDetail(query);
	if (result->PIMARMYCADRESID.getValue("").empty()) {
		cout << "No details were found" << endl;
		jvo->fail(result);
	}
	else {
		jvo->success(result);
	}
	return jvo;
}

StringJsonVO::Wrapper MilitaryController::execModifyMilitary(const MilitaryDTO::Wrapper& dto, const PayloadDTO& payload)
{
	//��ȡ�޸���id
	dto->UPDATEMAN = payload.getId();
	//��ȡ��ǰʱ��
	time_t timep;
	time(&timep);
	char tmp[256];
	strftime(tmp, sizeof(tmp), "%Y-%m-%d %H:%M:%S", localtime(&timep));
	//���ĸ���ʱ��
	dto->UPDATEDATE = tmp;
	// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();
	// ����У��
	if (dto->PIMARMYCADRESID.getValue("").empty())
	{
		jvo->init(String("PIMARMYCADRESID must be not null"), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	MilitaryService service;
	// ִ�������޸�
	if (service.updateData(dto)) {
		jvo->success(dto->PIMARMYCADRESID);
	}        
	else
	{
		cout << "The primary key is not found or the data is consistent before and after the modification!" << endl;
		jvo->fail(dto->PIMARMYCADRESID);
	}
	// ��Ӧ���
	return jvo;
}

StringJsonVO::Wrapper MilitaryController::execDownloadMilitary(const MilitaryDownloadQuery::Wrapper& query)
{
	// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();
	string filedName = MilitaryService().download(query);
	// ��Ӧ���
	if (filedName.empty()) {
		jvo->fail("download failed!");
	}
	else {
		jvo->success(filedName);
	}
	return jvo;
}
