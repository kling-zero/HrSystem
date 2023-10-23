#pragma once
#ifndef _CERTIFICATETYPE_SERVICE_
#define _CERTIFICATETYPE_SERVICE_
#include <list>
#include "domain/vo/CertificateManage/CertificateTypeVO.h"
#include "domain/dto/CertificateManage/CertificateTypeDTO.h"
#include "domain/query/CertificateManage/CertificateTypeQuery.h"
/**
* ֤�����Ͳ�ѯ�������--(֤�����-��ѯ֤�������б�)--weixiaoman
*/
class CertificateTypeService {
public:
	CertificateTypePageDTO::Wrapper listAll(const CertificateTypeQuery::Wrapper& query);
};

#endif // !_CERTIFICATETYPE_SERVICE_