#pragma once
#ifndef _ARCHIVE_DAO_
#define _ARCHIVE_DAO_
#include "BaseDAO.h"
#include "../../domain/do/archive/ArchiveDo.h"
#include "../../domain/query/archive/ArchiveQuery.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class ArchiveDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const ArchiveQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<ArchiveDO> selectWithPage(const ArchiveQuery::Wrapper& query);
	// ͨ��������ѯ����
	list<ArchiveDO> selectByName(const string& name);
	// ��������
	uint64_t insert(const ArchiveDO& iObj);
	// �޸�����
	int update(const ArchiveDO& uObj);
	// ͨ��IDɾ������
	int deleteById(uint64_t id);
};
#endif // !_ARCHIVE_DAO_
