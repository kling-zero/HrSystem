#pragma once

#ifndef _EMPLOYEE_INFOMATION_DTO_
#define _EMPLOYEE_INFOMATION_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * �������
 */
class EmployeeInformationDTO : public oatpp::DTO
{
	DTO_INIT(EmployeeInformationDTO, DTO);
	
	//��Ա��Ϣ��ʶ
	DTO_FIELD(String, personId);
	DTO_FIELD_INFO(personId) {
		info->description = ZH_WORDS_GETTER("employee.field.personId");
	}
	//������
	DTO_FIELD(String, createMan);
	DTO_FIELD_INFO(createMan) {
		info->description = ZH_WORDS_GETTER("employee.field.createMan");
	}
	//����ʱ��
	DTO_FIELD(String, createDate);
	DTO_FIELD_INFO(createDate) {
		info->description = ZH_WORDS_GETTER("employee.field.createDate");
	}
	// ����
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("employee.field.name");
	}
	//// �Ա�
	//DTO_FIELD(String, sex);
	//DTO_FIELD_INFO(sex) {
	//	info->description = ZH_WORDS_GETTER("employee.field.sex");
	//}
	// ����
	DTO_FIELD(UInt32, age);
	DTO_FIELD_INFO(age) {
		info->description = ZH_WORDS_GETTER("employee.field.age");
	}
	//���
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("employee.field.id");
	}
	//��֯
	DTO_FIELD(String, organize);
	DTO_FIELD_INFO(organize) {
		info->description = ZH_WORDS_GETTER("employee.field.organize");
	}
	//����
	DTO_FIELD(String, depart);
	DTO_FIELD_INFO(depart) {
		info->description = ZH_WORDS_GETTER("employee.field.depart");
	}
	//ְ��
	DTO_FIELD(String, job);
	DTO_FIELD_INFO(job) {
		info->description = ZH_WORDS_GETTER("employee.field.job");
	}
	//��λ
	DTO_FIELD(String, post);
	DTO_FIELD_INFO(post) {
		info->description = ZH_WORDS_GETTER("employee.field.post");
	}
	//֤����
	DTO_FIELD(String, idMum);
	DTO_FIELD_INFO(idMum) {
		info->description = ZH_WORDS_GETTER("employee.field.idMum");
	}
	//��������
	DTO_FIELD(String, birthday);
	DTO_FIELD_INFO(birthday) {
		info->description = ZH_WORDS_GETTER("employee.field.birthday");
	}
	//�ֻ�����
	DTO_FIELD(String, phone);
	DTO_FIELD_INFO(phone) {
		info->description = ZH_WORDS_GETTER("employee.field.phone");
	}
	//Ա��״̬
	DTO_FIELD(String, state);
	DTO_FIELD_INFO(state) {
		info->description = ZH_WORDS_GETTER("employee.field.state");
	}
};

/**
 * ʾ����ҳ�������
 */
class EmployeeInformationPageDTO : public PageDTO<EmployeeInformationDTO::Wrapper>
{
	DTO_INIT(EmployeeInformationPageDTO, PageDTO<EmployeeInformationDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_EMPLOYEE_INFOMATION_DTO_