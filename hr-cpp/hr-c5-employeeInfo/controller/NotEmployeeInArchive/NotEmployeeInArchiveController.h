#pragma once
#ifndef _NOT_EMPLOYEE_IN_ARCHIVE_CONTROLLER_
#define _NOT_EMPLOYEE_IN_ARCHIVE_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/NotEmployeeInArchive/NotEmployeeInArchiveQuery.h"
#include "domain/dto/NotEmployeeInArchive/NotEmployeeInArchiveDTO.h"
#include "domain/vo/NotEmployeeInArchive/NotEmployeeInArchiveVO.h"
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"

using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/*
	��Ա���ڵ�������
*/
class NotEmployeeInArchiveController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(NotEmployeeInArchiveController);
	// 3 ����ӿ�
	public:
		// 3.1 �����ѯ�ӿ�����
		ENDPOINT_INFO(queryNotEmployeeInArchive) {
			// ����ӿڱ���
			info->summary = ZH_WORDS_GETTER("archive.get.summary");
			// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
			API_DEF_ADD_AUTH();
			// ������Ӧ������ʽ
			API_DEF_ADD_RSP_JSON_WRAPPER(NotEmployeeInArchivePageJsonVO);
			// �����ҳ��������
			API_DEF_ADD_PAGE_PARAMS();
		}
		// 3.2 �����ѯ�ӿڴ���
		ENDPOINT(API_M_GET, "/not-employee-in-archive/query-by-pimpersonid", queryNotEmployeeInArchive, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, qps)) {
			// ������ѯ����
			API_HANDLER_QUERY_PARAM(query, NotEmployeeInArchiveQuery, qps);
			// ��Ӧ���
			API_HANDLER_RESP_VO(execQueryNotEmployeeInArchive(query, authObject->getPayload()));
		}
		// 3.1 ���嵼���ӿ�����
		ENDPOINT_INFO(exportNotEmployeeInArchive) {
			// ����ӿڱ���
			info->summary = ZH_WORDS_GETTER("archive.export.summary");
			// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
			API_DEF_ADD_AUTH();
			// ������Ӧ������ʽ
			API_DEF_ADD_RSP_JSON_WRAPPER(NotEmployeeInArchivePageJsonVO);
			// �����ҳ��������
			API_DEF_ADD_PAGE_PARAMS();
		}
		// 3.2 �����ѯ�ӿڴ���
		ENDPOINT(API_M_GET, "/not-employee-in-archive/export-data", exportNotEmployeeInArchive, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, qps)) {
			// ������ѯ����
			API_HANDLER_QUERY_PARAM(query, NotEmployeeInArchiveQuery, qps);
			// ��Ӧ���
			API_HANDLER_RESP_VO(execQueryNotEmployeeInArchive(query, authObject->getPayload()));
		}
		// 3.1 �����޸Ľӿ�����
		ENDPOINT_INFO(modifyNotEmployeeInArchive) {
			// ����ӿڱ���
			info->summary = ZH_WORDS_GETTER("archive.put.summary");
			// ������Ӧ������ʽ
			API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
		}
		// 3.2 �����޸Ľӿڴ���
		ENDPOINT(API_M_PUT, "/not-employee-in-archive/modify-pimpersonid", modifyNotEmployeeInArchive, BODY_DTO(NotEmployeeInArchiveDTO::Wrapper, dto)) {
			// ��Ӧ���
			API_HANDLER_RESP_VO(execModifyNotEmployeeInArchive(dto));
		}

private:
	// 3.3 ��ҳ��ѯ����
	NotEmployeeInArchivePageJsonVO::Wrapper execQueryNotEmployeeInArchive(const NotEmployeeInArchiveQuery::Wrapper& query, const PayloadDTO& payload);
	// 3.3 �޸�����
	Uint64JsonVO::Wrapper execModifyNotEmployeeInArchive(const NotEmployeeInArchiveDTO::Wrapper& dto);
};


#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _NOT_EMPLOYEE_IN_ARCHIVE_CONTROLLER_