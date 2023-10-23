#include "stdafx.h"
#include "CertificateInformationController.h"
#include "../../service/certificate-information/certificate-information/CertificateInformationService.h"
//����֤���ҳ��ѯ�ӿں���execQueryCertificateInformation
CertificateInformationPageJsonVO::Wrapper CertificateInformationController::execQueryCertificateInformation(const CertificateInformationPageQuery::Wrapper& query, const PayloadDTO& payload)
{
	// ����һ��Service
	CertificateInformationService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = CertificateInformationPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}