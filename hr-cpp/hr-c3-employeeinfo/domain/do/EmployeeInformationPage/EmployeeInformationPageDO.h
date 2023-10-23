#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: guyier
 @Date: 2023/05/24 13:28:40

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
#ifndef _EMPLOYEE_INfORMATION_PAGE_DO_
#define _EMPLOYEE_INfORMATION_PAGE_DO_
#include "../DoInclude.h"

/*
��ҳ��ѯʵ����
*/
class EmployeeInformationPageDO
{
	//��Ա��Ϣ��ʶ
	CC_SYNTHESIZE(string, personId, PersonId);
	//������
	CC_SYNTHESIZE(string, createMan, CreateMan);
	//����ʱ��
	CC_SYNTHESIZE(string, createDate, CreateDate);

	// ����
	CC_SYNTHESIZE(string, name, Name);
	// ����
	CC_SYNTHESIZE(int32_t, age, Age);
	//���
	CC_SYNTHESIZE(string, id, Id);
	//��֯
	CC_SYNTHESIZE(string, organize, Organize);
	//����
	CC_SYNTHESIZE(string, depart, Depart);
	//ְ��
	CC_SYNTHESIZE(string, job, Job);
	//��λ
	CC_SYNTHESIZE(string, post, Post);
	//֤����
	CC_SYNTHESIZE(string, idMum, IdMum);
	//��������
	CC_SYNTHESIZE(string, birthday, Birthday);
	//�ֻ�����
	CC_SYNTHESIZE(string, phone, Phone);
	//Ա��״̬
	CC_SYNTHESIZE(string, state, State);
public:
	EmployeeInformationPageDO() {
		personId = "";
		name = "";
		age = 0;
		id = "";
		organize = "";
		depart = "";
		job = "";
		post = "";
		idMum = "";
		birthday = "";
		phone = "";
		state = "";
	}
};

#endif // !_EMPLOYEE_INfORMATION_PAGE_DO_
