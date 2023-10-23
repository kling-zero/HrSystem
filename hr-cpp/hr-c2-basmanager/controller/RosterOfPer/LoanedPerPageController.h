#pragma once

#ifndef _LOANEDPERPAGE_CONTROLLER_
#define _LOANEDPERPAGE_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"

#include "domain/query/RosterOfPer/LoanedPerPageQuery.h"
#include "domain/dto/RosterOfPer/LoanedPerPageDTO.h"
#include "domain/vo/RosterOfPer/LoanedPerPageVO.h"

#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"

using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

// ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen
/*
����Ա������-�����Ա-��ҳ��ѯԱ���б�������ҳ��ǰ����ɣ���--luoluo
����Ա������-�����Ա-����֤�飨������ҳ��ǰ����ɣ���--δС��
*/
class LoanedPerPageController : public oatpp::web::server::api::ApiController // �̳п�����
{
	// ����������������
	API_ACCESS_DECLARE(LoanedPerPageController);
	// ����ӿ�
public:

	// �����ѯ�ӿ�����
	ENDPOINT_INFO(queryLoanedPerPage) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("loanedperpage.get.summary");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(LoanedPerPageVO);
		// �����ҳ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ������������������
		info->queryParams.add<String>("idAndName").description = ZH_WORDS_GETTER("loanedperpage.field.idAndName");
		info->queryParams["idAndName"].addExample("default", String(""));
		info->queryParams["idAndName"].required = false;
		info->queryParams.add<String>("pimPersonName").description = ZH_WORDS_GETTER("loanedperpage.field.pimPersonName");
		info->queryParams["pimPersonName"].addExample("default", String(""));
		info->queryParams["pimPersonName"].required = false;
		info->queryParams.add<String>("ygbh").description = ZH_WORDS_GETTER("loanedperpage.field.ygbh");
		info->queryParams["ygbh"].addExample("default", String(""));
		info->queryParams["ygbh"].required = false;
		info->queryParams.add<String>("zz").description = ZH_WORDS_GETTER("loanedperpage.field.zz1");
		info->queryParams["zz"].addExample("default", String(""));
		info->queryParams["zz"].required = false;
		info->queryParams.add<String>("bm").description = ZH_WORDS_GETTER("loanedperpage.field.bm1");
		info->queryParams["bm"].addExample("default", String(""));
		info->queryParams["bm"].required = false;
		info->queryParams.add<String>("zw").description = ZH_WORDS_GETTER("loanedperpage.field.zw1");
		info->queryParams["zw"].addExample("default", String(""));
		info->queryParams["zw"].required = false;
		info->queryParams.add<String>("gw").description = ZH_WORDS_GETTER("loanedperpage.field.gw1");
		info->queryParams["gw"].addExample("default", String(""));
		info->queryParams["gw"].required = false;
		info->queryParams.add<String>("fp").description = ZH_WORDS_GETTER("loanedperpage.field.fp");
		info->queryParams["fp"].addExample("default", String(""));
		info->queryParams["fp"].required = false;
		info->queryParams.add<String>("lx").description = ZH_WORDS_GETTER("loanedperpage.field.lx");
		info->queryParams["lx"].addExample("default", String(""));
		info->queryParams["lx"].required = false;
		info->queryParams.add<String>("fpzt").description = ZH_WORDS_GETTER("loanedperpage.field.fpzt");
		info->queryParams["fpzt"].addExample("default", String(""));
		info->queryParams["fpzt"].required = false;
	}
	// �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/bas/query-LoanedPerPage", queryLoanedPerPage, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// ������ѯ����
		API_HANDLER_QUERY_PARAM(userQuery, LoanedPerPageQuery, queryParams);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execQueryLoanedPerPage(userQuery, authObject->getPayload()));
	}
	//��������
	ENDPOINT_INFO(queryExportLoanedPer) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("loanedperpage.export.summary");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		//�����ҳ����
		// �����ҳ��������
		//API_DEF_ADD_PAGE_PARAMS();
		// ������������������
		info->queryParams.add<String>("idAndName").description = ZH_WORDS_GETTER("loanedperpage.field.idAndName");
		info->queryParams["idAndName"].addExample("default", String(""));
		info->queryParams["idAndName"].required = false;
		info->queryParams.add<String>("pimPersonName").description = ZH_WORDS_GETTER("loanedperpage.field.pimPersonName");
		info->queryParams["pimPersonName"].addExample("default", String(""));
		info->queryParams["pimPersonName"].required = false;
		info->queryParams.add<String>("ygbh").description = ZH_WORDS_GETTER("loanedperpage.field.ygbh");
		info->queryParams["ygbh"].addExample("default", String(""));
		info->queryParams["ygbh"].required = false;
		info->queryParams.add<String>("zz").description = ZH_WORDS_GETTER("loanedperpage.field.zz1");
		info->queryParams["zz"].addExample("default", String(""));
		info->queryParams["zz"].required = false;
		info->queryParams.add<String>("bm").description = ZH_WORDS_GETTER("loanedperpage.field.bm1");
		info->queryParams["bm"].addExample("default", String(""));
		info->queryParams["bm"].required = false;
		info->queryParams.add<String>("zw").description = ZH_WORDS_GETTER("loanedperpage.field.zw1");
		info->queryParams["zw"].addExample("default", String(""));
		info->queryParams["zw"].required = false;
		info->queryParams.add<String>("gw").description = ZH_WORDS_GETTER("loanedperpage.field.gw1");
		info->queryParams["gw"].addExample("default", String(""));
		info->queryParams["gw"].required = false;
		info->queryParams.add<String>("fp").description = ZH_WORDS_GETTER("loanedperpage.field.fp");
		info->queryParams["fp"].addExample("default", String(""));
		info->queryParams["fp"].required = false;
		info->queryParams.add<String>("lx").description = ZH_WORDS_GETTER("loanedperpage.field.lx");
		info->queryParams["lx"].addExample("default", String(""));
		info->queryParams["lx"].required = false;
		info->queryParams.add<String>("fpzt").description = ZH_WORDS_GETTER("loanedperpage.field.fpzt");
		info->queryParams["fpzt"].addExample("default", String(""));
		info->queryParams["fpzt"].required = false;
	}
	// �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/bas/get-loanedPer", queryExportLoanedPer, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// ������ѯ����
		API_HANDLER_QUERY_PARAM(userQuery, LoanedPerPageQuery, queryParams);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execExportLoanedPer(userQuery, authObject->getPayload()));
	}

private:
	// ��ʾ��ҳ��ѯ����
	LoanedPerPageVO::Wrapper execQueryLoanedPerPage(const LoanedPerPageQuery::Wrapper& query, const PayloadDTO& payload);
	// �����Ա��Ϣ����
	StringJsonVO::Wrapper execExportLoanedPer(const LoanedPerPageQuery::Wrapper& query, const PayloadDTO& payload);
};

// ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _LOANEDPERPAGE_CONTROLLER_