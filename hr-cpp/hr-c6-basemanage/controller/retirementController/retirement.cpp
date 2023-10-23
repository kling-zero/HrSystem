#include "stdafx.h"
#include "retirement.h"
#include "service/reitirement/retirementService.h"

RetirementQueryPageJsonVO::Wrapper RetirementController::execQueryTest(const RetirementQuery_gan::Wrapper & query)
{
	// ����һ��Service
	retirementService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = RetirementQueryPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
/*
StringJsonVO::Wrapper TestController::execQueryTest1(const PageQuery::Wrapper& query1)
{
	auto vo = StringJsonVO::createShared();
	vo->success("test qurey1 success");
	return vo;
}
*/

/*
Uint64JsonVO::Wrapper TestController::execAddSample(const SampleDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	// �ǿ�У��
	if (!dto->age || !dto->name || !dto->sex)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ��ЧֵУ��
	if (dto->age < 0 || dto->name->empty() || dto->sex->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	//��Ӧ���
	return jvo;
}

Uint64JsonVO::Wrapper TestController::execAddSample1(const RetirementDTO::Wrapper& dto)
Uint64JsonVO::Wrapper RetirementController::execAddSample1(const RetirementDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ��Ӧ���
	return jvo;
}

Uint64JsonVO::Wrapper RetirementController::execModifySample(const RetirementDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ��Ӧ���
	return jvo;
}

Uint64JsonVO::Wrapper RetirementController::execRemoveSample(const RetirementDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();

	// ��Ӧ���
	return jvo;
}
*/