//�����Ҳ㼶�����б�
//���ߣ���Ƥ�����
//2023��5��26��
#pragma once
#ifndef _ARCHIVES_LEVEL_DAO_
#define _ARCHIVES_LEVEL_DAO_

#include "BaseDAO.h"
#include "../../domain/do/archivesLevel/ArchivesLevelDO.h"

class ArchivesLevelsDAO
{
	list<ArchivesLevelDO> getArchivesLevels();
};

#endif // !_ARCHIVES_LEVEL_DAO_



