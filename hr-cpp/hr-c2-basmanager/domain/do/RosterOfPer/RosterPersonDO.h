#pragma once
#ifndef _ROSTERPERSON_DO_
#define _ROSTERPERSON_DO_
#include "../DoInclude.h"
/**
 * ��Ա��������Ϣ��ѯ�������ݿ�ʵ�壬������ʹ��--(��Ա������-��Ա������-��ҳ��ѯԱ���б�)--weixiaoman
 */

class RosterPersonDO {
	//������λ
	CC_SYNTHESIZE(string, ormOrgName, ormOrgName);
	//�������� t_srforgsector
	CC_SYNTHESIZE(string, orgsetorName, orgsetorName);
	//Ա�����
	CC_SYNTHESIZE(string, ygbh, ygbh);
	//Ա������
	CC_SYNTHESIZE(string, pimpersonName, pimpersonName);
	//�Ա�
	CC_SYNTHESIZE(string, xb, xb);
	//����
	CC_SYNTHESIZE(string, mz, mz);
	//��������
	CC_SYNTHESIZE(string, csrq, csrq);
	//����
	CC_SYNTHESIZE(int, nl, nl);
	//����״��
	CC_SYNTHESIZE(string, hyzk, hyzk);
	//����
	CC_SYNTHESIZE(string, jg, jg);
	//������ò
	CC_SYNTHESIZE(string, zzmm, zzmm);
	//�뵳ʱ��
	CC_SYNTHESIZE(string, rdsj, rdsj);
	//֤������
	CC_SYNTHESIZE(string, zjhm, zjhm);
	//�������� 
	CC_SYNTHESIZE(string, hkxz, hkxz);
	//������ַ
	CC_SYNTHESIZE(string, hjdz, hjdz);
	//�籣�νɵ�		
	CC_SYNTHESIZE(string, sbcjd, sbcjd);
	//��һѧ�� 
	CC_SYNTHESIZE(string, dyxl, dyxl);
	//��һѧ��ѧУ��� 
	CC_SYNTHESIZE(string, xxlb, xxlb);
	//��һѧ��ѧϰ��ʽ 
	CC_SYNTHESIZE(string, xxlx, xxlx);
	//��һѧ����ѧרҵ 
	CC_SYNTHESIZE(string, dyxlsxzy, dyxlsxzy);
	//��һѧ����ҵʱ�� 
	CC_SYNTHESIZE(string, dyxlbysj, dyxlbysj);
	//��һѧ����ҵԺУ 
	CC_SYNTHESIZE(string, dyxlbyyx, dyxlbyyx);
	//���ѧ����ҵԺУ 
	CC_SYNTHESIZE(string, zgxlbyyx, zgxlbyyx);
	//���ѧ�� 
	CC_SYNTHESIZE(string, zgxl, zgxl);
	//���ѧ��ѧУ��� 
	CC_SYNTHESIZE(string, zgxxlb, zgxxlb);
	//���ѧ��ѧϰ��ʽ 
	CC_SYNTHESIZE(string, zgxllx, zgxllx);
	//���ѧ����ҵʱ�� 
	CC_SYNTHESIZE(string, zgxljssj, zgxljssj);
	//���ѧ����ѧרҵ 
	CC_SYNTHESIZE(string, zgxlsxzy, zgxlsxzy);
	//�μӹ���ʱ�� 
	CC_SYNTHESIZE(string, cjgzsj, cjgzsj);
	//�������� 
	CC_SYNTHESIZE(int, gznx, gznx);
	//����ϵͳ����ʱ�� 
	CC_SYNTHESIZE(string, tozjdate, tozjdate);
	//����ϵͳ�������� 
	CC_SYNTHESIZE(int, zjxtgznx, zjxtgznx);
	//�ֹ���ʱ�� 
	CC_SYNTHESIZE(string, dzjbjsj, dzjbjsj);
	//�ֹ������� 
	CC_SYNTHESIZE(string, bjgznx, bjgznx);
	//����λ����ʱ��
	CC_SYNTHESIZE(string, dbdwsj, dbdwsj);
	//����λ��������
	CC_SYNTHESIZE(string, bdwgznx, bdwgznx);
	//����ҵ��ϵͳ 
	CC_SYNTHESIZE(string, pimMajorseTypeName, pimMajorseTypeName);
	//ְ�� 
	CC_SYNTHESIZE(string, rank, rank);
	//ְ�� 
	CC_SYNTHESIZE(string, zw, zw);
	//��λ 
	CC_SYNTHESIZE(string, gw, gw);
	//��λ��� 
	CC_SYNTHESIZE(string, gwType, gwType);
	//��Ч���˳ɼ��������꣩ 
	CC_SYNTHESIZE(string, jxkhcj, jxkhcj);
	//��λ֤�� 
	CC_SYNTHESIZE(string, pimQualTypeName, pimQualTypeName);
	//רҵ�����ʸ�ְ�ƣ� 
	CC_SYNTHESIZE(string, careerName, careerName);
	//ְ�Ʊ�� 
	CC_SYNTHESIZE(string, zcbh, zcbh);
	//�Ƿ�ע����ʦ
	CC_SYNTHESIZE(int, sfzckjs, sfzckjs);
	//ע����ʦ֤���� 
	CC_SYNTHESIZE(int, zgzsbh, zgzsbh);
	//ִ��ְ��ҵ�ʸ�֤�� 
	CC_SYNTHESIZE(string, pimVocationalCatalogName, pimVocationalCatalogName);
	//��ְ���� 
	CC_SYNTHESIZE(string, rzqd, rzqd);
	//��ͬ��� 
	CC_SYNTHESIZE(string, htlb, htlb);
	//�Ͷ���ͬ���� 
	CC_SYNTHESIZE(string, contractType, contractType);
	//ǩ������ 
	CC_SYNTHESIZE(string, qsrq, qsrq);
	//�������� 
	CC_SYNTHESIZE(string, jsrq, jsrq);
	//��ͬ������ 
	CC_SYNTHESIZE(string, htsyq, htsyq);
	//��ͬ����
	CC_SYNTHESIZE(string, htqx, htqx);
	//��ϵ��ʽ
	CC_SYNTHESIZE(string, lxdh, lxdh);
	//Ա������
	CC_SYNTHESIZE(string, yglx, yglx);

