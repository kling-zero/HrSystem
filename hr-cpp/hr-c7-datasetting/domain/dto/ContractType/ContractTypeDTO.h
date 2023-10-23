#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/05/20 9:28:29

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
#ifndef _CONTRACTTYPE_H_
#define _CONTRACTTYPE_H_
//#include "ApiHelper.h"
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

#define API_DTO_FIELD(_TYPE_, _NAME_, _DESCRIPTION_, _REQUIRE_, _DEFAULT_) \
DTO_FIELD(_TYPE_, _NAME_) = _DEFAULT_; \
DTO_FIELD_INFO(_NAME_) { \
	info->description = _DESCRIPTION_; \
	info->required = _REQUIRE_; \
}

#define API_DTO_FIELD_DEFAULT(_TYPE_, _NAME_, _DESCRIPTION_) \
DTO_FIELD(_TYPE_, _NAME_); \
DTO_FIELD_INFO(_NAME_) { \
	info->description = _DESCRIPTION_; \
}

/*
	��ͬ���ʹ������
*/
class ContractTypeDTO : public oatpp::DTO
{	
public:
	ContractTypeDTO() {};
	ContractTypeDTO(String id, String name) :id(id), name(name) {};
	DTO_INIT(ContractTypeDTO, DTO);
	//Ա�����
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("contractType.field.tpyeID");
	}
	//Ա������
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("contractType.field.name");
	}

	//department: Ա��������λ
	DTO_FIELD(String, department);
	DTO_FIELD_INFO(department) {
		info->description = ZH_WORDS_GETTER("contractType.field.department");
	}

	//stat: Ա��״̬
	DTO_FIELD(String, stat);
	DTO_FIELD_INFO(stat) {
		info->description = ZH_WORDS_GETTER("contractType.field.stat");
	}

	//unitArrivalTime: ����λʱ��
	DTO_FIELD(String, unitArrivalTime);
	DTO_FIELD_INFO(unitArrivalTime) {
		info->description = ZH_WORDS_GETTER("contractType.field.unitArrivalTime");
	}

	//contractId: ��ͬ���
	DTO_FIELD(String, contractId);
	DTO_FIELD_INFO(contractId) {
		info->description = ZH_WORDS_GETTER("contractType.field.contractId");
	}

	//signingUnit: ��ͬǩ����λ
	DTO_FIELD(String, signingUnit);
	DTO_FIELD_INFO(signingUnit) {
		info->description = ZH_WORDS_GETTER("contractType.field.signingUnit");
	}

	//contract_category: ��ͬ���
	DTO_FIELD(String, contract_category);
	DTO_FIELD_INFO(contract_category) {
		info->description = ZH_WORDS_GETTER("contractType.field.contract_category");
	}

	//contract_type: ��ͬ����
	DTO_FIELD(String, contract_type);
	DTO_FIELD_INFO(contract_type) {
		info->description = ZH_WORDS_GETTER("contractType.field.contract_type");
	}

	//startDate: ��ʼ����
	DTO_FIELD(String, startDate);
	DTO_FIELD_INFO(startDate) {
		info->description = ZH_WORDS_GETTER("contractType.field.startDate");
	}

	//endDate: ��������
	DTO_FIELD(String, endDate);
	DTO_FIELD_INFO(endDate) {
		info->description = ZH_WORDS_GETTER("contractType.field.endDate");
	}

	//contractStatus: ��ͬ״̬
	DTO_FIELD(String, contractStatus);
	DTO_FIELD_INFO(contractStatus) {
		info->description = ZH_WORDS_GETTER("contractType.field.contractStatus");
	}

	//remainingDays: ��ͬʣ��ʱ��
	DTO_FIELD(String, remainingDays);
	DTO_FIELD_INFO(remainingDays) {
		info->description = ZH_WORDS_GETTER("contractType.field.remainingDays");
	}

	//expiryDate: ���õ���ʱ��
	DTO_FIELD(String, expiryDate);
	DTO_FIELD_INFO(expiryDate) {
		info->description = ZH_WORDS_GETTER("contractType.field.expiryDate");
	}

	//API_DTO_FIELD_DEFAULT(String, contractTypeId, ZH_WORDS_GETTER("contractType.field.tpyeID"));

};

/**
 * ��ͬ���ͷ�ҳ�������
 */
class ContractTypePageDTO : public PageDTO<ContractTypeDTO::Wrapper>
{
	DTO_INIT(ContractTypePageDTO, PageDTO<ContractTypeDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_CONTRACTTYPE_H_