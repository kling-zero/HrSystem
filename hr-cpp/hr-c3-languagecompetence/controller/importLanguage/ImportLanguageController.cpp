#include "stdafx.h"
#include "ImportLanguageController.h"
#include "ExcelComponent.h"

/**
 * ʵ�������ļ��ϴ�ģ��
 * �����ˣ���
 */
StringJsonVO::Wrapper ImportLanguageController::execImportLanguage(const ImportLanguageDTO::Wrapper& dto/*, const PayloadDTO & payload*/)
{
	auto jvo = StringJsonVO::createShared();
	jvo->success("import language competence success");
	return jvo;
}
