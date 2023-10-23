#pragma once
#ifndef _DELETEPROJTAGDAO_H_
#define _DELETEPROJTAGDAO_H_
#include "BaseDAO.h"
#include "domain/do/projTag/ProjTagDO.h"
#include "domain/query/projTag/PageProjTagQuery.h"

/**
 * ��Ŀ��ǩ - ɾ����Ŀ��ǩDAO
 * ������ : ���֮��
 */
class DeleteProjTagDAO : public BaseDAO
{
public:
	int deleteById(string id);
};
#endif // !_DELETEPROJTAGDAO_H_