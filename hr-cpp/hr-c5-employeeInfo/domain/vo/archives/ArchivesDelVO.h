#pragma once

#ifndef _ARCHIVES_DEL_VO_H_
#define _ARCHIVES_DEL_VO_H_

#include "../../GlobalInclude.h"
#include "../../dto/archives/ArchivesDelDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ɾ��JsonVO��������Ӧ���ͻ��˵�Json����
 */

class ArchivesDelJsonVO : public JsonVO<ArchivesDelDTO::Wrapper> {
	DTO_INIT(ArchivesDelJsonVO, JsonVO<ArchivesDelDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)

#endif // !_ARCHIVES_VO_H_