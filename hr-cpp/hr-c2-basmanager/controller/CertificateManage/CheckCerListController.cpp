#include "stdafx.h"
#include "CheckCerListController.h"
#include "../../service/CertificateManage/CheckCerListService.h"
/**
* ��ҳ��ѯ֤���б�--(֤�����-��ҳ��ѯ֤���б�)--pine
 */
CheckCerListPageJsonVO::Wrapper CheckCerListController::execQueryCheckCerList(const CheckCerListQuery::Wrapper& query, const PayloadDTO& payload)
{
	////������Ӧ����
	//auto vo = CheckCerListPageJsonVO::createShared();
	////������ҳ����
	//auto pdto = CheckCerListPageDTO::createShared();
	//pdto->addData(CheckCerListDTO::createShared(1, "zs"));
	//pdto->addData(CheckCerListDTO::createShared(2, "ls"));
	////��Ӧ���
	//vo->success(pdto);
	//return vo;

	// ����һ��Service
	CheckCerListService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = CheckCerListPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
