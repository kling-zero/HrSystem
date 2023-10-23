#include "stdafx.h"
#include "ScientificService.h"
#include "CharsetConvertHepler.h"
#include "ExcelComponent.h"
#include "FastDfsClient.h"
#include "../../dao/scientific/ScientificDAO.h"

#define DO_TO_VECTOR(f) \
ss.clear(); \
ss<<sub.get##f(); \
row.push_back(ss.str()); \
ss.str("");

ScientificDTO::Wrapper ScientificService::listDetail(const ScientificViewQuery::Wrapper& query)
{
	// �������ض���
	ScientificDAO dao;
	auto lists = dao.selectDetail(query);
	auto dto = ScientificDTO::createShared();
	if (!lists.empty()) {
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, lists.front(), updateman, Updateman, pimresearchfindingsname, Pimresearchfindingsname, fj, Fj, enable, Enable, createdate, Createdate, updatedate, Updatedate, createman, Createman, pimresearchfindingsid, Pimresearchfindingsid, pimpersonid, Pimpersonid, hqsj, Hqsj, jlss, Jlss, jlglbh, Jlglbh, jlczz, Jlczz, reason, Reason);
	}
	return dto;
}

bool ScientificService::updateData(const ScientificDTO::Wrapper& dto)
{
	// ��װDO����
	ScientificDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Updateman, updateman, Pimresearchfindingsname, pimresearchfindingsname, Fj, fj, Enable, enable, Createdate, createdate, Updatedate, updatedate, Createman, createman, Pimresearchfindingsid, pimresearchfindingsid, Pimpersonid, pimpersonid, Hqsj, hqsj, Jlss, jlss, Jlglbh, jlglbh, Jlczz, jlczz, Reason, reason);
	// ִ�������޸�
	ScientificDAO dao;
	return dao.update(data) == 1;
}

string ScientificService::download(const ScientificDownloadQuery::Wrapper& query)
{
	vector<vector<string>> data;
	list<ScientificDO> result = ScientificDAO().selectWithPage(query);
	data.push_back({
		CharsetConvertHepler::ansiToUtf8("������") ,
		CharsetConvertHepler::ansiToUtf8("���гɹ�����") ,
		CharsetConvertHepler::ansiToUtf8("����") ,
		CharsetConvertHepler::ansiToUtf8("ENABLE") ,
		CharsetConvertHepler::ansiToUtf8("����ʱ��") ,
		CharsetConvertHepler::ansiToUtf8("����ʱ��") ,
		CharsetConvertHepler::ansiToUtf8("������") ,
		CharsetConvertHepler::ansiToUtf8("���гɹ���ʶ") ,
		CharsetConvertHepler::ansiToUtf8("��Ա��Ϣ��ʶ") ,
		CharsetConvertHepler::ansiToUtf8("��ȡʱ��") ,
		CharsetConvertHepler::ansiToUtf8("��¼����") ,
		CharsetConvertHepler::ansiToUtf8("��¼������") ,
		CharsetConvertHepler::ansiToUtf8("��¼������") ,
		CharsetConvertHepler::ansiToUtf8("�ܾ�ԭ��")
		});
	for (ScientificDO sub : result)
	{
		vector<string> row;
		stringstream ss;
		DO_TO_VECTOR(Updateman);
		DO_TO_VECTOR(Pimresearchfindingsname);
		DO_TO_VECTOR(Fj);
		DO_TO_VECTOR(Enable);
		DO_TO_VECTOR(Createdate);
		DO_TO_VECTOR(Updatedate);
		DO_TO_VECTOR(Createman);
		DO_TO_VECTOR(Pimresearchfindingsid);
		DO_TO_VECTOR(Pimpersonid);
		DO_TO_VECTOR(Hqsj);
		DO_TO_VECTOR(Jlss);
		DO_TO_VECTOR(Jlglbh);
		DO_TO_VECTOR(Jlczz);
		DO_TO_VECTOR(Reason);
		data.push_back(row);
	}
	stringstream ss;
	ss << "./temp/excel/" << chrono::system_clock::now().time_since_epoch().count() << ".xlsx";
	string fileName = ss.str();
	string sheetName = CharsetConvertHepler::ansiToUtf8("���ݱ�1");
	ExcelComponent excel;
	excel.writeVectorToFile(fileName, sheetName, data);
#ifdef LINUX
	//����ͻ��˶���
	FastDfsClient client("conf/client.conf");
#else
	//����ͻ��˶���
	FastDfsClient client("192.168.88.1");
#endif
	//�ϴ�excel���
	std::string fieldName = client.uploadFile(fileName);
	std::cout << "upload fieldname is : " << fieldName << std::endl;
	ss.str("");
	ss.clear();
	ss << "http://192.168.88.1:8888/" << fieldName;


	//cout << ss.str() << endl;

	return ss.str();
}
