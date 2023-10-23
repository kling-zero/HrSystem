#pragma once
#ifndef _QUALIFICATIONVO_H_
#define _QUALIFICATIONVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/Qualification/QualificationDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����һ��֤����Ϣ��ʾJsonVO����������Ӧ���ͻ���
 */

class QualificationJsonVO : public JsonVO<QualificationDTO::Wrapper>
{
	DTO_INIT(QualificationJsonVO, JsonVO<QualificationDTO::Wrapper>);
};

/**
 * ����һ��֤����Ϣ��ҳ��ʾJsonVO����������Ӧ���ͻ���
 */
class QualificationPageJsonVO : public JsonVO<QualificationPageDTO::Wrapper>
{
	DTO_INIT(QualificationPageJsonVO, JsonVO<QualificationPageDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)
#endif
