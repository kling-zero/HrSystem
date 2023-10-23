#pragma once
#ifndef _ARCHIVECONTROLLLER_
#define _ARCHIVECONTROLLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/archive/ArchiveQuery.h"
#include "domain/dto/archive/ArchiveDTO.h"
#include "domain/vo/archive/ArchiveVO.h"
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"

using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
class ArchiveController : public oatpp::web::server::api::ApiController // �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(ArchiveController);
	// 3 ����ӿ�
public:
	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(queryArchive) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("archive.get.summary");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(ArchivePageJsonVO);
		// �����ҳ��������
		API_DEF_ADD_PAGE_PARAMS();
	}
	ENDPOINT(API_M_GET, "/archive/query-archive", queryArchive, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// ������ѯ����
		API_HANDLER_QUERY_PARAM(archiveQuery, ArchiveQuery, queryParams);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execQueryArchive(archiveQuery, authObject->getPayload()));
	}
	// 3.1 ���������ӿ�����
	ENDPOINT_INFO(addArchive) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("archive.post.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 ���������ӿڴ���
	ENDPOINT(API_M_POST, "/archive/add-archive", addArchive, BODY_DTO(ArchiveDTO::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execAddArchive(dto));
	}
	// 3.1 �����޸Ľӿ�����
	ENDPOINT_INFO(modifyArchive) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("archive.put.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 �����޸Ľӿڴ���
	ENDPOINT(API_M_PUT, "/archive/modify-archive", modifyArchive, BODY_DTO(ArchiveDTO::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execModifyArchive(dto));
	}
	// 3.1 ����ɾ���ӿ�����
	ENDPOINT_INFO(removeArchive) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("archive.delete.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 ����ɾ���ӿڴ���
	ENDPOINT(API_M_DEL, "/archive/remote-archive", removeArchive, BODY_DTO(ArchiveDTO::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execRemoveArchive(dto));
	}
private:
	// 3.3 ��ʾ��ҳ��ѯ����
	ArchivePageJsonVO::Wrapper execQueryArchive(const ArchiveQuery::Wrapper& query, const PayloadDTO& payload);
	// 3.3 ��ʾ��������
	Uint64JsonVO::Wrapper execAddArchive(const ArchiveDTO::Wrapper& dto);
	// 3.3 ��ʾ�޸�����
	Uint64JsonVO::Wrapper execModifyArchive(const ArchiveDTO::Wrapper& dto);
	// 3.3 ��ʾɾ������
	Uint64JsonVO::Wrapper execRemoveArchive(const ArchiveDTO::Wrapper& dto);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // 