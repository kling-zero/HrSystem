#pragma once
#ifndef _CERTIFICATE_INFORMATION_DAO_H_
#define _CERTIFICATE_INFORMATION_DAO_H_
#include "BaseDAO.h"
#include "../../../domain/do/certificate-information/CertificateInformationDO.h"
#include "../../../domain/query/certificate-information/CertificateInformationPageQuery.h"

class CertificateInformationDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const CertificateInformationPageQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<CertificateInformationDO> selectWithPage(const CertificateInformationPageQuery::Wrapper& query);
};

#endif //
