#pragma once
#ifndef _ARCHIVE_SERVICE_
#define _ARCHIVE_SERVICE_
#include <list>
#include "domain/vo/archive/ArchiveVO.h"
#include "domain/query/archive/ArchiveQuery.h"
#include "domain/dto/archive/ArchiveDTO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class ArchiveService
{
public:
	// ��ҳ��ѯ��������
	ArchivePageDTO::Wrapper listAll(const ArchiveQuery::Wrapper& query);
	// ��������
	uint64_t saveData(const ArchiveDTO::Wrapper& dto);
	// �޸�����
	bool updateData(const ArchiveDTO::Wrapper& dto);
	// ͨ��IDɾ������
	bool removeData(uint64_t id);
};

#endif // !_ARCHIVE_SERVICE_

