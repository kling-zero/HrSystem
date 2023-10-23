#pragma once
#ifndef _ARCHIVESDAO_H_
#define _ARCHIVESDAO_H_
#include "BaseDAO.h"
#include "../../domain/do/archives/ArchivesDO.h"
#include "../../domain/query/archives/ArchivesQuery.h"

class ArchivesDAO : public BaseDAO {
public:
	//ͳ���ж���������
	uint64_t count(const ArchivesQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<ArchivesDO> selectWithPage(const ArchivesQuery::Wrapper& query);
};

#endif // !_ARCHIVESDAO_H_