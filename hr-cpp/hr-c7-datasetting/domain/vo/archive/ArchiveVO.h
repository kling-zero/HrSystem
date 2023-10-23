#pragma once
#ifndef _ARCHIVEVO_H_
#define _ARCHIVEVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/archive/ArchiveDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����һ����������Ϣ��ʾJsonVO����������Ӧ���ͻ���
 */
class ArchiveJsonVO : public JsonVO<ArchiveDTO::Wrapper>
{
	DTO_INIT(ArchiveJsonVO, JsonVO<ArchiveDTO::Wrapper>);
};

/**
 * ����һ����������Ϣ��ҳ��ʾJsonVO����������Ӧ���ͻ���
 */
class ArchivePageJsonVO : public JsonVO<ArchivePageDTO::Wrapper>
{
	DTO_INIT(ArchivePageJsonVO, JsonVO<ArchivePageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif