/*
 Copyright Zero One Star. All rights reserved.

 @Author: Chen J
 @Date: 2023/05/17 21:33:02
*/
#ifndef _EDUCATION_H_
#define _EDUCATION_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/*
* ������Ϣ�������
*/


class EducationSingleDTO : public oatpp::DTO
{
	DTO_INIT(EducationSingleDTO, DTO);
	// ������Ϣ��ʶ �����
	DTO_FIELD(String, PIMEDUCATIONID);
	DTO_FIELD_INFO(PIMEDUCATIONID) {
		info->description = ZH_WORDS_GETTER("education.PIMEDUCATIONID");
	}
	// ѧ��
	DTO_FIELD(String, XL);
	DTO_FIELD_INFO(XL) {
		info->description = ZH_WORDS_GETTER("education.XL");
	}
	// ��ѧʱ��
	//DTO_FIELD(UInt64, QSSJ);
	DTO_FIELD(String, QSSJ);
	DTO_FIELD_INFO(QSSJ) {
		info->description = ZH_WORDS_GETTER("education.QSSJ");
	}
	// ��ҵʱ��
	//DTO_FIELD(UInt64, JSSJ);
	DTO_FIELD(String, JSSJ);
	DTO_FIELD_INFO(JSSJ) {
		info->description = ZH_WORDS_GETTER("education.JSSJ");
	}
	// ��ҵԺУ
	DTO_FIELD(String, BYYX);
	DTO_FIELD_INFO(BYYX) {
		info->description = ZH_WORDS_GETTER("education.BYYX");
	}
	// һ��ѧ��
	DTO_FIELD(String, XKML);
	DTO_FIELD_INFO(XKML) {
		info->description = ZH_WORDS_GETTER("education.XKML");
	}
	// ��ѧרҵ
	DTO_FIELD(String, SXZY);
	DTO_FIELD_INFO(SXZY) {
		info->description = ZH_WORDS_GETTER("education.SXZY");
	}
	// ѧϰ��ʽ
	DTO_FIELD(String, XLLX);
	DTO_FIELD_INFO(XLLX) {
		info->description = ZH_WORDS_GETTER("education.XLLX");
	}
	// ѧУ����
	DTO_FIELD(String, XXXZ);
	DTO_FIELD_INFO(XXXZ) {
		info->description = ZH_WORDS_GETTER("education.XXXZ");
	}
	// �Ƿ��һѧ��
	DTO_FIELD(UInt64, SFDYXL);
	DTO_FIELD_INFO(SFDYXL) {
		info->description = ZH_WORDS_GETTER("education.SFDYXL");
	}
	//�Ƿ����ѧ��
	DTO_FIELD(UInt64, SFZGXL);
	DTO_FIELD_INFO(SFZGXL) {
		info->description = ZH_WORDS_GETTER("education.SFZGXL");
	}
	// ��ҵ֤
	DTO_FIELD(String, BTZ);
	DTO_FIELD_INFO(BTZ) {
		info->description = ZH_WORDS_GETTER("education.BTZ");
	}
	// ѧλ֤
	DTO_FIELD(String, XWZ);
	DTO_FIELD_INFO(XWZ) {
		info->description = ZH_WORDS_GETTER("education.XWZ");
	}
	// ѧ����֤
	DTO_FIELD(String, XLCX);
	DTO_FIELD_INFO(XLCX) {
		info->description = ZH_WORDS_GETTER("education.XLCX");
	}
	// ��������
	DTO_FIELD(String, FJ);
	DTO_FIELD_INFO(FJ) {
		info->description = ZH_WORDS_GETTER("education.FJ");
	}
	//// �����pimpersonid
	//DTO_FIELD(String, PIMPERSONID);
	//DTO_FIELD_INFO(PIMPERSONID) {
	//	info->description = ZH_WORDS_GETTER("education.PIMPERSONID");
	//}



	//// ��������
	//DTO_FIELD(String, JYMC);
	//DTO_FIELD_INFO(JYMC) {
	//	info->description = ZH_WORDS_GETTER("education.JYMC");
	//}


	//// ������
	//DTO_FIELD(String, CREATEMAN);
	//DTO_FIELD_INFO(CREATEMAN) {
	//	info->description = ZH_WORDS_GETTER("education.CREATEMAN");
	//}

