#pragma once
/**
 *  ֤����� ���� ֤����Ϣ ���� ��ѯ������ָ��֤�� ���� ������
 */
#ifndef _SpercificCertificate_SERVICE_
#define _SpercificCertificate_SERVICE_
#include <list>
#include "domain/vo/CertificateManage/SpercificCertificateVO.h"
#include "domain/query/CertificateManage/SpercificCertificateQuery.h"
#include "domain/dto/CertificateManage/SpercificCertificateDTO.h"
class SpercificCertificateService {
public:
	bool updateData(const SpercificCertificateDTO::Wrapper& dto);
	SpercificCertificateDTO::Wrapper querySpercificCertificate(const SpercificCertificateQuery::Wrapper &query);
};

#endif // !_SpercificCertificate_SERVICE_
#pragma once
