/**
 *  ֤����� ���� ֤����Ϣ ���� ��ѯ������ָ��֤�� ���� ������
 */
#ifndef _SPERTIFIC_CERTIFICATE_DTO_
#define _SPERTIFIC_CERTIFICATE_DTO_
#include "../../GlobalInclude.h"
#include OATPP_CODEGEN_BEGIN(DTO)

class SpercificCertificateDTO : public oatpp::DTO
{

	DTO_INIT(SpercificCertificateDTO, DTO);
	
	// ִ��ְ��ҵ�ʸ���Ϣ��ʶ
	DTO_FIELD(String, PIMVOCATIONALID);
	DTO_FIELD_INFO(PIMVOCATIONALID) {
		info->description = ZH_WORDS_GETTER("spercificcertificate.field.PIMVOCATIONALID");
	}
	// ����  required
	DTO_FIELD(String, pimperSonName);
	DTO_FIELD_INFO(pimperSonName) {
		info->description = ZH_WORDS_GETTER("spercificcertificate.field.pimperSonName");
	}
	// ֤����  required
	DTO_FIELD(String, zgzsbh);
	DTO_FIELD_INFO(zgzsbh) {
		info->description = ZH_WORDS_GETTER("spercificcertificate.field.zgzsbh");
	}
	// ֤������  required
	DTO_FIELD(String, zslx);
	DTO_FIELD_INFO(zslx) {
		info->description = ZH_WORDS_GETTER("spercificcertificate.field.zslx");
	}
	// ֤������
	DTO_FIELD(String, pimVocationalName);
	DTO_FIELD_INFO(pimVocationalName) {
		info->description = ZH_WORDS_GETTER("spercificcertificate.field.pimVocationalName");
	}
	// ǩ������
	DTO_FIELD(String, zgsydw);
	DTO_FIELD_INFO(zgsydw) {
		info->description = ZH_WORDS_GETTER("spercificcertificate.field.zgsydw");
	}
	// ע����
	DTO_FIELD(String, REGISNUMBER);
	DTO_FIELD_INFO(REGISNUMBER) {
		info->description = ZH_WORDS_GETTER("spercificcertificate.field.REGISNUMBER");
	}
	// ע�ᵥλ
	DTO_FIELD(String, zcdw);
	DTO_FIELD_INFO(zcdw) {
		info->description = ZH_WORDS_GETTER("spercificcertificate.field.zcdw");
	}
	// �籣���ɵ�λ
	DTO_FIELD(String, SOCSECPAYUNIT);
	DTO_FIELD_INFO(SOCSECPAYUNIT) {
		info->description = ZH_WORDS_GETTER("spercificcertificate.field.SOCSECPAYUNIT");
	}
	// һ������B֤���
	DTO_FIELD(String, bcardNumber);
	DTO_FIELD_INFO(bcardNumber) {
		info->description = ZH_WORDS_GETTER("spercificcertificate.field.bcardNumber");
	}
	
	// ֤�������

	// ǩ������  required
	DTO_FIELD(String, zghqrq);
	DTO_FIELD_INFO(zghqrq) {
		info->description = ZH_WORDS_GETTER("spercificcertificate.field.zghqrq");
	}
	// ��ʼע��ʱ��
	DTO_FIELD(String, CSZCSJ);
	DTO_FIELD_INFO(CSZCSJ) {
		info->description = ZH_WORDS_GETTER("spercificcertificate.field.CSZCSJ");
	}
	// ��ע��ʱ��
	DTO_FIELD(String, XZCSJ);
	DTO_FIELD_INFO(XZCSJ) {
		info->description = ZH_WORDS_GETTER("spercificcertificate.field.XZCSJ");
	}
	// ʧЧ����
	DTO_FIELD(String, sxrq);
	DTO_FIELD_INFO(sxrq) {
		info->description = ZH_WORDS_GETTER("spercificcertificate.field.sxrq");
	}
	// �������
	DTO_FIELD(String, NSQK);
	DTO_FIELD_INFO(NSQK) {
		info->description = ZH_WORDS_GETTER("spercificcertificate.field.NSQK");
	}
	// ʹ�����
	DTO_FIELD(String, SYQK);
	DTO_FIELD_INFO(SYQK) {
		info->description = ZH_WORDS_GETTER("spercificcertificate.field.SYQK");
	}
	// ������
	DTO_FIELD(String, ALTERATION);
	DTO_FIELD_INFO(ALTERATION) {
		info->description = ZH_WORDS_GETTER("spercificcertificate.field.ALTERATION");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif 
