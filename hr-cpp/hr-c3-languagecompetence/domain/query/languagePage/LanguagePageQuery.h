#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: jun
 @Date: 2023/05/21 1:24:39

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
#ifndef _LANGUAGEPAGEQUERY_H_
#define _LANGUAGEPAGEQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class LanguagePageQuery : public PageQuery
{
	DTO_INIT(LanguagePageQuery, PageQuery);
	//���Ա�ʶ����ID
	API_DTO_FIELD_DEFAULT(String, languageAbilityID, u8"���Ա�ʶ����");
	//����ȼ���ȡʱ��
	API_DTO_FIELD_DEFAULT(String, gainTime, u8"����ȼ���ȡʱ��");
	//��Ȩ
	API_DTO_FIELD_DEFAULT(Int32, permission, u8"��Ȩ");
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
	//����ʱ��
	API_DTO_FIELD_DEFAULT(String, createTime, u8"����ʱ��");
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

#include OATPP_CODEGEN_END(DTO)

#endif // !_LANGUAGEPAGEQUERY_H_