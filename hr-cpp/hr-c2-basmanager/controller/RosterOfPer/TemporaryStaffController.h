#pragma once
/**
 * ��ְ��Ա��Ϣ��ѯ--(��Ա������-��ְ��Ա-��ҳ��ѯԱ���б�)--weixiaoman
 */

#ifndef _TEMPORARYSTAFFCONTROLLER_H_
#define _TEMPORARYSTAFFCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/RosterOfPer/TemporaryStaffQuery.h"
#include "domain/dto/RosterOfPer/TemporaryStaffDTO.h"
#include "domain/vo/RosterOfPer/TemporaryStaffVO.h"
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"

using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

// ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen
/**
 * ��ְ��Ա���ܿ�����
 */
class TempStaffController : public oatpp::web::server::api::ApiController 
{
	// ����������������
	API_ACCESS_DECLARE(TempStaffController);

	// ����ӿ�
public:
	// �����ѯ�ӿ�����
	ENDPOINT_INFO(queryTempStaff) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("TempStaff.get.summary");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(TemporaryStaffPageJsonVO);
		// �����ҳ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ������������������
		info->queryParams.add<String>("idandname").description = ZH_WORDS_GETTER("TempStaff.field.idandname");
		info->queryParams["idandname"].addExample("default", String(""));
		//info->queryParams["idandname"].required = false;
		//info->queryParams.add<String>("id").description = ZH_WORDS_GETTER("TempStaff.field.id");
		//info->queryParams["id"].addExample("default", String(""));
		//info->queryParams["id"].required = false;
	}
	// �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/bas/query-tempstaff", queryTempStaff, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// ������ѯ����
		API_HANDLER_QUERY_PARAM(userQuery, TempStaffQuery, queryParams);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execQueryTempstaff(userQuery, authObject->getPayload()));
	}

	// ��������
	ENDPOINT_INFO(queryExportTempStaff) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("TempStaff.export.summary");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		//�����ҳ����
		//info->queryParams.add<UInt64>("pageIndex").description = API_PAGE_INDEX_DESC; 
		//info->queryParams["pageIndex"].addExample("default", oatpp::UInt64(1)); 
		//info->queryParams.add<UInt64>("pageSize").description = API_PAGE_SIZE_DESC; 
		//info->queryParams["pageSize"].addExample("default", oatpp::UInt64(10));
		// ������������������
		info->queryParams.add<String>("idandname").description = ZH_WORDS_GETTER("TempStaff.field.idandname");
		info->queryParams["idandname"].addExample("default", String(""));
	}
	// �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/bas/get-tempstaff", queryExportTempStaff, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// ������ѯ����
		API_HANDLER_QUERY_PARAM(userQuery, TempStaffQuery, queryParams);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execExportTempstaff(userQuery, authObject->getPayload()));
	}
private:
	// ��ְ��Ա��ҳ��ѯ����
	TemporaryStaffPageJsonVO::Wrapper execQueryTempstaff(const TempStaffQuery::Wrapper& query, const PayloadDTO& payload);
	// ������ְ��Ա����
	StringJsonVO::Wrapper execExportTempstaff(const TempStaffQuery::Wrapper& query, const PayloadDTO& payload);
};

// ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _TEMPORARYSTAFFCONTROLLER_H_