
/*
 Copyright Zero One Star. All rights reserved.

 @Author: jun
 @Date: 2023/05/23 20:34:46

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
#ifndef _LANGUAGEDO_H_
#define _LANGUAGEDO_H_
#include "../DoInclude.h"
#include <ctime> 
/**
 * ��������DOģ��
 * �����ˣ���
 */
class LanguageDO
{
	//���Ա�ʶ����ID
	CC_SYNTHESIZE(string, languageAbilityID, LanguageAbilityID);
	//����ʱ��
	CC_SYNTHESIZE(string, updateDate, UpdateDate);
	//��ɵ�
	CC_SYNTHESIZE(int, permission, Permission);
	//����ȼ���ȡʱ��
	CC_SYNTHESIZE(string, gainTime, GainTime);
	//����
	CC_SYNTHESIZE(string, attachment, Attachment);
	//����
	CC_SYNTHESIZE(string, languageType, LanguageType);
	//������
	CC_SYNTHESIZE(string, createMan, CreateMan);
	//������
	CC_SYNTHESIZE(string, updateMan, UpdateMan);
	//���Եȼ�
	CC_SYNTHESIZE(string, languageLevel, LanguageLevel);
	//����ʱ��
	CC_SYNTHESIZE(string, createDate, CreateDate)
	//��Ա��Ϣ��ʶ
	CC_SYNTHESIZE(string, personID, PersonID);
	//��¼����
	CC_SYNTHESIZE(string, jlss, JLSS);
	//��¼������
	CC_SYNTHESIZE(string, jlglbh, JLGLBH);
	//��¼����״̬
	CC_SYNTHESIZE(string, jlspzt, JLSPZT);
	//��¼������
	CC_SYNTHESIZE(string, jlczz, JLCZZ);

public:
	//��ʼ��
	LanguageDO() {
		languageAbilityID = "";
		permission = 0;
		gainTime = "";
		attachment = "";
		languageType = "";
		createMan = "";
		updateMan = "";
		languageLevel = "";
		personID = "";
		jlss = "";
		jlglbh = "";
		jlspzt = "";
		jlczz = "";
	}
};

#endif // !_LANGUAGEDO_H_#pragma once
