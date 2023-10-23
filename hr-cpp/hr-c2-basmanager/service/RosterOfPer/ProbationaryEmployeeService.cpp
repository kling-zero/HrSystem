#include "stdafx.h"
#include "CharsetConvertHepler.h"
#include "ExcelComponent.h"
#include "ProbationaryEmployeeService.h"
#include "../../dao/RosterOfPer/ProbationaryEmployeeDAO.h"
#include "FastDfsClient.h"

ProbationaryEmployeePageDTO::Wrapper ProbationaryEmployeeService::listAll(const ProbationaryEmployeeQuery::Wrapper& query)
{
	auto pages = ProbationaryEmployeePageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	ProbationaryEmployeeDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}


	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<ProbationaryEmployeeDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (ProbationaryEmployeeDO sub : result)
	{
		auto dto = ProbationaryEmployeeDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, PIMPERSONID, pimPersonId,id, YGBH, name, PIMPERSONNAME,
			zz, ORMORGNAME, bm, ORMORGSECTORNAME,
			zw, ZW, gw, ORMPOSTNAME, rzsj, RZSJ,
			daoqishijian, SYDQ);
		pages->addData(dto);
	}

	return pages;
}

std::string ProbationaryEmployeeService::exportData(const ProbationaryEmployeeQuery::Wrapper& query)
{
	ProbationaryEmployeeDAO dao;
	auto listdata = dao.selectAll(query);

	std::vector<std::vector<std::string>> datas;

	std::vector<std::string> rowHead;
	rowHead.push_back(CharsetConvertHepler::ansiToUtf8("Ա�����"));
	rowHead.push_back(CharsetConvertHepler::ansiToUtf8("����"));
	rowHead.push_back(CharsetConvertHepler::ansiToUtf8("��֯"));
	rowHead.push_back(CharsetConvertHepler::ansiToUtf8("����"));
	rowHead.push_back(CharsetConvertHepler::ansiToUtf8("ְ��"));
	rowHead.push_back(CharsetConvertHepler::ansiToUtf8("��λ"));
	rowHead.push_back(CharsetConvertHepler::ansiToUtf8("��ְʱ��"));
	rowHead.push_back(CharsetConvertHepler::ansiToUtf8("���õ���ʱ��"));

	datas.push_back(rowHead);

	for (auto row : listdata)
	{
		std::vector<std::string> vec = row.ProbationaryEmployeetoVector();
		datas.push_back(vec);
	}

	std::stringstream ss;
	ss << "public/static/Excel/";


	// ����ʱ���
	auto now = std::chrono::system_clock::now();
	auto tm_t = std::chrono::system_clock::to_time_t(now);
	ss << std::put_time(std::localtime(&tm_t), "%Y%m%d%H%M%S");
	// ��ȡ����
	auto tSeconds = std::chrono::duration_cast<std::chrono::seconds>(now.time_since_epoch());
	auto tMilli = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch());
	auto ms = tSeconds - tMilli;
	ss << setfill('0') << setw(3) << ms.count();
	// ƴ�Ӻ�׺
	ss << ".xlsx";

	std::string fileName = CharsetConvertHepler::ansiToUtf8(ss.str());
	// ע�⣺��Ϊxlnt���ܴ洢��utf8������ַ���������������Ҫת������
	std::string sheetName = CharsetConvertHepler::ansiToUtf8("����Ա����Ϣ��");

	// ���浽Excel
	ExcelComponent excel;
	excel.writeVectorToFile(fileName, sheetName, datas);


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

	// ɾ�������ļ�
	const char* filename = fileName.c_str();
	if (std::remove(filename) != 0) {
		// ɾ��ʧ��
		std::perror("Error deleting local file");
	}
	else {
		// ɾ���ɹ�
		std::puts("Local file successfully deleted");
	}

	return ss.str();
}
