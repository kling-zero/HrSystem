#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: guyier
 @Date: 2023/05/25 22:21:05

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
#ifndef _EMPLOYEE_INFORMATION_MAPPER_
#define _EMPLOYEE_INFORMATION_MAPPER_

#include "Mapper.h"
#include "domain/do/EmployeeInformationPage/EmployeeInformationPageDO.h"

/**
 * Ա����Ϣ���ֶ�ƥ��ӳ��
 */
class EmployeeInformationMapper :public Mapper<EmployeeInformationPageDO>
{
public:
	EmployeeInformationPageDO mapper(ResultSet* resultSet) const override
	{
		EmployeeInformationPageDO data;
		//��Ա��Ϣ��ʶ
		data.setPersonId(resultSet->getString(1));
		//������
		data.setCreateMan(resultSet->getString(4));
		//����ʱ��
		data.setCreateMan(resultSet->getString(7));

		// ����
		data.setName(resultSet->getString(3));
		// ����
		data.setAge(resultSet->getInt(16));
		//���
		data.setId(resultSet->getString(8));
		//��֯
		data.setOrganize(resultSet->getString(46));
		//����
		data.setDepart(resultSet->getString(47));
		//ְ��
		data.setJob(resultSet->getString(50));
		//��λ
		data.setPost(resultSet->getString(49));
		//֤����
		data.setIdMum(resultSet->getString(13));
		//��������
		data.setBirthday(resultSet->getString(15));
		//�ֻ�����
		data.setPhone(resultSet->getString(20));
		//Ա��״̬
		data.setState(resultSet->getString(35));
		return data;
	}
};

#endif // !_EMPLOYEE_INFORMATION_MAPPER_
