//2023��5��21��
//�����Ҳ㼶�����б�
//���ߣ���Ƥ�����
#pragma once
#ifndef _ARCHIVES_LIST_VO_
#define _ARCHIVES_LIST_VO_

#include "../../GlobalInclude.h"
#include "../../dto/archivesLevels/ArchivesLevelsDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class ArchivesListVO : public JsonVO<ArchivesLevelsListDTO::Wrapper>
{
	DTO_INIT(ArchivesListVO, JsonVO<ArchivesLevelsListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_ARCHIVES_LIST_VO_
