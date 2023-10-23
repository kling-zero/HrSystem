/*
 Copyright Zero One Star. All rights reserved.

 @Author: mengHuan
 @Date: 2023/05/15 15:32:21

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
#include "LaborDispatchConstroller.h"
#include "service/laborDispatch/LaborDispatchService-mh.h"




LaborDispatchPageJsonVO::Wrapper LaborDispatchConstroller::executeQueryAll_ld(const LaborDispatchQuery::Wrapper& query)
{
	//����һ��Service
	LaborDispatchService service;
	//��ѯ����
	auto result = service.listAll_ld(query);
	//��Ӧ���
	auto jvo = LaborDispatchPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

Uint64JsonVO::Wrapper LaborDispatchConstroller::execAddLaborDispatch_ld(const LaborDispatchModifyDTO::Wrapper& dto)
{
	auto vo = Uint64JsonVO::createShared();
	//����У��
	//1.�ǿ�У��
	if (!dto->name || !dto->unit ) {
		vo->init(UInt64(-1), RS_PARAMS_INVALID);
		return vo;
	}
	//2.��ЧֵУ��
	if (dto->name->empty() || dto->unit->empty() ) {
		vo->init(UInt64(-1), RS_PARAMS_INVALID);
		return vo;
	}
	//��һ��Service
	LaborDispatchService service;
	//ִ����������
	uint64_t id = service.saveData_ld(dto);
	if (id > 0) {
		vo->success(UInt64(id));
	}
	else {
		vo->fail(UInt64(id));
	}
	return vo;
}

StringJsonVO::Wrapper LaborDispatchConstroller::execRemoveLaborDispatch_ld(const LaborDispatchRemoveDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto vo = StringJsonVO::createShared();
	// ����У��
	if (!dto->id || dto->id->empty())
	{
		vo->fail("parameter is empty");
		return vo;
	}
	// ����һ��Service
	LaborDispatchService service;
	// ִ������ɾ��
	auto it = dto->id->begin();
	while (it != dto->id->end()) {
		if (service.removeData_ld(it->getValue(""))) {
			vo->success("delete success");
		}
		else
		{
			vo->fail("delete fail");
		}
		it++;
	}
	return vo;
}

StringJsonVO::Wrapper LaborDispatchConstroller::execExportLaborDispatch_ld(const LaborDispatchQuery::Wrapper& query, const LaborDispatchExportDTO::Wrapper& dto)
{
	//���巵�����ݶ���
	auto vo = StringJsonVO::createShared();
	LaborDispatchService service;
	string filedName = service.LaborDispatchExport_ld(query,dto);
	//��Ӧ���
	if (filedName.empty()) {
		vo->fail("export failed!");
	}
	else {
		vo->success(filedName);
	}
	return vo;
}

