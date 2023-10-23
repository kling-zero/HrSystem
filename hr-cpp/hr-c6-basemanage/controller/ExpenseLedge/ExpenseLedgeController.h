#pragma once

#ifndef EXPENSEYCONTROLLER_H_
#define EXPENSEYCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/ExpenseLedger/ExpenseLedgerDTO.h"
#include "domain/vo/ExpenseLedge/ExpenseLedgerVO.h"
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"

using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * JobTitle����������������
 */
class ExpenseLedgeController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(ExpenseLedgeController);
	// 3 ����ӿ�
public:
	// ��ѯ�ѱ�
	ENDPOINT_INFO(queryExpense) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("expense.get.summary");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(ExpenseLedgerJsonVO);
		// ������������������
		info->queryParams.add<String>("pimexpaccountid").description = ZH_WORDS_GETTER("expense.field.expense_id");
		info->queryParams["pimexpaccountid"].addExample("default", String("12238653280246456320"));
		info->queryParams["pimexpaccountid"].required = true;
	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/retirement-management/query-expense", queryExpense, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// ������ѯ����
		API_HANDLER_QUERY_PARAM(userQuery, ExpenseLedgerDTO, queryParams);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execQueryExpense(userQuery, authObject->getPayload()));
	}
	
	//�����ѱ�
	ENDPOINT_INFO(getExpense) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("expense.export.summary");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		// ������������������
		info->queryParams.add<String>("pimexpaccountname").description = ZH_WORDS_GETTER("expense.field.expense_name");
		info->queryParams["pimexpaccountname"].addExample("default", String(u8"�ϸɲ����"));
		info->queryParams["pimexpaccountname"].required = false;
	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/retirement-management/export-expense", getExpense, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// ������ѯ����
		API_HANDLER_QUERY_PARAM(userQuery, ExpenseLedgerDTO, queryParams);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execGetExpense(userQuery, authObject->getPayload()));
	}

	// �޸ķѱ�
	ENDPOINT_INFO(modifyExpense) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("expense.update.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 �����޸Ľӿڴ���
	ENDPOINT(API_M_PUT, "/retirement-management/modify-expense", modifyExpense, BODY_DTO(ExpenseLedgerDTO::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execModifyExpense(dto));
	}
private:
	// 3.3 ��ʾ��ѯ����
	ExpenseLedgerJsonVO::Wrapper execQueryExpense(const ExpenseLedgerDTO::Wrapper& query, const PayloadDTO& payload);
	StringJsonVO::Wrapper execGetExpense(const ExpenseLedgerDTO::Wrapper& query, const PayloadDTO& payload);
	Uint64JsonVO::Wrapper execModifyExpense(const ExpenseLedgerDTO::Wrapper& dto);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_