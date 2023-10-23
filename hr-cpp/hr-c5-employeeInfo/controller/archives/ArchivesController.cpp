#include "stdafx.h"
#include "ArchivesController.h"


ArchivesPageJsonVO::Wrapper ArchivesController::execQueryArchivesInfo(const ArchivesQuery::Wrapper& query, const PayloadDTO& payload)
{
	ArchivesService service;
	auto result = service.getAll(query);
	auto jvo = ArchivesPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

ArchivesPageJsonVO::Wrapper ArchivesController::execQueryPageArchivesInfo(const ArchivesQuery::Wrapper& query)
{
	// ����һ��Service
	ArchivesService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = ArchivesPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

Uint64JsonVO::Wrapper ArchivesController::execAddArchivesInfo(const ArchivesDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	// ��ЧֵУ��
	if (dto->dabh->empty()               || dto->orMorGId3->empty()     || dto->dabgd->empty()       ||
		dto->archivesCenterId->empty() || dto->dazt->empty()        || dto->ygbh->empty()        ||
		dto->pimPersonId->empty()      || dto->ygzt->empty()        || dto->ormOrgName->empty()  ||
		!dto->zt || !dto->education || !dto->dateOfBirth || !dto->joinPartyDate || !dto->startWorkDatae)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	ArchivesService service;
	// ִ����������
	uint64_t id = service.saveData(dto);
	if (id > 0) {
		jvo->success(UInt64(id));
	}
	else
	{
		jvo->fail(UInt64(id));
	}
	return jvo;
}

Uint64JsonVO::Wrapper ArchivesController::execRemoveArchivesInfo(const ArchivesDelDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	for (auto id = dto->deleteById->begin(); id != dto->deleteById->end(); ++id)
	{
		if (!*id) {
			jvo->init(UInt64(-1), RS_PARAMS_INVALID);
			return jvo;
		}
	}
	// ����һ��Service
	ArchivesService service;
	// ִ������ɾ��
	if (service.removeData(dto)) {
		jvo->success(1);
	}
	else
	{
		jvo->fail(-1);
	}
	return jvo;
}