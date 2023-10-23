#pragma once
#ifndef _ARCHIVES_CENTER_DTO_H_
#define _ARCHIVES_CENTER_DTO_H_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class ArchivesCenterDTO : public oatpp::DTO
{
	DTO_INIT(ArchivesCenterDTO, DTO);
	// �����
	DTO_FIELD(UInt64, SertalNo);
	DTO_FIELD_INFO(SertalNo) {
		info->description = ZH_WORDS_GETTER("archivesCenter.field.SertalNo");
	}
	// ����������
	DTO_FIELD(String, ArchivesCenterName);
	DTO_FIELD_INFO(ArchivesCenterName) {
		info->description = ZH_WORDS_GETTER("archivesCenter.field.ArchivesCenterName");
	}
	// ���
	DTO_FIELD(String, CabinetNo);
	DTO_FIELD_INFO(CabinetNo) {
		info->description = ZH_WORDS_GETTER("archivesCenter.field.CabinetNo");
	}
	// ���
	DTO_FIELD(String, BNumber);
	DTO_FIELD_INFO(BNumber) {
		info->description = ZH_WORDS_GETTER("archivesCenter.field.BNumber");
	}
};

class ArchivesCenterPageDTO : public PageDTO<ArchivesCenterDTO::Wrapper>
{
	DTO_INIT(ArchivesCenterPageDTO, PageDTO<ArchivesCenterDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_ARCHIVES_CENTER_DTO_H_
