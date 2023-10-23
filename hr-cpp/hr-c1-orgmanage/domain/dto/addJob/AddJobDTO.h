#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/05/27 10:11:00

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#ifndef _ADDJOBDTO_H_
#define _ADDJOBDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class AddJobDTO : public oatpp::DTO
{
	DTO_INIT(AddJobDTO, DTO);
	// ��λ������
	DTO_FIELD(String, postName);
	DTO_FIELD_INFO(postName) {
		info->description = ZH_WORDS_GETTER("jobSet.add.postName");
	}
	// ��λ����ʶ
	/*DTO_FIELD(String, postId);
	DTO_FIELD_INFO(postId) {
		info->description = ZH_WORDS_GETTER("jobSet.add.postId");
	}*/
	// ��֯��ʶ
	DTO_FIELD(String, orgId);
	DTO_FIELD_INFO(orgId) {
		info->description = ZH_WORDS_GETTER("jobSet.add.orgId");
	}
	// ��λ����
	DTO_FIELD(String, jobType);
	DTO_FIELD_INFO(jobType) {
		info->description = ZH_WORDS_GETTER("jobSet.add.jobType");
	}
	// ��λ����
	DTO_FIELD(String, jobClass);
	DTO_FIELD_INFO(jobClass) {
		info->description = ZH_WORDS_GETTER("jobSet.add.jobClass");
	}
	// �Ƿ���ʱ����
	DTO_FIELD(String, isTemp);
	DTO_FIELD_INFO(isTemp) {
		info->description = ZH_WORDS_GETTER("jobSet.add.isTemp");
	}
	// �Ƿ��ܸ�λ
	DTO_FIELD(String, isConfidential);
	DTO_FIELD_INFO(isConfidential) {
		info->description = ZH_WORDS_GETTER("jobSet.add.isConfidential");
	}
	// ��λ����
	DTO_FIELD(String, postNature);
	DTO_FIELD_INFO(postNature) {
		info->description = ZH_WORDS_GETTER("jobSet.add.postNature");
	}
	// �Ƿ�ؼ���λ
	DTO_FIELD(String, isKeyPostion);
	DTO_FIELD_INFO(isKeyPostion) {
		info->description = ZH_WORDS_GETTER("jobSet.add.isKeyPostion");
	}
	// ���ñ�ʶ
	DTO_FIELD(String, sign);
	DTO_FIELD_INFO(sign) {
		info->description = ZH_WORDS_GETTER("jobSet.add.sign");
	}
	// ���齻������
	DTO_FIELD(UInt32, yearLimit);
	DTO_FIELD_INFO(yearLimit) {
		info->description = ZH_WORDS_GETTER("jobSet.add.yearLimit");
	}
	// ���뽻������
	DTO_FIELD(UInt32, mustYearLimit);
	DTO_FIELD_INFO(mustYearLimit) {
		info->description = ZH_WORDS_GETTER("jobSet.add.mustYearLimit");
	}
public:
	AddJobDTO()
	{
		sign = "";
		isKeyPostion = "";
		postNature = "";
		isConfidential = "";
		isTemp = "";
		jobClass = "";
		jobType = "";
		orgId = "";
		postName = "";
		yearLimit = 1;
		mustYearLimit = 1;
	}
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_ADDJOBDTO_H_