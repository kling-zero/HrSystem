#pragma once
/*
* ������������--ɾ����������(֧������ɾ��)--pine
*/
#ifndef _DELETE_LEGAL_ENTITY_SERVICE_
#define _DELETE_LEGAL_ENTITY_SERVICE_
#include <list>
#include "domain/query/LegalEntitySet/DeleteLegalEntityQuery.h"
#include "domain/dto/LegalEntitySet/DeleteLegalEntityDTO.h"
#include "domain/vo/LegalEntitySet/DeleteLegalEntityVO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class DeleteLegalEntityService
{
public:
public:
	// ͨ��IDɾ������
	bool removeData(const DeleteLegalEntityDTO::Wrapper& dto);
};

#endif // !_SAMPLE_SERVICE_

