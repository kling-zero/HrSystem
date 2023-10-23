#include "stdafx.h"
#include "TitleController.h"
#include "../../service/Title/TitleService.h"
// ��ҳ��ѯ����
TitlePageJsonVO::Wrapper TitleController::execQueryTitle(const TitleQuery::Wrapper& query, const PayloadDTO& payload)
{
    
     // ����һ��Service
    TitleService service;
    // ��ҳ��ѯ����
    auto result = service.listAll(query);
    // ������Ӧ����
    auto jvo = TitlePageJsonVO::createShared();
    // ��Ӧ���
   jvo->success(result);
    return jvo;
}

// ��������
Uint64JsonVO::Wrapper TitleController::execAddTitle(const TitleDTO::Wrapper& dto)
{
    // ���巵�����ݶ���
    auto jvo = Uint64JsonVO::createShared();
    // �ǿ�У��
	if (!dto->id || !dto->name || !dto->num )
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
    // ��ЧֵУ��
	if (dto->id < 0 || dto->name->empty() || dto->num->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	TitleService service;
	// ִ����������
	uint64_t id = service.saveData(dto);
    // ��Ӧ���
	
		jvo->success(UInt64(id));

    return jvo;
}

// �޸�����
Uint64JsonVO::Wrapper TitleController::execModifyTitle(const TitleDTO::Wrapper& dto)
{
    // ������Ӧ����
    auto jvo = Uint64JsonVO::createShared();
	if (!dto->id || dto->id <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	TitleService service;
	// ִ�������޸�
	service.updateData(dto);
		jvo->success(dto->id.getValue({}));

	
    // ��Ӧ���
    
    return jvo;
}

// ɾ������
Uint64JsonVO::Wrapper TitleController::execRemoveTitle(const TitleDTO_delete::Wrapper& dto)
{
    // ������Ӧ����
    auto jvo = Uint64JsonVO::createShared();
	if (!dto->id || dto->id <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	TitleService service;
	// ִ������ɾ��
	service.removeData(dto->id.getValue({}));
		jvo->success(dto->id.getValue({}));
	
	
    // ��Ӧ���
   
    return jvo;
}