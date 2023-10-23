#pragma once
#ifndef _ARCHIVESDTO_H_
#define _ARCHIVESDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
//������ѯ������������
class ArchivesDTO :public oatpp::DTO {
public:
	ArchivesDTO() {}
	ArchivesDTO(String id, String name) :id(id), name(name) {};
	DTO_INIT(ArchivesDTO, DTO);

	// Ա�����
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("sample.field.id");
	}
	// Ա������
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("sample.field.name");
	}
	//�������
	DTO_FIELD(String, dabh);
	DTO_FIELD_INFO(dabh) {
		info->description = ZH_WORDS_GETTER("archives.dabh");
	}

	//����λ
	DTO_FIELD(String, ormorgid3);
	DTO_FIELD_INFO(ormorgid3) {
		info->description = ZH_WORDS_GETTER("archives.ormorgid3");
	}

	//�������ܵ�
	DTO_FIELD(String, dabgd);
	DTO_FIELD_INFO(dabgd) {
		info->description = ZH_WORDS_GETTER("archives.dabgd");
	}

	//������
	DTO_FIELD(String, archivescentername);
	DTO_FIELD_INFO(archivescentername) {
		info->description = ZH_WORDS_GETTER("archives.archivescenterid");
	}

	//����ѧ��
	DTO_FIELD(String, education);
	DTO_FIELD_INFO(education) {
		info->description = ZH_WORDS_GETTER("archives.education");
	}
	//������������
	DTO_FIELD(String, dateofbirth);
	DTO_FIELD_INFO(dateofbirth) {
		info->description = ZH_WORDS_GETTER("archives.dateofbirth");
	}

	//�����뵳ʱ��
	DTO_FIELD(String, joinpartydate);
	DTO_FIELD_INFO(joinpartydate) {
		info->description = ZH_WORDS_GETTER("archives.joinpartydate");
	}
	//�����μӹ���ʱ��
	DTO_FIELD(String, startworkdatae);
	DTO_FIELD_INFO(startworkdatae) {
		info->description = ZH_WORDS_GETTER("archives.startworkdatae");
	}

	//����״̬
	DTO_FIELD(String, dazt);
	DTO_FIELD_INFO(dazt) {
		info->description = ZH_WORDS_GETTER("archives.dazt");
	}
};

class ArchivesPageDTO : public PageDTO<ArchivesDTO::Wrapper>
{
	DTO_INIT(ArchivesPageDTO, PageDTO<ArchivesDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_ARCHIVESDTO_H_

