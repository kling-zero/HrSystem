#pragma once

#ifndef _LEGALENTITYSET_QUERY_
#define _LEGALENTITYSET_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/*
��֯���� ������������ ���� ������������  -- cpt

�����������������б� `LegalEntitySetPullDownList`

����ָ������������Ϣ  `UpdateLegalerSettingMessage`

������������ `LegalEntitySet`

�����������ã�֧������������** `LegalEntitySet`
*/
class LegalEntitySetQuery : public PageQuery
{
	DTO_INIT(LegalEntitySetQuery, PageQuery);
	// ���������ʶ
	DTO_FIELD(String, ormsignorgid);
	DTO_FIELD_INFO(ormsignorgid) {
		info->description = ZH_WORDS_GETTER("LegalEntitySet.field.ormsignorgid");
	}
	// ǩԼ���嵥λ����
	DTO_FIELD(String, contractsignorgname);
	DTO_FIELD_INFO(contractsignorgname) {
		info->description = ZH_WORDS_GETTER("LegalEntitySet.field.contractsignorgname");
	}
	//  Ĭ��ǩԼ����
	DTO_FIELD(String, isdefaultsignorg);
	DTO_FIELD_INFO(isdefaultsignorg) {
		info->description = ZH_WORDS_GETTER("LegalEntitySet.field.isdefaultsignorg");
	}
	// ǩԼ���嵥λ��ʶ
	DTO_FIELD(String, contractsignorgid);
	DTO_FIELD_INFO(contractsignorgid) {
		info->description = ZH_WORDS_GETTER("LegalEntitySet.field.contractsignorgid");
	}
	// ����λ��ʶ
	DTO_FIELD(String, ormorgid);
	DTO_FIELD_INFO(ormorgid) {
		info->description = ZH_WORDS_GETTER("LegalEntitySet.field.ormorgid");
	}
	//// ������
	//DTO_FIELD(String, updateman);
	//DTO_FIELD_INFO(updateman) {
	//	info->description = ZH_WORDS_GETTER("LegalEntitySet.field.updateman");
	//}
	//// ������
	//DTO_FIELD(String, createman);
	//DTO_FIELD_INFO(createman) {
	//	info->description = ZH_WORDS_GETTER("LegalEntitySet.field.createman");
	//}
	//// ����ʱ��
	//DTO_FIELD(String, createdate);
	//DTO_FIELD_INFO(createdate) {
	//	info->description = ZH_WORDS_GETTER("LegalEntitySet.field.createdate");
	//}
	//// ����ʱ��
	//DTO_FIELD(String, updatedate);
	//DTO_FIELD_INFO(updatedate) {
	//	info->description = ZH_WORDS_GETTER("LegalEntitySet.field.updatedate");
	//}

	// ���������ʶ
	/*DTO_FIELD(String, signorgid);
	DTO_FIELD_INFO(signorgid) {
		info->description = ZH_WORDS_GETTER("LegalEntitySet.field.signorgid");
	}*/
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_LEGALENTITYSET_QUERY_
