#pragma once
#ifndef _SCIENTIFICDAO_H_
#define _SCIENTIFICDAO_H_
#include "BaseDAO.h"
#include "../../domain/do/scientific/ScientificDO.h"
#include "../../domain/query/scientific/ScientificQuery.h"

class ScientificDAO : public BaseDAO
{
public:
	// ��ѯ��������
	list<ScientificDO> selectDetail(const ScientificViewQuery::Wrapper& query);
	// �޸�����
	int update(const ScientificDO& uObj);
	// ��ҳ��ѯ����
	list<ScientificDO> selectWithPage(const ScientificDownloadQuery::Wrapper& query);

};

#endif // !_ScientificDAO_H_
