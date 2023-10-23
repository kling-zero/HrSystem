#pragma once
/*
��֯���� ���� �������� ���� ������������  -- cpt

�����������������б� `LegalEntitySetPullDownList`

����ָ������������Ϣ  `UpdateLegalerSettingMessage`

������������ `LegalEntitySet`

�����������ã�֧������������** `LegalEntitySet`
*/

#ifndef _LEGALENTITYSET_DTO_
#define _LEGALENTITYSET_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)


class LegalEntitySetDTO : public oatpp::DTO {
public: 
	LegalEntitySetDTO() {};
	LegalEntitySetDTO(String ormsignorgid):ormsignorgid(ormsignorgid) {};
	LegalEntitySetDTO(String ormsignorgid, String ormsignorgname, String contractsignorgname, String isdefaultsignorg) {	};
	DTO_INIT(LegalEntitySetDTO, DTO);
	// ���������ʶ
	DTO_FIELD(String, ormsignorgid);
	DTO_FIELD_INFO(ormsignorgid) {
		info->description = ZH_WORDS_GETTER("LegalEntitySet.field.ormsignorgid");
	}
	// ǩԼ���嵥λ����
	/*DTO_FIELD(String, contractsignorgname);
	DTO_FIELD_INFO(contractsignorgname) {
		info->description = ZH_WORDS_GETTER("LegalEntitySet.field.contractsignorgname");
	}*/
	//  Ĭ��ǩԼ����
	DTO_FIELD(String, isdefaultsignorg) = "1";
	DTO_FIELD_INFO(isdefaultsignorg) {
		info->description = ZH_WORDS_GETTER("LegalEntitySet.field.isdefaultsignorg");
	}
	// ǩԼ���嵥λ��ʶ
	/*DTO_FIELD(String, contractsignorgid);
	DTO_FIELD_INFO(contractsignorgid) {
		info->description = ZH_WORDS_GETTER("LegalEntitySet.field.contractsignorgid");
	}*/
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
	DTO_FIELD(String, signorgid);
	DTO_FIELD_INFO(signorgid) {
		info->description = ZH_WORDS_GETTER("LegalEntitySet.field.signorgid");
	}
};

class LegalEntitySetPageDTO : public PageDTO<LegalEntitySetDTO::Wrapper> {
	DTO_INIT(LegalEntitySetPageDTO, PageDTO<LegalEntitySetDTO::Wrapper>);
};

class LegalEntitySetPullDownDTO : public oatpp::DTO {
	DTO_INIT(LegalEntitySetPullDownDTO, DTO);
	DTO_FIELD(List<LegalEntitySetDTO::Wrapper>, legalEntitySetPullDownList) = {};
	DTO_FIELD_INFO(legalEntitySetPullDownList) {
		info->description = ZH_WORDS_GETTER("LegalEntitySet.dto.legalEntitySetPullDownList");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_LEGALENTITYSET_DTO_