#pragma once

#ifndef _Add_Employee_Info_DTO
#define _Add_Employee_Info_DTO

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * ����Ա��������Ϣ
 */
class AddEmployeeInfoDTO : public oatpp::DTO
{
	DTO_INIT(AddEmployeeInfoDTO, DTO);
	
	//������Ϣ
	//ѧ��
	DTO_FIELD(String, degree);
	DTO_FIELD_INFO(degree) {
		info->description = ZH_WORDS_GETTER("employee.education.degree");
	}
	//��ѧʱ��
	DTO_FIELD(String, enrollmentDate);
	DTO_FIELD_INFO(enrollmentDate) {
		info->description = ZH_WORDS_GETTER("employee.field.education");
	}
	//��ҵʱ��
	DTO_FIELD(String, graduationDate);
	DTO_FIELD_INFO(graduationDate) {
		info->description = ZH_WORDS_GETTER("employee.education.graduationDate");
	}
	//��ҵԺУ
	DTO_FIELD(String, graduatedInstitution);
	DTO_FIELD_INFO(graduatedInstitution) {
		info->description = ZH_WORDS_GETTER("employee.education.graduatedInstitution");
	}
	//һ��ѧ��
	DTO_FIELD(String, primaryDiscipline);
	DTO_FIELD_INFO(primaryDiscipline) {
		info->description = ZH_WORDS_GETTER("employee.education.primaryDiscipline");
	}
	//��ѧרҵ
	DTO_FIELD(String, major);
	DTO_FIELD_INFO(major) {
		info->description = ZH_WORDS_GETTER("employee.education.major");
	}
	//ѧϰ��ʽ
	DTO_FIELD(String, studyFormat);
	DTO_FIELD_INFO(studyFormat) {
		info->description = ZH_WORDS_GETTER("employee.education.studyFormat");
	}
	//ѧУ����
	DTO_FIELD(String, schoolNature);
	DTO_FIELD_INFO(schoolNature) {
		info->description = ZH_WORDS_GETTER("employee.education.schoolNature");
	}
	//�Ƿ��һѧ��
	DTO_FIELD(Boolean, firstDegree);
	DTO_FIELD_INFO(firstDegree) {
		info->description = ZH_WORDS_GETTER("employee.education.firstDegree");
	}
	//���ѧ��
	DTO_FIELD(String, highestEducationDegree);
	DTO_FIELD_INFO(highestEducationDegree) {
		info->description = ZH_WORDS_GETTER("employee.education.highestEducationDegree");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // _USERDTO_H_