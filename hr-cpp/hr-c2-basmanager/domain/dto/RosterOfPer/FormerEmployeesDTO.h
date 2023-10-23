/**
 * ��Ա������ - ��ְ��ԱDTOʵ�� - ������
 */
#ifndef _FORMER_EMPLOYEES_DTO_
#define _FORMER_EMPLOYEES_DTO_
#include "../../GlobalInclude.h"
#include OATPP_CODEGEN_BEGIN(DTO)

class FormerEmployeesDTO : public oatpp::DTO
{

    DTO_INIT(FormerEmployeesDTO, DTO);
    
	// Ψһ��ʶ
	DTO_FIELD(String, PIMPERSONID);
	DTO_FIELD_INFO(PIMPERSONID) {
		info->description = ZH_WORDS_GETTER("formeremployees.field.PIMPERSONID");
	}
	// ���
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("formeremployees.field.id");
	}
	// ����
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("formeremployees.field.name");
	}
	// �ֻ�����
	DTO_FIELD(String, phoneNumber);
	DTO_FIELD_INFO(phoneNumber) {
		info->description = ZH_WORDS_GETTER("formeremployees.field.phonenumber");
	}
	// ��������
	DTO_FIELD(String, chushengriqi);
	DTO_FIELD_INFO(chushengriqi) {
		info->description = ZH_WORDS_GETTER("formeremployees.field.dateofbirth");
	}
	// �Ա�
	DTO_FIELD(String, sex);
	DTO_FIELD_INFO(sex) {
		info->description = ZH_WORDS_GETTER("formeremployees.field.sex");
	}
	// ��֯
	DTO_FIELD(String, organization);
	DTO_FIELD_INFO(organization) {
		info->description = ZH_WORDS_GETTER("formeremployees.field.organization");
	}
	// ����
	DTO_FIELD(String, department);
	DTO_FIELD_INFO(department) {
		info->description = ZH_WORDS_GETTER("formeremployees.field.department");
	}
	// ְ��
	DTO_FIELD(String, rank);
	DTO_FIELD_INFO(rank) {
		info->description = ZH_WORDS_GETTER("formeremployees.field.rank");
	}
	// ͨѶ��ַ
	DTO_FIELD(String, mail_address);
	DTO_FIELD_INFO(mail_address) {
		info->description = ZH_WORDS_GETTER("formeremployees.field.mail_address");
	}
	// ��ͥ��ϵ��
	DTO_FIELD(String, family_contact);
	DTO_FIELD_INFO(family_contact) {
		info->description = ZH_WORDS_GETTER("formeremployees.field.family_contact");
	}
	// ��ͥ��ϵ�˵绰
	DTO_FIELD(String, family_contact_number);
	DTO_FIELD_INFO(family_contact_number) {
		info->description = ZH_WORDS_GETTER("formeremployees.field.family_contact_number");
	}
};

/**
 * ��ְԱ����ҳ�������
 */
class FormerEmployeesPageDTO : public PageDTO<FormerEmployeesDTO::Wrapper>
{
	DTO_INIT(FormerEmployeesPageDTO, PageDTO<FormerEmployeesDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_$FILE_BASE_UPPER$_H
