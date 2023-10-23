#include"stdafx.h"
#include"RewardAndPunishmentInformationController.h"
#include "../../service/rewardandpunishmentinformation/RewardAndPunishmentInformationService.h"
#include "rocketmq/RocketMQClient.h"


//��ѯ
RewardAndPunishmentInformationPageJsonVO::Wrapper RewardAndPunishmentInformationController::execQueryRewardAndPunishmentInformation(const RewardAndPunishmentInformationPageQuery::Wrapper& query)
{
	auto vo = RewardAndPunishmentInformationPageJsonVO::createShared();

	auto pdto = RewardAndPunishmentInformationPageDTO::createShared();
	// ����һ��Service
	RewardAndPunishmentInformationService service;
	//// ��ѯ����
	 pdto = service.listAll(query);
	 
	 vo->success(pdto);
	
	 return vo;
}

//����
Uint64JsonVO::Wrapper RewardAndPunishmentInformationController::execAddRewardAndPunishmentInformation(const AddRewardAndPunishmentInformationDTO::Wrapper& dto, const PayloadDTO& payload)
{
	auto jvo = Uint64JsonVO::createShared();
	if (!dto->lx || !dto->jlsj || !dto->jcsj || !dto->jcje || !dto->jcjb || !dto->bz || !dto->pimrewardpunishmentname || !dto->pimpersonid || !dto->pimrewardpunishmentid)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	//��Чֵ����
	if (dto->lx->empty() || dto->jlsj->empty() || dto->jcsj->empty() || dto->jcjb->empty() || dto->bz->empty() || dto->pimrewardpunishmentname->empty() || dto->pimpersonid->empty() || dto->pimrewardpunishmentid->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	//�������ϴ�
	RewardAndPunishmentInformationService service;
	uint64_t id = service.saveData(dto, payload);
	if (id > 0) {
		jvo->success(UInt64(id));
	}
	else
	{
		jvo->fail(UInt64(id));
	}

	return jvo;
}

//ɾ��
Uint64JsonVO::Wrapper RewardAndPunishmentInformationController::execDelRewardAndPunishmentInformation(const DelRewardAndPunishmentInformationDTO::Wrapper& dto)
{
	auto jvo = Uint64JsonVO::createShared();

	int length = dto->deleteById->size();

	if (length <= 0 || !dto->pimpersonid)
	{
		jvo->init(uint64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	for (auto it = dto->deleteById->begin(); it != dto->deleteById->end(); ++it)
	{
		if (!(*it))
		{
			jvo->init(uint64(-1), RS_PARAMS_INVALID);
			return jvo;
		}
	}
	RewardAndPunishmentInformationService service;
	if (service.removeData(dto))
	{
		jvo->success(1);
	}
	else
	{
		jvo->fail(1);
	}
	return jvo;
}

//����
StringJsonVO::Wrapper RewardAndPunishmentInformationController::execRewardAndPunishmentInformationInto(const String& body, const String& suffix, const String& pimpersonid, const PayloadDTO& payload)
{
	auto jvo = StringJsonVO::createShared();
	if (!pimpersonid || !body || !suffix)
	{
		jvo->fail("����ʧ��,�ļ�Ϊ��");
	}
	if (pimpersonid->empty() || body->empty() || suffix->empty())
	{
		jvo->fail("����ʧ��,û������");
	}
	RewardAndPunishmentInformationService service;
	service.saveManyData(body, suffix, pimpersonid, payload);
	jvo->success("�ļ�����ɹ�");
	return jvo;
}
	
