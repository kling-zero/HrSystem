#ifndef _ARCHIVEQUERY_
#define _ARCHIVEQUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ�������Ҳ�ѯ����
 */
class ArchiveQuery : public PageQuery
{
	DTO_INIT(ArchiveQuery, PageQuery);
	// �����
	DTO_FIELD(Int64, sortid);
	DTO_FIELD_INFO(sortid) {
		info->description = ZH_WORDS_GETTER("archive.field.sortid");
	}
	// ����������
	DTO_FIELD(String, archivename);
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

#include OATPP_CODEGEN_END(DTO)
#endif //

