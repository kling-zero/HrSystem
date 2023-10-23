#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 14:21:55

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
#ifndef _SAMPLE_MAPPER_
#define _SAMPLE_MAPPER_

#include "Mapper.h"
#include "domain/do/RosterOfPer/RraineeDO.h"

/**
 * ʾ�����ֶ�ƥ��ӳ��
 */
class RraineeMapper : public Mapper<RraineeDO>
{
public:
	RraineeDO mapper(ResultSet* resultSet) const override
	{
		RraineeDO data;
		data.setYgbh(resultSet->getString(1));
		data.setPcmjxszzkhjgjlname(resultSet->getString(2));
		data.setZz(resultSet->getString(3));
		data.setBm(resultSet->getString(4));
		data.setZw(resultSet->getString(5));
		data.setGw(resultSet->getString(6));
		data.setDuration(resultSet->getString(7));
		data.setKsrq(resultSet->getString(8));
		data.setJsrq(resultSet->getString(9));
		return data;
	}
};

/*
RraineeMapper��������ǽ�ResultSet�����е�����ӳ�䵽RraineeDO�����С�ResultSetͨ�����ڱ�ʾ�����ݿ��м������Ľ������
mapper��������һ��ResultSet*��������ָ��ResultSet�����ָ�룬������һ��RraineeDO����
��mapper�����У����ȴ���һ��RraineeDO����data��Ȼ��ͨ������resultSet����ĸ��ַ�������getUInt64��getString��getInt��
��ȡ������еľ������ݣ���ʹ��data�������Ӧsetter��������setId��setName��setSex��setAge�����������õ�RraineeDO�����С�
��󣬽����õ�RraineeDO���󷵻ء�
��δ���չʾ��һ�ֳ���������ӳ��ģʽ�����ڽ����ݿ��ѯ���ӳ�䵽�Զ�������ݶ����С�
*/
#endif // !_SAMPLE_MAPPER_