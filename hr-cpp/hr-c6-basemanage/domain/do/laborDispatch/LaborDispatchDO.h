#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: mengHuan
 @Date: 2023/05/25 21:11:50

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#ifndef _LABORDISPATCHDO_H_
#define _LABORDISPATCHDO_H_

class LaborDispatchDO
{
	CC_SYNTHESIZE(string, enable, _Enable);
	//������ǲ��˾��������
	CC_SYNTHESIZE(string, name, Name);
	//������ǲ��˾�����ʶ
	CC_SYNTHESIZE(string, id, Id);
	//������λ
	CC_SYNTHESIZE(string,unit, Unit);
	//����ʱ��
	CC_SYNTHESIZE(string, createdate, Createdate);
	//������
	CC_SYNTHESIZE(string, createman, Createman);
	//������
	CC_SYNTHESIZE(string, updateman, Updateman);
	//����ʱ��
	CC_SYNTHESIZE(string, updatedate, Updatedate);
	//��Ӫ��Χ
	CC_SYNTHESIZE(string, jyfw, Jyfw);
	//��ϵ��ַ
	CC_SYNTHESIZE(string, lxdz, Lxdz);
	//��ϵ��ʽ
	CC_SYNTHESIZE(string, lxfs, Lxfs);
	//��ϵ��
	CC_SYNTHESIZE(string, lxr, Lxr);
	//��˾���
	CC_SYNTHESIZE(string, gsjj, Gsjj);
	//��Ա��Ϣ��ʶ
	CC_SYNTHESIZE(string, pimpersonid, Pimpersonid);
	// ��֯��ʶ
	CC_SYNTHESIZE(string, ormorgid, Ormorgid);
	//ע�᱾��
	CC_SYNTHESIZE(string, regcapital, Regcapital);
	//����
	CC_SYNTHESIZE(string, legalperson, Legalperson);
	//�ֶ�
	CC_SYNTHESIZE(string, ziduan, Ziduan);

public:
	LaborDispatchDO() {
		enable = "";
		name = "";
		id = "";
		unit = "";
		createdate = "";
		createman = "";
		updateman = "";
		updatedate = "";
		jyfw = "";
		lxdz = "";
		lxfs = "";
		lxr = "";
		gsjj = "";
		pimpersonid = "";
		ormorgid = "";
		regcapital = "";
		legalperson = "";
		ziduan = "";
	}
};

#endif // !_LABORDISPATCHDO_H_