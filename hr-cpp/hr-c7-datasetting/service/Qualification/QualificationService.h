#pragma once
#ifndef _QUALIFICATION_SERVICE_
#define _QUALIFICATION_SERVICE_
#include <list>
#include "domain/vo/Qualification/QualificationVO.h"
#include "domain/query/Qualification/QualificationQuery.h"
#include "domain/dto/Qualification/QualificationDTO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class QualificationService
{
public:
	// ��ҳ��ѯ��������
	QualificationPageDTO::Wrapper listAll(const QualificationQuery::Wrapper& query);
	// ��������
	uint64_t saveData(const QualificationDTO::Wrapper& dto);
	// �޸�����
	bool updateData(const QualificationDTO::Wrapper& dto);
	// ͨ��IDɾ������
	bool removeData(uint64_t id);
};

#endif // !_QUALIFICATION_SERVICE_