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
#include "sciresult/SciResultController.h"
#include "work-history/WorkHistoryController.h"
#include "certificate-information/CertificateInformationController.h"
#include"contract/ContractController.h"
#include "jobtitle-information/JobTitleInformationController.h"
#include"military/MilitaryController.h"
#include "work-history/WorkHistoryController.h"
#include "controller/pimarmycadres/PimarmycadresController.h"
#include "controller/rewardandpunish/RewardAndPunishController.h"
#include "rewardandpunishmentinformation/RewardAndPunishmentInformationController.h"
#include "archives/ArchivesController.h"
#include "scientific/ScientificController.h"
#include "trainingrecord/TrainingRecordController.h"



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
//#ifdef HTTP_SERVER_DEMO
//	createSampleRouter();
//#endif

	//#TIP :ϵͳ��չ·�ɶ��壬д���������
	ROUTER_SIMPLE_BIND(SciResultController);
	//�������гɹ�Controller�͵�����ϢController
	ROUTER_SIMPLE_BIND(ArchivesController);
	ROUTER_SIMPLE_BIND(ScientificController);
	ROUTER_SIMPLE_BIND(PimarmycadresController);

	//#TIP :ϵͳ��չ·�ɶ��壬д���������
	//��·�ɣ�����������
	ROUTER_SIMPLE_BIND(CertificateInformationController);
	ROUTER_SIMPLE_BIND(JobTitleInformationController);
	ROUTER_SIMPLE_BIND(WorkHistoryController);

	// ��ContractController
	ROUTER_SIMPLE_BIND(ContractController);
	// ��MilitaryController
	ROUTER_SIMPLE_BIND(MilitaryController);
	//��RewardAndPunishController
	ROUTER_SIMPLE_BIND(RewardAndPunishController);
	//��TrainingRecordController
	ROUTER_SIMPLE_BIND(TrainingRecordController);
	ROUTER_SIMPLE_BIND(RewardAndPunishmentInformationController);
}



//#ifdef HTTP_SERVER_DEMO
//void Router::createSampleRouter()
//{
//	// �󶨿�����
//	ROUTER_SIMPLE_BIND(CertificateInformationController);
//	// �󶨿�����
//	ROUTER_SIMPLE_BIND(JobTitleInformationController);
//	// �󶨿�����
//	ROUTER_SIMPLE_BIND(WorkHistoryController);
//
//	// ��WebSocket������
//	router->addController(WSContorller::createShared());
//}
//#endif
