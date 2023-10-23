#include "stdafx.h"
#include "PimarmycadresController.h"
#include "ExcelComponent.h"
#include "CharsetConvertHepler.h"
#include "FastDfsClient.h"
#include "service/pimarmycadres/PimarmycadresService.h"
#include "uselib/rocketmq/TestRocket.h"

PimarmycadresFindVO::Wrapper PimarmycadresController::execQueryPimarmycadres(const PimarmycadresPageQuery::Wrapper& query)
{
	auto vo = PimarmycadresFindVO::createShared();

	auto pdto = PimarmycadresFindPageDTO::createShared();
	PimarmycadresService service;
	pdto = service.listAll(query);
	vo->success(pdto);

	return vo;

}


Uint64JsonVO::Wrapper PimarmycadresController::execAddPimarmycadres(const AddPimarmycadresDTO::Wrapper& dto, const PayloadDTO& payload)
{
	auto jvo = Uint64JsonVO::createShared();

	if (!dto->level || !dto->form || !dto->occurtime || !dto->pimid) {
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	jvo->success(1);


	PimarmycadresService service;
	uint64_t id = service.saveData(dto, payload);

	return jvo;
}


Uint64JsonVO::Wrapper PimarmycadresController::execDelPimarmycadres(const DelPimarmycadresDTO::Wrapper& dto)
{
	auto jvo = Uint64JsonVO::createShared();

	int length = dto->deleteById->size();

	if (length <= 0 || !dto->pimid)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	else
	{
		for (auto it = dto->deleteById->begin(); it != dto->deleteById->end(); ++it)
		{
			if (!(*it))
			{
				jvo->init(UInt64(-1), RS_PARAMS_INVALID);
				return jvo;
			}
		}
	}

	PimarmycadresService service;
	if (service.removeData(dto))
	{
		jvo->success(1);
	}
	else
	{
		jvo->fail(1);
	}

	return jvo;
}


StringJsonVO::Wrapper PimarmycadresController::execIntoPimarmycadres(const String& body, const String& suffix, const String& pimpersonid, const PayloadDTO& payload)
{
	auto jvo = StringJsonVO::createShared();
	if (!pimpersonid || !body || !suffix)
	{
		jvo->fail("����ʧ��,�ļ�Ϊ��");
	}
	if (pimpersonid->empty() || body->empty() || suffix->empty())
	{
		jvo->fail("����ʧ��,û������");
	}
	PimarmycadresService service;
	service.saveManyData(body, suffix, pimpersonid, payload);
	jvo->success("�ļ�����ɹ�");
	return jvo;
}
/*
{
	auto jvo = StringJsonVO::createShared();
	if (!pimpersonid || !body || !suffix)
	{
		jvo->fail("����ʧ��,�ļ�Ϊ��");
	}
	if (pimpersonid->empty() || body->empty() || suffix->empty())
	{
		jvo->fail("����ʧ��,û������");
	}

	// ����ʱ�������һ����ʱ�ļ�����
	std::stringstream ss;
	ss << "public/static/Excel/";

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
	ss <<"." << suffix.getValue("");

	// ��ʱ�ļ�����
	std::string fileName = ss.str();
	// �����ļ�����ʱĿ¼
	body.saveToFile(fileName.c_str());

	// �ϴ���FastDFS�ļ�������
#ifdef LINUX
	//����ͻ��˶���
	FastDfsClient client("conf/client.conf", 3);
#else
	//����ͻ��˶���
	FastDfsClient client("8.130.87.15");
#endif
	std::string fieldName = client.uploadFile(fileName);
	std::cout << "upload fieldname is : " << fieldName << std::endl;
	ss.str("");
	ss.clear();
	ss << "http://8.130.87.15:8888/" << fieldName;

	cout << ss.str() << endl;

	//TestRocket::getInstance().testRocket(fieldName, pimpersonid, payload);

	//ִ������߼�
	PimarmycadresService service;
	service.saveManyData(fileName, pimpersonid,payload.getUsername());


	jvo->success("�ļ�����ɹ�");
	return jvo;
}

*/


