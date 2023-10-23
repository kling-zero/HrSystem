#pragma once
#ifndef _LEGALENTITYSETSERVICE_SERVICE_
#define _LEGALENTITYSETSERVICE_SERVICE_
#include "domain/dto/LegalEntitySet/ImportLeagalPerSettingDTO.h"
#include <list>
#include "domain/vo/LegalEntitySet/LegalEntitySetVO.h"
#include "domain/dto/LegalEntitySet/LegalEntitySetDTO.h"
#include "domain/query/LegalEntitySet/LegalEntitySetQuery.h"
#include "domain/do/LegalEntitySet/LegalEntitySetDO.h"
#include "domain/dto/LegalEntitySet/LegalEntityAddSetDTO.h"
#include "domain/dto/LegalEntitySet/LegalEntitySetUpdateDTO.h"
//#include "domain/dto/LegalEntitySet/LegalEntitySetQueryDTO.h"
/*
��֯���� ������������ ���� ������������  -- cpt

�����������������б� `LegalEntitySetPullDownList`

����ָ������������Ϣ  `UpdateLegalerSettingMessage`

������������ `LegalEntitySet`

�����������ã�֧������������** `LegalEntitySet`
*/
class LegalEntitySetService
{
public:
	// ��ҳ��ѯ��������
	LegalEntitySetQueryPageDTO::Wrapper listAll(const LegalEntitySetQuery::Wrapper& query);
	// ��������
	uint64_t insertData(const LegalEntitySetAddDTO::Wrapper& dto, const PayloadDTO& payload);
	// �޸�����
	bool updateData(const LegalEntitySetUpdateDTO::Wrapper& dto );
	// ͨ��IDɾ������
	//bool removeData(uint64_t id);
	LegalEntitySetPullDownDTO::Wrapper legalEntityPulldownList();
};
#endif // !_LEGALENTITYSETSERVICE_SERVICE_