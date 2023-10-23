#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Detachment
 @Date: 2023/05/17 13:48:29

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
#ifndef _EMPLOYEEINFOADDDTO_H_
#define _EMPLOYEEINFOADDDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/* *
* ���Ա����ϢDTO
* ִ���ˣ�Detachment
*/
class EmployeeInfoAddDTO : public oatpp::DTO
{
	DTO_INIT(EmployeeInfoAddDTO, DTO);
	//��Ա��Ϣ��ʶ
	//API_DTO_FIELD_DEFAULT(String, pimpersonid, ZH_WORDS_GETTER("employee.field.pimpersonid"));
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
	DTO_FIELD(String, idType);
	DTO_FIELD_INFO(idType) {
		info->description = ZH_WORDS_GETTER("employee.field.idtype");
	}
	//֤������
	DTO_FIELD(String, idNum);
	DTO_FIELD_INFO(idNum) {
		info->description = ZH_WORDS_GETTER("employee.field.idnum");
		info->required = true;
	}
	//�ֻ�����
	DTO_FIELD(String, phoneNum);
	DTO_FIELD_INFO(phoneNum) {
		info->description = ZH_WORDS_GETTER("employee.field.phone");
		info->required = true;
	}
	//Ա��״̬
	DTO_FIELD(String, state);
	DTO_FIELD_INFO(state) {
		info->description = ZH_WORDS_GETTER("employee.field.state");
		info->required = true;
	}
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_EMPLOYEEINFODTO_H_