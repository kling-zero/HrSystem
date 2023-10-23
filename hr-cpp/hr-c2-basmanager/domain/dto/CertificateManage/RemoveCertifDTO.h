#pragma once
/*
��֤�����-֤����Ϣ-ɾ��֤�飨֧������ɾ������--����
*/
#ifndef _REMOVECERTIF_DTO_
#define _REMOVECERTIF_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)


class RemoveCertifDTO : public oatpp::DTO
{
	DTO_INIT(RemoveCertifDTO, DTO);
	DTO_FIELD(List<String>, idByBatch) = {};
	DTO_FIELD_INFO(idByBatch) {
		info->description= ZH_WORDS_GETTER("certif.field.idByBatch");
	}
	/*
	// ���
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("certif.field.id");
	}
	*/
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_REMOVECERTIF_DTO_