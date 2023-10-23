#pragma once
/**
 * (֤�����-��ѯ֤�������б�)--weixiaoman
 */
#ifndef _CERTIFICATETYPE_VO_
#define _CERTIFICATETYPE_VO_

#include "../../GlobalInclude.h"
#include "../../dto/CertificateManage/CertificateTypeDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ֤��������ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class CertificateTypeJsonVO : public JsonVO<CertificateTypeDTO::Wrapper> {
	DTO_INIT(CertificateTypeJsonVO, JsonVO<CertificateTypeDTO::Wrapper>);
};

/**
 * ֤��������ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class CertificateTypePageJsonVO : public JsonVO<CertificateTypePageDTO::Wrapper> {
	DTO_INIT(CertificateTypePageJsonVO, JsonVO<CertificateTypePageDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)
#endif // !_CERTIFICATETYPE_VO_