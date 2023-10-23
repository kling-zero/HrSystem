#pragma once
#ifndef _CERTIFICATE_SERVICE_
#define _CERTIFICATE_SERVICE_
#include <list>
#include "domain/vo/Certificate/CertificateVO.h"
#include "domain/query/Certificate/CertificateQuery.h"
#include "domain/dto/Certificate/CertificateDTO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class CertificateService
{
public:
	// ��ҳ��ѯ��������
	CertificatePageDTO::Wrapper listAll(const CertificateQuery::Wrapper& query);
	// ��������
	uint64_t saveData(const CertificateDTO::Wrapper& dto);
	// �޸�����
	bool updateData(const CertificateDTO::Wrapper& dto);
	// ͨ��IDɾ������
	bool removeData(uint64_t id);
};

#endif // !_CERTIFICATE_SERVICE_

