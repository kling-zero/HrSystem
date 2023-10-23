#pragma once
/*
 Copyright Zero One Star. All rights reserved.
 @Author: Andrew211vibe
 @Date: 2023/05/27 7:25:35

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
#ifndef _JOBSETSERVICE_H_
#define _JOBSETSERVICE_H_

#include "domain/vo/jobSet/ImportJobVO.h"
#include "domain/dto/jobSet/ImportJobDTO.h"
#include "domain/dto/addJob/AddJobDTO.h"

/**
 * ��Ŀ��ǩservice��ʵ��
 */
class JobSetService
{
public:
	/**
	 * ������Ŀ��ǩ������������
	 * �����ˣ�Andrew
	 */
	ImportJobVO::Wrapper addMultiJob(const ImportJobDTO::Wrapper &dto, const PayloadDTO &payload);
	/**
	 * ������Ŀ��ǩ
	 * �����ˣ�Andrew
	 */
	std::string saveJob(const AddJobDTO::Wrapper& dto, const PayloadDTO& payload);
};

#endif // !_JOBSETSERVICE_H_