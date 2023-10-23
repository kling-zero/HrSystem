#pragma once
#ifndef _MODWORKHISTORY_VO_H_
#define  _MODWORKHISTORY_VO_H_
#include "../../GlobalInclude.h"
#include "../../dto/work-history/ModWorkHistoryDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ���޸���ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class ModWorkHistoryJsonVO : public JsonVO< ModWorkHistoryDTO::Wrapper> {
	DTO_INIT(ModWorkHistoryJsonVO, JsonVO< ModWorkHistoryDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif 