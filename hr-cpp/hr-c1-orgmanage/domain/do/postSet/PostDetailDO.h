#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: rice
 @Date: 2023/5/21 16:57:23

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
#ifndef _POSTDETAIL_DO_
#define _POSTDETAIL_DO_
#include "../DoInclude.h"

/**
 * ��λ���� - ��ѯָ����λ����DO
 */
class PostDetailDO
{
	// ������*
	CC_SYNTHESIZE(uint32_t, xh,Xh);
	// ��λ����*
	CC_SYNTHESIZE(string, gwfl, Gwfl);
	// �Ƿ��ܸ�*
	CC_SYNTHESIZE(string, isConfidential, IsConfidential);
	// ��λ������*
	CC_SYNTHESIZE(string, ormPostName, OrmPostName);
	// ���齻������*
	CC_SYNTHESIZE(uint32_t, nx,Nx);
	// ���뽻������*
	CC_SYNTHESIZE(uint32_t, bxjlnx, Bxjlnx);
	// �Ƿ�ؼ���λ*
	CC_SYNTHESIZE(string, isKeyPostion, IsKeyPostion);
	// ��λ����*
	CC_SYNTHESIZE(string, postNature, PostNature);
	// ���ñ�ʶ*
	CC_SYNTHESIZE(string, startStopSign, StartStopSign);
	// ��λ����ʶ
	CC_SYNTHESIZE(string, ormPostId, OrmPostId);
	// ������
	CC_SYNTHESIZE(string, createMan, CreateMan);
	// ����ʱ��
	CC_SYNTHESIZE(string, updateDate, UpdateDate);
	// ������
	CC_SYNTHESIZE(string, updateMan, UpdateMan);
	// ����ʱ��
	CC_SYNTHESIZE(string, createDate, CreateDate);
	// �ڲ���֯������ʶ
	CC_SYNTHESIZE(string, orgId, OrgId);
	// ��λ����
	CC_SYNTHESIZE(string, gwType, GwType);
	// �Ƿ���ʱ����
	CC_SYNTHESIZE(string, isTemp, IsTemp);
	// �ⲿ��֯������ʶ
	CC_SYNTHESIZE(string, ormOrgId, OrmOrgId);
	// ��֯��������(���ݿ���ΪORGNAME,��������Ϊormorgname)
	CC_SYNTHESIZE(string, ormOrgName, OrmOrgName);
public:
	PostDetailDO() {
		xh = 0;
		gwfl = "";
		isConfidential = "";
		ormPostName = "";
		nx = 0;
		bxjlnx = 0;
		isKeyPostion = "";
		postNature = "";
		startStopSign = "";
		ormPostId = "";
		createMan = "";
		updateDate = "";
		updateMan = "";
		createDate = "";
		orgId = "";
		gwType = "";
		isTemp = "";
		ormOrgId = "";
		ormOrgName = "";
	}
};

#endif // !_POSTDETAIL_DO_
