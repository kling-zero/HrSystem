#ifndef EXPENSEYDTO_H
#define EXPENSEYDTO_H
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * �ѱ�DTO
 */
class ExpenseLedgeDTO : public oatpp::DTO
{
	DTO_INIT(ExpenseLedgeDTO, DTO);

	// �������
	DTO_FIELD(String, PIMEXPACCOUNTNAME);
	DTO_FIELD_INFO(PIMEXPACCOUNTNAME) {
		info->description = ZH_WORDS_GETTER("expense.field.expense_name");
	}

	// ���ñ�ʶ
	DTO_FIELD(String, PIMEXPACCOUNTID);
	DTO_FIELD_INFO(PIMEXPACCOUNTID) {
		info->description = ZH_WORDS_GETTER("expense.field.expense_id");
	}

	// ���ý��
	DTO_FIELD(Float64, FYJE);
	DTO_FIELD_INFO(FYJE) {
		info->description = ZH_WORDS_GETTER("expense.field.expense_num");
	}
	// ��������
	DTO_FIELD(UInt32, FFRS);
	DTO_FIELD_INFO(FFRS) {
		info->description = ZH_WORDS_GETTER("expense.field.people_num");
	}
	
	// ����ʱ��
	DTO_FIELD(String, FFSJ);
	DTO_FIELD_INFO(FFSJ) {
		info->description = ZH_WORDS_GETTER("expense.field.get_time");
	}
	// ���ñ�׼
	DTO_FIELD(String, FFYBZ);
	DTO_FIELD_INFO(FFYBZ) {
		info->description = ZH_WORDS_GETTER("expense.field.expense_std");
	}
};
#endif