#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 10:59:38

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
#ifndef _SCIRESULT_DTO_
#define _SCIRESULT_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ���������
 */
class SciResultDTO : public oatpp::DTO
{
public:
	SciResultDTO() {};
	SciResultDTO(String UPDATEMAN, String PIMRESEARCHFINDINGSNAME) :UPDATEMAN(UPDATEMAN), PIMRESEARCHFINDINGSNAME(PIMRESEARCHFINDINGSNAME) {};
	DTO_INIT(SciResultDTO, DTO);
	//������
	DTO_FIELD(String, UPDATEMAN);
	DTO_FIELD_INFO(UPDATEMAN) {
		info->description = ZH_WORDS_GETTER("sciresult.UPDATEMAN");
	}
	//���гɹ�����
	DTO_FIELD(String, PIMRESEARCHFINDINGSNAME);
	DTO_FIELD_INFO(PIMRESEARCHFINDINGSNAME) {
		info->description = ZH_WORDS_GETTER("sciresult.PIMRESEARCHFINDINGSNAME");
	}
	//����
	DTO_FIELD(String, FJ);
	DTO_FIELD_INFO(FJ) {
		info->description = ZH_WORDS_GETTER("sciresult.FJ");
	}
	DTO_FIELD(String, ENABLE);
	DTO_FIELD_INFO(ENABLE) {
		info->description = ZH_WORDS_GETTER("sciresult.ENABLE");
	}
	
	//����ʱ��
	DTO_FIELD(String, CREATEDATE);
	DTO_FIELD_INFO(CREATEDATE) {
		info->description = ZH_WORDS_GETTER("sciresult.CREATEDATE");
	}
	//����ʱ��
	DTO_FIELD(String, UPDATEDATE);
	DTO_FIELD_INFO(UPDATEDATE) {
		info->description = ZH_WORDS_GETTER("sciresult.UPDATEDATE");
	}
	//������
	DTO_FIELD(String, CREATEMAN);
	DTO_FIELD_INFO(CREATEMAN) {
		info->description = ZH_WORDS_GETTER("sciresult.CREATEMAN");
	}
	//���гɹ���ʶ
	DTO_FIELD(String, PIMRESEARCHFINDINGSID);
	DTO_FIELD_INFO(PIMRESEARCHFINDINGSID) {
		info->description = ZH_WORDS_GETTER("sciresult.PIMRESEARCHFINDINGSID");
	}
	//��Ա��Ϣ��ʶ
	DTO_FIELD(String, PIMPERSONID);
	DTO_FIELD_INFO(PIMPERSONID) {
		info->description = ZH_WORDS_GETTER("sciresult. PIMPERSONID");
	}
	//��ȡʱ��
	DTO_FIELD(String, HQSJ);
	DTO_FIELD_INFO(HQSJ) {
		info->description = ZH_WORDS_GETTER("sciresult.HQSJ");
	}
	//��¼����
	DTO_FIELD(String, JLSS);
	DTO_FIELD_INFO(JLSS) {
		info->description = ZH_WORDS_GETTER("sciresult.JLSS");
	}
	//����״̬
	DTO_FIELD(String, JLSPZT);
	DTO_FIELD_INFO(JLSPZT) {
		info->description = ZH_WORDS_GETTER("sciresult.JLSPZT");
	}
	//��¼������
	DTO_FIELD(String, JLGLBH);
	DTO_FIELD_INFO(JLGLBH) {
		info->description = ZH_WORDS_GETTER("sciresult.JLGLBH");
	}
	//��¼������
	DTO_FIELD(String, JLCZZ);
	DTO_FIELD_INFO(JLCZZ) {
		info->description = ZH_WORDS_GETTER("sciresult.JLCZZ");
	}
	//�ܾ�ԭ��
	DTO_FIELD(String, REASON);
	DTO_FIELD_INFO(REASON) {
		info->description = ZH_WORDS_GETTER("sciresult.REASON");
	}



   
};

/**
 * ʾ����ҳ�������
 */
class SciResultPageDTO : public PageDTO<SciResultDTO::Wrapper>
{
	DTO_INIT(SciResultPageDTO, PageDTO<SciResultDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_