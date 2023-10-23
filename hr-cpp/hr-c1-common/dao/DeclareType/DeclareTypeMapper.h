//2023��5��27��
//���ߣ���Ƥ�����
//�걨���������б�����ݿ�ƥ��ӳ��
#pragma once
#ifndef _DECLARE_TYPE_MAPPER_
#define _DECLARE_TYPE_MAPPER_

#include "Mapper.h"
#include "domain/do/declareType/DeclareTypeDO.h"

class DeclareTypeMapper : public Mapper<DeclareTypeDO>
{
public:
	DeclareTypeDO mapper(ResultSet* result) const override
	{
		DeclareTypeDO declareTypeData;
		declareTypeData.setDeclareType(result->getString(1));
		return declareTypeData;
	}
};

#endif // !_DECLARE_TYPE_MAPPER_
