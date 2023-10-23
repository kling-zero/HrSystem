#pragma once
/*
��Ա������-��������Ա-��ҳ��ѯԱ���б�--pine
*/
#ifndef _CHECK_RETIRES_DTO_
#define _CHECK_RETIRES_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class CheckRetiresListDTO : public oatpp::DTO
{
public:
	//�޲ι���
	CheckRetiresListDTO() {};
	//�вι���
	//CheckRetiresListDTO(UInt64 id, String name, Int32 age, String sex) {};
	//CheckRetiresListDTO(UInt64 id, String name) :id(id), name(name) {};
	DTO_INIT(CheckRetiresListDTO, DTO);
	// Ա�����
	DTO_FIELD(String, ygbh);
	DTO_FIELD_INFO(ygbh) {
		info->description = ZH_WORDS_GETTER("rosterofper.field.ygbh");
	}
	// Ψһ��ʶ
	DTO_FIELD(String, pimpersonid);
	DTO_FIELD_INFO(pimpersonid) {
		info->description = ZH_WORDS_GETTER("rosterofper.field.id");
	}
	// Ա�����+������ģ����ѯ��
	DTO_FIELD(String, idAndName);
	DTO_FIELD_INFO(idAndName) {
		info->description = ZH_WORDS_GETTER("rosterofper.field.idAndName");
	}
	// Ա������
	DTO_FIELD(String, pimpersonname);
	DTO_FIELD_INFO(pimpersonname) {
		info->description = ZH_WORDS_GETTER("rosterofper.field.pimpersonname");
	}
	// �Ա�
	DTO_FIELD(String, xb);
	DTO_FIELD_INFO(xb) {
		info->description = ZH_WORDS_GETTER("rosterofper.field.xb");
	}
	// ����
	DTO_FIELD(String, nj);
	DTO_FIELD_INFO(nj) {
		info->description = ZH_WORDS_GETTER("rosterofper.field.nj");
	}
	// ͨѶ��ַ
	DTO_FIELD(String, postaladdress);
	DTO_FIELD_INFO(postaladdress) {
		info->description = ZH_WORDS_GETTER("rosterofper.field.postaladdress");
	}
	// ���ݵ�
	DTO_FIELD(String, retiPlace);
	DTO_FIELD_INFO(retiPlace) {
		info->description = ZH_WORDS_GETTER("rosterofper.field.retiPlace");
	}
	// ��ͥ��ϵ��
	DTO_FIELD(String, jtlxr);
	DTO_FIELD_INFO(jtlxr) {
		info->description = ZH_WORDS_GETTER("rosterofper.field.jtlxr");
	}
	// ��ͥ��ϵ�˵绰
	DTO_FIELD(String, jtlxrdh);
	DTO_FIELD_INFO(jtlxrdh) {
		info->description = ZH_WORDS_GETTER("rosterofper.field.jtlxrdh");
	}
	// ��֯
	DTO_FIELD(String, zz);
	DTO_FIELD_INFO(zz) {
		info->description = ZH_WORDS_GETTER("rosterofper.field.zz");
	}
	// ����
	DTO_FIELD(String, bm);
	DTO_FIELD_INFO(bm) {
		info->description = ZH_WORDS_GETTER("rosterofper.field.bm");
	}
	// ְ��
	DTO_FIELD(String, rank);
	DTO_FIELD_INFO(rank) {
		info->description = ZH_WORDS_GETTER("rosterofper.field.rank");
	}
	// ����ǰְ��
	DTO_FIELD(String, yzw);
	DTO_FIELD_INFO(yzw) {
		info->description = ZH_WORDS_GETTER("rosterofper.field.yzw");
	}
	// ����ǰ��λ
	DTO_FIELD(String, ygw);
	DTO_FIELD_INFO(ygw) {
		info->description = ZH_WORDS_GETTER("rosterofper.field.ygw");
	}
	// ����ʱ��
	DTO_FIELD(String, txdq);
	DTO_FIELD_INFO(txdq) {
		info->description = ZH_WORDS_GETTER("rosterofper.field.txdq");
	}
	// ʵ������ʱ��
	DTO_FIELD(String, sjtxrq);
	DTO_FIELD_INFO(sjtxrq) {
		info->description = ZH_WORDS_GETTER("rosterofper.field.sjtxrq");
	}
	// �ֻ�����
	DTO_FIELD(String, lxdh);
	DTO_FIELD_INFO(lxdh) {
		info->description = ZH_WORDS_GETTER("rosterofper.field.lxdh");
	}
	// ���������Ͻ��
	DTO_FIELD(String, spdylje);
	DTO_FIELD_INFO(spdylje) {
		info->description = ZH_WORDS_GETTER("rosterofper.field.spdylje");
	}
};

class CheckRetiresListPageDTO : public PageDTO<CheckRetiresListDTO::Wrapper>
{
	DTO_INIT(CheckRetiresListPageDTO, PageDTO<CheckRetiresListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // 