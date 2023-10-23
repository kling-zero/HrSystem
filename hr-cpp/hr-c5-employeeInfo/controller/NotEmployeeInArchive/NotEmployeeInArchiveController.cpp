#include "stdafx.h"
#include "NotEmployeeInArchiveController.h"

NotEmployeeInArchivePageJsonVO::Wrapper NotEmployeeInArchiveController::execQueryNotEmployeeInArchive(const NotEmployeeInArchiveQuery::Wrapper& query, const PayloadDTO& payload){
	// ������Ӧ����
	auto vo = NotEmployeeInArchivePageJsonVO::createShared();
	// ������ҳ����
	auto adto = NotEmployeeInArchivePageDTO::createShared();
	adto->addData(NotEmployeeInArchiveDTO::createShared());
	adto->addData(NotEmployeeInArchiveDTO::createShared());
	// ��Ӧ���
	vo->success(adto);
	return vo;
}

Uint64JsonVO::Wrapper NotEmployeeInArchiveController::execModifyNotEmployeeInArchive(const NotEmployeeInArchiveDTO::Wrapper& dto){
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	return jvo;
}