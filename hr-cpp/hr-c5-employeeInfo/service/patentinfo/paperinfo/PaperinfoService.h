#pragma once

#ifndef _PAPERINFO_SERVICE_
#define _PAPERINFO_SERVICE_
#include <list>
#include "domain/vo/paperinfo/PaperVO.h"
#include "domain/query/paperinfo/PaperQuery.h"
#include "domain/dto/paperinfo/PaperDTO.h"

/**
 * ������Ϣ����ʵ��
 */
class PaperinfoService
{
public:
	// ��ҳ��ѯ��������
	PaperPageDTO::Wrapper listAll(const PaperQuery::Wrapper& query);
	// ��������
	// int Ӱ����������
	int saveData(const PaperDTO::Wrapper& dto);
	// ͨ��IDɾ������
	bool removeData(string id);
	// ��ѯ����ID
	uint64_t selectPaperID(const PaperDTO::Wrapper& dto);
};

#endif // !_SAMPLE_SERVICE_

