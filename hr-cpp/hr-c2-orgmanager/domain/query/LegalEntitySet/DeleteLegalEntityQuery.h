#pragma once
/**
* ������������--ɾ����������(֧������ɾ��)--pine
 */
#ifndef _DELETE_LEGAL_ENTITY_QUERY_
#define _DELETE_LEGAL_ENTITY_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

 /**
* ������������--ɾ����������(֧������ɾ��)--pine
  */
class DeleteLegalEntityQuery : public PageQuery
{
	DTO_INIT(DeleteLegalEntityQuery, PageQuery);
	//ǩԼ���嵥λ��ʶCONTRACTSIGNORGID
	DTO_FIELD(List<String>, contractsignorgid);
	DTO_FIELD_INFO(contractsignorgid) {
		info->description = ZH_WORDS_GETTER("LegalEntitySet.field.contractsignorgid");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_DELETE_LEGAL_ENTITY_QUERY_