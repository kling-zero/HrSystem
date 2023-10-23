#pragma once

/*
��֯���� ���� �������� ���� ������������  -- cpt

�����������������б� `LegalEntitySetPullDownList`

����ָ������������Ϣ  `UpdateLegalerSettingMessage`

������������ `LegalEntitySet`

�����������ã�֧������������** `LegalEntitySet`
*/

#ifndef _LEGALENTITYSETQUERY_DTO_
#define _LEGALENTITYSETQUERY_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)


class LegalEntitySetQueryDTO : public oatpp::DTO {
public:
	LegalEntitySetQueryDTO() {};
	LegalEntitySetQueryDTO(String contractsignorgid, String contractsignorgname, String ormsignorgid, String ormorgid, String isdefaultsignorg) : 
		contractsignorgid(contractsignorgid), contractsignorgname(contractsignorgname), ormsignorgid(ormsignorgid), ormorgid(ormorgid), isdefaultsignorg(isdefaultsignorg) {};
	DTO_INIT(LegalEntitySetQueryDTO, DTO);
	// ǩԼ���嵥λ��ʶ
	DTO_FIELD(String, contractsignorgid);
	DTO_FIELD_INFO(contractsignorgid) {
		info->description = ZH_WORDS_GETTER("LegalEntitySet.field.contractsignorgid");
	}
	// ǩԼ���嵥λ����
	DTO_FIELD(String, contractsignorgname);
	DTO_FIELD_INFO(contractsignorgname) {
		info->description = ZH_WORDS_GETTER("LegalEntitySet.field.contractsignorgname");
	}
	// ���������ʶ
	DTO_FIELD(String, ormsignorgid);
	DTO_FIELD_INFO(ormsignorgid) {
		info->description = ZH_WORDS_GETTER("LegalEntitySet.field.ormsignorgid");
	}
	// ����λ��ʶ
	DTO_FIELD(String, ormorgid);
	DTO_FIELD_INFO(ormorgid) {
		info->description = ZH_WORDS_GETTER("LegalEntitySet.field.ormorgid");
	}
	// // Ĭ��ǩԼ����
	DTO_FIELD(String, isdefaultsignorg);
	DTO_FIELD_INFO(isdefaultsignorg) {
		info->description = ZH_WORDS_GETTER("LegalEntitySet.field.isdefaultsignorg");
	}
};

class LegalEntitySetQueryPageDTO : public PageDTO<LegalEntitySetQueryDTO::Wrapper> {
	DTO_INIT(LegalEntitySetQueryPageDTO, PageDTO<LegalEntitySetQueryDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_LEGALENTITYSETQUERY_DTO_