#pragma once
#pragma once

#ifndef _UPDATE_ARCHIVE_INFO_VO_
#define _UPDATE_ARCHIVE_INFO_VO_

#include "../../GlobalInclude.h"
#include "../../dto/UpdateArchiveInfo/UpdateArchiveInfoDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class UpdateArchiveInfoVO : public JsonVO<UpdateArchiveInfoDTO::Wrapper> {
	DTO_INIT(UpdateArchiveInfoVO, JsonVO<UpdateArchiveInfoDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_UPDATE_ARCHIVE_INFO_VO_