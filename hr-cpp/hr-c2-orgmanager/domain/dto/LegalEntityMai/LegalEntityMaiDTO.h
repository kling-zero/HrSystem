#pragma once

#ifndef _LEGALENTITYMAIDTO_H_
#define _LEGALENTITYMAIDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/* ��������ά�����ݴ��������--����֯����-��������-��������ά����--TripleGold */
class LegalEntityMaiDTO : public oatpp::DTO
{
public:
	LegalEntityMaiDTO() {};
	// �вι��캯��
	LegalEntityMaiDTO(String name, String orgcode) : ORMSIGNORGNAME(name), ORGCODE(orgcode) {};
	LegalEntityMaiDTO(String id, String name, String orgcode) : ORMSIGNORGID(id), ORMSIGNORGNAME(name), ORGCODE(orgcode) {};
	/*LegalEntityMaiDTO(String id, String updateman, String createman, String createdate,
		String name, String updatedate, String orgcode, String shortForm) :
		ORMSIGNORGID(id), UPDATEMAN(updateman), CREATEMAN(createman), CREATEDATE(createdate),
		ORMSIGNORGNAME(name), UPDATEDATE(updatedate), ORGCODE(orgcode), ZZJC(shortForm) {};*/
	DTO_INIT(LegalEntityMaiDTO, DTO);
	// ���������ʶ
	DTO_FIELD(String, ORMSIGNORGID);
	DTO_FIELD_INFO(ORMSIGNORGID) {
		info->description = ZH_WORDS_GETTER("LegalEntityMai.field.id");
	}
	// ������������
	DTO_FIELD(String, ORMSIGNORGNAME);
	DTO_FIELD_INFO(ORMSIGNORGNAME) {
		info->description = ZH_WORDS_GETTER("LegalEntityMai.field.name");
	}
	// ��֯���
	DTO_FIELD(String, ORGCODE);
	DTO_FIELD_INFO(ORGCODE) {
		info->description = ZH_WORDS_GETTER("LegalEntityMai.field.orgcode");
	}

	//// ���������ʶ
	//DTO_FIELD(String, ORMSIGNORGID);
	//DTO_FIELD_INFO(ORMSIGNORGID) {
	//	info->description = ZH_WORDS_GETTER("LegalEntityMai.field.id");
	//}
	//// ������
	//DTO_FIELD(String, UPDATEMAN);
	//DTO_FIELD_INFO(UPDATEMAN) {
	//	info->description = ZH_WORDS_GETTER("LegalEntityMai.field.updateman");
	//}
	//// ������
	//DTO_FIELD(String, CREATEMAN);
	//DTO_FIELD_INFO(CREATEMAN) {
	//	info->description = ZH_WORDS_GETTER("LegalEntityMai.field.createman");
	//}
	//// ����ʱ��
	//DTO_FIELD(String, CREATEDATE);
	//DTO_FIELD_INFO(CREATEDATE) {
	//	info->description = ZH_WORDS_GETTER("LegalEntityMai.field.createdate");
	//}
	//// ������������
	//DTO_FIELD(String, ORMSIGNORGNAME);
	//DTO_FIELD_INFO(ORMSIGNORGNAME) {
	//	info->description = ZH_WORDS_GETTER("LegalEntityMai.field.name");
	//}
	//// ����ʱ��
	//DTO_FIELD(String, UPDATEDATE);
	//DTO_FIELD_INFO(UPDATEDATE) {
	//	info->description = ZH_WORDS_GETTER("LegalEntityMai.field.updatedate");
	//}
	//// ��֯���
	//DTO_FIELD(String, ORGCODE);
	//DTO_FIELD_INFO(ORGCODE) {
	//	info->description = ZH_WORDS_GETTER("LegalEntityMai.field.orgcode");
	//}
	//// ���
	//DTO_FIELD(String, ZZJC);
	//DTO_FIELD_INFO(ZZJC) {
	//	info->description = ZH_WORDS_GETTER("LegalEntityMai.field.short");
	//}
};

/* ���巨�������ҳ������� */
class LegalEntityMaiPageDTO : public PageDTO<LegalEntityMaiDTO::Wrapper> 
{
	DTO_INIT(LegalEntityMaiPageDTO, PageDTO<LegalEntityMaiDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_LEGALENTITYMAI_H_