#pragma once
#ifndef _JOB_UPDATE_DTO_
#define _JOB_UPDATE_DTO_
#include "../../../GlobalInclude.h"
#include OATPP_CODEGEN_BEGIN(DTO)

class JobUpdateDTO : public oatpp::DTO
{
	DTO_INIT(JobUpdateDTO, DTO);

	// ��λ����*
	DTO_FIELD(String, gwfl);
	DTO_FIELD_INFO(gwfl) {
		info->description = ZH_WORDS_GETTER("orgmanage.dto.gwfl");
	}
	// �Ƿ��ܸ�*
	DTO_FIELD(String, isConfidential);
	DTO_FIELD_INFO(isConfidential) {
		info->description = ZH_WORDS_GETTER("orgmanage.dto.isConfidential");
	}
	// ��λ������*
	DTO_FIELD(String, ormPostName);
	DTO_FIELD_INFO(ormPostName) {
		info->description = ZH_WORDS_GETTER("orgmanage.dto.ormPostName");
	}
	// �Ƿ�ؼ���λ*
	DTO_FIELD(String, isKeyPostion);
	DTO_FIELD_INFO(isKeyPostion) {
		info->description = ZH_WORDS_GETTER("orgmanage.dto.isKeyPostion");
	}
	// ��λ����*
	DTO_FIELD(String, postNature);
	DTO_FIELD_INFO(postNature) {
		info->description = ZH_WORDS_GETTER("orgmanage.dto.postNature");
	}
	// ���ñ�ʶ*
	DTO_FIELD(String, startStopSign);
	DTO_FIELD_INFO(startStopSign) {
		info->description = ZH_WORDS_GETTER("orgmanage.dto.startStopSign");
	}

	// ��λ����ʶ
	DTO_FIELD(String, ormPostId);
	DTO_FIELD_INFO(ormPostId) {
		info->description = ZH_WORDS_GETTER("orgmanage.dto.ormPostId");
	}

	// ��λ����
	DTO_FIELD(String, gwType);
	DTO_FIELD_INFO(gwType) {
		info->description = ZH_WORDS_GETTER("orgmanage.dto.gwType");
	}

	// �Ƿ���ʱ����
	DTO_FIELD(String, isTemp);
	DTO_FIELD_INFO(isTemp) {
		info->description = ZH_WORDS_GETTER("orgmanage.dto.isTemp");
	}

	// ��֯��ʶ
	DTO_FIELD(String, ormOrgId);
	DTO_FIELD_INFO(ormOrgId) {
		info->description = ZH_WORDS_GETTER("orgmanage.dto.ormOrgId");
	}
	// ���齻������
	DTO_FIELD(UInt32, nx);
	DTO_FIELD_INFO(nx) {
		info->description = ZH_WORDS_GETTER("jobSet.add.yearLimit");
	}
	// ���뽻������
	DTO_FIELD(UInt32, bxjlnx);
	DTO_FIELD_INFO(bxjlnx) {
		info->description = ZH_WORDS_GETTER("jobSet.add.mustYearLimit");
	}
};


#include OATPP_CODEGEN_END(DTO)
#endif // !_JOB_UPDATE_DTO_
