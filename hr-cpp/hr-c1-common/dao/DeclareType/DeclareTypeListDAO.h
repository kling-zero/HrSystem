//2023��5��27��
//���ߣ���Ƥ�����
//�걨�б��DAO
#pragma once
#ifndef _DECLARE_TYPE_LIST_DAO_
#define _DECLARE_TYPE_LIST_DAO_

#include "BaseDAO.h"
#include "../../domain/do/declareType/DeclareTypeDO.h"

class DeclareTypeListDAO : public BaseDAO
{
public:
	//�����걨�����б�
	std::list<DeclareTypeDO> getDeclareTypeList();

};

#endif // !_DECLARE_TYPE_LIST_DAO_


