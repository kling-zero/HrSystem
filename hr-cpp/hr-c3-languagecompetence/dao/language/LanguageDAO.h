#pragma once
#ifndef _LANGUAGE_DAO_
#define _LANGUAGE_DAO_

#include "BaseDAO.h"
#include "../../domain/do/language/LanguageDO.h"
#include "../../domain/query/language/LanguageQuery.h"
#include "../../domain/query/languagePage/LanguagePageQuery.h"

/**
 * ������������ģ������ݿ����
 * �����ˣ���
 */
class LanguageDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const LanguageQuery::Wrapper& query);
	// ��ҳ��ѯqueryͳ����������
	uint64_t countPage(const LanguagePageQuery::Wrapper& query);
	// ��ҳ��������
	list<LanguageDO> selectWithPage(const LanguagePageQuery::Wrapper& query);
	// ͨ��������ѯ����
	list<LanguageDO> selectOneById(const string& id);
	// ��������
	int insert(const LanguageDO& iObj);
	// �޸�����
	int update(const LanguageDO& uObj);
	// ͨ��IDɾ������
	int deleteById(std::string id);
};

#endif  // !_LANGUAGE_DAO_
