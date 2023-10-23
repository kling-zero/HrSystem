#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:52:32

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
#ifndef _SCIRESULT_DO_
#define _SCIRESULT_DO_
#include "../DoInclude.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class SciResultDO
{
	    //������
	CC_SYNTHESIZE(string, UPDATEMAN, _UPDATEMAN);

		//���гɹ�����
	CC_SYNTHESIZE(string, PIMRESEARCHFINDINGSNAME, _PIMRESEARCHFINDINGSNAME);
		//����
	CC_SYNTHESIZE(string, FJ, _FJ);
		//ENABLE
	CC_SYNTHESIZE(string, ENABLE, _ENABLE);
		//����ʱ��
	CC_SYNTHESIZE(string, CREATEDATE, _CREATEDATE);
		//����ʱ��
	CC_SYNTHESIZE(string, UPDATEDATE, _UPDATEDATE);
		//������
	CC_SYNTHESIZE(string, CREATEMAN, _CREATEMAN);
		//���гɹ���ʶ
	CC_SYNTHESIZE(string, PIMRESEARCHFINDINGSID, _PIMRESEARCHFINDINGSID);
		//��Ա��Ϣ��ʶ
	CC_SYNTHESIZE(string, PIMPERSONID, _PIMPERSONID);
		//��ȡʱ��
	CC_SYNTHESIZE(string, HQSJ, _HQSJ);
		//��¼����
	CC_SYNTHESIZE(string, JLSS, _JLSS);
		//����״̬
	CC_SYNTHESIZE(string, JLSPZT, _JLSPZT);
		//��¼������
	CC_SYNTHESIZE(string, JLGLBH, _JLGLBH);
		//��¼������
	CC_SYNTHESIZE(string, JLCZZ, _JLCZZ);
		//�ܾ�ԭ��
	CC_SYNTHESIZE(string, REASON, _REASON); 
public:
	SciResultDO() = default;

	SciResultDO(std::vector<std::string> vec)
	{
		//�޸�
		int i = 0;
		set_PIMRESEARCHFINDINGSNAME(vec[i++]);
		set_HQSJ(vec[i++]);
		set_FJ(vec[i++]);
	}

};

#endif // !_SAMPLE_DO_
