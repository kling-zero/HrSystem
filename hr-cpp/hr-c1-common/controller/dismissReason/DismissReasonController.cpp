
#include "stdafx.h"
#include "DismissReasonController.h"
#include "service/leaveAndDismissReason/LeaveAndDismissReasonService.h"

PullListVO::Wrapper DismissReasonController::execQueryDismissReason()
{
	// ���巵�����ݶ���
	auto jvo = PullListVO::createShared();
	LeaveAndDismissReasonService service;
	auto dto = service.listAll();
	// �����ɹ���Ϣ
	jvo->success(dto);
	return jvo;
}
