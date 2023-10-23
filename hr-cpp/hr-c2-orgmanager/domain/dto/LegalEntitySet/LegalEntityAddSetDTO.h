#pragma once

#ifndef _LEGALENTITYSETADDQUERY_DTO_
#define _LEGALENTITYSETADDQUERY_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class LegalEntitySetAddDTO : public oatpp::DTO {
public:
	LegalEntitySetAddDTO() {};
	LegalEntitySetAddDTO(String ormsignorgid, String ormorgid, String contractsignorgname, String isdefaultsignorg) : 
		ormsignorgid(ormsignorgid), ormorgid(ormorgid), contractsignorgname(contractsignorgname), isdefaultsignorg(isdefaultsignorg) {	};
	//LegalEntitySetAddDTO(String ormsignorgid, String ormorgid, String contractsignorgname, String isdefaultsignorg) {	};
	DTO_INIT(LegalEntitySetAddDTO, DTO);
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
	//  Ĭ��ǩԼ����
	DTO_FIELD(String, isdefaultsignorg) = "1";
	DTO_FIELD_INFO(isdefaultsignorg) {
		info->description = ZH_WORDS_GETTER("LegalEntitySet.field.isdefaultsignorg");
	}
	// ����λ��ʶ
	DTO_FIELD(String, ormorgid);
	DTO_FIELD_INFO(ormorgid) {
		info->description = ZH_WORDS_GETTER("LegalEntitySet.field.ormorgid");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_LEGALENTITYSETDELQUERY_DTO_