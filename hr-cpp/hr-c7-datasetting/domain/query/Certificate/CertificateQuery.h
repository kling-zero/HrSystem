#pragma once
#ifndef _CERTIFICATEQUERY_H_
#define _CERTIFICATEQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����λ����֤���ѯ����
 */
class CertificateQuery :public PageQuery
{
	DTO_INIT(CertificateQuery, PageQuery);
	// �����
	DTO_FIELD(UInt64, seialno);
	DTO_FIELD_INFO(seialno) {
		info->description = ZH_WORDS_GETTER("certificate.field.seialno");
	}
	// ����������
	DTO_FIELD(String, pimqualtypename);
	DTO_FIELD_INFO(pimqualtypename) {
		info->description = ZH_WORDS_GETTER("certificate.field.pimqualtypename");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif
