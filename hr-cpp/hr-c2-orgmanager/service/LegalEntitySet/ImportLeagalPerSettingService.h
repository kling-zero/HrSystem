#pragma once
/*
(������������-���뷨������)--����
*/
#ifndef _IMPORTLEAGALPERSETTING_SERVICE_
#define _IMPORTLEAGALPERSETTING_SERVICE_
#include <list>

#include "domain/dto/LegalEntitySet/ImportLeagalPerSettingDTO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class ImportLeagalPerSettingService
{
public:
	// ��������
	uint64_t saveData(const ImportLeagalPerSettingDTO::Wrapper& dto);

};

#endif // !_IMPORTLEAGALPERSETTING_SERVICE_

