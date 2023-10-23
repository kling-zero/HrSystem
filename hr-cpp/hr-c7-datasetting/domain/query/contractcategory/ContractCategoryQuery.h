#pragma once
#ifndef _CONTRACTCATEGORYQUERY_H_
#define _CONTRACTCATEGORYQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��ͬ����ҳ��ѯ����
 */
class ContractCategoryQuery : public PageQuery
{
	DTO_INIT(ContractCategoryQuery, PageQuery);

	// ��ͬ�������
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("contractCategory.field.name");
	}

};

#include OATPP_CODEGEN_END(DTO)

#endif // !_CONTRACTCATEGORYQUERY_H_

