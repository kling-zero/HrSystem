#pragma once
#ifndef _ARCHIVEDTO_H_
#define _ARCHIVEDTO_H_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * ����һ�����޸ĵ�������Ϣ�Ĵ������
 */
class ArchiveDTO : public oatpp::DTO
{
	DTO_INIT(ArchiveDTO, DTO);
	// �����
	DTO_FIELD(UInt64, sortid);
	DTO_FIELD_INFO(sortid) {
		info->description = ZH_WORDS_GETTER("archive.field.sortid");
	}
	// ����������
	DTO_FIELD(String,archivename);
	DTO_FIELD_INFO(archivename) {
		info->description = ZH_WORDS_GETTER("archive.field.archivename");
	}
	// ���
	DTO_FIELD(Int32, cabinetnum);
	DTO_FIELD_INFO(cabinetnum) {
		info->description = ZH_WORDS_GETTER("archive.field.cabinetnum");
	}
	//���
	DTO_FIELD(Int32, layernum);
	DTO_FIELD_INFO(layernum) {
		info->description = ZH_WORDS_GETTER("archive.field.layernum");
	}
	//���
	DTO_FIELD(Int32, numid);
	DTO_FIELD_INFO(numid) {
		info->description = ZH_WORDS_GETTER("archive.field.numid");
	}
};

/**
 * ����һ����������Ϣ��ҳ�������
 */
class ArchivePageDTO : public PageDTO<ArchiveDTO::Wrapper>
{
	DTO_INIT(ArchivePageDTO, PageDTO<ArchiveDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // _USERDTO_H_