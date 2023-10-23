#pragma once

#ifndef _PATENTINFOCONTROLLER_H_
#define _PATENTINFOCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/query/patentinfo/PatentinfoQuery.h"
#include "domain/vo/paptentinfo/PatentinfoVO.h"
#include "domain/dto/patentinfo/PatentinfoDTO.h"
#include "domain/dto/patentinfo/DelPatentDTO.h"
#include "domain/dto/patentinfo/AddPatentDTO.h"
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
class PatentinfoController : public oatpp::web::server::api::ApiController // 1
{
	// 2 ����������������
	API_ACCESS_DECLARE(PatentinfoController);
public: // ����ӿ�
	// 3.1 ����ɾ���ӿ�����
	ENDPOINT_INFO(removePatent) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("patentInformation.delete.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 ����ɾ���ӿڴ���
	ENDPOINT(API_M_DEL, "/employee-info/remove-patentinfo", removePatent, BODY_DTO(List<String>, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execRemovePatent(dto));
	}



private: // ����ӿ�ִ�к���
	////��ҳ�鿴ָ��Ա��ר����Ϣ����ҳ��ѯ�б�
	//PatentinfoPageJsonVO::Wrapper execQueryPagePatent(const PatentinfoQuery::Wrapper& query);

	////����ָ��Ա��ר����Ϣ������������
	//Uint64JsonVO::Wrapper execAddPatent(const AddPatentDTO::Wrapper& dto);

	//ɾ��ָ��Ա��ר����Ϣ��֧������ɾ����
	Uint64JsonVO::Wrapper execRemovePatent(const List<String>& dto);



};

#include OATPP_CODEGEN_END(ApiController) // 0

#endif // !_TESTCONTROLLER_H_