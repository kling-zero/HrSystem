/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/12/03 14:58:34

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
#include "stdafx.h"
#include "Router.h"
#include "ApiHelper.h"
#ifdef HTTP_SERVER_DEMO
#include "user/UserController.h"
#include "sample/SampleController.h"
#include "uselib/ws/WSController.h"
#endif

// ��λ����
#include "jobSet/importJobController/ImportJobController.h"
#include "jobSet/postQueryController/PostQueryController.h"
#include "jobSet/postDeleteController/PostDeleteController.h"
#include "jobSet/jobOutput/JobOutputController.h"
#include "jobSet/jobUpdate/JobUpdateController.h"
#include "jobSet/addJobController/AddJobController.h"
// ��Ŀ��ǩ
#include "projTag/pageQueryProjTagList/PageQueryProjTagListController.h"
#include "projTag/deleteProjTag/DeleteProjTagController.h"
#include "projTag/exportProjTagController/ExportProjTagController.h"
#include "projTag/importTagController/ImportTagController.h"
#include "projTag/addTagController/AddTagController.h"
#include "projTag/modifyProjTagController/ModifyProjTagController.h"
#include "projTag/itemLabel/ItemLabelController.h"
#include "projTag/queryOrgList/QueryOrgListController.h"
//���Ʋ�ѯ
#include "orgbz/PageQueryBzController.h"

// ��������˹ر�Swagger�ĵ���
#ifdef CLOSE_SWAGGER_DOC
// �򻯰󶨿������궨��
#define ROUTER_SIMPLE_BIND(__CLASS__) \
router->addController(__CLASS__::createShared())
#else
// �򻯰󶨿������궨��
#define ROUTER_SIMPLE_BIND(__CLASS__) \
BIND_CONTROLLER(docEndpoints, router, __CLASS__)
#endif

Router::Router(Endpoints* docEndpoints, HttpRouter* router)
{
	this->docEndpoints = docEndpoints;
	this->router = router;
}

void Router::initRouter()
{
#ifdef HTTP_SERVER_DEMO
	createSampleRouter();
#endif

	//#TIP :ϵͳ��չ·�ɶ��壬д���������
	createJobSetRouter();
	createProjTagRouter();
	createBzRouter();
}

#ifdef HTTP_SERVER_DEMO
void Router::createSampleRouter()
{
	// ��ʾ��������
	ROUTER_SIMPLE_BIND(SampleController);
	// ���û�������
	ROUTER_SIMPLE_BIND(UserController);

	// ��WebSocket������
	router->addController(WSContorller::createShared());
}
#endif

void Router::createJobSetRouter()
{
	/**
	 * �����λ&������λ
	 * �����ˣ�Andrew
	 */
	ROUTER_SIMPLE_BIND(ImportJobController);
	ROUTER_SIMPLE_BIND(AddJobController);
	/**
	 * ��ѯָ����λ����&ɾ����λ
	 * �����ˣ��׷�
	 */
	ROUTER_SIMPLE_BIND(PostQueryController);
	ROUTER_SIMPLE_BIND(PostDeleteController);
	/**
	 * ���¸�λ&������λ
	 * �����ˣ���Ƥ�����
	 */
	ROUTER_SIMPLE_BIND(JobOutputController);
	ROUTER_SIMPLE_BIND(JobUpdateController);
}

void Router::createProjTagRouter()
{
	/**
	 * ������Ŀ��ǩ&������Ŀ��ǩ&��֯�б��ҳ��ѯ
	 * �����ˣ�Andrew
	 */
	ROUTER_SIMPLE_BIND(ExportProjTagController);
	ROUTER_SIMPLE_BIND(ModifyProjTagController);
	ROUTER_SIMPLE_BIND(QueryOrgListController);
	/**
	 * ������Ŀ��ǩ&������Ŀ��ǩ
	 * �����ˣ�Զ��
	 */
	ROUTER_SIMPLE_BIND(ImportTagController);
	ROUTER_SIMPLE_BIND(AddTagController);
	/**
	 * ��ҳ��ѯ��Ŀ��ǩ&ɾ����Ŀ��ǩ
	 * �����ˣ����֮��
	 */
	ROUTER_SIMPLE_BIND(PageQueryProjTagListController);
	ROUTER_SIMPLE_BIND(DeleteProjTagController);
	/**
	 * ��ѯָ����Ŀ��ǩ����
	 * �����ˣ�Ե��
	 */
	ROUTER_SIMPLE_BIND(ItemLabelController);
}

void Router::createBzRouter()
{
	/**
	 * ���Ʋ�ѯ
	 * �����ˣ�xubuxi
	 */
	ROUTER_SIMPLE_BIND(PageQueryBzController);
}
