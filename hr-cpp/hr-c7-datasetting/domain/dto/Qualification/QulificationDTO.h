#pragma once
#ifndef _QULIFICATIONDTO_H_
#define _QULIFICATIONDTO_H_

#include "../../GlobalInclude.h"
#include "ApiHelper.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/*
  ֤���ѯ������������
*/

class QualificationDTO : public oatpp::DTO
{
public:
	QualificationDTO(){};
	DTO_INIT(QualificationDTO, DTO);
	//ִҵ�ʸ�����
	API_DTO_FIELD_DEFAULT(String, qulificationName, ZH_WORDS_GETTER("qulification.field.qulificationName"));
	//����
	API_DTO_FIELD_DEFAULT(String, rank, ZH_WORDS_GETTER("qulification.field.rank"));
	//ִҵ�ʸ�
	API_DTO_FIELD_DEFAULT(String, practicingQulification, ZH_WORDS_GETTER("qulification.field.practicingQulification"));
	
	
};
/*
  ֤���ѯ��ҳ������������
*/
class QualificationPageDTO : public PageDTO<QualificationDTO::Wrapper>
{
	DTO_INIT(QualificationPageDTO, PageDTO<QualificationDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif //!_QULIFICATIONDTO_H_