#pragma once
#ifndef _PROBATIONARY_EMPLOYEE_DTO_
#define _PROBATIONARY_EMPLOYEE_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��Ա������ - ������ԱDTOʵ�� - ������
 */
class ProbationaryEmployeeDTO : public oatpp::DTO
{
public:
	//�޲ι���
	ProbationaryEmployeeDTO() {};

	DTO_INIT(ProbationaryEmployeeDTO, DTO);
	// Ψһ��ʶ
	DTO_FIELD(String, PIMPERSONID);
	DTO_FIELD_INFO(PIMPERSONID) {
		info->description = ZH_WORDS_GETTER("formeremployees.field.PIMPERSONID");
	}
	// ���
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("sample.field.id");
	}
	// ����A
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("sample.field.name");
	}
	// ��֯
	DTO_FIELD(String, zz);
	DTO_FIELD_INFO(zz) {
		info->description = ZH_WORDS_GETTER("probationaryemployee.field.zz");
	}
	// ����
	DTO_FIELD(String, bm);
	DTO_FIELD_INFO(bm) {
		info->description = ZH_WORDS_GETTER("probationaryemployee.field.bm");
	}
	// ְ��
	DTO_FIELD(String, zw);
	DTO_FIELD_INFO(zw) {
		info->description = ZH_WORDS_GETTER("probationaryemployee.field.zw");
	}
	// ��λ
	DTO_FIELD(String, gw);
	DTO_FIELD_INFO(gw) {
		info->description = ZH_WORDS_GETTER("probationaryemployee.field.gw");
	}
	// ��ְʱ��
	DTO_FIELD(String, rzsj);
	DTO_FIELD_INFO(rzsj) {
		info->description = ZH_WORDS_GETTER("probationaryemployee.field.rzsj");
	}
	// ���õ���ʱ��
	DTO_FIELD(String, daoqishijian);
	DTO_FIELD_INFO(daoqishijian) {
		info->description = ZH_WORDS_GETTER("probationaryemployee.field.time");
	}
};

class ProbationaryEmployeePageDTO : public PageDTO<ProbationaryEmployeeDTO::Wrapper>
{
	DTO_INIT(ProbationaryEmployeePageDTO, PageDTO<ProbationaryEmployeeDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // 