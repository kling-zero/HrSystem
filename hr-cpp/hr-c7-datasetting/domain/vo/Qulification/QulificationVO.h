#pragma once
#ifndef _QULIFICATIONVO_H_
#define _QULIFICATIONVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/Qulification/QulificationDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����һ��ִҵ�ʸ���Ϣ��ʾJsonVO����������Ӧ���ͻ���
 */

class qulificationJsonVO : public JsonVO<QulificationDTO::Wrapper>
{
	DTO_INIT(QulificationJsonVO, JsonVO<QulificationDTO::Wrapper>);
};

/**
 * ����һ��ִҵ�ʸ���Ϣ��ҳ��ʾJsonVO����������Ӧ���ͻ���
 */
class QulificationPageJsonVO : public JsonVO<QulificationPageDTO::Wrapper>
{
	DTO_INIT(QulificationPageJsonVO, JsonVO<QulificationPageDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)
#endif
 