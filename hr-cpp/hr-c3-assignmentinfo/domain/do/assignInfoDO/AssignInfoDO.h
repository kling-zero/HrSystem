#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: ahao
 @Date: 2023/5/26 11:52:32

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
#ifndef _ASSIGN_INFO_DO_
#define _ASSIGN_INFO_DO_
#include "../DoInclude.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class AssignInfoDO
{
	//������Ϣ��ʶ
	CC_SYNTHESIZE(string, assignId, AssignId);
	// ���
	CC_SYNTHESIZE(string, id, Id);
	// ����(�������η���)
	CC_SYNTHESIZE(string, assign, Assign);
	// ����״̬
	CC_SYNTHESIZE(string, assignState, AssignState);
	// ����
	CC_SYNTHESIZE(string, etype, Etype);
	// ��֯
	CC_SYNTHESIZE(string, organize, Organize);
	// ����
	CC_SYNTHESIZE(string, depart, Depart);
	// ְ��
	CC_SYNTHESIZE(string, job, Job);
	// ��λ
	CC_SYNTHESIZE(string, post, Post);
	// ��ְ��ʼʱ��
	CC_SYNTHESIZE(string, startTime, StartTime);
	// ��ְ����ʱ��
	CC_SYNTHESIZE(string, endTime, EndTime);
	//������
	CC_SYNTHESIZE(string, createMan, CreateMan);
	//����ʱ��
	CC_SYNTHESIZE(string, createDate, CreateDate);
	//������
	CC_SYNTHESIZE(string, updateMan, UpdateMan);
	//����ʱ��
	CC_SYNTHESIZE(string, updateDate, UpdateDate);

public:
	AssignInfoDO() {
		assignId = "";
		id = "";
		assign = "";
		assignState = "";
		etype = "";
		organize = "";
		depart = "";
		job = "";
		post = "";
		startTime = "";
		endTime = "";
		createMan = "";
		createDate = "";
		updateMan = "";
		updateDate = "";
	}
};

#endif // !_Assign_Info_DO_