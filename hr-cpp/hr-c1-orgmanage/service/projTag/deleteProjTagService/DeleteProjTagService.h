#pragma once
#ifndef _DELETEPROJTAGSERVICE_H_
#define _DELETEPROJTAGSERVICE_H_
#include <list>
#include "domain/dto/projTag/DeleteProjTagDTO.h"

/**
 * ��Ŀ��ǩ - ɾ����Ŀ��ǩService
 * ������ : ���֮��
 */
class DeleteProjTagService
{
public:
	bool removeData(string id);
	bool removeBatchData(const DeleteProjTagBatchDTO::Wrapper& deleteBatchProjTagDTO);
};

#endif // !_DELETEPROJTAGSERVICE_H_