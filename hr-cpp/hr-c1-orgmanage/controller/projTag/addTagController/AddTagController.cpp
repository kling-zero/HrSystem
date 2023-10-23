#include "stdafx.h"
#include "AddTagController.h"
#include "service/projTag/ProjTagService.h"
#include "SimpleDateTimeFormat.h"
#include "domain/do/projTag/ProjTagDO.h"
StringJsonVO::Wrapper AddTagController::execAddProjTag(const AddProjTagDTO::Wrapper& dto, const PayloadDTO& payload)
{
	auto jvo = StringJsonVO::createShared();

	// У��dto����
	// ����У��
	// ������֯��ʶ�Ƿ�Ϊ��
	if (!dto->ormorgid)
	{
		jvo->init("-1", RS_PARAMS_INVALID);
		return jvo;
	}
	
	// ��ЧֵУ��
	
	ProjTagDO data;
	string time = SimpleDateTimeFormat::format();
	string name = payload.getUsername();
	// ����DO����
	data.setCreateTime(time);
	data.setUpdateTime(time);
	data.setCreator(name);
	data.setUpdater(name);
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto,
		TagName, ormxmbqname,
		OrgId, ormorgid);
	// ����һ��service
	ProjTagService service;

	// ִ���������� 
	// ִ�гɹ��󷵻���Ŀ��ǩidֵ
	String id = service.saveData(data);

	//��Ӧ���
	if (id != "-1")
	{
		jvo->init(id, RS_SUCCESS);
	}
	else
	{
		jvo->init(id, RS_FAIL);
	}
	return jvo;
}
