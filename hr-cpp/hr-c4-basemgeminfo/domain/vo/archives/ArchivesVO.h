#pragma once
#ifndef  _ARCHIVESVO_H_
#define  _ARCHIVESVO_H_
#include "../../GlobalInclude.h"
#include "../../dto/archives/ArchivesDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * ������ѯJsonVO
 */
class ArchivesJsonVO : public JsonVO<ArchivesDTO::Wrapper>
{
	DTO_INIT(ArchivesJsonVO, JsonVO<ArchivesDTO::Wrapper>);
};

/**
 * ������ѯ��ҳJsonVO
 */
class ArchivesPageJsonVO : public JsonVO<ArchivesPageDTO::Wrapper>
{
	DTO_INIT(ArchivesPageJsonVO, JsonVO<ArchivesPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // ! _ARCHIVESVO_H_
