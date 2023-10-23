#pragma once
#ifndef _CERTIFICATETYPE_DAO_
#define _CERTIFICATETYPE_DAO_
#include "BaseDAO.h"
#include "../../domain/do/CertificateManage/CertificateTypeDO.h"
#include "../../domain/query/CertificateManage/CertificateTypeQuery.h"

/**
 * ֤�����ͷ�ҳ��ѯ����--(֤�����-��ѯ֤�������б�)--weixiaoman
 */
class CertificateTypeDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const CertificateTypeQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<CertificateTypeDO> selectWithPage(const CertificateTypeQuery::Wrapper& query);
};
#endif // !_CERTIFICATETYPE_DAO_