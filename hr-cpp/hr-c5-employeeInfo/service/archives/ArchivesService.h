#pragma once

#ifndef _ARCHIVES_SERVICE_
#define _ARCHIVES_SERVICE_
#include <list>
#include "domain/vo/archives/ArchivesVO.h"
#include "domain/query/archives/ArchivesQuery.h"
#include "domain/dto/archives/ArchivesDTO.h"
#include "domain/dto/archives/ArchivesDelDTO.h"
#include "domain/vo/archives/ArchivesDelVO.h"

/**
 * ����ʵ��
 */
class ArchivesService
{
public:
	// ��ѯ��ϸ��Ϣ
	ArchivesPageDTO::Wrapper getAll(const ArchivesQuery::Wrapper& query);
	// ��ҳ��ѯ��������
	ArchivesPageDTO::Wrapper listAll(const ArchivesQuery::Wrapper& query);
	// ��������
	uint64_t saveData(const ArchivesDTO::Wrapper& dto);
	// ͨ��IDɾ������
	bool removeData(const ArchivesDelDTO::Wrapper& dto);
};

#endif // !_ARCHIVES_SERVICE_

