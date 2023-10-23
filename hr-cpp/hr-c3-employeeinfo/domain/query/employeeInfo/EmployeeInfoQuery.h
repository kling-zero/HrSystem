#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Detachment
 @Date: 2023/05/17 14:29:04

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
#ifndef _EMPLOYEE_INFO_QUERY_
#define _EMPLOYEE_INFO_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"
#include "ApiHelper.h"

#include OATPP_CODEGEN_BEGIN(DTO)
//��ѯ����Ա����Ϣ
class EmployeeInfoQuery : public PageQuery
{
	DTO_INIT(EmployeeInfoQuery, PageQuery);
	//��Ա��Ϣ��ʶ
	API_DTO_FIELD_DEFAULT(String, pimpersonid, ZH_WORDS_GETTER("employee.field.pimpersonid"));
	//Ա�����
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("employee.field.id");
	}
	//Ա������
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("employee.field.name");
	}
	//֤������
	DTO_FIELD(String, idType);
	DTO_FIELD_INFO(idType) {
		info->description = ZH_WORDS_GETTER("employee.field.idtype");
	}
	//֤������
	DTO_FIELD(String, idNum);
	DTO_FIELD_INFO(idNum) {
		info->description = ZH_WORDS_GETTER("employee.field.idnum");
	}
	//��������
	DTO_FIELD(String, birthday);
	DTO_FIELD_INFO(birthday) {
		info->description = ZH_WORDS_GETTER("employee.field.birthday");
	}
	// ����
	DTO_FIELD(Int32, age);
	DTO_FIELD_INFO(age) {
		info->description = ZH_WORDS_GETTER("employee.field.age");
	}
	// �Ա�
	DTO_FIELD(String, sex);
	DTO_FIELD_INFO(sex) {
		info->description = ZH_WORDS_GETTER("employee.field.sex");
	}
	// ����
	DTO_FIELD(String, nation);
	DTO_FIELD_INFO(nation) {
		info->description = ZH_WORDS_GETTER("employee.field.nation");
	}
	// ����
	DTO_FIELD(String, native);
	DTO_FIELD_INFO(native) {
		info->description = ZH_WORDS_GETTER("employee.field.native");
	}
	// ����״��
	DTO_FIELD(String, marriage);
	DTO_FIELD_INFO(marriage) {
		info->description = ZH_WORDS_GETTER("employee.field.marriage");
	}
	// ������ò
	DTO_FIELD(String, politic);
	DTO_FIELD_INFO(politic) {
		info->description = ZH_WORDS_GETTER("employee.field.politic");
	}
	// ְ��
	DTO_FIELD(String, rank);
	DTO_FIELD_INFO(rank) {
		info->description = ZH_WORDS_GETTER("employee.field.rank");
	}
	// �μӹ���ʱ��
	DTO_FIELD(String, workTime);
	DTO_FIELD_INFO(workTime) {
		info->description = ZH_WORDS_GETTER("employee.field.workTime");
	}
	// ������λʱ��
	DTO_FIELD(String, inTime);
	DTO_FIELD_INFO(inTime) {
		info->description = ZH_WORDS_GETTER("employee.field.inTime");
	}
	// ��������
	DTO_FIELD(String, email);
	DTO_FIELD_INFO(email) {
		info->description = ZH_WORDS_GETTER("employee.field.email");
	}
	// ����ְ��
	DTO_FIELD(String, techTitle);
	DTO_FIELD_INFO(techTitle) {
		info->description = ZH_WORDS_GETTER("employee.field.techTitle");
	}
	// ���ѧ��
	DTO_FIELD(String, acaCredit);
	DTO_FIELD_INFO(acaCredit) {
		info->description = ZH_WORDS_GETTER("employee.field.acaCredit");
	}
	// ��һѧ��
	DTO_FIELD(String, firAcaCredit);
	DTO_FIELD_INFO(firAcaCredit) {
		info->description = ZH_WORDS_GETTER("employee.field.firAcaCredit");
	}
	// ִҵ֤��
	DTO_FIELD(String, pracCertificate);
	DTO_FIELD_INFO(pracCertificate) {
		info->description = ZH_WORDS_GETTER("employee.field.pracCertificate");
	}
	// ��Ƭ·��
	DTO_FIELD(String, photo);
	DTO_FIELD_INFO(photo) {
		info->description = ZH_WORDS_GETTER("employee.field.photo");
	}
	//�ֻ�����
	DTO_FIELD(String, phone);
	DTO_FIELD_INFO(phone) {
		info->description = ZH_WORDS_GETTER("employee.field.phone");
	}
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_EMPLOYEE_INFO_QUERY_