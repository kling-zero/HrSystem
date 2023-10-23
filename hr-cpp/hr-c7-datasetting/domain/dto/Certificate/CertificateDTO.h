#pragma once
#ifndef _CERTIFICATEDTO_H_
#define _CERTIFICATEDTO_H_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����һ�����޸ĸ�λ����֤��Ĵ������
 */
class CertificateDTO : public oatpp::DTO
{
	DTO_INIT(CertificateDTO, DTO);
	// �����
	DTO_FIELD(UInt64, seialno);
	DTO_FIELD_INFO(seialno) {
		info->description = ZH_WORDS_GETTER("certificate.field.seialno");
	}
	// ��λ����֤��
	DTO_FIELD(String, pimqualtypename);
	DTO_FIELD_INFO(pimqualtypename) {
		info->description = ZH_WORDS_GETTER("certificate.field.pimqualtypename");
	}
};

/*
  ֤���ѯ��ҳ������������
*/
class CertificatePageDTO : public PageDTO<CertificateDTO::Wrapper>
{
	DTO_INIT(CertificatePageDTO, PageDTO<CertificateDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif //!_CERTIFICATEDTO_H_
