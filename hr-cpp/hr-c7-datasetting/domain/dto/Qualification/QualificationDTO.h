#pragma once
#ifndef _QUALIFICATIONDTO_H_
#define _QUALIFICATIONDTO_H_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/*
  ����һ�����޸�ִҵ�ʸ�֤����Ϣ�Ĵ������
*/

class QualificationDTO : public oatpp::DTO
{
	DTO_INIT(QualificationDTO, DTO);
	// ִҵ�ʸ�רҵ����
	DTO_FIELD(String, pimqualmajorid);
	DTO_FIELD_INFO(pimqualmajorid) {
		info->description = ZH_WORDS_GETTER("archive.field.pimqualmajorid");
	}
	// ����
	DTO_FIELD(String, qualevel);
	DTO_FIELD_INFO(qualevel) {
		info->description = ZH_WORDS_GETTER("archive.field.qualevel");
	}
	// ִҵ�ʸ�
	DTO_FIELD(String, pimqualmajorname);
	DTO_FIELD_INFO(pimqualmajorname) {
		info->description = ZH_WORDS_GETTER("archive.field.pimqualmajorname");
	}
	//רҵ
	DTO_FIELD(String, quamajor);
	DTO_FIELD_INFO(quamajor) {
		info->description = ZH_WORDS_GETTER("archive.field.quamajor");
	}
};
/**
 * ����һ��ִҵ�ʸ�֤����Ϣ��ҳ�������
 */
class QualificationPageDTO : public PageDTO<QualificationDTO::Wrapper>
{
	DTO_INIT(QualificationPageDTO, PageDTO<QualificationDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif //!_QUALIFICATIONDTO_H_