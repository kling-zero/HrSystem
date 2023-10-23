#pragma once
#ifndef _CHECK_CER_CONTROLLER_
#define _CHECK_CER_CONTROLLER_

#include "ApiHelper.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/query/CertificateManage/CheckCerListQuery.h"
#include "domain/dto/CertificateManage/CheckCerListDTO.h"
#include "domain/vo/CertificateManage/CheckCerListVO.h"
/*������δ�õ�*/
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"

using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;
// ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) 

/**
* ��ҳ��ѯ֤���б�--(֤�����-��ҳ��ѯ֤���б�)--pine
 */
class CheckCerListController : public oatpp::web::server::api::ApiController // �̳п�����
{
	// ����������������
	API_ACCESS_DECLARE(CheckCerListController);

public: //  ����ӿڣ�����ӿ�������ӿڶ˵㣩
	    // ���������ӿ�����
	ENDPOINT_INFO(queryCheckCerList) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("cermanage.get.checklist");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ��������
		API_DEF_ADD_RSP_JSON_WRAPPER(CheckCerListPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ���������ѯ������required��ʾ�Ƿ���루Ա����š�֤�����ƣ�
		info->queryParams.add<String>("nameOfPAndV").description = ZH_WORDS_GETTER("cermanage.field.nameOfPAndV");
		info->queryParams["nameOfPAndV"].addExample("default", String(""));
		info->queryParams["nameOfPAndV"].required = false;
		info->queryParams.add<String>("ygbh").description = ZH_WORDS_GETTER("cermanage.field.ygbh");
		info->queryParams["ygbh"].addExample("default", String(""));
		info->queryParams["ygbh"].required = false;
		info->queryParams.add<String>("pimperSonName").description = ZH_WORDS_GETTER("cermanage.field.pimperSonName");
		info->queryParams["pimperSonName"].addExample("default", String(""));
		info->queryParams["pimperSonName"].required = false;
		info->queryParams.add<String>("pimVocationalName").description = ZH_WORDS_GETTER("cermanage.field.pimVocationalName");
		info->queryParams["pimVocationalName"].addExample("default", String(""));
		info->queryParams["pimVocationalName"].required = false;
	}
	    // �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/bas/query-CheckCerList", queryCheckCerList, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		API_HANDLER_QUERY_PARAM(query, CheckCerListQuery, queryParams);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execQueryCheckCerList(query, authObject->getPayload()));
	}

private:// ����ִ�к���
	    // ��ҳ��ѯ����
	CheckCerListPageJsonVO::Wrapper execQueryCheckCerList(const CheckCerListQuery::Wrapper& query, const PayloadDTO& payload);

};

// ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController)
#endif // _CheckCerList_CONTROLLER_