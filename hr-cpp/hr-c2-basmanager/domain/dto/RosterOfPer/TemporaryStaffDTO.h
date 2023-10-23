#pragma once
#ifndef _TEMPORARYSTAFFDTO_H_
#define _TEMPORARYSTAFFDTO_H_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * ��ְ��Ա�������--(��Ա������-��ְ��Ա-��ҳ��ѯԱ���б�)--weixiaoman
 */
class TemporaryStaffDTO : public oatpp::DTO {
public:
	DTO_INIT(TemporaryStaffDTO, DTO);
	//Ա�����
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("TempStaff.field.id");
	}
	//Ա������
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("TempStaff.field.name");
	}
	//Ա��״̬
	DTO_FIELD(String, empStatus);
	DTO_FIELD_INFO(empStatus) {
		info->description = ZH_WORDS_GETTER("TempStaff.field.empStatus");
	}
	//��ְ״̬
	DTO_FIELD(String, tempStatus);
	DTO_FIELD_INFO(tempStatus) {
		info->description = ZH_WORDS_GETTER("TempStaff.field.tempStatus");
	}
	//��ְ��֯
	DTO_FIELD(String, tempOrg);
	DTO_FIELD_INFO(tempOrg) {
		info->description = ZH_WORDS_GETTER("TempStaff.field.tempOrg");
	}
	//��ְ����
	DTO_FIELD(String, tempDept);
	DTO_FIELD_INFO(tempDept) {
		info->description = ZH_WORDS_GETTER("TempStaff.field.tempDept");
	}
	//��ְ��ʼʱ��
	DTO_FIELD(String, tempStartTime);
	DTO_FIELD_INFO(tempStartTime) {
		info->description = ZH_WORDS_GETTER("TempStaff.field.tempStartTime");
	}
	//��ְ����ʱ��
	DTO_FIELD(String, tempEndTime);
	DTO_FIELD_INFO(tempEndTime) {
		info->description = ZH_WORDS_GETTER("TempStaff.field.tempEndTime");
	}
	//��ְ��ԱΨһ��ʶ
	DTO_FIELD(String, pimpersonId);
	DTO_FIELD_INFO(pimpersonId) {
		info->description = ZH_WORDS_GETTER("TempStaff.field.pimpersonId");
	}
};

/**
 * ��ְ��Ա��ҳ�������
 */
class TemporaryStaffPageDTO : public PageDTO<TemporaryStaffDTO::Wrapper>
{
	DTO_INIT(TemporaryStaffPageDTO, PageDTO<TemporaryStaffDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_TEMPORARYSTAFFDTO_H_