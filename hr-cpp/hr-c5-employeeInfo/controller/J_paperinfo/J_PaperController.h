#pragma once

#ifndef _J_PAPERINFO_H_
#define _J_PAPERINFO_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"

#include "domain/query/paperinfo/PaperQuery.h"
#include "domain/vo/J_paperinfo/J_PaperVO.h"
#include "domain/dto/J_paperinfo/J_PaperinfoDTO.h"


#include OATPP_CODEGEN_BEGIN(ApiController) // 0

/**
 * ���Կ�����
 */
class J_PaperController : public oatpp::web::server::api::ApiController // 1
{
	// 2 ����������������
	API_ACCESS_DECLARE(J_PaperController);
public: // ����ӿ�

	//�鿴ָ��Ա��������Ϣ��ָ��������Ϣ���飩
	// 3 ����ӿ�����
	ENDPOINT_INFO(selectPaperinfo) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("paperInformation.select.summary");
		// ������Ӧ��������
		API_DEF_ADD_RSP_JSON_WRAPPER(J_PaperinfoJsonVO);
		//ר����Ϣ����
		info->queryParams.add<String>("pimpaperid").description = ZH_WORDS_GETTER("paperInformation.pimpaper.pimpaperid");
		info->queryParams["pimpaperid"].addExample("default", String("FB0BE96B-1F65-4190-9AD7-9AD1C60450A5"));
		info->queryParams["pimpaperid"].required = true;
	}
	// 4 ����ӿڶ˵�
	ENDPOINT(API_M_GET, "/employee-info/select-by-pimpaperid", selectPaperinfo, QUERY(String, pimpaperid)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execSelectByPimpaperid(pimpaperid));
	}



	// 3.1 �����޸Ľӿ�����
	ENDPOINT_INFO(modifyPaperinfo) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("paperInformation.put.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 �����޸Ľӿڴ���
	ENDPOINT(API_M_PUT, "/employee-info/modify-by-pimpaperid", modifyPaperinfo, BODY_DTO(ModifyPaperinfoDTO::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execModifyByPimpaperid(dto));
	}


private: // ����ӿ�ִ�к���

	//�鿴ָ��Ա��������Ϣ��ָ��������Ϣ���飩
	J_PaperinfoJsonVO::Wrapper execSelectByPimpaperid(const String& str);

	//�޸�ָ��Ա��������Ϣ�������޸ģ�
	Uint64JsonVO::Wrapper execModifyByPimpaperid(const ModifyPaperinfoDTO::Wrapper& dto);

};

#include OATPP_CODEGEN_END(ApiController) // 0

#endif // !_PAPERINFOCONTROLLER_H_