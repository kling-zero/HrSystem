#pragma once

#ifndef _ARCHIVES_CONTROLLER_H_
#define _ARCHIVES_CONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/query/archives/ArchivesQuery.h"
#include "domain/vo/archives/ArchivesVO.h"
#include "service/archives/ArchivesService.h"
//#include "domain/dto/archives/ArchivesDelDto.h"

/*
	������Ϣ������
*/

// �򻯱���������
/*
parameter: parm->��ѯ���� defaultVal->Ĭ��ֵ
���Ͷ���string
*/

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController)

class ArchivesController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(ArchivesController);
public:
	// ��ѯָ�������ӿ�����+����
	ENDPOINT_INFO(queryArchivesInfo) {
		info->summary = ZH_WORDS_GETTER("specifiedArchives.get.summary");
		// ����Ĭ����Ȩ����
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(ArchivesJsonVO);
		// �����ҳ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ������
		info->queryParams.add<String>("pimArchivesId").description = ZH_WORDS_GETTER("archives.newField.pimArchivesId");
		info->queryParams["pimArchivesId"].addExample("default", String("12"));
		info->queryParams["pimArchivesId"].required = true;
	}
	ENDPOINT(API_M_GET, "/archives/query-archivesinfo", queryArchivesInfo, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// ������ѯ����
		API_HANDLER_QUERY_PARAM(query, ArchivesQuery, queryParams);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execQueryArchivesInfo(query, authObject->getPayload()));
	}

	// ��ҳ��ѯ�ӿ�����+����
	ENDPOINT_INFO(queryPageArchivesinfo) {
		//����ӿڱ���
		info->summary = ZH_WORDS_GETTER("archives.get.summary");
		//������Ӧ��������
		API_DEF_ADD_RSP_JSON_WRAPPER(ArchivesPageJsonVO);
		//�����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ������
		info->queryParams.add<String>("pimPersonName").description = ZH_WORDS_GETTER("archives.newField.pimPersonName");
		info->queryParams["pimPersonName"].addExample("default", String("LiHua"));
		info->queryParams["pimPersonName"].required = false;
		info->queryParams.add<String>("ygbh").description = ZH_WORDS_GETTER("archives.newField.ygbh");
		info->queryParams["ygbh"].addExample("default", String("1234"));
		info->queryParams["ygbh"].required = false;
		info->queryParams.add<String>("dabh").description = ZH_WORDS_GETTER("archives.newField.dabh");
		info->queryParams["dabh"].addExample("default", String("1234"));
		info->queryParams["dabh"].required = false;
		info->queryParams.add<String>("ygzt").description = ZH_WORDS_GETTER("archives.newField.ygzt");
		info->queryParams["ygzt"].addExample("default", String(ZH_WORDS_GETTER("archives.sample.ygzt")));
		info->queryParams["ygzt"].required = false;
		info->queryParams.add<String>("dazt").description = ZH_WORDS_GETTER("archives.newField.dazt");
		info->queryParams["dazt"].addExample("default", String(ZH_WORDS_GETTER("archives.sample.dazt")));
		info->queryParams["dazt"].required = false;
	}
	ENDPOINT(API_M_GET, "/archives/query-archivesinfo-page", queryPageArchivesinfo, QUERIES(QueryParams, qps)) {
		//������ѯ����������������ģ�Ͷ���
		API_HANDLER_QUERY_PARAM(query, ArchivesQuery, qps);
		//��Ӧ���
		API_HANDLER_RESP_VO(execQueryPageArchivesInfo(query));
	}

	// �½������ӿ�����+����
	ENDPOINT_INFO(addArchivesInfo) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("archives.post.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	ENDPOINT(API_M_POST, "/archives/add-archivesinfo", addArchivesInfo, BODY_DTO(ArchivesDTO::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execAddArchivesInfo(dto));
	}

	// ɾ�������ӿ�����+����
	ENDPOINT_INFO(removeArchivesInfo) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("archives.delete.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	ENDPOINT(API_M_DEL, "/archives/remove-archivesinfo", removeArchivesInfo, BODY_DTO(ArchivesDelDTO::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execRemoveArchivesInfo(dto));
	}

private:
	// ��ѯָ����������ϸ����
	ArchivesPageJsonVO::Wrapper execQueryArchivesInfo(const ArchivesQuery::Wrapper& query, const PayloadDTO& payload);
	// ��ҳ��ѯָ������
	ArchivesPageJsonVO::Wrapper execQueryPageArchivesInfo(const ArchivesQuery::Wrapper& query);
	// ��������
	Uint64JsonVO::Wrapper execAddArchivesInfo(const ArchivesDTO::Wrapper& dto);
	// ɾ������
	Uint64JsonVO::Wrapper execRemoveArchivesInfo(const ArchivesDelDTO::Wrapper& dto);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) // 0
#endif 

