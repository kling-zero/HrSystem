/**
 *  ֤����� ���� ֤����Ϣ ���� ��ѯ������ָ��֤�� ���� ������
 */
#include "stdafx.h"
#include "UpdateCertificateController.h"
#include "../../service/CertificateManage/SpercificCertificateService.h"

StringJsonVO::Wrapper UpdateCertificateController::execUpdateSpercificCertificate(const SpercificCertificateDTO::Wrapper& dto)
{
	{
		// ���巵�����ݶ���
		auto jvo = StringJsonVO::createShared();
		// ����У��
		if (dto->PIMVOCATIONALID.getValue("").empty())
		{
			jvo->init(String("PIMVOCATIONALID must be not null"), RS_PARAMS_INVALID);
			return jvo;
		}
		// ����һ��Service
		SpercificCertificateService service;
		// ִ��������
		if (service.updateData(dto)) {
			jvo->success(dto->PIMVOCATIONALID);
		}
		else
		{
			jvo->fail(dto->PIMVOCATIONALID);
		}
		// ��Ӧ���
		return jvo;
	}
}

SpercificCertificateJsonVO::Wrapper UpdateCertificateController::execGetSpercificCertificate(const SpercificCertificateQuery::Wrapper& query)
{
	// ����һ��JsonVO����
	auto vo = SpercificCertificateJsonVO::createShared();
	// ����һ����ҳ����
	SpercificCertificateService service;
	auto result = service.querySpercificCertificate(query);

	vo->success(result);
	// ��Ӧ���
	return vo;
}