#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Detachment
 @Date: 2023/05/25 8:13:17

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
#ifndef _EMPLOYEEINFOSERVICE_H_
#define _EMPLOYEEINFOSERVICE_H_
#include <list>
#include "domain/query/employeeInfo/EmployeeInfoQuery.h"
#include "domain/dto/employeeInfo/EmployeeInfoDTO.h"
#include "domain/dto/employeeInfo/EmployeeInfoAddDTO.h"

/* *
* Ա����Ϣservice
* ִ���ˣ�Detachment
*/
class EmployeeInfoService
{
public:
	//��ѯָ��Ա��Ա����Ϣ
	EmployeeInfoQuery::Wrapper listEmployee(const EmployeeInfoQuery::Wrapper& query);
	//����Ա����Ϣ
	bool insertEmployee(const EmployeeInfoAddDTO::Wrapper& edto, const PayloadDTO& payLoad);
	//�޸�ָ��Ա��Ա����Ϣ
	bool updateEmployee(const EmployeeInfoDTO::Wrapper& edto, const PayloadDTO& payLoad);
};

#endif // !_EMPLOYEEINFOSERVICE_H_