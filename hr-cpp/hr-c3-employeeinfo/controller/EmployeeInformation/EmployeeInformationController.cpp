#include "stdafx.h"
#include "EmployeeInformationController.h"
#include "service/EmployeeInformation/EmployeeInformationServicer.h"

//��ҳ��ѯԱ���б�
EmployeeInformationPageJsonVO::Wrapper EmployeeInformationController::execEmployeeInformation(const EmployeeInformationPageQuery::Wrapper& query, const PayloadDTO& payload)
{
	// ����һ��Service
	EmployeeInformationServicer service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = EmployeeInformationPageJsonVO::createShared();
	jvo->success(result); 
	return jvo;

}
//����Ա����Ϣ
ImportJobJsonVO::Wrapper EmployeeInformationController::execImportEmployeeInfo(const ImportInfoDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// ��������VO
	auto vo = ImportJobJsonVO::createShared();
	// ����У��
	if (dto->filePath->empty()) {
		vo->init({}, RS_PARAMS_INVALID);
		return vo;
	}

	// ������������
	/*String str1 = "123abc";
	String str2 = "456def";
	String str3 = "789ghi";
	auto ij = ImportJobVO::createShared();
	ij->newId->push_back("123abc");
	ij->newId->push_back("456def");
	ij->newId->push_back("789ghi");
	vo->init(ij, RS_SUCCESS);*/

	// TODO: ����service
	std::list<std::string> result;
	EmployeeInformationServicer service;
	auto res = service.addMultiEmployee(dto, payload);

	if (res->newId->size())
		vo->init(res, RS_SUCCESS);
	else
		vo->init(res, RS_FAIL);

	return vo;

}
//����Ա����Ϣ(������ҳ��ǰ�����)
StringJsonVO::Wrapper EmployeeInformationController::execExportEmployeeInfo(const PostDetailQuery::Wrapper& query) {
	auto vo = StringJsonVO::createShared();

	EmployeeInformationServicer service;
	string url = service.exportEmpInfomation(query);

	if (url.empty())
		vo->fail(url);
	else
		vo->success(url);
	return vo;

}
//����Ա����Ϣ 
Uint64JsonVO::Wrapper EmployeeInformationController::execAddEmployee(const EmployeeInformationDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	// �ǿ�У��
	if (!dto->name || !dto->age)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ��ЧֵУ��
	if (dto->name->empty()|| dto->age < 0 )
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// ����һ��Service
	EmployeeInformationServicer service;
	// ִ����������
	uint64_t id = service.saveData(dto,payload);
	if (id >= 0) {
		jvo->success(UInt64(id));
	}
	else
	{
		jvo->fail(UInt64(id));
	}
	//��Ӧ���
	return jvo;
}