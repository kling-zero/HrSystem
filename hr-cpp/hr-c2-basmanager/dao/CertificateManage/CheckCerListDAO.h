#pragma once
/*
֤�����-��ҳ��ѯ֤���б�--pine
*/
#ifndef _CHECH_CER_LIST_DAO_
#define _CHECH_CER_LIST_DAO_
#include "BaseDAO.h"
#include "../../domain/do/CertificateManage/CertificateDO.h"
#include "../../domain/query/CertificateManage/CheckCerListQuery.h"

class CheckCerListDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const CheckCerListQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<CertificateDO> selectWithPage(const CheckCerListQuery::Wrapper& query);

};
#endif // !_SAMPLE_DAO_
