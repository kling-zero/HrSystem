#pragma once
/**
 * (��Ա������-��ְ��Ա-��ҳ��ѯԱ���б�)--weixiaoman
 */
#ifndef _TEMPORARYSTAFF_VO_
#define _TEMPORARYSTAFF_VO_

#include "../../GlobalInclude.h"
#include "../../dto/RosterOfPer/TemporaryStaffDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��ְ��Ա��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class TemporaryStaffJsonVO : public JsonVO<TemporaryStaffDTO::Wrapper> {
	DTO_INIT(TemporaryStaffJsonVO, JsonVO<TemporaryStaffDTO::Wrapper>);
};

/**
 * ��ְ��Ա��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class TemporaryStaffPageJsonVO : public JsonVO<TemporaryStaffPageDTO::Wrapper> {
	DTO_INIT(TemporaryStaffPageJsonVO, JsonVO<TemporaryStaffPageDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)
#endif // !_TEMPORARYSTAFF_VO_