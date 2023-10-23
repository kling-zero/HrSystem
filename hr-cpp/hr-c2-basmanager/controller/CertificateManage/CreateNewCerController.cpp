#include "stdafx.h"
#include "CreateNewCerController.h"
#include "../../service/CertificateManage/CreateNewCerService.h"
/**
  �½�֤��--(֤�����-�½�֤��)--pine
 */
Uint64JsonVO::Wrapper CreateNewCerController::execAddNewCer(const CreateNewCerDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();

	// �ǿ�У��
	if (!dto->ygbh || !dto->pimVocationalName)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ��ЧֵУ�� ygbh, pimvocationalid, bcardNumber, pimVocationalName, zslx, zghqrq, zgsydw, zcdw(��ʱ���ʽ���м���)

	if (dto->ygbh->empty() || dto->pimVocationalName->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}


	// ִ����������
	CreateNewCerService service;
	uint64_t id = service.saveData(dto);
	if (id > 0) {
		jvo->success(UInt64(id));
	}
	else
	{
		jvo->fail(UInt64(id));
	}
	return jvo;
}
