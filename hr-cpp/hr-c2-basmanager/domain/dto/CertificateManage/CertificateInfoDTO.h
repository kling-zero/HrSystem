#ifndef _CERTIFICATE_INFO_DTO_
#define _CERTIFICATE_INFO_DTO_
#include "../../GlobalInclude.h"
#include OATPP_CODEGEN_BEGIN(DTO)

class CertificateInfoDTO : public oatpp::DTO
{
public:
	CertificateInfoDTO() {};
	CertificateInfoDTO(UInt64 id, String name) : id(id), name(name) {};

	DTO_INIT(CertificateInfoDTO, DTO);

	// ���
	DTO_FIELD(UInt64, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("sample.field.id");
	}
	// ����
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("sample.field.name");
	}
	// ����
	DTO_FIELD(Int32, age);
	DTO_FIELD_INFO(age) {
		info->description = ZH_WORDS_GETTER("sample.field.age");
	}
	// �Ա�
	DTO_FIELD(String, sex);
	DTO_FIELD_INFO(sex) {
		info->description = ZH_WORDS_GETTER("sample.field.sex");
	}
	// ��֯
	DTO_FIELD(String, organization);
	DTO_FIELD_INFO(organization) {
		info->description = ZH_WORDS_GETTER("sample.field.organization");
	}
	// ����
	DTO_FIELD(String, department);
	DTO_FIELD_INFO(department) {
		info->description = ZH_WORDS_GETTER("sample.field.department");
	}
	// ְ��
	DTO_FIELD(String, rank);
	DTO_FIELD_INFO(rank) {
		info->description = ZH_WORDS_GETTER("sample.field.rank");
	}
	// ͨѶ��ַ
	DTO_FIELD(String, mail_address);
	DTO_FIELD_INFO(mail_address) {
		info->description = ZH_WORDS_GETTER("sample.field.mail_address");
	}
	// ��ͥ��ϵ��
	DTO_FIELD(String, family_contact);
	DTO_FIELD_INFO(family_contact) {
		info->description = ZH_WORDS_GETTER("sample.field.family_contact");
	}
	// ��ͥ��ϵ�˵绰
	DTO_FIELD(String, family_contact_number);
	DTO_FIELD_INFO(family_contact_number) {
		info->description = ZH_WORDS_GETTER("sample.field.family_contact_number");
	}
};

/**
 * ֤����Ϣ��ҳ�������
 */
class CertificateInfoPageDTO : public PageDTO<CertificateInfoDTO::Wrapper>
{
	DTO_INIT(CertificateInfoPageDTO, PageDTO<CertificateInfoDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_$FILE_BASE_UPPER$_H
