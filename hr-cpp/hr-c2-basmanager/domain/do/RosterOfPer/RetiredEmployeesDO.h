#pragma once
#ifndef _RETIRED_EMPLPYEES_DO_
#define _RETIRED_EMPLPYEES_DO_
#include "../DoInclude.h"
/*
 ������Ա��DO--����Ա�����ᣩ--pine
 (��Ӧ���ݿ��t_pcmydjdmx���춯�����ϸ �� t_pcmydmx���춯��ϸ)
 */

class RetiredEmployeesDO
{
	// Ա�����
	CC_SYNTHESIZE(string, ygbh, ygbh);
	// Ա��id����PIMPERSONID
	CC_SYNTHESIZE(string, pimpersonid, pimpersonid);
	//����+���
	CC_SYNTHESIZE(string, idAndName, idAndName);
	// Ա������
	CC_SYNTHESIZE(string, pimpersonname, pimpersonname);//�޸�
	// �Ա�
	CC_SYNTHESIZE(string, xb, xb);
	// ����
	CC_SYNTHESIZE(string, nj, nj);
	// ͨѶ��ַ
	CC_SYNTHESIZE(string, postaladdress, postaladdress);
	// ���ݵ�
	CC_SYNTHESIZE(string, retiPlace, retiPlace);
	// ��ͥ��ϵ��
	CC_SYNTHESIZE(string, jtlxr, jtlxr);
	// ��ͥ��ϵ�˵绰
	CC_SYNTHESIZE(string, jtlxrdh, jtlxrdh);
	// ��֯
	CC_SYNTHESIZE(string, zz, zz);
	// ����
	CC_SYNTHESIZE(string, bm, bm);
	// ְ��
	CC_SYNTHESIZE(string, rank, rank);
	//����ǰְ��
	CC_SYNTHESIZE(string, yzw, yzw);
	//����ǰ��λ
	CC_SYNTHESIZE(string, ygw, ygw);
	//����ʱ��
	CC_SYNTHESIZE(string, txdq, txdq);
	//ʵ������ʱ��
	CC_SYNTHESIZE(string, sjtxrq, sjtxrq);
	//�ֻ�����
	CC_SYNTHESIZE(string, lxdh, lxdh);
	//���������Ͻ��
	CC_SYNTHESIZE(string, spdylje, spdylje);
public:
	RetiredEmployeesDO() {
		ygbh = "";
		pimpersonid = "";
		pimpersonname = "";
		xb = "";
		nj = "-1";
		postaladdress = "";
		retiPlace = "";
		jtlxr = "";
		jtlxrdh = "";
		zz = "";
		bm = "";
		rank = "";
		yzw = "";
		ygw = "";
		txdq = "";
		sjtxrq = "";
		lxdh = "";
		spdylje = "";

	}
};

#endif // !_SAMPLE_DO_
