#pragma once
/**
 *  ֤����� ���� ֤����Ϣ ���� ��ѯ������ָ��֤�� ���� ������
 */

#ifndef _SPERCIFIC_CERTIFICATE_DAO_
#define _SPERCIFIC_CERTIFICATE_DAO_
#include "BaseDAO.h"
#include "SpercificCertificateMapper.h"
#include "../../domain/do/CertificateManage/SpercificCertificateDO.h"
#include "../../domain/query/CertificateManage/SpercificCertificateQuery.h"

class SpercificCertificateDAO : public BaseDAO
{
public:
	// ��ѯ����
	std::list<SpercificCertificateDO> querySpercificC(const SpercificCertificateQuery::Wrapper& query);
	// �޸�����
	int update(const SpercificCertificateDO& uObj);
	// ͨ��IDɾ������
	int deleteById(uint64_t id);
};
#endif // !_SpercificCertificate_DAO_
