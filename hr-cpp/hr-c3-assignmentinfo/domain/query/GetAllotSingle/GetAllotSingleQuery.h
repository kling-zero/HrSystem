#ifndef _USERQUERY_H_
#define _USERQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����һ����ѯ�û���Ϣ�����ݴ���ģ��
 */
class GetAllotSingleQuery : public PageQuery
{
	// �����ʼ��
	DTO_INIT(GetAllotSingleQuery, PageQuery);
	// Ա������pimpersonname
	DTO_FIELD(String, pimpersonname);
	DTO_FIELD_INFO(pimpersonname) {
		info->description = ZH_WORDS_GETTER("t_pimperson.pimpersonname");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_USERQUERY_H_