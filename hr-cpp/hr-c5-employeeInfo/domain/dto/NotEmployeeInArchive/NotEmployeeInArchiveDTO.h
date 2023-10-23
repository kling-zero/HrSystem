#pragma once
#ifndef _NOT_EMPLOYEE_IN_ARCHIVE_DTO_
#define _NOT_EMPLOYEE_IN_ARCHIVE_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

//�������������
class NotEmployeeInArchiveDTO : public oatpp::DTO {
	DTO_INIT(NotEmployeeInArchiveDTO, DTO);
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
	//����״̬
	DTO_FIELD(String, dazt);
	DTO_FIELD_INFO(dazt) {
		info->description = ZH_WORDS_GETTER("archive.dto.dazt");
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
	//Ա��״̬
	DTO_FIELD(String, ygzt);
	DTO_FIELD_INFO(ygzt) {
		info->description = ZH_WORDS_GETTER("archive.dto.ygzt");
	}
	//������
	DTO_FIELD(String, operat);
	DTO_FIELD_INFO(operat) {
		info->description = ZH_WORDS_GETTER("archive.dto.operat");
	}
	//��ע
	DTO_FIELD(String, bz);
	DTO_FIELD_INFO(bz) {
		info->description = ZH_WORDS_GETTER("archive.dto.bz");
	}
	//����ʱ��
	DTO_FIELD(String, createdate);
	DTO_FIELD_INFO(createdate) {
		info->description = ZH_WORDS_GETTER("archive.dto.createdate");
	}
	//������
	DTO_FIELD(String, createman);
	DTO_FIELD_INFO(createman) {
		info->description = ZH_WORDS_GETTER("archive.dto.createman");
	}
	//������������
	DTO_FIELD(String, daddrq);
	DTO_FIELD_INFO(daddrq) {
		info->description = ZH_WORDS_GETTER("archive.dto.daddrq");
	}
	//������λ
	DTO_FIELD(String, dcdw);
	DTO_FIELD_INFO(dcdw) {
		info->description = ZH_WORDS_GETTER("archive.dto.dcdw");
	}
	//���뵥λ
	DTO_FIELD(String, drdw);
	DTO_FIELD_INFO(drdw) {
		info->description = ZH_WORDS_GETTER("archive.dto.drdw");
	}
	//������¼����
	DTO_FIELD(String, ddjltype);
	DTO_FIELD_INFO(ddjltype) {
		info->description = ZH_WORDS_GETTER("archive.dto.ddjltype");
	}
	//�����鵵�ر����¼��ʶ
	DTO_FIELD(String, pimarchiveschangeid);
	DTO_FIELD_INFO(pimarchiveschangeid) {
		info->description = ZH_WORDS_GETTER("archive.dto.pimarchiveschangeid");
	}
	//������Ϣ��ʶ
	DTO_FIELD(String, pimarchivesid);
	DTO_FIELD_INFO(pimarchivesid) {
		info->description = ZH_WORDS_GETTER("archive.dto.pimarchivesid");
	}
	//����ʱ��
	DTO_FIELD(String, updatedate);
	DTO_FIELD_INFO(updatedate) {
		info->description = ZH_WORDS_GETTER("archive.dto.updatedate");
	}
	//������
	DTO_FIELD(String, updateman);
	DTO_FIELD_INFO(updateman) {
		info->description = ZH_WORDS_GETTER("archive.dto.updateman");
	}
};
//���������ҳ�������
class NotEmployeeInArchivePageDTO : public PageDTO<NotEmployeeInArchiveDTO::Wrapper>
{
	DTO_INIT(NotEmployeeInArchivePageDTO, PageDTO<NotEmployeeInArchiveDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_NOT_EMPLOYEE_IN_ARCHIVE_DTO_