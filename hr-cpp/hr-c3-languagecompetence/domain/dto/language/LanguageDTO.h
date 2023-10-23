#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: jun
 @Date: 2023/05/17 19:31:17

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
#ifndef _LANGUAGEDTO_H_
#define _LANGUAGEDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����ģ�鴫�����
 */
class LanguageDTO : public oatpp::DTO
{
	DTO_INIT(LanguageDTO, DTO);
	//����������ʶId
	API_DTO_FIELD_DEFAULT(String, languageAbilityID, u8"���Ա�ʶ����Id");
	//��ɵ�
	API_DTO_FIELD_DEFAULT(Int32, permission, u8"��Ȩ");
	//����ȼ���ȡʱ��
	API_DTO_FIELD_DEFAULT(String, gainTime, u8"����ȼ���ȡʱ��");
	//����
	API_DTO_FIELD_DEFAULT(String, attachment, u8"����");
	//����
	API_DTO_FIELD_DEFAULT(String, languageType, u8"����");
	//������
	API_DTO_FIELD_DEFAULT(String, createMan, u8"������");
	//������
	API_DTO_FIELD_DEFAULT(String, updateMan, u8"������");
	//���Եȼ�
	API_DTO_FIELD_DEFAULT(String, languageLevel, u8"���Եȼ�");
	//��Ա��Ϣ��ʶ
	API_DTO_FIELD_DEFAULT(String, personID, u8"��Ա��Ϣ��ʶ");
	//��¼����
	API_DTO_FIELD_DEFAULT(String, jlss, u8"��¼����");
	//��¼������
	API_DTO_FIELD_DEFAULT(String, jlglbh, u8"��¼������");
	//��¼����״̬
	API_DTO_FIELD_DEFAULT(String, jlspzt, u8"��¼����״̬");
	//��¼������
	API_DTO_FIELD_DEFAULT(String, jlczz, u8"��¼������");
};
/**
 * ����ģ���ҳ�������
 */
class LanguagePageDTO : public PageDTO<LanguageDTO::Wrapper> 
{
	DTO_INIT(LanguagePageDTO, PageDTO<LanguageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_LANGUAGEDTO_H_