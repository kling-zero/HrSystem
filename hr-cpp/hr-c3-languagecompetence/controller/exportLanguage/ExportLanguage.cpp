#include "stdafx.h"
#include "ExportLanguage.h"

/**
 * ���������ļ�����ʵ��
 * �����ˣ���
 */
StringJsonVO::Wrapper execDownloadLanguage(const EmployeeLanguageExportQuery::Wrapper& query)
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