	//// ������Ϣ����
	//DTO_FIELD(String, PIMEDUCATIONNAME);
	//DTO_FIELD_INFO(PIMEDUCATIONNAME) {
	//	info->description = ZH_WORDS_GETTER("education.PIMEDUCATIONNAME");
	//}

	//// ������
	//DTO_FIELD(String, UPDATEMAN);
	//DTO_FIELD_INFO(UPDATEMAN) {
	//	info->description = ZH_WORDS_GETTER("education.UPDATEMAN");
	//}

	//// ����ʱ��
	//DTO_FIELD(UInt64, UPDATEDATE);
	//DTO_FIELD_INFO(UPDATEDATE) {
	//	info->description = ZH_WORDS_GETTER("education.UPDATEDATE");
	//}

	//// ����ʱ��
	//DTO_FIELD(Int64, CREATEDATE);
	//DTO_FIELD_INFO(CREATEDATE) {
	//	info->description = ZH_WORDS_GETTER("education.CREATEDATE");
	//}

	//// ��Ա��Ϣ��ʶ
	//DTO_FIELD(String, PIMPERSONID);
	//DTO_FIELD_INFO(PIMPERSONID) {
	//	info->description = ZH_WORDS_GETTER("education.PIMPERSONID");
	//}
	//// ��¼����
	//DTO_FIELD(String, JLSS);
	//DTO_FIELD_INFO(JLSS) {
	//	info->description = ZH_WORDS_GETTER("education.JLSS");
	//}
	//// ��¼������
	//DTO_FIELD(String, JLGLBH);
	//DTO_FIELD_INFO(JLGLBH) {
	//	info->description = ZH_WORDS_GETTER("education.JLGLBH");
	//}
	//// ��¼����״̬
	//DTO_FIELD(String, JLSPZT);
	//DTO_FIELD_INFO(JLSPZT) {
	//	info->description = ZH_WORDS_GETTER("education.JLSPZT");
	//}
	//// ��¼������
	//DTO_FIELD(String, JLCZZ);
	//DTO_FIELD_INFO(JLCZZ) {
	//	info->description = ZH_WORDS_GETTER("education.JLCZZ");
	//}
	//// ���ű�ʶ
	//DTO_FIELD(String, ORMORGSECTORID);
	//DTO_FIELD_INFO(ORMORGSECTORID) {
	//	info->description = ZH_WORDS_GETTER("education.ORMORGSECTORID");
	//}
	//// ѧλ
	//DTO_FIELD(String, DEGREE);
	//DTO_FIELD_INFO(DEGREE) {
	//	info->description = ZH_WORDS_GETTER("education.DEGREE");
	//}
	//// Ա�����
	//DTO_FIELD(String, YGBH);
	//DTO_FIELD_INFO(YGBH) {
	//	info->description = ZH_WORDS_GETTER("education.YGBH");
	//}
	//// �μӹ���ʱ��
	//DTO_FIELD(UInt64, CJGZSJ);
	//DTO_FIELD_INFO(CJGZSJ) {
	//	info->description = ZH_WORDS_GETTER("education.CJGZSJ");
	//}
	//// ����ϵͳ����ʱ��
	//DTO_FIELD(UInt64, TOZJDATE);
	//DTO_FIELD_INFO(TOZJDATE) {
	//	info->description = ZH_WORDS_GETTER("education.TOZJDATE");
	//}
	//// �ֹ���ʱ��
	//DTO_FIELD(UInt64, DZJBJSJ);
	//DTO_FIELD_INFO(DZJBJSJ) {
	//	info->description = ZH_WORDS_GETTER("education.DZJBJSJ");
	//}
	//// ����λ����ʱ��
	//DTO_FIELD(UInt64, DBDWSJ);
	//DTO_FIELD_INFO(DBDWSJ) {
	//	info->description = ZH_WORDS_GETTER("education.DBDWSJ");
	//}
	//// �ܾ�ԭ��
	//DTO_FIELD(String, REASON);
	//DTO_FIELD_INFO(REASON) {
	//	info->description = ZH_WORDS_GETTER("education.REASON");
	//}

	

};

/**
 * ������Ϣ��ҳ�������
 */
class EducationPageDTO : public PageDTO<EducationSingleDTO::Wrapper>
{
	DTO_INIT(EducationPageDTO, PageDTO<EducationSingleDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)

#endif // !_EDUCATION_H_#pragma once
