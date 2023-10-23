#pragma once
#pragma once
#ifndef _UPDATE_ARCHIVE_INFO_DTO_
#define _UPDATE_ARCHIVE_INFO_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

//�������������
class UpdateArchiveInfoDTO : public oatpp::DTO {
	DTO_INIT(UpdateArchiveInfoDTO, DTO);
	//�������
	DTO_FIELD(String, dabh);
	DTO_FIELD_INFO(dabh) {
		info->description = ZH_WORDS_GETTER("archive.dto.dabh");
	}
	//����λ
	DTO_FIELD(String, gldw);
	DTO_FIELD_INFO(gldw) {
		info->description = ZH_WORDS_GETTER("archive.dto.gldw");
	}
	//�Ƿ��½���
	DTO_FIELD(String, sfxjd);
	DTO_FIELD_INFO(sfxjd) {
		info->description = ZH_WORDS_GETTER("archive.dto.sfxjd");
	}
	//�������ܵ�
	DTO_FIELD(String, bgd);
	DTO_FIELD_INFO(bgd) {
		info->description = ZH_WORDS_GETTER("archive.dto.dabgd");
	}
	//������
	DTO_FIELD(String, archivescentername);
	DTO_FIELD_INFO(archivescentername) {
		info->description = ZH_WORDS_GETTER("archive.dto.archivescentername");
	}
	//Ա�����
	DTO_FIELD(String, ygbh);
	DTO_FIELD_INFO(ygbh) {
		info->description = ZH_WORDS_GETTER("archive.dto.ygbh");
	}
	//Ա������
	DTO_FIELD(String, pimpersonname);
	DTO_FIELD_INFO(pimpersonname) {
		info->description = ZH_WORDS_GETTER("archive.dto.pimpersonname");
	}
	//������λ
	DTO_FIELD(String, ormorgname);
	DTO_FIELD_INFO(ormorgname) {
		info->description = ZH_WORDS_GETTER("archive.dto.ormorgname");
	}
	//����ѧ��
	DTO_FIELD(String, education);
	DTO_FIELD_INFO(education) {
		info->description = ZH_WORDS_GETTER("archive.dto.education");
	}
	//������������
	DTO_FIELD(String, dateofbirth);
	DTO_FIELD_INFO(dateofbirth) {
		info->description = ZH_WORDS_GETTER("archive.dto.dateofbirth");
	}
	// �����뵳ʱ��
	DTO_FIELD(String, joinpartydate);
	DTO_FIELD_INFO(joinpartydate) {
		info->description = ZH_WORDS_GETTER("archive.dto.joinpartydate");
	}
	// �����μӹ���ʱ��
	DTO_FIELD(String, startworkdate);
	DTO_FIELD_INFO(startworkdate) {
		info->description = ZH_WORDS_GETTER("archive.dto.startworkdate");
	}
	// ����״̬
	DTO_FIELD(String, dastate);
	DTO_FIELD_INFO(dastate) {
		info->description = ZH_WORDS_GETTER("archive.dto.dastate");
	}
	//��ע
	DTO_FIELD(String, bz);
	DTO_FIELD_INFO(bz) {
		info->description = ZH_WORDS_GETTER("archive.dto.bz");
	}
	//����
	DTO_FIELD(String, fj);
	DTO_FIELD_INFO(fj) {
		info->description = ZH_WORDS_GETTER("archive.dto.fj");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_UPDATE_ARCHIVE_INFO_DTO_