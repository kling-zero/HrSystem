#pragma once

#ifndef _J_PATENTINFO_SERVICE_
#define _J_PATENTINFO_SERVICE_
#include <list>
#include "domain/vo/J_patentinfo/J_PatentinfoVO.h"
#include "domain/dto/J_patentinfo/J_PatentinfoDTO.h"



/**
 * ר������ʵ��
 */
class PatentService
{
public:
	// ��ѯ��������
	J_PatentinfoDTO::Wrapper listAll(const string& pimpatentid);

	// �޸�����
	bool updateData(const ModifyPatentinfoDTO::Wrapper& dto);

};

#endif // !_PATENTINFO_SERVICE_
