/*
(������������-���뷨������)--����
*/
#include "stdafx.h"
#include "ImportLeagalPerSettingController.h"
#include "../../service/LegalEntitySet/ImportLeagalPerSettingService.h"

Uint64JsonVO::Wrapper ImportLeagalPerSettingController::execAddLeagalPerSetting(const ImportLeagalPerSettingDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	//// ����У��
	//// �ǿ�У��
	//if (!dto->age || !dto->name || !dto->sex)
	//{
	//	jvo->init(UInt64(-1), RS_PARAMS_INVALID);
	//	return jvo;
	//}
	//// ��ЧֵУ��
	//if (dto->age < 0 || dto->name->empty() || dto->sex->empty())
	//{
	//	jvo->init(UInt64(-1), RS_PARAMS_INVALID);
	//	return jvo;
	//}

	//// ����һ��Service
	//ImportLeagalPerSettingService service;
	//// ִ����������
	//uint64_t id = service.saveData(dto);
	//if (id > 0) {
	//	jvo->success(UInt64(id));
	//}
	//else
	//{
	//	jvo->fail(UInt64(id));
	//}
	////��Ӧ���
	return jvo;
}
