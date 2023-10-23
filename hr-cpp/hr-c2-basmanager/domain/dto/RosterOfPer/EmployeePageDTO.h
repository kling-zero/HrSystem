#pragma once
/*
����Ա������-��Ա������-��ҳ��ѯԱ���б�--����
*/
#ifndef _EMPLOYEE_PAGE_DTO_
#define _EMPLOYEE_PAGE_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class EmployeeDTO : public oatpp::DTO
{
	DTO_INIT(EmployeeDTO, DTO);
	// ������λ
	DTO_FIELD(String, ormOrgName);
	DTO_FIELD_INFO(ormOrgName) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.ormOrgName");
	}
	// �������� t_srforgsector
	DTO_FIELD(String, orgsetorName);
	DTO_FIELD_INFO(orgsetorName) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.orgsetorName");
	}
	// Ա�����
	DTO_FIELD(String, ygbh);
	DTO_FIELD_INFO(ygbh) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.ygbh");
	}
	// Ա������
	DTO_FIELD(String, pimpersonName);
	DTO_FIELD_INFO(pimpersonName) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.pimpersonName");
	}
	// �Ա�
	DTO_FIELD(String, xb);
	DTO_FIELD_INFO(xb) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.xb");
	}
	// ����
	DTO_FIELD(String, mz);
	DTO_FIELD_INFO(mz) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.mz");
	}
	// ��������
	DTO_FIELD(String, csrq);
	DTO_FIELD_INFO(csrq) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.csrq");
	}
	// ����
	DTO_FIELD(Int32, nl);
	DTO_FIELD_INFO(nl) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.nl");
	}
	// ����״��
	DTO_FIELD(String, hyzk);
	DTO_FIELD_INFO(hyzk) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.hyzk");
	}
	// ����
	DTO_FIELD(String, jg);
	DTO_FIELD_INFO(jg) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.jg");
	}
	// ������ò
	DTO_FIELD(String, zzmm);
	DTO_FIELD_INFO(zzmm) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.zzmm");
	}
	// �뵳ʱ��
	DTO_FIELD(String, rdsj);
	DTO_FIELD_INFO(rdsj) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.rdsj");
	}
	// ֤������
	DTO_FIELD(String, zjhm);
	DTO_FIELD_INFO(zjhm) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.zjhm");
	}
	// ��������
	DTO_FIELD(String, hkxz);
	DTO_FIELD_INFO(hkxz) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.hkxz");
	}
	// ������ַ
	DTO_FIELD(String, hjdz);
	DTO_FIELD_INFO(hjdz) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.hjdz");
	}
	// �籣�νɵ�
	DTO_FIELD(String, sbcjd);
	DTO_FIELD_INFO(sbcjd) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.sbcjd");
	}
	// ��һѧ��
	DTO_FIELD(String, dyxl);
	DTO_FIELD_INFO(dyxl) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.dyxl");
	}
	// ��һѧ��ѧУ���
	DTO_FIELD(String, xxlb);
	DTO_FIELD_INFO(xxlb) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.xxlb");
	}
	// ��һѧ��ѧϰ��ʽ
	DTO_FIELD(String, xxlx);
	DTO_FIELD_INFO(xxlx) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.xxlx");
	}
	// ��һѧ����ѧרҵ
	DTO_FIELD(String, dyxlsxzy);
	DTO_FIELD_INFO(dyxlsxzy) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.dyxlsxzy");
	}
	// ��һѧ����ҵʱ��
	DTO_FIELD(String, dyxlbysj);
	DTO_FIELD_INFO(dyxlbysj) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.dyxlbysj");
	}
	// ��һѧ����ҵԺУ
	DTO_FIELD(String, dyxlbyyx);
	DTO_FIELD_INFO(dyxlbyyx) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.dyxlbyyx");
	}
	// ���ѧ����ҵԺУ
	DTO_FIELD(String, zgxlbyyx);
	DTO_FIELD_INFO(zgxlbyyx) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.zgxlbyyx");
	}
	// ���ѧ��
	DTO_FIELD(String, zgxl);
	DTO_FIELD_INFO(zgxl) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.zgxl");
	}
	// ���ѧ��ѧУ���
	DTO_FIELD(String, zgxxlb);
	DTO_FIELD_INFO(zgxxlb) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.zgxxlb");
	}
	// ���ѧ��ѧϰ��ʽ
	DTO_FIELD(String, zgxllx);
	DTO_FIELD_INFO(zgxllx) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.zgxllx");
	}
	// ���ѧ����ҵʱ��
	DTO_FIELD(String, zgxljssj);
	DTO_FIELD_INFO(zgxljssj) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.zgxljssj");
	}
	// ���ѧ����ѧרҵ
	DTO_FIELD(String, zgxlsxzy);
	DTO_FIELD_INFO(zgxlsxzy) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.zgxlsxzy");
	}
	// �μӹ���ʱ��
	DTO_FIELD(String, cjgzsj);
	DTO_FIELD_INFO(cjgzsj) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.cjgzsj");
	}
	// ��������
	DTO_FIELD(Int32, gznx);
	DTO_FIELD_INFO(gznx) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.gznx");
	}
	// ����ϵͳ����ʱ��
	DTO_FIELD(String, tozjdate);
	DTO_FIELD_INFO(tozjdate) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.tozjdate");
	}
	// ����ϵͳ��������
	DTO_FIELD(Int32, zjxtgznx);
	DTO_FIELD_INFO(zjxtgznx) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.zjxtgznx");
	}
	// �ֹ���ʱ��
	DTO_FIELD(String, dzjbjsj);
	DTO_FIELD_INFO(dzjbjsj) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.dzjbjsj");
	}
	// �ֹ�������
	DTO_FIELD(String, bjgznx);
	DTO_FIELD_INFO(bjgznx) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.bjgznx");
	}
	// ����λ����ʱ��
	DTO_FIELD(String, dbdwsj);
	DTO_FIELD_INFO(dbdwsj) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.dbdwsj");
	}
	// ����λ��������
	DTO_FIELD(String, bdwgznx);
	DTO_FIELD_INFO(bdwgznx) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.bdwgznx");
	}
	// ����ҵ��ϵͳ
	DTO_FIELD(String, pimMajorseTypeName);
	DTO_FIELD_INFO(pimMajorseTypeName) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.pimMajorseTypeName");
	}
	// ְ��
	DTO_FIELD(String, rank);
	DTO_FIELD_INFO(rank) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.rank");
	}
	// ְ��
	DTO_FIELD(String, zw);
	DTO_FIELD_INFO(zw) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.zw");
	}
	// ��λ
	DTO_FIELD(String, gw);
	DTO_FIELD_INFO(gw) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.gw");
	}
	// ��λ���
	DTO_FIELD(String, gwType);
	DTO_FIELD_INFO(gwType) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.gwType");
	}
	// ��Ч���˳ɼ��������꣩
	DTO_FIELD(String, jxkhcj);
	DTO_FIELD_INFO(jxkhcj) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.jxkhcj");
	}
	// ��λ֤��
	DTO_FIELD(String, pimQualTypeName);
	DTO_FIELD_INFO(pimQualTypeName) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.pimQualTypeName");
	}
	// רҵ�����ʸ�ְ�ƣ�
	DTO_FIELD(String, careerName);
	DTO_FIELD_INFO(careerName) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.careerName");
	}
	// ְ�Ʊ��
	DTO_FIELD(String, zcbh);
	DTO_FIELD_INFO(zcbh) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.zcbh");
	}
	// �Ƿ�ע����ʦ
	DTO_FIELD(Int32, sfzckjs);
	DTO_FIELD_INFO(sfzckjs) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.sfzckjs");
	}
	// ע����ʦ֤����
	DTO_FIELD(Int32, zgzsbh);
	DTO_FIELD_INFO(zgzsbh) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.zgzsbh");
	}
	// ִ��ְ��ҵ�ʸ�֤��
	DTO_FIELD(String, pimVocationalCatalogName);
	DTO_FIELD_INFO(pimVocationalCatalogName) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.pimVocationalCatalogName");
	}
	// ��ְ����
	DTO_FIELD(String, rzqd);
	DTO_FIELD_INFO(rzqd) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.rzqd");
	}
	// ��ͬ���
	DTO_FIELD(String, htlb);
	DTO_FIELD_INFO(htlb) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.htlb");
	}
	// �Ͷ���ͬ����
	DTO_FIELD(String, contractType);
	DTO_FIELD_INFO(contractType) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.contractType");
	}
	// ǩ������
	DTO_FIELD(String, qsrq);
	DTO_FIELD_INFO(qsrq) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.qsrq");
	}
	// ��������
	DTO_FIELD(String, jsrq);
	DTO_FIELD_INFO(jsrq) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.jsrq");
	}
	// ��ͬ������
	DTO_FIELD(String, htsyq);
	DTO_FIELD_INFO(htsyq) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.htsyq");
	}
	// ��ͬ����
	DTO_FIELD(String, htqx);
	DTO_FIELD_INFO(htqx) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.htqx");
	}
	// ��ϵ��ʽ
	DTO_FIELD(String, lxdh);
	DTO_FIELD_INFO(lxdh) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.lxdh");
	}
	// Ա������
	DTO_FIELD(String, yglx);
	DTO_FIELD_INFO(yglx) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.yglx");
	}

	/*****�ò������ֶ�*****/
	// ��Ա��ϸ���ʶ
	DTO_FIELD(String, PCMDETAILID);
	DTO_FIELD_INFO(PCMDETAILID) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.PCMDETAILID");
	}
	// ��Ա��ϸ������
	DTO_FIELD(String, PCMDETAILNAME);
	DTO_FIELD_INFO(PCMDETAILNAME) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.PCMDETAILNAME");
	}
	// ������
	DTO_FIELD(String, CREATEMAN);
	DTO_FIELD_INFO(CREATEMAN) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.CREATEMAN");
	}
	// ENABLE
	DTO_FIELD(Int32, ENABLE);
	DTO_FIELD_INFO(ENABLE) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.ENABLE");
	}
	// ����ʱ��
	DTO_FIELD(String, CREATEDATE);
	DTO_FIELD_INFO(CREATEDATE) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.CREATEDATE");
	}
	// ������
	DTO_FIELD(String, UPDATEMAN);
	DTO_FIELD_INFO(UPDATEMAN) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.UPDATEMAN");
	}
	// ����ʱ��
	DTO_FIELD(String, UPDATEDATE);
	DTO_FIELD_INFO(UPDATEDATE) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.UPDATEDATE");
	}
	// ��֯��ʶ
	DTO_FIELD(String, ORMORGID);
	DTO_FIELD_INFO(ORMORGID) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.ORMORGID");
	}
	// ���ű�ʶ
	DTO_FIELD(String, ORMORGSECTORID);
	DTO_FIELD_INFO(ORMORGSECTORID) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.ORMORGSECTORID");
	}
	// FIRSTEDUCATION
	DTO_FIELD(Int32, FIRSTEDUCATION);
	DTO_FIELD_INFO(FIRSTEDUCATION) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.FIRSTEDUCATION");
	}
	// SFZGXL
	DTO_FIELD(Int32, SFZGXL);
	DTO_FIELD_INFO(SFZGXL) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.SFZGXL");
	}
	// ��ע
	DTO_FIELD(String, BZ);
	DTO_FIELD_INFO(BZ) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.BZ");
	}
	// ע����ʦרҵ�׶ο�����ͨ����Ŀ��
	DTO_FIELD(String, KSTGKMS);
	DTO_FIELD_INFO(KSTGKMS) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.KSTGKMS");
	}
	// ��ѵ
	DTO_FIELD(String, PX);
	DTO_FIELD_INFO(PX) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.PX");
	}
	// ����
	DTO_FIELD(String, FIELD);
	DTO_FIELD_INFO(FIELD) {
		info->description = ZH_WORDS_GETTER("employeeDTO.field.FIELD");
	}
};

class EmployeePageDTO : public PageDTO<EmployeeDTO::Wrapper>
{
	DTO_INIT(EmployeePageDTO, PageDTO<EmployeeDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_EMPLOYEE_PAGE_DTO_
