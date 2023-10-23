#pragma once
#ifndef _CERTIFICATE_INFORMATION_DTO_H_
#define _CERTIFICATE_INFORMATION_DTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ְ�Ʋ�ѯ������������
 */
class CertificateInformationDTO : public oatpp::DTO
{
public:
	CertificateInformationDTO() {};
	CertificateInformationDTO(String zgzsbh, String pimvocationalname) :zgzsbh(zgzsbh), pimvocationalname(pimvocationalname) {};

	DTO_INIT(CertificateInformationDTO, DTO);
	//pimpersonid: ��Ա��Ϣ��ʶ
	DTO_FIELD(String, pimpersonid);
	DTO_FIELD_INFO(pimpersonid) {
		info->description = ZH_WORDS_GETTER("certificateinformation.field.pimpersonid");
	}
	//zgzsbh: ֤����
	DTO_FIELD(String, zgzsbh);
	DTO_FIELD_INFO(zgzsbh) {
		info->description = ZH_WORDS_GETTER("certificateinformation.field.zgzsbh");
	}
	// pimvocationalname: ֤������
	DTO_FIELD(String, pimvocationalname);
	DTO_FIELD_INFO(pimvocationalname) {
		info->description = ZH_WORDS_GETTER("certificateinformation.field.pimvocationalname");
	}
	//zslx: ֤������
	DTO_FIELD(String, zslx);
	DTO_FIELD_INFO(zslx) {
		info->description = ZH_WORDS_GETTER("certificateinformation.field.zslx");
	}
	//zghqrq: ǩ������
	DTO_FIELD(String, zghqrq);
	DTO_FIELD_INFO(zghqrq) {
		info->description = ZH_WORDS_GETTER("certificateinformation.field.zghqrq");
	}
	//zgsydw: ǩ������
	DTO_FIELD(String, zgsydw);
	DTO_FIELD_INFO(zgsydw) {
		info->description = ZH_WORDS_GETTER("certificateinformation.field.zgsydw");
	}
	//fzyxq: ��֤��Ч��
	DTO_FIELD(String, fzyxq);
	DTO_FIELD_INFO(fzyxq) {
		info->description = ZH_WORDS_GETTER("certificateinformation.field.fzyxq");
	}
	
};

/**
 * ��ͬ��ѯ��ҳ������������
 */
class CertificateInformationPageDTO : public PageDTO<CertificateInformationDTO::Wrapper>
{
	DTO_INIT(CertificateInformationPageDTO, PageDTO<CertificateInformationDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif
