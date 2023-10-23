#include "stdafx.h"
#include "PatentinfoController.h"
#include "service/patentinfo/patentinfoService.h"


//PatentinfoPageJsonVO::Wrapper PatentinfoController::execQueryPagePatent(const PatentinfoQuery::Wrapper& query)
//{
//	// ������Ӧ����
//	auto vo = PatentinfoPageJsonVO::createShared();
//	// ������ҳ����
//	auto pdto = PatentinfoPageDTO::createShared();
//	pdto->addData(PatentinfoDTO::createShared("1", "page1"));
//	pdto->addData(PatentinfoDTO::createShared("2", "page2"));
//	// ��Ӧ���
//	vo->success(pdto);
//	return vo;
//}




//Uint64JsonVO::Wrapper PatentinfoController::execAddPatent(const AddPatentDTO::Wrapper& dto)
//{
//	// ���巵�����ݶ���
//	auto jvo = Uint64JsonVO::createShared();
//	// ����У��
//	// �ǿ�У��
//	if (!dto->zlh || !dto->pimpatentname || !dto->zlhqsj || !dto->zlpzgb)
//	{
//		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
//		return jvo;
//	}
//	// ��ЧֵУ��
//	if (dto->zlh->empty() || dto->pimpatentname->empty() || dto->zlhqsj->empty() || dto->zlpzgb->empty())
//	{
//		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
//		return jvo;
//	}
//
//	// ����һ��Service
//	PatentinfoService service;
//	// ִ����������
//	int id = service.saveData(dto);
//	if (id > 0) {
//		jvo->success(UInt64(id));
//	}
//	else
//	{
//		jvo->fail(UInt64(id));
//	}
//	//��Ӧ���
//	return jvo;
//
//
//}

//����idɾ��ר����Ϣ
Uint64JsonVO::Wrapper PatentinfoController::execRemovePatent(const List<String>& dto)
{
	auto jvo = Uint64JsonVO::createShared();
	int length = dto->size();
	if (length <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	for (auto it = dto->begin(); it != dto->end(); ++it)
	{
		if (!(*it))
		{
			jvo->init(UInt64(-1), RS_PARAMS_INVALID);
			return jvo;
		}
	}
	
	PatentinfoService service;
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

