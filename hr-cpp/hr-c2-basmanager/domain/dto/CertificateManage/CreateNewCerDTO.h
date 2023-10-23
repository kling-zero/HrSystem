#pragma once
#ifndef _CREATE_NEW_CER_DTO_
#define _CREATE_NEW_CER_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ���������
 */
class CreateNewCerDTO : public oatpp::DTO
{
public:
	//�޲ι���
	CreateNewCerDTO() {};
	//�вι���
	//CreateNewCerDTO(UInt64 id, String name, Int32 age, String sex) {};
	//CreateNewCerDTO(UInt64 id, String name) :id(id), name(name) {};
	DTO_INIT(CreateNewCerDTO, DTO);
	// Ա�����
	DTO_FIELD(String, ygbh);
	DTO_FIELD_INFO(ygbh) {
		info->description = ZH_WORDS_GETTER("cermanage.field.ygbh");
	}
	// ֤����
	DTO_FIELD(String, zgzsbh);
	DTO_FIELD_INFO(zgzsbh) {
		info->description = ZH_WORDS_GETTER("cermanage.field.zgzsbh");
	}
	// һ������B֤���
	DTO_FIELD(String, bcardNumber);
	DTO_FIELD_INFO(bcardNumber) {
		info->description = ZH_WORDS_GETTER("cermanage.field.bcardNumber");
	}
	// ֤������(ִҵ�ʸ�֤��)
	DTO_FIELD(String, pimVocationalName);
	DTO_FIELD_INFO(pimVocationalName) {
		info->description = ZH_WORDS_GETTER("cermanage.field.pimVocationalName");
	}
	// ֤������
	DTO_FIELD(String, zslx);
	DTO_FIELD_INFO(zslx) {
		info->description = ZH_WORDS_GETTER("cermanage.field.zslx");
	}
	// ǩ������
	DTO_FIELD(String, zghqrq);
	DTO_FIELD_INFO(zghqrq) {
		info->description = ZH_WORDS_GETTER("cermanage.field.zghqrq");
	}
	// ǩ������
	DTO_FIELD(String, zgsydw);
	DTO_FIELD_INFO(zgsydw) {
		info->description = ZH_WORDS_GETTER("cermanage.field.zgsydw");
	}
	// ע�ᵥλ
	DTO_FIELD(String, zcdw);
	DTO_FIELD_INFO(zcdw) {
		info->description = ZH_WORDS_GETTER("cermanage.field.zcdw");
	}
	// ʧЧ����
	DTO_FIELD(String, sxrq);
	DTO_FIELD_INFO(sxrq) {
		info->description = ZH_WORDS_GETTER("cermanage.field.sxrq");
	}
	// �������
	DTO_FIELD(String, nsqk);
	DTO_FIELD_INFO(nsqk) {
		info->description = ZH_WORDS_GETTER("cermanage.field.nsqk");
	}
	// ʹ�����
	DTO_FIELD(String, syqk);
	DTO_FIELD_INFO(syqk) {
		info->description = ZH_WORDS_GETTER("cermanage.field.syqk");
	}
	// ������
	DTO_FIELD(String, alteration);
	DTO_FIELD_INFO(alteration) {
		info->description = ZH_WORDS_GETTER("cermanage.field.alteration");
	}
	// Ա��Ψһ��ʶ
	DTO_FIELD(String, pimpersonid);
	DTO_FIELD_INFO(pimpersonid) {
		info->description = ZH_WORDS_GETTER("cermanage.field.pimpersonid");
	}
	// ע����
	DTO_FIELD(String, regisnumber);
	DTO_FIELD_INFO(regisnumber) {
		info->description = ZH_WORDS_GETTER("cermanage.field.regisnumber");
	}
	// �籣���ɵ�λ
	DTO_FIELD(String, socsecpayunit);
	DTO_FIELD_INFO(socsecpayunit) {
		info->description = ZH_WORDS_GETTER("cermanage.field.socsecpayunit");
	}
	// ��ʼע��ʱ��
	DTO_FIELD(String, cszcsj);
	DTO_FIELD_INFO(cszcsj) {
		info->description = ZH_WORDS_GETTER("cermanage.field.cszcsj");
	}
	// ��ע��ʱ��
	DTO_FIELD(String, xzcsj);
	DTO_FIELD_INFO(xzcsj) {
		info->description = ZH_WORDS_GETTER("cermanage.field.xzcsj");
	}
};

/**
 * ʾ����ҳ�������
 */
class CreateNewCerPageDTO : public PageDTO<CreateNewCerDTO::Wrapper>
{
	DTO_INIT(CreateNewCerPageDTO, PageDTO<CreateNewCerDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // 
/*
ǰ�����봫�����
*/