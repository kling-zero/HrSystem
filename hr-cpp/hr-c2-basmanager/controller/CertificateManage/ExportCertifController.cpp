/*
��֤�����-֤����Ϣ-����֤�飨������ҳ��ǰ����ɣ���--����
*/
#include "stdafx.h"
#include "ExportCertifController.h"
#include "../../service/CertificateManage/ExportCertifService.h"

ExportCertifJsonVO::Wrapper ExportCertifController::execExportCertif(const ExportCertifQuery::Wrapper& query, const PayloadDTO& payload)
{
	// ����һ��Service
	// ExportCertifService service;
	// ��ѯ����
	//auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = ExportCertifJsonVO::createShared();
	//jvo->success(result);
	return jvo;
}