	/*****�ò������ֶ�*****/
	//��Ա��ϸ���ʶ
	CC_SYNTHESIZE(string, PCMDETAILID, PCMDETAILID);
	//��Ա��ϸ������
	CC_SYNTHESIZE(string, PCMDETAILNAME, PCMDETAILNAME);
	//������
	CC_SYNTHESIZE(string, CREATEMAN, CREATEMAN);
	//ENABLE
	CC_SYNTHESIZE(int, ENABLE, ENABLE);
	//����ʱ��
	CC_SYNTHESIZE(string, CREATEDATE, CREATEDATE);
	//������
	CC_SYNTHESIZE(string, UPDATEMAN, UPDATEMAN);
	//����ʱ��
	CC_SYNTHESIZE(string, UPDATEDATE, UPDATEDATE);
	//��֯��ʶ
	CC_SYNTHESIZE(string, ORMORGID, ORMORGID);
	//���ű�ʶ
	CC_SYNTHESIZE(string, ORMORGSECTORID, ORMORGSECTORID);
	//FIRSTEDUCATION
	CC_SYNTHESIZE(int, FIRSTEDUCATION, FIRSTEDUCATION);
	//SFZGXL
	CC_SYNTHESIZE(int, SFZGXL, SFZGXL);
	//��ע
	CC_SYNTHESIZE(string, BZ, BZ);
	//ע����ʦרҵ�׶ο�����ͨ����Ŀ��
	CC_SYNTHESIZE(string, KSTGKMS, KSTGKMS);
	//��ѵ
	CC_SYNTHESIZE(string, PX, PX);
	//����
	CC_SYNTHESIZE(string, FIELD, FIELD);

public:
	RosterPersonDO() { 
		this->gznx = 0; 
		this->nl = 0; 
		this->sfzckjs = 0; 
		this->zgzsbh = 0; 
		this->zjxtgznx = 0; 

		//�ò������ֶ�
		this->ENABLE = 0;
		this->FIRSTEDUCATION = 0;
		this->SFZGXL = 0;
	};
};

#endif // !_ROSTERPERSON_DO_

