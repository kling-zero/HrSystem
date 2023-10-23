#pragma once
#ifndef _CERTIFICATEVO_H_
#define _CERTIFICATEVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/Certificate/CertificateDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����һ��֤����Ϣ��ʾJsonVO����������Ӧ���ͻ���
 */

class CertificateJsonVO : public JsonVO<CertificateDTO::Wrapper>
{
	DTO_INIT(CertificateJsonVO, JsonVO<CertificateDTO::Wrapper>);
};

/**
 * ����һ��֤����Ϣ��ҳ��ʾJsonVO����������Ӧ���ͻ���
 */
class CertificatePageJsonVO : public JsonVO<CertificatePageDTO::Wrapper>
{
	DTO_INIT(CertificatePageJsonVO, JsonVO<CertificatePageDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)
#endif
 