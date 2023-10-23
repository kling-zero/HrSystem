#pragma once
#ifndef TERMINATIONREMINDERVO_H
#define TERMINATIONREMINDERVO_H
#include "../../GlobalInclude.h"
#include "../../dto/TerminationReminderDTO/TerminationReminderDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class TerminationReminderJsonVO : public JsonVO<TerminationReminderDTO::Wrapper> {
	DTO_INIT(TerminationReminderJsonVO, JsonVO<TerminationReminderDTO::Wrapper>);
};

/**
 * ʾ����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class TerminationReminderPageJsonVO : public JsonVO<TerminationReminderPageDTO::Wrapper> {
	DTO_INIT(TerminationReminderPageJsonVO, JsonVO<TerminationReminderPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif