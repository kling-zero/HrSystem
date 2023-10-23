#pragma once
#ifndef _TRAININGRECORDDTO_H_
#define _TRAININGRECORDDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
class TrainingRecordDTO : public oatpp::DTO {
	DTO_INIT(TrainingRecordDTO, DTO);

	// ��ѵ��Ա������ʶ
	DTO_FIELD(String, TRMTRIANPERSONID);
	DTO_FIELD_INFO(TRMTRIANPERSONID) {
		info->description = ZH_WORDS_GETTER("trainingrecord.trmtrianpersonid");
	}

	// ��ѵ�༶
	DTO_FIELD(String, PXBJ);
	DTO_FIELD_INFO(PXBJ) {
		info->description = ZH_WORDS_GETTER("trainingrecord.pxbj");
	}

	// ��ѵ��ʼʱ��
	DTO_FIELD(String, TRAINBEGIN);
	DTO_FIELD_INFO(TRAINBEGIN) {
		info->description = ZH_WORDS_GETTER("trainingrecord.trainbegin");
	}

	// ��ѵ����ʱ��
	DTO_FIELD(String, TRAINEND);
	DTO_FIELD_INFO(TRAINEND) {
		info->description = ZH_WORDS_GETTER("trainingrecord.trainend");
	}

	// ��ѵ�γ�
	DTO_FIELD(String, PXKC);
	DTO_FIELD_INFO(PXKC) {
		info->description = ZH_WORDS_GETTER("trainingrecord.pxkc");
	}

	// ��ѵ����
	DTO_FIELD(String, TRMTRAINAGENCYNAME);
	DTO_FIELD_INFO(TRMTRAINAGENCYNAME) {
		info->description = ZH_WORDS_GETTER("trainingrecord.trmtrainagencyname");
	}

	// ��ѵ���
	DTO_FIELD(String, TRAINRES);
	DTO_FIELD_INFO(TRAINRES) {
		info->description = ZH_WORDS_GETTER("trainingrecord.trainres");
	}

	// ����
	DTO_FIELD(String, FS);
	DTO_FIELD_INFO(FS) {
		info->description = ZH_WORDS_GETTER("trainingrecord.fs");
	}

};

/**
 * ʾ����ҳ�������
 */
class TrainingRecordPageDTO : public PageDTO<TrainingRecordDTO::Wrapper>
{
	DTO_INIT(TrainingRecordPageDTO, PageDTO<TrainingRecordDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)
#endif