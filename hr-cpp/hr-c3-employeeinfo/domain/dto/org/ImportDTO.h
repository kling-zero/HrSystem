#pragma once
#ifndef _IMPORTDTO_
#define _IMPORTDTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ���������
 */
class ImportDTO : public oatpp::DTO
{
	DTO_INIT(ImportDTO , DTO);

    // �����Ƿ�ɹ�
	DTO_FIELD(String, success);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_org_DTO_