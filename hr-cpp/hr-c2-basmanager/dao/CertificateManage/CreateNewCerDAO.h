#pragma once
/*
֤�����-�½�֤��--pine
*/
#ifndef _CREATE_NEW_CER_DAO_
#define _CREATE_NEW_CER_DAO_
#include "BaseDAO.h"
#include "../../domain/do/CertificateManage/CertificateDO.h"
#include "../../domain/query/CertificateManage/CreateNewCerQuery.h"

/**
 * ��Ա����š�֤�����ƣ�(Ա������Ҫ���)
 */
class CreateNewCerDAO : public BaseDAO
{
public:
	// ��������
	uint64_t insert(const CertificateDO& iObj);
};
#endif // !_CREATE_NEW_CER_DAO_
