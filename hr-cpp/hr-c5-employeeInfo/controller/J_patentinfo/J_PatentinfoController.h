#pragma once

#ifndef _J_PATENTINFOCONTROLLER_H_
#define _J_PATENTINFOCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/vo/J_patentinfo/J_PatentinfoVO.h"
#include "domain/dto/J_patentinfo/J_PatentinfoDTO.h"
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"

using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

#include OATPP_CODEGEN_BEGIN(ApiController) // 0

/**
 * ���Կ�����
 */
class J_PatentinfoController : public oatpp::web::server::api::ApiController // 1
{
	// 2 ����������������
	API_ACCESS_DECLARE(J_PatentinfoController);
public: // ����ӿ�






	//�鿴ָ��Ա��ר����Ϣ��ָ��ר����Ϣ���飩
	// 3 ����ӿ�����
	ENDPOINT_INFO(queryPatentinfo) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("patentInformation.select.summary");
		// ������Ӧ��������
		API_DEF_ADD_RSP_JSON_WRAPPER(J_PatentinfoJsonVO);
		//ר����Ϣ����
		info->queryParams.add<String>("pimpatentid").description = ZH_WORDS_GETTER("patentInformation.pimpatent.pimpatentid");
		info->queryParams["pimpatentid"].addExample("default", String("E436974B-BA1A-4478-8716-6F1DC15ADFC8"));
		info->queryParams["pimpatentid"].required = true;
	}
	// 4 ����ӿڶ˵�
	ENDPOINT(API_M_GET, "/employee-info/query-by-pimpatentid", queryPatentinfo, QUERY(String, pimpatentid)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execQueryPatentinfo(pimpatentid));
	}


	// 3.1 �����޸Ľӿ�����
	ENDPOINT_INFO(modifySample) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("patentInformation.put.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 �����޸Ľӿڴ���
	ENDPOINT(API_M_PUT, "/employee-info/modify-patentinfo", modifySample, BODY_DTO(ModifyPatentinfoDTO::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execModifyPatentinfo(dto));
	}


private: // ����ӿ�ִ�к���
	//�鿴ָ��Ա��ר����Ϣ��ָ��ר����Ϣ���飩
	J_PatentinfoJsonVO::Wrapper execQueryPatentinfo(const String& str);

	//�޸�ָ��Ա��ר����Ϣ�������޸ģ�
	Uint64JsonVO::Wrapper execModifyPatentinfo(const ModifyPatentinfoDTO::Wrapper& dto);

};

#include OATPP_CODEGEN_END(ApiController) // 0

#endif // !_TESTCONTROLLER_H_