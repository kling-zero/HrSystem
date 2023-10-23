#pragma once
#ifndef _TRAININGRECORDQUERY_H_
#define _TRAININGRECORDQUERY_H_
#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ҳ��ѯ����
 */
class TrainingRecordPageQuery : public PageQuery
{
	DTO_INIT(TrainingRecordPageQuery, PageQuery);

	// ��ѵ��Ա������ʶ
	DTO_FIELD(String, trmtrianpersonid);
	DTO_FIELD_INFO(trmtrianpersonid) {
		info->description = ZH_WORDS_GETTER("trainingrecord.trmtrianpersonid");
	}

	// ��ѵ�༶
	DTO_FIELD(String, pxbj);
	DTO_FIELD_INFO(pxbj) {
		info->description = ZH_WORDS_GETTER("trainingrecord.pxbj");
	}

	// ��ѵ��ʼʱ��
	DTO_FIELD(String, trainbegin);
	DTO_FIELD_INFO(trainbegin) {
		info->description = ZH_WORDS_GETTER("trainingrecord.trainbegin");
	}

	// ��ѵ����ʱ��
	DTO_FIELD(String, trainend);
	DTO_FIELD_INFO(trainend) {
		info->description = ZH_WORDS_GETTER("trainingrecord.trainend");
	}

	// ��ѵ�γ�
	DTO_FIELD(String, pxkc);
	DTO_FIELD_INFO(pxkc) {
		info->description = ZH_WORDS_GETTER("trainingrecord.pxkc");
	}

	// ��ѵ����
	DTO_FIELD(String, trmtrainagencyname);
	DTO_FIELD_INFO(trmtrainagencyname) {
		info->description = ZH_WORDS_GETTER("trainingrecord.trmtrainagencyname");
	}

	// ��ѵ���
	DTO_FIELD(String, trainres);
	DTO_FIELD_INFO(trainres) {
		info->description = ZH_WORDS_GETTER("trainingrecord.trainres");
	}

	// ����
	DTO_FIELD(String, fs);
	DTO_FIELD_INFO(fs) {
		info->description = ZH_WORDS_GETTER("trainingrecord.fs");
	}

};

#include OATPP_CODEGEN_END(DTO)
#endif