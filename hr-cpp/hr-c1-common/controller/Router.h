#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/12/03 14:58:43

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
#ifndef _ROUTER_
#define _ROUTER_
#include "oatpp/web/server/api/Endpoint.hpp"
#include "oatpp/web/server/HttpRouter.hpp"
using namespace oatpp::web::server;
using namespace oatpp::web::server::api;

/**
 * ǰ�˷��ʷ�����·�ɰ󶨣����ڶ���ǰ�˷��ʺ�˽ӿںͷ���·����
 * swagger�ĵ�����ʾ����ַ��http://localhost:8090/swagger/ui
 */
class Router
{
private:
	// �ĵ����ʶ˵�
	Endpoints* docEndpoints;
	// ·�ɶ���
	HttpRouter* router;
public:
	// �����ʼ��
	Router(Endpoints* docEndpoints, HttpRouter* router);
	// ���г�ʼ��
	void initRouter();

private:

#ifdef HTTP_SERVER_DEMO
	// ������ʾ·��
	void createSampleRouter();

#endif
	/**
	 * �󶨵������ܵغ͵���״̬�����б�
	 * �����ˣ�Զ��
	 */
	void createFileReservationRouter();
	void createFileStatusRouter();
	/**
	 * ��֤�����ͺ�ְҵ�ʸ�֤�����������б�
	 * �����ˣ��׷�
	 */
	void creatTestRouter();

	/**
	 * �󶨺�ͬ����&��ת���������б�·��
	 * �����ˣ�Andrew
	 */
	void createTypeContractRouter();
	void createArmyLevelTypeRouter();
	void createContractStatusRouter();

	/**
	 * ��ְ�Ƶȼ�����&������������б�·��
	 * �����ˣ����֮��
	 */
	void createJobLevelTypeRouter();
	void createCostTypeRouter();

	/**
	 * �����Ҳ㼶&�걨���������б�
	 * �����ˣ���Ƥ�����
	 */
	void createDeclareRouter();
	void createArchivesLevelsRouter();

	/**
	 * �񽱵ȼ�&��λ��������б�
	 * �����ˣ�Ե��
	 */
	void createAwardLevelRouter();
	void createJobCategoryRouter();
	
	/**
	 * ����ְԭ��&��Ƹԭ�������б�
	 * �����ˣ�Զ��
	 */
	void createLeaveReasonRouter();
	void createDismissReasonRouter();
	//����״̬�����б�&�������������б�
	// �����ˣ����
	void createAuditStatusRouter();
	void createEvalutionTypesRouter();
};

#endif // !_ROUTER_
