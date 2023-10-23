#pragma once

#ifndef PATENTINFO_SERVICE_
#define PATENTINFO_SERVICE_
#include "domain/vo/paptentinfo/PatentinfoVO.h"
#include "domain/query/patentinfo/PatentinfoQuery.h"
#include "domain/dto/patentinfo/PatentinfoDTO.h"
#include "domain/dto/patentinfo/DelPatentDTO.h"
#include "domain/dto/patentinfo/AddPatentDTO.h"
//#include "oatpp/core/data/mapping/type/Object.hpp"

/**
 * ������Ϣ����ʵ��
 */
class PatentinfoService
{
public:
	// ��ҳ��ѯ��������
	PatentinfoPageDTO::Wrapper listAll(const PatentinfoQuery::Wrapper& query);


	// �������
	int saveData(const AddPatentDTO::Wrapper& dto);
	
	// ͨ��IDɾ������ ֧������ɾ��
	bool removeData(const oatpp::List<oatpp::String>& dto);


	// ��ѯ����ID
	uint64_t selectPaperID(const PatentinfoDTO::Wrapper& dto);
};

#endif // !_SAMPLE_SERVICE_

