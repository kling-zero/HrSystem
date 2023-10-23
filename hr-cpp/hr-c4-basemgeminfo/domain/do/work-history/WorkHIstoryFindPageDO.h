#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: huilai
 @Date: 2023/05/18 8:59:52

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
#ifndef _WORKHISTORYFINDPAGEDO_H_
#define _WORKHISTORYFINDPAGEDO_H_


#include "../DoInclude.h"

class WorkHistoryFindDO
{
	//1��ְ��ʼʱ��
	CC_SYNTHESIZE(std::string, RZKSSJ, rZKSSJ);

	//2��ְ����ʱ��
	CC_SYNTHESIZE(std::string, RZJSSJ, rZJSSJ);

	//3������λ
	CC_SYNTHESIZE(std::string, ORMORGNAME, oRMORGNAME);

	//4����
	CC_SYNTHESIZE(std::string, ORMORGSECTORNAME, oRMORGSECTORNAME);

	//5ְλ
	CC_SYNTHESIZE(std::string, ORMDUTYNAME, oRMDUTYNAME);

	//6��λ
	CC_SYNTHESIZE(std::string, ORMPOSTNAME, oRMPOSTNAME);

	//7��ְ�������
	CC_SYNTHESIZE(std::string, CFPLX, cFPLX);

	//8�Ƿ���Ҫ����
	CC_SYNTHESIZE(uint64_t, EXPERIENCE, eXPERIENCE);

	//9������������id
	CC_SYNTHESIZE(std::string, PIMWORKHISTORYID, pIMWORKHISTORYID);

	//10��Ա��Ϣid
	CC_SYNTHESIZE(std::string, PIMPERSONID, pIMPERSONID);

public:
	std::vector<std::string> WorkHistoryToVector()
	{
		std::vector<std::string> vecStr{ this->getrZKSSJ(), this->getrZJSSJ(),\
			this->getoRMORGNAME(), this->getoRMORGSECTORNAME(),this->getoRMDUTYNAME(),\
			this->getoRMPOSTNAME(), this->getcFPLX(), to_string(this->geteXPERIENCE()) };

		return vecStr;
	}

};

#endif // !_WORKHISTORYFINDPAGEDO_H__