#pragma once
#ifndef _ADDSCIRESULTDTO_H_
#define _ADDSCIRESULTDTO_H_
#define DTO_INIT_(type, field, name) DTO_FIELD(type, field); \
DTO_FIELD_INFO(field) { \
	info->description = ZH_WORDS_GETTER(name); \
}

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class AddSciResultDTO : public oatpp::DTO
{
	DTO_INIT(AddSciResultDTO, DTO);

	//������
	DTO_INIT_(String, UPDATEMAN, "sciresult.UPDATEMAN")

		//���гɹ�����
		DTO_INIT_(String, PIMRESEARCHFINDINGSNAME, "sciresult.PIMRESEARCHFINDINGSNAME")
		//����
		DTO_INIT_(String, FJ, "sciresult.FJ")

		//ENABLE
		DTO_INIT_(String, ENABLE, "sciresult.ENABLE")

		//����ʱ��
		DTO_INIT_(String, CREATEDATE, "sciresult.CREATEDATE")

		//����ʱ��
		DTO_INIT_(String, UPDATEDATE, "sciresult.UPDATEDATE")

		//������
		DTO_INIT_(String, CREATEMAN, "sciresult.CREATEMAN")

		//���гɹ���ʶ
		DTO_INIT_(String, PIMRESEARCHFINDINGSID, "sciresult.PIMRESEARCHFINDINGSID")
		//��Ա��Ϣ��ʶ
		DTO_INIT_(String, PIMPERSONID, "sciresult.PIMPERSONID")
		//��ȡʱ��
		DTO_INIT_(String, HQSJ, "sciresult.HQSJ")
		//��¼����
		DTO_INIT_(String, JLSS, "sciresult.JLSS")
		//����״̬
		DTO_INIT_(String, JLSPZT, "sciresult.JLSPZT")
		//��¼������
		DTO_INIT_(String, JLGLBH, "sciresult.JLGLBH")
		//��¼������
		DTO_INIT_(String, JLCZZ, "sciresult.JLCZZ")
		//�ܾ�ԭ��
		DTO_INIT_(String, REASON, "sciresult.REASON")

};

#include OATPP_CODEGEN_END(DTO)

#endif // !_ADDWORKHISTORYDTO_H_