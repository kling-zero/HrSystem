#pragma once
/**
 * ��Ա������ - ��ְ��ԱQueryʵ�� - ������
 */

#ifndef _FORMER_EMPLOYEES_QUERY_
#define _FORMER_EMPLOYEES_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class FormerEmployeesQuery : public PageQuery
{
	DTO_INIT(FormerEmployeesQuery, PageQuery); 
	// ��Ż�����
	DTO_FIELD(String, id_or_name);
	DTO_FIELD_INFO(id_or_name) {
		info->description = ZH_WORDS_GETTER("sample.field.id_or_name");
	}
	//// ���
	//DTO_FIELD(String, id);
	//DTO_FIELD_INFO(id) {
	//	info->description = ZH_WORDS_GETTER("sample.field.id");
	//}
	//// ���
	//DTO_FIELD(String, id);
	//DTO_FIELD_INFO(id) {
	//	info->description = ZH_WORDS_GETTER("sample.field.id");
	//}
	//// ����
	//DTO_FIELD(String, name);
	//DTO_FIELD_INFO(name) {
	//	info->description = ZH_WORDS_GETTER("sample.field.name");
	//}
	//// ����
	//DTO_FIELD(Int32, age);
	//DTO_FIELD_INFO(age) {
	//	info->description = ZH_WORDS_GETTER("sample.field.age");
	//}
	//// �Ա�
	//DTO_FIELD(String, sex);
	//DTO_FIELD_INFO(sex) {
	//	info->description = ZH_WORDS_GETTER("sample.field.sex");
	//}
	//// ��֯
	//DTO_FIELD(String, organization);
	//DTO_FIELD_INFO(organization) {
	//	info->description = ZH_WORDS_GETTER("sample.field.organization");
	//}
	//// ����
	//DTO_FIELD(String, department);
	//DTO_FIELD_INFO(department) {
	//	info->description = ZH_WORDS_GETTER("sample.field.department");
	//}
	//// ְ��
	//DTO_FIELD(String, rank);
	//DTO_FIELD_INFO(rank) {
	//	info->description = ZH_WORDS_GETTER("sample.field.rank");
	//}
	//// ͨѶ��ַ
	//DTO_FIELD(String, mail_address);
	//DTO_FIELD_INFO(mail_address) {
	//	info->description = ZH_WORDS_GETTER("sample.field.mail_address");
	//}
	//// ��ͥ��ϵ��
	//DTO_FIELD(String, family_contact);
	//DTO_FIELD_INFO(family_contact) {
	//	info->description = ZH_WORDS_GETTER("sample.field.family_contact");
	//}
	//// ��ͥ��ϵ�˵绰
	//DTO_FIELD(String, family_contact_number);
	//DTO_FIELD_INFO(family_contact_number) {
	//	info->description = ZH_WORDS_GETTER("sample.field.family_contact_number");
	//}
};

#include OATPP_CODEGEN_END(DTO)
#endif 