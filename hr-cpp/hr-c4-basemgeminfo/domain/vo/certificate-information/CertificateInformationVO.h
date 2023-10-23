#pragma once
#ifndef _CERTIFICATE_INFORMATION_VO_H_
#define _CERTIFICATE_INFORMATION_VO_H_
#include "../../GlobalInclude.h"
#include "../../dto/certificate-information/CertificateInformationDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)



/**
 * ʾ����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class CertificateInformationPageJsonVO : public JsonVO<CertificateInformationPageDTO::Wrapper> {
	DTO_INIT(CertificateInformationPageJsonVO, JsonVO<CertificateInformationDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif 
