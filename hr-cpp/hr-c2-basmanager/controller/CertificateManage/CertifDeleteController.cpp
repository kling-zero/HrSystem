/*
��֤�����-֤����Ϣ-ɾ��֤�飨֧������ɾ������--����
*/
#include "stdafx.h"
#include "CertifDeleteController.h"
#include "../../service/CertificateManage/DeleteCertifService.h"

StringJsonVO::Wrapper CertifDeleteController::execRemoveCertif(const RemoveCertifDTO::Wrapper& dto)
{

	auto jvo = StringJsonVO::createShared();

	int length = dto->idByBatch->size();
	if (length <= 0 || !dto->idByBatch) {
		jvo->init(string("param null"), RS_PARAMS_INVALID);
		return jvo;
	}

	for (auto it = dto->idByBatch->begin(); it!=dto->idByBatch->end(); ++it)
	{
		if ((*it)->size()!=36) {//���жϱ�Ÿ�ʽ�Ƿ����//��һ���ŵ��ַ�����Ϊ32
			jvo->init(string("param err"), RS_PARAMS_INVALID);
			return jvo;
		}
	}

	stringstream str;
	for (auto it = dto->idByBatch->begin(); it != dto->idByBatch->end(); ++it) str << (*it).getValue("") <<" ";

	if (DeleteCertifService().removeData(dto)) jvo->success(str.str());
	else jvo->fail(str.str());

	return jvo;
}