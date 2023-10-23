#pragma once
#ifndef _TITLECONTROLLLER_
#define _TITLECONTROLLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/Title/TitleQuery.h"
#include "domain/dto/Title/TitleDTO.h"
#include "domain/vo/Title/TitleVO.h"
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
class TitleController : public oatpp::web::server::api::ApiController // �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(TitleController);
	// 3 ����ӿ�
public:
	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(queryTitle) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("Title.get.summary");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(TitlePageJsonVO);
		// �����ҳ��������
		API_DEF_ADD_PAGE_PARAMS();
		info->queryParams.add<String>("name").description = ZH_WORDS_GETTER("Title.field.name");
		info->queryParams["name"].addExample("default", String(ZH_WORDS_GETTER("Title.field.name")));
		info->queryParams["name"].required = false;
	}
	ENDPOINT(API_M_GET, "/Title/query-Title", queryTitle, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// ������ѯ����
		API_HANDLER_QUERY_PARAM(TitleQuery, TitleQuery, queryParams);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execQueryTitle(TitleQuery, authObject->getPayload()));
	}

	// 3.1 ���������ӿ�����
	ENDPOINT_INFO(addTitle) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("Title.post.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 ���������ӿڴ���
	ENDPOINT(API_M_POST, "/Title/add-Title", addTitle, BODY_DTO(TitleDTO::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execAddTitle(dto));
	}

	// 3.1 �����޸Ľӿ�����
	ENDPOINT_INFO(modifyTitle) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("Title.put.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 �����޸Ľӿڴ���
	ENDPOINT(API_M_PUT, "/Title/modify-Title", modifyTitle, BODY_DTO(TitleDTO::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execModifyTitle(dto));
	}

	// 3.1 ����ɾ���ӿ�����
	ENDPOINT_INFO(removeTitle) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("Title.delete.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 ����ɾ���ӿڴ���
	ENDPOINT(API_M_DEL, "/Title/delete-Title", removeTitle, BODY_DTO(TitleDTO_delete::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execRemoveTitle(dto));
	}
private:
	// 3.3 ��ʾ��ҳ��ѯ����
	TitlePageJsonVO::Wrapper execQueryTitle(const TitleQuery::Wrapper& query, const PayloadDTO& payload);
	// 3.3 ��ʾ��������
	Uint64JsonVO::Wrapper execAddTitle(const TitleDTO::Wrapper& dto);
	// 3.3 ��ʾ�޸�����
	Uint64JsonVO::Wrapper execModifyTitle(const TitleDTO::Wrapper& dto);
	// 3.3 ��ʾɾ������
	Uint64JsonVO::Wrapper execRemoveTitle(const TitleDTO_delete::Wrapper& dto);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // 