#include "stdafx.h"
#include "RewardAndPunishController.h"
#include "../../service/rewardandpunish/RewardAndPunishService.h"
#include <iostream>

RewardAndPunishJsonVO::Wrapper RewardAndPunishController::execQueryRewardAndPunish(const RewardAndPunishDetailQuery::Wrapper& query) {
	// ��Ӧ���
	auto jvo = RewardAndPunishJsonVO::createShared();
	// ����һ��Service
	RewardAndPunishService service;
	// ��ѯ����
	auto result = service.listDetail(query);
	if (result->PIMREWARDPUNISHMENTID.getValue("").empty()) {
		std::cout << "No details were found" << std::endl;
		jvo->fail(result);
	}
	else {
		jvo->success(result);
	}
	return jvo;
}

StringJsonVO::Wrapper RewardAndPunishController::execModifyRewardAndPunish(const RewardAndPunishDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();
	//����У��
	if (dto->PIMREWARDPUNISHMENTID.getValue("").empty())
	{
		jvo->init(String("PIMREWARDPUNISHMENTID must be not null"), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	RewardAndPunishService service;
	// ִ�������޸�
	if (service.updateData(dto)) {
		jvo->success(dto->PIMREWARDPUNISHMENTID);
	}
	else
	{
		jvo->fail(dto->PIMREWARDPUNISHMENTID);
	}
	// ��Ӧ���
	return jvo;
}

StringJsonVO::Wrapper RewardAndPunishController::execDownloadRewardAndPunish(const RewardAndPunishDownloadQuery::Wrapper& query)
{
	// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();
	string filedName = RewardAndPunishService().download(query);
	// ��Ӧ���
	if (filedName.empty()) {
		jvo->fail("download failed!");
	}
	else {
		jvo->success(filedName);
	}
	return jvo;
}
