#pragma once
/*
֤�����-��ҳ��ѯ֤���б�--pine
*/
#ifndef _CHECK_CER_LIST_SERVICE_
#define _CHECK_CER_LIST_SERVICE_
#include <list>
#include "domain/query/CertificateManage/CheckCerListQuery.h"
#include "domain/dto/CertificateManage/CheckCerListDTO.h"
#include "domain/vo/CertificateManage/CheckCerListVO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class CheckCerListService
{
public:
	// ��ҳ��ѯ��������
	CheckCerListPageDTO::Wrapper listAll(const CheckCerListQuery::Wrapper& query);

};

#endif // !_CHECK_CER_LIST_SERVICE_

