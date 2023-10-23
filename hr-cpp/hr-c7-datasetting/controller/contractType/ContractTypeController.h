#pragma once
#ifndef _CONTRACTCONTROLLER_H_
#define _CONTRACTCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
//#include "ApiHelper.h"
#include "domain/query/ContractType/ContractTypeQuery.h"
#include "domain/dto/ContractType/ContractTypeDTO.h"
#include "domain/vo/ContractType/ContractTypeVO.h"
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"

using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

#include OATPP_CODEGEN_BEGIN(ApiController) // 0

/**
 * ��ͬ��ѯ������
 */
class ContractTypeController : public oatpp::web::server::api::ApiController // 1
{
	// 2 ����������������
	API_ACCESS_DECLARE(ContractTypeController);
public: // ����ӿ�
	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(queryContract) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("contractType.get.summary");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ��������
		API_DEF_ADD_RSP_JSON_WRAPPER(ContractTypePageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ���������ѯ����
		info->queryParams.add<String>("name").description = ZH_WORDS_GETTER("contractType.field.name");
		info->queryParams["name"].addExample("default", String("he tong ming"));
		info->queryParams["name"].required = false;
	}
	// 3.1 �����ѯ�ӿڶ˵�
	ENDPOINT(API_M_GET, "/contracttype/query-contractType", queryContract, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// ������ѯ����������������ģ�Ͷ���
		API_HANDLER_QUERY_PARAM(ContractTypeQuery, ContractTypeQuery, queryParams);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execQueryContractType(ContractTypeQuery, authObject->getPayload()));
	}
	// ���������ӿ�����
	ENDPOINT_INFO(addContractType) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("contractType.post.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(ContractTypeJsonVO);
	}
	// ���������ӿڴ���
	ENDPOINT(API_M_POST, "/contracttype/add-contractType", addContractType, BODY_DTO(ContractTypeDTO::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execAddContractType(dto));
	}
	// �����޸Ľӿ�����
	ENDPOINT_INFO(modifyContractType) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("contractType.put.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(ContractTypeJsonVO);
	}
	// �����޸Ľӿڴ���
	ENDPOINT(API_M_PUT, "/contracttype/modify-contractType", modifyContractType, BODY_DTO(ContractTypeDTO::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execModifyContractType(dto));
	}
	// ����ɾ���ӿ�����
	ENDPOINT_INFO(removeContractType) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("contractType.delete.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(ContractTypeJsonVO);
	}
	// 3.2 ����ɾ���ӿڴ���
	ENDPOINT(API_M_DEL, "/contract/remote-contractType", removeContractType, BODY_DTO(ContractTypeDTO::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execRemoveContractType(dto));
	}
private: // ����ӿ�ִ�к���
	// 5 ����ӿڵ�ִ�к���
	//ContractTypePageJsonVO::Wrapper ContractController::execQueryContractType(const ContractTypeQuery::Wrapper & query)
	ContractTypePageJsonVO::Wrapper execQueryContractType(const ContractTypeQuery::Wrapper& query, const PayloadDTO& payload);
	Uint64JsonVO::Wrapper execAddContractType(const ContractTypeDTO::Wrapper& dto);
	Uint64JsonVO::Wrapper execModifyContractType(const ContractTypeDTO::Wrapper& dto);
	Uint64JsonVO::Wrapper execRemoveContractType(const ContractTypeDTO::Wrapper& dto);
};

#include OATPP_CODEGEN_END(ApiController) // 0

#endif // !_CONTRACTCONTROLLER_H_