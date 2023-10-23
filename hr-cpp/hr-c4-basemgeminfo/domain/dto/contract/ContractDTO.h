#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/05/13 19:52:05

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
#ifndef _CONTRACTDTO_H_
#define _CONTRACTDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��ͬ��ѯ������������
 */
class ContractDTO : public oatpp::DTO
{
public:
	DTO_INIT(ContractDTO, DTO);

	// ��Ա��Ϣ��ʶ
	DTO_FIELD(String, PIMPERSONID);
	DTO_FIELD_INFO(PIMPERSONID) {
		info->description = ZH_WORDS_GETTER("contract.PIMPERSONID");
	}
	// ��ͬ���
	DTO_FIELD(String, HTBH);
	DTO_FIELD_INFO(HTBH) {
		info->description = ZH_WORDS_GETTER("contract.HTBH");
	}
	// ��ͬ���
	DTO_FIELD(String, HTLX);
	DTO_FIELD_INFO(HTLX) {
		info->description = ZH_WORDS_GETTER("contract.HTLX");
	}
	// ��ͬ����
	DTO_FIELD(String, CONTRACTTYPE);
	DTO_FIELD_INFO(CONTRACTTYPE) {
		info->description = ZH_WORDS_GETTER("contract.CONTRACTTYPE");
	}
	// ��ʼ����
	DTO_FIELD(String, QSRQ);
	DTO_FIELD_INFO(QSRQ) {
		info->description = ZH_WORDS_GETTER("contract.QSRQ");
	}
	// ��������
	DTO_FIELD(String, JSRQ);
	DTO_FIELD_INFO(JSRQ) {
		info->description = ZH_WORDS_GETTER("contract.JSRQ");
	}
	// ��ͬ״̬
	DTO_FIELD(String, HTZT);
	DTO_FIELD_INFO(HTZT) {
		info->description = ZH_WORDS_GETTER("contract.HTZT");
	}
	// ���õ���ʱ��
	DTO_FIELD(String, SYDQSJ);
	DTO_FIELD_INFO(SYDQSJ) {
		info->description = ZH_WORDS_GETTER("contract.SYDQSJ");
	}
};

/**
 * ��ͬ��ѯ��ҳ������������
 */
class ContractPageDTO : public PageDTO<ContractDTO::Wrapper>
{
	DTO_INIT(ContractPageDTO, PageDTO<ContractDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_CONTRACTDTO_H_