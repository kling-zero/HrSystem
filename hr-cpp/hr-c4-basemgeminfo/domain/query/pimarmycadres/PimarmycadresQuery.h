#pragma once
#ifndef _PIMARMYCADRES_QUERY_H_
#define _PIMARMYCADRES_QUERY_H_
#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"
#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * ����һ����ѯ�û���Ϣ�����ݴ���ģ��
 */
class PimarmycadresQuery : public oatpp::DTO
{
	// �����ʼ��
	DTO_INIT(PimarmycadresQuery, DTO);

	DTO_FIELD(String, pimid);
	DTO_FIELD_INFO(pimid) {
		info->description = ZH_WORDS_GETTER("Pimarmycadres.field.pimid");
	}

};

#include OATPP_CODEGEN_END(DTO)
#endif 
