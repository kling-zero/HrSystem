#include "stdafx.h"
#include "CertificateController.h"
#include"../../service/Certificate/CertificateService.h"

// ��ҳ��ѯ����
CertificatePageJsonVO::Wrapper CertificateController::execQueryCertificate(const CertificateQuery::Wrapper& query, const PayloadDTO& payload)
{
	// ����һ��Service
	CertificateService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = CertificatePageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

// ��������
Uint64JsonVO::Wrapper CertificateController::execAddCertificate(const CertificateDTO::Wrapper& dto)
{

	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	// �ǿ�У��
	if (!dto->seialno || !dto->pimqualtypename)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	//// ��ЧֵУ��
	if (dto->seialno < 0 || dto->pimqualtypename->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// ����һ��Service
	CertificateService service;
	// ִ����������
	uint64_t id = service.saveData(dto);
	jvo->success(UInt64(id));

	return jvo;
}
// �޸�����
Uint64JsonVO::Wrapper CertificateController::execModifyCertificate(const CertificateDTO::Wrapper& dto)
{
	// ���巵�����ݶ���

	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	if (!dto->seialno || dto->seialno <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	CertificateService service;
	service.updateData(dto);
	jvo->success(dto->seialno);
	return jvo;
}

// ɾ������
Uint64JsonVO::Wrapper CertificateController::execRemoveCertificate(const CertificateDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	if (!dto->seialno || dto->seialno <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	CertificateService service;
	// ִ������ɾ��
	service.removeData(dto->seialno.getValue(0));
	jvo->success(dto->seialno);

	// ��Ӧ���
	return jvo;
}
