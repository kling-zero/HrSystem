#include "stdafx.h"
#include "ImportTagController.h"
#include "ExcelComponent.h"
#include "service/projTag/ProjTagService.h"
#define RTN(__VO__, __MSG__) __VO__->setStatus(__MSG__); \
return __VO__;

ImportProjTagJsonVO::Wrapper ImportTagController::execImportTag(const ImportTagDTO::Wrapper& dto, const PayloadDTO& payload)
{
	auto vo = ImportProjTagJsonVO::createShared();
	
	if (dto->filePath->empty()) {
		vo->init({}, RS_PARAMS_INVALID);
		return vo;
	}

	// TODO: ����service
	std::list<std::string> result;
	ProjTagService service;
	auto res = service.addMultiTag(dto, payload);

	// -1:����������5000
	if (res->newId->front() == "-1") {
		vo->init(res, ResultStatus("The file has lots of data.", 5001));
	}
	// -2:���ݲ��������ݿ�������������������ƣ���������
	else if (res->newId->front() == "-2")
	{
		vo->init(res, ResultStatus("The data does not meet the constraints", 5002));
	}
	// �����ɹ�
	else {
		vo->init(res, RS_SUCCESS);
	}
	return vo;
}
