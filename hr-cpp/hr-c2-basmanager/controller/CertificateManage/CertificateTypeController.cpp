#include "stdafx.h"
#include "CertificateTypeController.h"
#include "../../service/CertificateManage/CertificateTypeService.h"
/**
 * ֤�����Ͳ�ѯ���ܵ㣬������ʹ��--(֤�����-֤������)--weixiaoman
 */
CertificateTypePageJsonVO::Wrapper CertificateTypeController::execQueryCertificateType(const CertificateTypeQuery::Wrapper& query, const PayloadDTO& payload)
{
	// ����һ��Service
	CertificateTypeService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = CertificateTypePageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
