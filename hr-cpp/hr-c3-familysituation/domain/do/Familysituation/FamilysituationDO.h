#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Marvin
 @Date: 2023/05/24 16:17:01

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
#ifndef _FAMILYSITUATIONDO_H_
#define _FAMILYSITUATIONDO_H_
#include "../DoInclude.h"

/**
 * ��ͥ������ݿ�ʵ����
 */
class FamilysituationDO
{
	// ��ͥ������
	CC_SYNTHESIZE(string, id, Id);
	// Ա�����
	CC_SYNTHESIZE(string, personid, PersonId);
	// ��ϵ
	CC_SYNTHESIZE(string, frelationship, Relationship);
	// ����
	CC_SYNTHESIZE(string, name, Name);
	// �Ա�
	CC_SYNTHESIZE(string, gender, Gender);
	// ����
	CC_SYNTHESIZE(int, age, Age);
	// ������λ
	CC_SYNTHESIZE(string, workplace, Workplace);
	// ְ��
	CC_SYNTHESIZE(string, job, Job);
	// ������ò
	CC_SYNTHESIZE(string, politicalstatus, Politicalstatus);
	// ֤������
	CC_SYNTHESIZE(string, doctype, Doctype);
	// ֤����
	CC_SYNTHESIZE(string, identification, Identification);
	// ��������
	CC_SYNTHESIZE(string, dob, Dob);
	// �Ƿ�����
	CC_SYNTHESIZE(int, testament, Testament);
	// �Ƿ������ϵ��
	CC_SYNTHESIZE(string, ice, Ice);
	// Ȩ����֤��ԱID
	CC_SYNTHESIZE(string, authid, AuthId);
	// ����ʱ��
	CC_SYNTHESIZE(string, opertime, Opertime);
public:
	FamilysituationDO() {
		id = "";
		personid = "";
		frelationship = "";
		name = "";
		gender = "";
		age = -1;
		workplace = "";
		job = "";
		politicalstatus = "";
		doctype = "";
		identification = "";
		dob = "";
		testament = -1;
		ice = "";
		authid = "";
		opertime = "";
	}
};

#endif // !_FAMILYSITUATIONDO_H_