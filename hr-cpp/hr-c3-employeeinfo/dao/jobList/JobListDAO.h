#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Detachment
 @Date: 2023/05/29 21:41:08

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
#ifndef _JOBLISTDAO_H_
#define _JOBLISTDAO_H_
#include "BaseDAO.h"
#include "../../domain/do/jobList/JobListDO.h"
#include "JobListMapper.h"
#include "../../domain/query/jobList/JobListQuery.h"

/* *
* ��λ��Ϣ
* ִ���ˣ�Detachment
*/
class JobListDAO : public BaseDAO
{
public:
	/* *
	* ͳ�Ʒ�ҳ����
	* ִ���ˣ�Detachment
	*/
	uint64_t count(const JobListQuery::Wrapper& query);
	/* *
	* ��ҳ��ѯ��λ�б�
	* ִ���ˣ�Detachment
	*/
	list<JobListDO> selectJobList(const JobListQuery::Wrapper& query);
};

#endif // !_JOBLISTDAO_H_