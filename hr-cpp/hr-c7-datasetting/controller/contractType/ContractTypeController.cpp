#include "stdafx.h"
#include "ContractTypeController.h"
#include"../../service/contractType/ContractTypeService.h"

ContractTypePageJsonVO::Wrapper  ContractTypeController::execQueryContractType(const ContractTypeQuery::Wrapper& query, const PayloadDTO& payload)
{
	// ����һ��Service
	ContractTypeService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	// ������Ӧ����
	auto jvo = ContractTypePageJsonVO::createShared();
	// ������ҳ����
	/*auto pdto = ContractTypePageDTO::createShared();
	pdto->addData(ContractTypeDTO::createShared("1", "zs"));
	pdto->addData(ContractTypeDTO::createShared("2", "ls"));*/
	jvo->success(result);
	//jvo->success(pdto);
	return jvo;
}

Uint64JsonVO::Wrapper ContractTypeController::execAddContractType(const ContractTypeDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��&�ǿ�У�� ���ж�ֵ(|| !dto->department || !dto->stat)

	if (!dto->id || !dto->name) {
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ��ЧֵУ��
	if (stoll(dto->id) < 0 || dto->name->empty()) {
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// ����һ��Service
	ContractTypeService service;
	// ��������
	uint64_t id = service.saveData(dto);
	if (id > 0) {
		jvo->success(UInt64(id));
	}
	else
	{
		jvo->fail(UInt64(id));
	}
	//��Ӧ���
	//jvo->success(1);
	return jvo;
}

Uint64JsonVO::Wrapper ContractTypeController::execModifyContractType(const ContractTypeDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��

	if (!dto->id || stoll(dto->id) <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// ����һ��Service
	ContractTypeService service;
	// ִ�������޸�
	if (service.updateData(dto)) {
		jvo->success(stoull(dto->id));
	}
	else
	{
		jvo->fail(stoull(dto->id));
	}
	// ��Ӧ���
	//jvo->success(1);

	return jvo;
}

Uint64JsonVO::Wrapper ContractTypeController::execRemoveContractType(const ContractTypeDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	if (!dto->id || stoll(dto->id) <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// ����һ��Service
	ContractTypeService service;
	// ִ������ɾ��
	if (service.removeData(stoull(dto->id))) {
		jvo->success(stoull(dto->id));
	}
	else
	{
		jvo->fail(stoull(dto->id));
	}
	// ��Ӧ���
	//jvo->success(1);
	return jvo;
}
