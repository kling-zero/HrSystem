#pragma once
#ifndef _WORKHISTORY_VO_H_
#define _WORKHISTORY_VO_H_
#include "../../GlobalInclude.h"
#include "../../dto/work-history/WorkHistoryDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * ʾ����ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class WorkHistoryJsonVO : public JsonVO<WorkHistoryDTO::Wrapper> {
	DTO_INIT(WorkHistoryJsonVO, JsonVO<WorkHistoryDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)
#endif // !_WORKHISTORY_VO_H_
