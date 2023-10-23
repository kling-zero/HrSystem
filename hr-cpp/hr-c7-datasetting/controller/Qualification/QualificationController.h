#pragma once
#ifndef _QUALIFICATION_CONTROLLER_
#define _QUALIFICATION_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/Qualification/QualificationQuery.h"
#include "domain/dto/Qualification/QualificationDTO.h"
#include "domain/vo/Qualification/QualificationVO.h"
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
class QualificationController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(QualificationController);
	// 3 ����ӿ�
public:
	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(queryQualification) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("qualification.get.summary");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(QualificationPageJsonVO);
		// �����ҳ��������
		API_DEF_ADD_PAGE_PARAMS();
	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/qualification/query-qualification", queryQualification, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// ������ѯ����
		API_HANDLER_QUERY_PARAM(userQuery, QualificationQuery, queryParams);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execQueryQualification(userQuery, authObject->getPayload()));
	}
	// 3.1 ���������ӿ�����
	ENDPOINT_INFO(addQualification) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("qualification.post.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 ���������ӿڴ���
	ENDPOINT(API_M_POST, "/qualification/add-qualification", addQualification, BODY_DTO(QualificationDTO::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execAddQualification(dto));
	}
	// 3.1 �����޸Ľӿ�����
	ENDPOINT_INFO(modifyQualification) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("qualification.put.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 �����޸Ľӿڴ���
	ENDPOINT(API_M_PUT, "/qualification/modify-qualification", modifyQualification, BODY_DTO(QualificationDTO::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execModifyQualification(dto));
	}
	// 3.1 ����ɾ���ӿ�����
	ENDPOINT_INFO(removeQualification) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("qualification.delete.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	// 3.2 ����ɾ���ӿڴ���
	ENDPOINT(API_M_DEL, "/qualification/remove-qualification", removeQualification, BODY_DTO(QualificationDTO::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execRemoveQualification(dto));
	}
private:
	// 3.3 ��ʾ��ҳ��ѯ����
	QualificationPageJsonVO::Wrapper execQueryQualification(const QualificationQuery::Wrapper& query, const PayloadDTO& payload);
	// 3.3 ��ʾ��������
	Uint64JsonVO::Wrapper execAddQualification(const QualificationDTO::Wrapper& dto);
	// 3.3 ��ʾ�޸�����
	Uint64JsonVO::Wrapper execModifyQualification(const QualificationDTO::Wrapper& dto);
	// 3.3 ��ʾɾ������
	Uint64JsonVO::Wrapper execRemoveQualification(const QualificationDTO::Wrapper& dto);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_
