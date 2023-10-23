#pragma once

#ifndef _J_PAPER_SERVICE_
#define _J_PAPER_SERVICE_
#include <list>
#include "domain/vo/J_paperinfo/J_PaperVO.h"
#include "domain/dto/J_paperinfo/J_PaperinfoDTO.h"

/**
 * ������Ϣ����ʵ��
 */
class PaperService
{
public:
	// ��ѯָ��������Ϣ����
	J_PaperinfoDTO::Wrapper listAll(const string& st);
	// �޸�����
	bool updateData(const ModifyPaperinfoDTO::Wrapper& dto);
};

#endif // !_PAPER_SERVICE_

