//2023��5��27��
//���ߣ���Ƥ�����
//�����Ҳ㼶�����б�����ݿ�ƥ��ӳ��
#pragma once
#ifndef _ARCHIVES_LEVEL_MAPPER_
#define _ARCHIVES_LEVEL_MAPPER_

#include "Mapper.h"
#include "domain/do/archivesLevel/ArchivesLevelDO.h"

class ArchivesLevelMapper : public Mapper<ArchivesLevelDO> 
{
public:
	ArchivesLevelDO mapper(ResultSet* result) const override
	{
		ArchivesLevelDO archivelsLevelsData;
		archivelsLevelsData.setArchiveslevel(result->getString(1));
		return archivelsLevelsData;
	}
};


#endif // !_ARCHIVES_LEVEL_MAPPER_
