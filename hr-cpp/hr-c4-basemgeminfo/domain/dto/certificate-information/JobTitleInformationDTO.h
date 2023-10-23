#pragma once
#ifndef _JOBTITLE_INFORMATION_DTO_H_
#define _JOBTITLE_INFORMATION_DTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��ͬ��ѯ������������
 */
class JobTitleInformationDTO : public oatpp::DTO
{
public:
	JobTitleInformationDTO() {};
	JobTitleInformationDTO(String credentials_num, String professoranalysis_name) :credentials_num(credentials_num), professoranalysis_name(professoranalysis_name) {};

	DTO_INIT(JobTitleInformationDTO, DTO);
	//professoranalysis_name: ְ������ 
	DTO_FIELD(String, professoranalysis_name);
	DTO_FIELD_INFO(professoranalysis_name) {
		info->description = ZH_WORDS_GETTER("jobtitleinformation.field.professoranalysis_name");
	}
	//credentials_num: ֤����
	DTO_FIELD(String, credentials_num);
	DTO_FIELD_INFO(credentials_num) {
		info->description = ZH_WORDS_GETTER("jobtitleinformation.field.credentials_num");
	}
	//professor_grades: ְ�Ƶȼ�
	DTO_FIELD(String, professor_grades);
	DTO_FIELD_INFO(professor_grades) {
		info->description = ZH_WORDS_GETTER("jobtitleinformation.field.professor_grades");
	}
	//major: רҵ���
	DTO_FIELD(String, major);
	DTO_FIELD_INFO(major) {
		info->description = ZH_WORDS_GETTER("jobtitleinformation.field.major");
	}
	//zchqrq: ְ�ƻ�ȡ����
	DTO_FIELD(String, zchqrq);
	DTO_FIELD_INFO(zchqrq) {
		info->description = ZH_WORDS_GETTER("jobtitleinformation.field.zchqrq");
	}
	//reviewbody: ����λ
	DTO_FIELD(String, reviewbody);
	DTO_FIELD_INFO(reviewbody) {
		info->description = ZH_WORDS_GETTER("jobtitleinformation.field.vreviewbody");
	}
	//lssuingagency: ǩ������
	DTO_FIELD(String, lssuingagency);
	DTO_FIELD_INFO(lssuingagency) {
		info->description = ZH_WORDS_GETTER("jobtitleinformation.field.lssuingagency");
	}
	//employtime: ְ��Ƹ��ʱ��
	DTO_FIELD(String, employtime);
	DTO_FIELD_INFO(employtime) {
		info->description = ZH_WORDS_GETTER("jobtitleinformation.field.employtime");
	}
	//enable: �Ƿ����ְ��
	DTO_FIELD(String, enable);
	DTO_FIELD_INFO(enable) {
		info->description = ZH_WORDS_GETTER("jobtitleinformation.field.enable");
	}
	//employeeid Ա�����
	DTO_FIELD(String, employeeid);
	DTO_FIELD_INFO(employeeid) {
		info->description = ZH_WORDS_GETTER("jobtitleinformation.field.employeeid");
	}
};

/**
 * ��ͬ��ѯ��ҳ������������
 */
class JobTitleInformationPageDTO : public PageDTO<JobTitleInformationDTO::Wrapper>
{
	DTO_INIT(JobTitleInformationPageDTO, PageDTO<JobTitleInformationDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif