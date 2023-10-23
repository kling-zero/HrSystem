#pragma once
#pragma once
#ifndef _EvaluationTypesCONTROLLER_H_
#define _EvaluationTypesCONTROLLER_H_
#include "oatpp-swagger/Types.hpp"

#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/pullList/PullListVO.h"
#include <ApiHelper.h>
//#include "domain/vo/user/MenuVO.h"
using namespace oatpp;

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen
/**
 * �����������Ϳ�����Controller�ӿڣ�
 * �����ˣ�fengchu
 */
//�������Ϳ�����
class EvaluationTypesController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(EvaluationTypesController);
public:
	// �����ѯ�����û���Ϣ�ӿڶ˵�����
	ENDPOINT_INFO(queryEvaluationTypes) {
		info->summary = ZH_WORDS_GETTER("common.controller.evaluationTypes");
		API_DEF_ADD_RSP_JSON_WRAPPER(PullListVO);
		API_DEF_ADD_AUTH();
	}

	ENDPOINT(API_M_GET, PATH_TO_PULLIST("/evaluation-types"), queryEvaluationTypes, API_HANDLER_AUTH_PARAME) {
		API_HANDLER_RESP_VO(execQueryEvaluationTypes());
	}


private:
	// ����ӿ�ִ�к���
	PullListVO::Wrapper execQueryEvaluationTypes();

};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif // _EvaluationTypesCONTROLLER_H_