#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/05/17 19:42:46

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
#ifndef _PIMARMYCADRESDO_H_
#define _PIMARMYCADRESDO_H_
#include "../DoInclude.h"


class PimarmycadresDO {
	// ���
	CC_SYNTHESIZE(string, pimid, Pimid);
	//	����
	CC_SYNTHESIZE(string, form, Form);
	// ����
	CC_SYNTHESIZE(string, level, Level);
	// ����ʱ��
	CC_SYNTHESIZE(string, occurtime, Occurtime);
	//����·��
	CC_SYNTHESIZE(string, annexPath, AnnexPath);
	//��¼id
	CC_SYNTHESIZE(string, pimarmycadresid, Pimarmycadresid);




};



#endif