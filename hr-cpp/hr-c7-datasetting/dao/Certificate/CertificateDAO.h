#pragma once
#ifndef _CERTIFICATE_DAO_
#define _CERTIFICATE_DAO_
#include "BaseDAO.h"
#include "../../domain/do/Certificate/CertificateDO.h"
#include "../../domain/query/Certificate/CertificateQuery.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class CertificateDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const CertificateQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<CertificateDO> selectWithPage(const CertificateQuery::Wrapper& query);
	// ͨ��������ѯ����
	list<CertificateDO> selectByName(const string& name);
	// ��������
	uint64_t insert(const CertificateDO& iObj);
	// �޸�����
	int update(const CertificateDO& uObj);
	// ͨ��IDɾ������
	int deleteById(uint64_t id);
};
#endif // !_CERTIFICATE_DAO_
