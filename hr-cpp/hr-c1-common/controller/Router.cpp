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

//����
#include "auditStatus/AuditStatusController.h"
#include "certDropDownList/profCertsList/ProfCertsListController.h"
#include "certDropDownList/certTypeList/CertTypeListController.h"
#include "contractType/ContractTypeController.h"
#include "armyLevelType/ArmyLevelTypeController.h"
#include "fileStatus/FileStatusController.h"
#include "fileReservation/FileReservationController.h"
#include "jobLevelTypeList/JobLevelTypeListController.h"
#include "costTypeList/CostTypeListController.h"
#include "declareType/DeclareController.h"
#include "archivesLevel/ArchivesLevelsController.h"
#include "leaveReason/LeaveReasonController.h"
#include "dismissReason/DismissReasonController.h"
#include "awardLevel/AwardLevelController.h"
#include "jobCategory/JobCategoryController.h"
#include "typeContract/TypeContractListController.h"
#include "evaluationTypes/EvaluationTypesController.h"
#include "contractStatus/ContractStatusController.h"

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
	createAwardLevelRouter();
	createJobCategoryRouter();
	createTypeContractRouter();
	createArmyLevelTypeRouter();
	creatTestRouter();
	createJobLevelTypeRouter();
	createCostTypeRouter();
	createDeclareRouter();
	createArchivesLevelsRouter();
	createFileReservationRouter();
	createFileStatusRouter();
	createLeaveReasonRouter();
	createDismissReasonRouter();
	createAuditStatusRouter();
	createEvalutionTypesRouter();
	createContractStatusRouter();
	// ��ͬ���ӿ�
	// �����ˣ��첻ϴ
	ROUTER_SIMPLE_BIND(ContractTypeController);
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

void Router::createDeclareRouter() {
	ROUTER_SIMPLE_BIND(DeclareController);
}

void Router::createArchivesLevelsRouter() {
	ROUTER_SIMPLE_BIND(ArchivesLevelsController);
}

void Router::createLeaveReasonRouter()
{
	ROUTER_SIMPLE_BIND(LeaveReasonController);
}

void Router::createDismissReasonRouter()
{
	ROUTER_SIMPLE_BIND(DismissReasonController);
}

void Router::createFileReservationRouter()
{
	ROUTER_SIMPLE_BIND(FileReservationController);
}

void Router::createFileStatusRouter()
{
	ROUTER_SIMPLE_BIND(FileStatusController);
}

void Router::creatTestRouter()
{
	// ��ְҵ�ʸ�֤�����������б������
	ROUTER_SIMPLE_BIND(ProfCertsListController);
	ROUTER_SIMPLE_BIND(CertTypeListController);
}

void Router::createTypeContractRouter()
{
	ROUTER_SIMPLE_BIND(TypeContractListController);
}

void Router::createArmyLevelTypeRouter()
{
	ROUTER_SIMPLE_BIND(ArmyLevelTypeController);
}

void Router::createContractStatusRouter()
{
	ROUTER_SIMPLE_BIND(ConstractStatusController);
}

void Router::createJobLevelTypeRouter()
{
	ROUTER_SIMPLE_BIND(JobLevelTypeListController);
}

void Router::createCostTypeRouter()
{
	ROUTER_SIMPLE_BIND(CostTypeListController);
}

void Router::createAwardLevelRouter()
{
	ROUTER_SIMPLE_BIND(AwardLevelController);
}

void Router::createJobCategoryRouter()
{
	ROUTER_SIMPLE_BIND(JobCategoryController);
}
void Router::createAuditStatusRouter()
{
	ROUTER_SIMPLE_BIND(AuditStatusController);
}

void  Router::createEvalutionTypesRouter()
{
	ROUTER_SIMPLE_BIND(EvaluationTypesController);
}