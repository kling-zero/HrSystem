#pragma once

#ifndef EXPENSEYVO_H
#define EXPENSEYVO_H

#include "../../GlobalInclude.h"
#include "../../dto/ExpenseLedge/ExpenseLedgeDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ������Ӧ���ͻ��˵�Json���󣬹��ڷѱ�
 */
class ExpenseLedgeJsonVO : public JsonVO<ExpenseLedgeDTO::Wrapper> {
	DTO_INIT(ExpenseLedgeJsonVO, JsonVO<ExpenseLedgeDTO::Wrapper>);
};

class ExportExpenseJsonV0 : public JsonVO<Vector<ExpenseLedgeDTO::Wrapper>> {
	DTO_INIT(ExportExpenseJsonV0, JsonVO<Vector<ExpenseLedgeDTO::Wrapper>>)
};
#include OATPP_CODEGEN_END(DTO)

#endif // !_SAMPLE_VO_