#include "stdafx.h"//cpp�ļ���һ���µ���Ԥ�����ͷ
#include "controller/GoshController/TestController.h"
#include "service/Gosh/GoshService.h"
#include "domain/vo/Gosh/ContractVO.h"

//��ʾ��ѯ��ͬ��Ϣ
ContractPageJsonVO::Wrapper GoshController::execQueryContract(const ContractQuery::Wrapper& query, const PayloadDTO& payload)
{
	// ����һ��Service
	GoshService service;
	// ��ѯ����
	auto result = service.listContract(query);
	// ��Ӧ���
	auto jvo = ContractPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
//��ʾ��ѯ������Ϣ
ContractPageJsonVO::Wrapper GoshController::execQueryPerson(const ContractQuery::Wrapper& query, const PayloadDTO& payload)
{
	// ����һ��Service
	GoshService service;
	// ��ѯ����
	auto result = service.listPerson(query);
	// ��Ӧ���
	auto jvo = ContractPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
//��ʾ������ͬ����
Uint64JsonVO::Wrapper GoshController::execAddContract(const ContractDTO_gs_insert::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	// �ǿ�У��
	if (dto->personid->empty()||dto->type->empty() || dto->variety->empty() || dto->date->empty() || dto->condition->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	GoshService service;
	// ִ����������
	uint64_t id = service.saveData(dto);
	if (id >= 0) {
		jvo->success(UInt64(1));
	}
	else
	{
		jvo->fail(UInt64(-1));
	}
	//��Ӧ���
	return jvo;
}
//��ʾ����ɾ����ͬ����
Uint64JsonVO::Wrapper GoshController::execRemoveContract(const ContractDTO_gs_delete::Wrapper& dto)
{
	auto jvo = Uint64JsonVO::createShared();

	int length = dto->deleteById->size();

	if (length <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	for (auto it = dto->deleteById->begin(); it != dto->deleteById->end(); ++it)
	{
		if (!(*it))
		{
			jvo->init(UInt64(-1), RS_PARAMS_INVALID);
			return jvo;
		}
	}

	GoshService service;
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