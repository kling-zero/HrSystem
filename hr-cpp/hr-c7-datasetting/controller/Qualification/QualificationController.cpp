#include "stdafx.h"
#include "QualificationController.h"
#include"../../service/Qualification/QualificationService.h"

// ��ҳ��ѯ����
QualificationPageJsonVO::Wrapper QualificationController::execQueryQualification(const QualificationQuery::Wrapper& query, const PayloadDTO& payload)
{
	// ����һ��Service
	QualificationService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = QualificationPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

// ��������
Uint64JsonVO::Wrapper QualificationController::execAddQualification(const QualificationDTO::Wrapper& dto)
{

	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	// �ǿ�У��
	if (!dto->pimqualmajorid || !dto->qualevel || !dto->pimqualmajorname || !dto->quamajor)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	//// ��ЧֵУ��
	if (dto->pimqualmajorid->empty() || dto->qualevel->empty() || dto->pimqualmajorname->empty() || dto->quamajor->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// ����һ��Service
	QualificationService service;
	// ִ����������
	uint64_t id = service.saveData(dto);
	jvo->success(UInt64(id));

	return jvo;
}

// �޸�����
Uint64JsonVO::Wrapper QualificationController::execModifyQualification(const QualificationDTO::Wrapper& dto)
{
	// ���巵�����ݶ���

	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	if (!dto->pimqualmajorid || !dto->qualevel || !dto->pimqualmajorname || !dto->quamajor)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	QualificationService service;
	service.updateData(dto);
	jvo->success(dto->pimqualmajorid || dto->qualevel || dto->pimqualmajorname || dto->quamajor);
	return jvo;
}

 //ɾ������
Uint64JsonVO::Wrapper QualificationController::execRemoveQualification(const QualificationDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();

	// ��Ӧ���
	return jvo;
}

//Uint64JsonVO::Wrapper QualificationController::execRemoveQualification(const QualificationDTO::Wrapper& dto)
//{
//	// ���巵�����ݶ���
//	auto jvo = Uint64JsonVO::createShared();
//	// ����У��
//	if (!dto->pimqualmajorid || !dto->qualevel || !dto->pimqualmajorname || !dto->quamajor)
//	{
//		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
//		return jvo;
//	}
//	// ����һ��Service
//	QualificationService service;
//	// ִ������ɾ��
//	service.removeData(dto->pimqualmajorid.getValue(""));
//	jvo->success(dto->pimqualmajorid);
//
//	// ��Ӧ���
//	return jvo;
//}




























//#include "stdafx.h"
//#include "QualificationController.h"
//
//QualificationPageJsonVO::Wrapper QualificationController::executeQueryAll_ld(const QualificationQuery::Wrapper& query)
//{
//	//����һ��Service
//	QualificationService service;
//	//��ѯ����
//	auto result = service.listAll_ld(query);
//	//��Ӧ���
//	auto jvo = QualificationPageJsonVO::createShared();
//	jvo->success(result);
//	return jvo;
//}
//
//Uint64JsonVO::Wrapper QualificationConstroller::execAddQualification_ld(const QualificationDTO::Wrapper& dto)
//{
//	auto vo = Uint64JsonVO::createShared();
//	//����У��
//	//1.�ǿ�У��
//	if (!dto->name || !dto->id || !dto->pimpersonid || !dto->ormorgid) {
//		vo->init(UInt64(-1), RS_PARAMS_INVALID);
//		return vo;
//	}
//	//2.��ЧֵУ��
//	if (dto->name->empty() || dto->id->empty() || dto->pimpersonid->empty() || dto->ormorgid->empty()) {
//		vo->init(UInt64(-1), RS_PARAMS_INVALID);
//		return vo;
//	}
//	//��һ��Service
//	QualificationService service;
//	//ִ����������
//	uint64_t id = service.saveData_ld(dto);
//	if (id > 0) {
//		vo->success(UInt64(id));
//	}
//	else {
//		vo->fail(UInt64(id));
//	}
//	return vo;
//}
//
//StringJsonVO::Wrapper QualificationConstroller::execRemoveQualification_ld(const QualificationRemoveDTO::Wrapper& dto)
//{
//	// ���巵�����ݶ���
//	auto vo = StringJsonVO::createShared();
//	// ����У��
//	if (!dto->id || dto->id->empty())
//	{
//		vo->fail("parameter is empty");
//		return vo;
//	}
//	// ����һ��Service
//	QualificationService service;
//	// ִ������ɾ��
//	auto it = dto->id->begin();
//	while (it != dto->id->end()) {
//		if (service.removeData_ld(it->getValue(""))) {
//			vo->success("delete success");
//		}
//		else
//		{
//			vo->fail("delete fail");
//		}
//		it++;
//	}
//	return vo;
//}