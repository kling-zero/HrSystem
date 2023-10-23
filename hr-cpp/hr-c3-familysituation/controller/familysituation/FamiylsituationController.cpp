#include "stdafx.h"
#include "FamilysituationController.h"
#include "FastDfsClient.h"
#include "../../service/familysituation/FamilysituationService.h"

// ��ҳ��ѯ��Ӧ
FamilysituationPageJsonVO::Wrapper FamilysituationController::execQueryByFamilysituation(const FamilysituationQuery::Wrapper& query, const PayloadDTO& payload)
{
	FamilysituationService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto vo = FamilysituationPageJsonVO::createShared();
	vo->success(result);
	return vo;
}

// ָ����ѯ��Ӧ
FamilysituationJsonVO::Wrapper FamilysituationController::execOneQueryFamilysituation(const FamilysituationQuery::Wrapper& query)
{
	FamilysituationService service;
	// ��ѯ����
	auto result = service.getOne(query);
	// ��Ӧ���
	auto vo = FamilysituationJsonVO::createShared();
	vo->success(result);
	return vo;
}


// �����Ӧ
Uint64JsonVO::Wrapper FamilysituationController::execAddFamilysituation(const FamilysituationDTO::Wrapper& dto, const PayloadDTO& payload)
{
	auto vo = Uint64JsonVO::createShared();
	// ����У��
	// �ǿ�У��
	if (!dto->id || !dto->personid)
	{
		vo->init(UInt64(-1), RS_PARAMS_INVALID);
		return vo;
	}
	// ��ЧֵУ��
	if (dto->id->empty())
	{
		vo->init(UInt64(-1), RS_PARAMS_INVALID);
		return vo;
	}
	// ����һ��Service
	FamilysituationService service;
	// ����Ȩ����֤��Ϣ
	auto authId = payload.getUsername();
	// ִ����������
	auto result = service.saveData(dto, authId);
	if (result == 0) {
		vo->success(UInt64(result));
	}
	else
	{
		vo->fail(UInt64(result));
	}
	return vo;
}

// �޸���Ӧ
Uint64JsonVO::Wrapper FamilysituationController::execModifyFamilysituation(const FamilysituationDTO::Wrapper& dto, const PayloadDTO& payload)
{
	auto vo = Uint64JsonVO::createShared();
	// ��ЧֵУ��
	if (dto->id->empty())
	{
		vo->init(UInt64(-1), RS_PARAMS_INVALID);
		return vo;
	}
	// ����һ��Service
	FamilysituationService service;
	// ִ�������޸�
	auto result = service.updateData(dto, payload.getUsername());
	if (result) {
		vo->success(UInt64(result));
	}
	else
	{
		vo->fail(UInt64(result));
	}
	return vo;
}

// ɾ����Ӧ
Uint64JsonVO::Wrapper FamilysituationController::execRemoveFamilysituation(const FamilyBatchDeleteDTO::Wrapper& dto)
{
	auto vo = Uint64JsonVO::createShared();
	// ��ЧֵУ�� ���ϲ���С��0
	int familySize = dto->batchFamilyId->size();
	if (familySize <= 0)
	{
		vo->init(UInt64(-1), RS_PARAMS_INVALID);
		return vo;
	}
	// ����һ��Service
	FamilysituationService service;
	// ִ������ɾ��
	auto result = service.removeData(dto);
	if (result > 0) {
		vo->success(UInt64(result));
	}
	else
	{
		vo->fail(UInt64(result));
	}
	return vo;
}

// ������Ӧ
StringJsonVO::Wrapper FamilysituationController::executeImportFamilysituation(const String& fileBody, const String& suffix)
{
	// ����ʱ�������һ����ʱ�ļ�����
	std::stringstream ss;
	ss << "public/static/file/";
	// ����ʱ���
	auto now = std::chrono::system_clock::now();
	auto tm_t = std::chrono::system_clock::to_time_t(now);
	ss << std::put_time(std::localtime(&tm_t), "%Y%m%d%H%M%S");
	// ��ȡ����
	auto tSeconds = std::chrono::duration_cast<std::chrono::seconds>(now.time_since_epoch());
	auto tMilli = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch());
	auto ms = tMilli - tSeconds;
	ss << std::setfill('0') << std::setw(3) << ms.count();
	// ƴ�Ӻ�׺��
	ss << suffix.getValue("");

	// ��ʱ�ļ�����
	std::string fileName = ss.str();
	// �����ļ�����ʱĿ¼
	fileBody.saveToFile(fileName.c_str());

//	// �����ϴ���FastDFS�ļ�������
//#ifdef LINUX
//	//����ͻ��˶���
//	FastDfsClient client("conf/client.conf", 3);
//#else
//	//����ͻ��˶���
//	FastDfsClient client("192.168.52.133");
//#endif
//	std::string fieldName = client.uploadFile(fileName);
//	std::cout << "upload fieldname is : " << fieldName << std::endl;
//	ss.str("");
//	ss.clear();
//	ss << "http://192.168.52.133:8888/" << fieldName;

	// excel�����߼�����ʱ����д��
	
	// ������Ӧ����
	auto vo = StringJsonVO::createShared();
	vo->success(String("cool"));
	return vo;
}


// ������Ӧ
StringJsonVO::Wrapper FamilysituationController::execExportFamilysituation(const FamilysituationQuery::Wrapper &query)
{
	auto jvo = StringJsonVO::createShared();
	// ����һ��Service
	// AssignInfoService service;
	// //// ��ѯ����
	// auto result = service.exportData(query);
	// if (!result.empty()) {
	// 	jvo->success(result);
	// } else {
	// 	jvo->fail("export fail");
	// }
	return jvo;
}

