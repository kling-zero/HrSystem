#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: rice
 @Date: 2023/5/23 18:08:32

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
#ifndef _CERTTYPE_DO_
#define _CERTTYPE_DO_
#include "../DoInclude.h"

/**
 * ֤�����������б��ѯDO
 * �����ˣ��׷�
 */
class CertTypeDO
{
	// ֤������ID
	CC_SYNTHESIZE(string, certTypeId, CertTypeId);
	// ֤����������
	CC_SYNTHESIZE(string, certTypeName, CertTypeName);
	// ֤�����ʹ���
	CC_SYNTHESIZE(string, certTypeCode, CertTypeCode);
	// ֤�������Ƿ���Ч (0��Ч, 1��Ч)
	CC_SYNTHESIZE(bool, certTypeValidity, CertTypeValidity);

public:
	CertTypeDO() {
		certTypeId = "";
		certTypeName = "";
		certTypeCode = "";
		certTypeValidity = 1;
	}
};

#endif // !_CERTTYPE_DO_
