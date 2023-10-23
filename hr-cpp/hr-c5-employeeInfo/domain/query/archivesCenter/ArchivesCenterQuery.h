#pragma once
#ifndef _ARCHIVES_CENTER_H_
#define _ARCHIVES_CENTER_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��ҳ��ѯ������
 */
class ArchivesCenterQuery : public PageQuery
{
	DTO_INIT(ArchivesCenterQuery, PageQuery);
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

#include OATPP_CODEGEN_END(DTO)

#endif // !_ARCHIVES_CENTER_H_
