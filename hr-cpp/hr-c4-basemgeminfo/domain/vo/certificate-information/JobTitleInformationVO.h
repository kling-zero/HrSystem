#pragma once
#ifndef _JOBTITLE_INFORMATION_VO_H_
#define _JOBTITLE_INFORMATION_VO_H_
#include "../../GlobalInclude.h"
#include "../../dto/certificate-information/JobTitleInformationDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)



/**
 * ʾ����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class JobTitleInformationPageJsonVO : public JsonVO<JobTitleInformationPageDTO::Wrapper> {
	DTO_INIT(JobTitleInformationPageJsonVO, JsonVO<JobTitleInformationDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif 

