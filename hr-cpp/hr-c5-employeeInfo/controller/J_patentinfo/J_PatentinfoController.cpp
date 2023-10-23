#include "stdafx.h"
#include "J_PatentinfoController.h"
#include "../../service/J_patentinfo/J_PatentService.h"


J_PatentinfoJsonVO::Wrapper J_PatentinfoController::execQueryPatentinfo(const String& str)
{
	// ����һ��Service
	PatentService service;
	// ��ѯ����
	auto result = service.listAll(str);
	//������Ӧ����
	auto vo = J_PatentinfoJsonVO::createShared();
	vo->success(result);
	return vo;
}



Uint64JsonVO::Wrapper J_PatentinfoController::execModifyPatentinfo(const ModifyPatentinfoDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	if (!dto->pimpatentid)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	PatentService service;
	// ִ�������޸�
	if (service.updateData(dto)) {
		jvo->success({});
	}
	else
	{
		jvo->fail({});
	}
	//jvo->success(dto->pimpatentid);
	return jvo;
}



