#pragma once
#ifndef _JOBTITLE_INFORMATION_PAGEQUERY_H_
#define _JOBTITLE_INFORMATION_PAGEQUERY_H_
#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ��ְ�Ʒ�ҳ��ѯ����
 */
class JobTitleInformationPageQuery : public PageQuery
{
	DTO_INIT(JobTitleInformationPageQuery, PageQuery);
	// ְ������
	DTO_FIELD(String, professoranalysis_name);
	DTO_FIELD_INFO(professoranalysis_name) {
		info->description = ZH_WORDS_GETTER("sample.field.professoranalysis_name");
	}
	// ֤���� credentials_num
	DTO_FIELD(String, credentials_num);
	DTO_FIELD_INFO(credentials_num) {
		info->description = ZH_WORDS_GETTER("sample.field.credentials_num");
	}
	// ְ�Ƶȼ� professor_grades
	DTO_FIELD(String, professor_grades);
	DTO_FIELD_INFO(professor_grades) {
		info->description = ZH_WORDS_GETTER("sample.field.professor_grades");
	}
	// ְ�ƻ�ȡ���� zchqrq
	DTO_FIELD(String, zchqrq);
	DTO_FIELD_INFO(zchqrq) {
		info->description = ZH_WORDS_GETTER("sample.field.zchqrq");
	}
	// ����λ reviewbody
	DTO_FIELD(String, reviewbody);
	DTO_FIELD_INFO(reviewbody) {
		info->description = ZH_WORDS_GETTER("sample.field.reviewbody");
	}
	// ǩ������ lssuingagency
	DTO_FIELD(String, lssuingagency);
	DTO_FIELD_INFO(lssuingagency) {
		info->description = ZH_WORDS_GETTER("sample.field.lssuingagency");
	}
	//ְ��Ƹ��ʱ�� employtime
	DTO_FIELD(String, employtime);
	DTO_FIELD_INFO(employtime) {
		info->description = ZH_WORDS_GETTER("sample.field.employtime");
	}
	//�Ƿ����ְ�� enable
	DTO_FIELD(String, enable);
	DTO_FIELD_INFO(enable) {
		info->description = ZH_WORDS_GETTER("sample.field.enable");
	}
	//Ա�����:employeeid
	DTO_FIELD(String, employeeid);
	DTO_FIELD_INFO(employeeid) {
		info->description = ZH_WORDS_GETTER("sample.field.employeeid");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_JOBTITLE_INFORMATION_PAGEQUERY_H_
