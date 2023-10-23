#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: yuanxiang
 @Date: 2023/05/23 17:01:55

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
#ifndef _PROJTAGSERVICE_H_
#define _PROJTAGSERVICE_H_
#include "domain/dto/projTag/ProjTagDTO.h"
#include "domain/dto/projTag/OrgListDTO.h"
#include "domain/query/projTag/OrgListQuery.h"
#include "domain/query/projTag/PageProjTagQuery.h"
#include "domain/dto/projTag/ModifyTagDTO.h"
#include "domain/vo/projTag/ProjTagVO.h"
#include "domain/dto/projTag/ImportTagDTO.h"
#include "domain/vo/projTag/ImportTagVO.h"
#include "domain/query/projTag/ExportProjTagQuery.h"
#include "domain/do/projTag/ProjTagDO.h"
/**
 * ��Ŀ��ǩService
 */
class ProjTagService
{
public:
	/**
	 * ������Ŀ��ǩ
	 * ����ֵ��
	 *	�ɹ�����Ŀ��ǩid
	 *  ʧ�ܣ�-1
	 * �����ˣ�Զ��
	 */
	string saveData(ProjTagDO& data);
	/**
	 * ��ҳ��ѯ��֯�б�
	 * �����ˣ�Andrew
	 */
	OrgListPageDTO::Wrapper listOrgList(const OrgListQuery::Wrapper &query);
	/**
	 * �޸���Ŀ��ǩ
	 * �����ˣ�Andrew
	 */
	bool updateProjTag(const ModifyTagDTO::Wrapper& dto, const PayloadDTO& payload);

	/**
	 * ������Ŀ��ǩ������������5000ʱ��ֻ����<=5000������
	 * ����ֵ��
	 *	�ɹ���������Ŀid�б�
	 *  ʧ��: -2�����ݲ��������ݿ�����
	 * �����ˣ�Զ��
	 */
	ImportTagVO::Wrapper addMultiTag(const ImportTagDTO::Wrapper& dto, const PayloadDTO& payload);
	/**
	 * ������Ŀ��ǩ�����5000����
	 * ����DAO��ѯ���ݿ⣬���غ��װ��Excel�ļ������浽FastDFS�ļ�������
	 * ����ֵ���ļ�������ƴ����������
	 * �����ˣ�Andrew
	 */
	std::string exportProjTag(const ExportProjTagQuery::Wrapper& query);
	/**
	 * ��ҳ��ѯ��Ŀ��ǩ
	 * �����ˣ����֮��
	 */
	ProjTagPageDTO::Wrapper listProjTagList(const PageProjTagQuery::Wrapper& query);
};

#endif // !_PROJTAGSERVICE_H_
