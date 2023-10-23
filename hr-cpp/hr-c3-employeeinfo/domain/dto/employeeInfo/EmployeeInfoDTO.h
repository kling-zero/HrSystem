#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Detachment
 @Date: 2023/05/17 20:01:54

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
#ifndef _EMPLOYEEINFODTO_H_
#define _EMPLOYEEINFODTO_H_

#include "../../GlobalInclude.h"
#include "ApiHelper.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/* *
* �޸�ָ��Ա����ϢDTO
* ִ���ˣ�Detachment
*/
class EmployeeInfoDTO : public oatpp::DTO
{
	DTO_INIT(EmployeeInfoDTO, DTO);
	//��Ա��Ϣ��ʶ
	API_DTO_FIELD_DEFAULT(String, pimpersonid, ZH_WORDS_GETTER("employee.field.pimpersonid"));
	//Ա�����
	DTO_FIELD(String, empid);
	DTO_FIELD_INFO(empid) {
		info->description = ZH_WORDS_GETTER("employee.field.id");
		info->required = true;
	}
	//Ա������
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("employee.field.name");
		info->required = true;
	}
	//֤������
	DTO_FIELD(String, idtype);
	DTO_FIELD_INFO(idtype) {
		info->description = ZH_WORDS_GETTER("employee.field.idtype");
		info->required = true;
	}
	//֤������
	DTO_FIELD(String, idnum);
	DTO_FIELD_INFO(idnum) {
		info->description = ZH_WORDS_GETTER("employee.field.idnum");
		info->required = true;
	}
	//��������
	DTO_FIELD(String, bthdate);
	DTO_FIELD_INFO(bthdate) {
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
	//Ѫ��
	API_DTO_FIELD_DEFAULT(String, blood, ZH_WORDS_GETTER("employee.field.blood"));
	//�ֻ�����
	DTO_FIELD(String, phone);
	DTO_FIELD_INFO(phone) {
		info->description = ZH_WORDS_GETTER("employee.field.phone");
		info->required = true;
	}
	// ��������
	DTO_FIELD(String, email);
	DTO_FIELD_INFO(email) {
		info->description = ZH_WORDS_GETTER("employee.field.email");
	}
	// ����״��
	DTO_FIELD(String, marriage);
	DTO_FIELD_INFO(marriage) {
		info->description = ZH_WORDS_GETTER("employee.field.marriage");
	}
	// ����
	DTO_FIELD(String, nation);
	DTO_FIELD_INFO(nation) {
		info->description = ZH_WORDS_GETTER("employee.field.nation");
	}
	//��������
	API_DTO_FIELD_DEFAULT(String, residentType, ZH_WORDS_GETTER("employee.field.residentType"));
	// ����
	DTO_FIELD(String, native);
	DTO_FIELD_INFO(native) {
		info->description = ZH_WORDS_GETTER("employee.field.native");
	}
	//�������ڵ�
	API_DTO_FIELD_DEFAULT(String, residentPlace, ZH_WORDS_GETTER("employee.field.residentPlace"));
	// ������ַ
	API_DTO_FIELD_DEFAULT(String, residentLocate, ZH_WORDS_GETTER("employee.field.residentLocate"));
	// ������ַ
	API_DTO_FIELD_DEFAULT(String, birthPlace, ZH_WORDS_GETTER("employee.field.birthPlace"));
	// ͨѶ��ַ
	API_DTO_FIELD_DEFAULT(String, comPlace, ZH_WORDS_GETTER("employee.field.comPlace"));
	// �ж�����Ů֤
	API_DTO_FIELD_DEFAULT(String, onlyCredit, ZH_WORDS_GETTER("employee.field.onlyCredit"));
	// �����س�
	API_DTO_FIELD_DEFAULT(String, hobby, ZH_WORDS_GETTER("employee.field.hobby"));
	// ����״��
	API_DTO_FIELD_DEFAULT(String, health, ZH_WORDS_GETTER("employee.field.health"));
	
	// ������ò
	DTO_FIELD(String, politic);
	DTO_FIELD_INFO(politic) {
		info->description = ZH_WORDS_GETTER("employee.field.politic");
	}
	API_DTO_FIELD_DEFAULT(String, state, ZH_WORDS_GETTER("employee.field.state"));
	API_DTO_FIELD_DEFAULT(String, workstate, ZH_WORDS_GETTER("employee.field.workstate"));
	API_DTO_FIELD_DEFAULT(String, inway, ZH_WORDS_GETTER("employee.field.inway"));
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
	API_DTO_FIELD_DEFAULT(Int32, blacklist, ZH_WORDS_GETTER("employee.field.blacklist"));
	// ��Ƭ·��
	DTO_FIELD(String, photo);
	DTO_FIELD_INFO(photo) {
		info->description = ZH_WORDS_GETTER("employee.field.photo");
	}
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_EMPLOYEEINFODTO_H_