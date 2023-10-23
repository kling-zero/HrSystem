#include "stdafx.h"
#include "J_PaperController.h"
#include "../../service/J_paperinfo/J_PaperService.h"

//�鿴ָ��Ա��������Ϣ��ָ��������Ϣ���飩
J_PaperinfoJsonVO::Wrapper J_PaperController::execSelectByPimpaperid(const String& str)
{
	// ����һ��Service
	PaperService service;
	// ��ѯ����
	auto result = service.listAll(str);
	//������Ӧ����
	auto vo = J_PaperinfoJsonVO::createShared();
	vo->success(result);
	return vo;
}

////�޸�ָ��Ա��������Ϣ�������޸ģ�
Uint64JsonVO::Wrapper J_PaperController::execModifyByPimpaperid(const ModifyPaperinfoDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	if (!dto->pimpaperid)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	 //����һ��Service
	PaperService service;
	 //ִ�������޸�
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

