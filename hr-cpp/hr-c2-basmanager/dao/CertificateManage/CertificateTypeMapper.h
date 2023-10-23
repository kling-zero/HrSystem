#pragma once
#ifndef _CERTIFICATETYPE_MAPPER_
#define _CERTIFICATETYPE_MAPPER_

#include "Mapper.h"
#include "../../domain/do/CertificateManage/CertificateTypeDO.h"

/**
 * ֤�����ͷ�ҳ��ѯMapper--(֤�����-��ѯ֤��������Ϣ)--weixiaoman
 */
class CertificateTypeMapper : public Mapper<CertificateTypeDO>
{
public:
	CertificateTypeDO mapper(ResultSet* resultSet) const override
	{
		CertificateTypeDO data;
		data.setCerType(resultSet->getString(1));
		data.setId(resultSet->getString(2));
		return data;
	}
};

#endif // !_CERTIFICATETYPE_MAPPER_