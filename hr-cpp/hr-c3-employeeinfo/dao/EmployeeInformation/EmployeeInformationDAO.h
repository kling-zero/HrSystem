#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: guyier
 @Date: 2023/05/25 20:30:40

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
#ifndef _EMPLOYEE_INFORMATION_DAO_
#define _EMPLOYEE_INFORMATION_DAO_
#include "BaseDAO.h"
#include "domain/do/EmployeeInformationPage/EmployeeInformationPageDO.h"
#include "domain/query/EmployeeInformationPageQuery/EmployeeInformationPageQuery.h"
#include "domain/query/postSet/PostDetailQuery.h"

class EmployeeInformationDAO:public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const EmployeeInformationPageQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<EmployeeInformationPageDO> selectWithPage(const EmployeeInformationPageQuery::Wrapper& query);
	// ��������
	uint64_t insert(const EmployeeInformationPageDO& iObj);
    //��Ա����Ϣ����������Ա����Ϣ��
	//std::list<std::string> insertMultiEmp(const std::list<EmployeeInformationPageDO>& data);
	//����Ա����Ϣ(������ҳ��ǰ�����)
	std::list<EmployeeInformationPageDO> exportEmpInfo(const PostDetailQuery::Wrapper& query);
	//���ɱ�ͷ
	vector<std::string> getEmpInfoHead();
};

#endif // !_EMPLOYEE_INFORMATION_DAO_
