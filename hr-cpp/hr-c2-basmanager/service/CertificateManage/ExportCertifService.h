#pragma once
#ifndef _EXPORTCERTIF_SERVICE_
#define _EXPORTCERTIF_SERVICE_
#include <list>
#include "domain/vo/CertificateManage/ExportCertifJsonVO.h"
#include "domain/query/CertificateManage/ExportCertifQuery.h"
#include "domain/dto/CertificateManage/ExportCertifDTO.h"

class ExportCertifService
{
public:
	// ��ҳ��ѯ��������
	ExportCertifDTO::Wrapper listAll(const ExportCertifQuery::Wrapper& query);
	// ��������
	uint64_t saveData(const ExportCertifDTO::Wrapper& dto);
	// �޸�����
	bool updateData(const ExportCertifDTO::Wrapper& dto);
	// ͨ��IDɾ������
	bool removeData(uint64_t id);
};

#endif // !_EXPORTCERTIF_SERVICE_

