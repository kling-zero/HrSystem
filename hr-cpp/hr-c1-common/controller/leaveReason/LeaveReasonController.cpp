
#include "stdafx.h"
#include "LeaveReasonController.h"
#include "service/leaveAndDismissReason/LeaveAndDismissReasonService.h"


PullListVO::Wrapper LeaveReasonController::execQueryLeaveReason()
{
	// ���巵�����ݶ���
	auto jvo = PullListVO::createShared();
	
	LeaveAndDismissReasonService service;
	auto dto = service.listAll();

	// �����ɹ���Ϣ
	jvo->success(dto);
	return jvo;
}
