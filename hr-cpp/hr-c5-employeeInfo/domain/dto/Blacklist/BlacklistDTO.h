#pragma once

#ifndef _BLACKLIST_DTO_
#define _BLACKLIST_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)


class BlacklistDTO : public oatpp::DTO {
	DTO_INIT(BlacklistDTO, DTO);
	//Ա�����
	DTO_FIELD(String, ygbh);
	DTO_FIELD_INFO(ygbh) {
		info->description = ZH_WORDS_GETTER("archive.dto.ygbh");
	}
    //Ա������
	DTO_FIELD(String, ygxm);
	DTO_FIELD_INFO(ygxm) {
		info->description = ZH_WORDS_GETTER("archive.dto.ygxm");
	}
	//֤������
	DTO_FIELD(String, zjhm);
	DTO_FIELD_INFO(zjhm) {
		info->description = ZH_WORDS_GETTER("archive.dto.zjhm");
	}
	//��֯
	DTO_FIELD(String, zz);
	DTO_FIELD_INFO(zz) {
		info->description = ZH_WORDS_GETTER("archive.dto.zz");
	}
	//Ա��״̬
	DTO_FIELD(String, ygzt);
	DTO_FIELD_INFO(ygzt) {
		info->description = ZH_WORDS_GETTER("archive.dto.ygzt");
	}
	//�Ƿ����������
	DTO_FIELD(String, sflrhmd);
	DTO_FIELD_INFO(sflrhmd) {
		info->description = ZH_WORDS_GETTER("archive.dto.sflrhmd");
	}
	//������ԭ��
	DTO_FIELD(String, hmdyy);
	DTO_FIELD_INFO(hmdyy) {
		info->description = ZH_WORDS_GETTER("archive.dto.hmdyy");
	}
};

class BlacklistPageDTO : public PageDTO<BlacklistPageDTO::Wrapper>
{
	DTO_INIT(BlacklistPageDTO, PageDTO<BlacklistDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)
#endif // !_BLACKLIST_DTO_
