#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: rice
 @Date: 2023/5/23 17:58:22

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#ifndef _CERTTYPE_DTO_
#define _CERTTYPE_DTO_
#include "../../GlobalInclude.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ֤�����������б��ѯDTO
 */
class CertTypeDTO : public oatpp::DTO
{
	DTO_INIT(CertTypeDTO, DTO);

	// ֤������ID
	DTO_FIELD(String, certTypeId);
	DTO_FIELD_INFO(certTypeId) {
		info->description = ZH_WORDS_GETTER("common.dto.certTypeId");
	}
	// ֤����������
	DTO_FIELD(String, certTypeName);
	DTO_FIELD_INFO(certTypeName) {
		info->description = ZH_WORDS_GETTER("common.dto.certTypeName");
	}
	// ֤�����ʹ���
	DTO_FIELD(String, certTypeCode);
	DTO_FIELD_INFO(certTypeCode) {
		info->description = ZH_WORDS_GETTER("common.dto.certTypeCode");
	}
	// ֤�������Ƿ���Ч (0��Ч, 1��Ч)
	DTO_FIELD(Boolean, certTypeValidity);
	DTO_FIELD_INFO(certTypeValidity) {
		info->description = ZH_WORDS_GETTER("common.dto.certTypeValidity");
	}
	CertTypeDTO()
	{
		certTypeId = "1";
		certTypeName = u8"ִ��ְ��ҵ�ʸ�֤��";
		certTypeCode = "10";
		certTypeValidity = 1;
	}
};

/**
 * ֤�����������б��ҳ��ѯDTO
 */
class CertTypeListDTO : public PageDTO<CertTypeDTO::Wrapper>
{
	DTO_INIT(CertTypeListDTO, PageDTO<CertTypeDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)
#endif // !_CERTTYPE_DTO_