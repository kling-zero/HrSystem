#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: huilai
 @Date: 2023/05/15 15:20:19

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
#ifndef _ADDWORKHISTORYDTO_H_
#define _ADDWORKHISTORYDTO_H_
#define DTO_INIT_(type, field, name) DTO_FIELD(type, field); \
DTO_FIELD_INFO(field) { \
	info->description = ZH_WORDS_GETTER(name); \
}

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class AddWorkHistoryDTO : public oatpp::DTO
{
	DTO_INIT(AddWorkHistoryDTO, DTO);
	
	//8��Ա��Ϣid
	DTO_INIT_(String, pimpersonid, "workhistory.field.pimpersonid")

		//��ְ��ʼʱ��
	DTO_FIELD(String, rzkssj);
	DTO_FIELD_INFO(rzkssj) {
		info->description = ZH_WORDS_GETTER("workhistory.field.rzkssj");
	}


	//��ְ����ʱ��
	DTO_FIELD(String, rzjssj);
	DTO_FIELD_INFO(rzjssj) {
		info->description = ZH_WORDS_GETTER("workhistory.field.rzjssj");
	}

	//������λ
	DTO_FIELD(String, ormorgname);
	DTO_FIELD_INFO(ormorgname) {
		info->description = ZH_WORDS_GETTER("workhistory.field.ormorgname");
	}

	//4����
	DTO_INIT_(String, ormorgsectorname, "workhistory.field.ormorgsectorname")

	//5ְ��
	DTO_INIT_(String, ormdutyname, "workhistory.field.ormdutyname")

	//6��λ
	DTO_INIT_(String, ormpostname, "workhistory.field.ormpostname")

	//7��ְ�������
	DTO_INIT_(String, cfplx, "workhistory.field.cfplx")

	//8�Ƿ���Ҫ����
	DTO_INIT_(UInt64, experience, "workhistory.field.experience")

	//��������id
	DTO_INIT_(String, pimworkhistoryid, "workhistory.field.pimworkhistoryid")

	
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_ADDWORKHISTORYDTO_H_