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
#include "LegalEntityMai/LegalEntityMaiController.h"
#include "LegalEntitySet/LegalEntitySetController.h"
#include "LegalEntitySet/DeleteLegalEntityController.h"

#include "LegalEntitySet/ImportLeagalPerSettingController.h"

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
	//#TIP :ϵͳ��չ·�ɶ��壬д���������
	ROUTER_SIMPLE_BIND(LegalEntityMaiController);//��������ά�����������--����֯����-��������-��������ά����--TripleGold
	ROUTER_SIMPLE_BIND(DeleteLegalEntityController);//������������--ɾ����������(֧������ɾ��)--pine
	ROUTER_SIMPLE_BIND(ImportLeagalPerSettingController);//(������������-���뷨������)--����
	ROUTER_SIMPLE_BIND(LegalEntitySetController);//������������  -- cpt
}