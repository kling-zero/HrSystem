#pragma once
#ifndef _AuditStatusCONTROLLER_H_
#define _AuditStatusCONTROLLER_H_
#include "oatpp-swagger/Types.hpp"

#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/pullList/PullListVO.h"
#include <ApiHelper.h>
//#include "domain/vo/user/MenuVO.h"
using namespace oatpp;

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen
/**
 * ��������״̬������Controller�ӿڣ�
 * �����ˣ�fengchu
 */
class AuditStatusController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(AuditStatusController);
public:
	// �����ѯ�����û���Ϣ�ӿڶ˵�����
	ENDPOINT_INFO(queryAuditStatus) {
		info->summary = ZH_WORDS_GETTER("common.controller.auditStatus");
		API_DEF_ADD_RSP_JSON_WRAPPER(PullListVO);
		API_DEF_ADD_AUTH();
	}
		
	ENDPOINT(API_M_GET, PATH_TO_PULLIST("/audit-status"), queryAuditStatus, API_HANDLER_AUTH_PARAME) {
		API_HANDLER_RESP_VO(execQueryAuditStatus());
	}

	
	
private:
	// ����ӿ�ִ�к���
	PullListVO::Wrapper execQueryAuditStatus();
	
};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif // _AuditStatusCONTROLLER_H_