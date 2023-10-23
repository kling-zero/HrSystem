#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: yuanxiang
 @Date: 2023/05/23 17:06:40

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
#ifndef _PROJTAGDAO_H_
#define _PROJTAGDAO_H_
#include "BaseDAO.h"
#include "domain/do/projTag/ProjTagDO.h"
#include "domain/do/projTag/OrgListDO.h"
#include "domain/query/projTag/OrgListQuery.h"
#include "domain/query/projTag/ExportProjTagQuery.h"
#include "domain/query/projTag/PageProjTagQuery.h"

/**
 * ��Ŀ��ǩDAOʵ��
 */
class ProjTagDAO : public BaseDAO
{
public:
	/**
	 * ��Ŀ��ǩ - ������Ŀ��ǩDAOʵ��
	 * �����ˣ�Զ��
	 */
	bool insert(const ProjTagDO& iObj);
	/**
	 * ��Ŀ��ǩ - ��ҳ��ѯ��֯�б�DAOʵ��
	 * ���ܣ���ѯ��֯�б��������ݷ�ҳ
	 * �����ˣ�Andrew
	 */
	std::list<OrgListDO> selectOrgList(const OrgListQuery::Wrapper& query);
	/**
	 * ��Ŀ��ǩ - ��ҳ��ѯ��֯�б�DAOʵ��
	 * ���ܣ�������������
	 * �����ˣ�Andrew
	 */
	uint64_t count(const OrgListQuery::Wrapper& query);
	/**
	 * ��Ŀ��ǩ - �޸���Ŀ��ǩDAOʵ��
	 * ���ܣ�����ָ����Ŀ��ǩΨһ��ʶ������Ŀ��ǩ����
	 * �����ˣ�Andrew
	 */
	bool updateProjTag(const ProjTagDO& data);

	/**
	 * ��Ŀ��ǩ - ������Ŀ��ǩDAOʵ��
	 * ���ܣ����ļ��е����ݵ��뵽���ݿ���
	 * �����ˣ�Զ��
	 */
	std::list<std::string> insertMultiTag(const std::list<ProjTagDO>& data);
	/**
	 * ��Ŀ��ǩ - ������Ŀ��ǩDAOʵ��
	 * ���ܣ���ѯ���5000�����ݵ�DO������
	 * �����ˣ�Andrew
	 */
	std::list<ProjTagDO> exportProjTag(const ExportProjTagQuery::Wrapper& query);
	/**
	 * ��Ŀ��ǩ - ��ҳ��ѯ��Ŀ��ǩ�б�DAOʵ��
	 * ���ܣ�������������
	 * �����ˣ����֮��
	 */
	uint64_t count(const PageProjTagQuery::Wrapper& query);
	/**
	 * ��Ŀ��ǩ - ��ҳ��ѯ��Ŀ��ǩ�б�DAOʵ��
	 * ���ܣ���ѯ��Ŀ��ǩ�б��������ݷ�ҳ
	 * �����ˣ����֮��
	 */
	std::list<ProjTagDO> selectProjTag(const PageProjTagQuery::Wrapper& query);
	/**
	 * ��ȡ��Ŀ��ǩ��ͷ
	 * �����ˣ�Andrew
	 */
	vector<std::string> getHead();
};

#endif // !_PROJTAGDAO_H_