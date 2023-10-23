#pragma once
/*
��֤�����-֤����Ϣ-����֤�飨������ҳ��ǰ����ɣ���--����
*/
#ifndef _EXPORTCERTIF_VO_
#define _EXPORTCERTIF_VO_

#include "../../GlobalInclude.h"
#include "../../dto/CertificateManage/ExportCertifDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class ExportCertifJsonVO : public JsonVO<ExportCertifDTO::Wrapper> {
	DTO_INIT(ExportCertifJsonVO, JsonVO<ExportCertifDTO::Wrapper>);
};

class ExportCertifPageJsonVO : public JsonVO<ExportCertifPageDTO::Wrapper> {
	DTO_INIT(ExportCertifPageJsonVO, JsonVO<ExportCertifPageDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)

#endif // !_EXPORTCERTIF_VO_