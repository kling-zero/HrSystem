#include "stdafx.h"
#include "ArchiveController.h"
#include"../../service/archive/ArchiveService.h"

// ��ҳ��ѯ����
ArchivePageJsonVO::Wrapper ArchiveController::execQueryArchive(const ArchiveQuery::Wrapper& query, const PayloadDTO& payload)
{
    // ����һ��Service
    ArchiveService service;
    // ��ѯ����
    auto result = service.listAll(query);
    // ��Ӧ���
    auto jvo = ArchivePageJsonVO::createShared();
    jvo->success(result);
    return jvo;
}

// ��������
Uint64JsonVO::Wrapper ArchiveController::execAddArchive(const ArchiveDTO::Wrapper& dto)
{
   
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	// �ǿ�У��
	if (!dto->sortid || !dto->archivename || !dto->cabinetnum||!dto->layernum||!dto->numid)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	//// ��ЧֵУ��
	if (dto->sortid<0 || dto->archivename->empty() || dto->cabinetnum<0 || dto->layernum<0 || dto->numid<0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// ����һ��Service
	ArchiveService service;
	// ִ����������
	uint64_t id = service.saveData(dto);
	jvo->success(UInt64(id));
	
	return jvo;
}
// �޸�����
Uint64JsonVO::Wrapper ArchiveController::execModifyArchive(const ArchiveDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	if (!dto->sortid || dto->sortid <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	ArchiveService service;
	service.updateData(dto);
	jvo->success(dto->sortid);
	return jvo;
}

// ɾ������
Uint64JsonVO::Wrapper ArchiveController::execRemoveArchive(const ArchiveDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	if (!dto->sortid || dto->sortid <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	ArchiveService service;
	// ִ������ɾ��
	service.removeData(dto->sortid.getValue(0));
	jvo->success(dto->sortid);

	// ��Ӧ���
	return jvo;
}