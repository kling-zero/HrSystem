#pragma once
#ifndef _ARCHIVES_DAO_
#define _ARCHIVES_DAO_
#include "BaseDAO.h"
#include "../../domain/do/archives/t_pimarchivesDO.h"
#include "../../domain/query/archives/ArchivesQuery.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class ArchivesDAO : public BaseDAO
{
public:
	// ��ѯ��ϸ����
	// asd
	list<t_pimarchivesDO> selectAll(const ArchivesQuery::Wrapper& query);
	// ͳ����������
	uint64_t count(const ArchivesQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<t_pimarchivesDO> selectWithPage(const ArchivesQuery::Wrapper& query);
	// �������� 
	uint64_t insert(const t_pimarchivesDO& iObj, uint64_t id);
	// ͨ��IDɾ������
	int deleteById(const string& id);
};
#endif // !_ARCHIVES_DAO_
