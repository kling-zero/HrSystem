#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: huilai
 @Date: 2023/05/20 11:40:01

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#ifndef _PIMARMYCADRESCONTROLLER_H_
#define _PIMARMYCADRESCONTROLLER_H_


#include "domain/vo/BaseJsonVO.h"
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"
#include "domain/query/pimarmycadres/PimarmycadresPageQuery.h"
#include "domain/vo/pimarmycadres/PimarmycadresVO.h"
#include "domain/dto/pimarmycadres/AddPimarmycadresDTO.h"
#include "domain/dto/pimarmycadres/DelPimarmycadresDTO.h"
#include "oatpp-swagger/Model.hpp"
#include "oatpp-swagger/Types.hpp"
#include <openssl/md5.h>
#include <boost/throw_exception.hpp>
#include <boost/throw_exception.hpp>

#include "ServerInfo.h"

#include "domain/query/pimarmycadres/PimarmycadresQuery.h"
//#include "domain/dto/Pimarmycadres/ModPimarmycadresDTO.h"
//#include "domain/vo/Pimarmycadres/ModPimarmycadresVO.h"
#include "domain/vo/pimarmycadres/PimarmycadresVO.h"
#include "domain/dto/pimarmycadres/PimarmycadresIntoDTO.h"


using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

#include OATPP_CODEGEN_BEGIN(ApiController)

class PimarmycadresController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(PimarmycadresController);
public: // ����ӿ�
	//  �����ѯ�ӿ�����
	ENDPOINT_INFO(queryPimarmycadres) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("pimarmycadres.get.summary");
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		//API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(PimarmycadresFindVO);
		// �����ҳ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ������������������
		info->queryParams.add<String>("pimid").description = ZH_WORDS_GETTER("pimarmycadres.field.pimid");
		info->queryParams["pimid"].addExample("default", String("6611212223"));
		info->queryParams["pimid"].required = false;
	}
	// �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/pimarmycadres/select", queryPimarmycadres, QUERIES(QueryParams, qps)) {
		//������ѯ����������������ģ�Ͷ���
		API_HANDLER_QUERY_PARAM(query, PimarmycadresPageQuery, qps);
		// ��Ӧ���
		API_HANDLER_RESP_VO(execQueryPimarmycadres(query));
		
		
		//PimarmycadresFindVO::Wrapper execQueryPimarmycadres(const PimarmycadresPageQuery::Wrapper & query);
	}

	// ���������ӿ�����
	ENDPOINT_INFO(addPimarmycadres) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("pimarmycadres.post.summary");
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// ���������ӿڴ���
	ENDPOINT(API_M_POST, "/pimarmycadres/add", addPimarmycadres, API_HANDLER_AUTH_PARAME, BODY_DTO(AddPimarmycadresDTO::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execAddPimarmycadres(dto, authObject->getPayload()));
	}

	// ��������ɾ���ӿ�����
	ENDPOINT_INFO(delPimarmycadres) {
		// ����ӿڱ���
		info->summary = ZH_WORDS_GETTER("pimarmycadres.delete.summary");
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// ��������ɾ���ӿڴ���
	ENDPOINT(API_M_POST, "/pimarmycadres/delete", delPimarmycadres, BODY_DTO(DelPimarmycadresDTO::Wrapper, dto)) {
		// ��Ӧ���
		API_HANDLER_RESP_VO(execDelPimarmycadres(dto));
	}

	// ����һ�����ļ�����ӿ�
	ENDPOINT_INFO(postFile) {
		API_DEF_ADD_AUTH();
		info->summary = ZH_WORDS_GETTER("pimarmycadres.file.summary");
		info->addConsumes<oatpp::swagger::Binary>("application/octet-stream");
		API_DEF_ADD_RSP_JSON(StringJsonVO::Wrapper);
		info->queryParams.add<String>("pimpersonid").description = ZH_WORDS_GETTER("pimarmycadres.field.pimpersonid");
		info->queryParams["pimpersonid"].addExample("default", String("1002"));
		/*info->queryParams["suffix"].description = ZH_WORDS_GETTER("pimarmycadres.file.suffix");
		info->queryParams["suffix"].addExample("xlsx", String(".xlsx"));*/
	}
	// �����ļ��ϴ��˵㴦��
	ENDPOINT(API_M_POST, "/pimarmycadres/file", postFile, API_HANDLER_AUTH_PARAME, BODY_STRING(String, body), QUERY(String, suffix), QUERY(String, pimpersonid)) {
		// ִ���ļ������߼�
		API_HANDLER_RESP_VO(execIntoPimarmycadres(body, suffix,pimpersonid,authObject->getPayload()));
	}

private:

	// �����ҳ��ѯִ�к���
	PimarmycadresFindVO::Wrapper execQueryPimarmycadres(const PimarmycadresPageQuery::Wrapper& query);

	//��������ִ�к���
	Uint64JsonVO::Wrapper execAddPimarmycadres(const AddPimarmycadresDTO::Wrapper& dto, const PayloadDTO& payload);

	//����ɾ��ִ�к���
	Uint64JsonVO::Wrapper execDelPimarmycadres(const DelPimarmycadresDTO::Wrapper& dto);

	//���嵼��ִ�к���
	StringJsonVO::Wrapper execIntoPimarmycadres(const String& body, const String& suffix,const String& pimpersonid, const PayloadDTO& payload);


};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_PIMARMYCADRESCONTROLLER_H_