#pragma once
/*
��֯���� ������������ ���� ������������  -- cpt

�����������������б� `LegalEntitySetPullDownList`

����ָ������������Ϣ  `UpdateLegalerSettingMessage`

������������ `LegalEntitySet`

�����������ã�֧������������** `LegalEntitySet`
*/
#ifndef _LEGALENTITYSET_DAO_
#define _LEGALENTITYSET_DAO_
#include "BaseDAO.h"
#include "domain/do/LegalEntitySet/LegalEntitySetDO.h"
#include "domain/query/LegalEntitySet/LegalEntitySetQuery.h"
/**
 * ʾ�������ݿ����ʵ��
 */
class LegalEntitySetDAO : public BaseDAO
{
public:
	// ͳ����������
	//uint64_t count(const LegalEntitySetQuery::Wrapper& query);
	// ��ҳ��ѯ����
	//list<LegalEntitySetDO> selectWithPage(const LegalEntitySetQuery::Wrapper& query);
	// ��������
	uint64_t insert(const LegalEntitySetDO& iObj);
	// �޸�����
	int update(const LegalEntitySetDO& uObj);
	// �����������������б�  
	std::list<LegalEntitySetDO> legalerNamePullDownList();
	// ͳ����������
	uint64_t count(const LegalEntitySetQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<LegalEntitySetDO> selectWithPage(const LegalEntitySetQuery::Wrapper& query);
	
};
#endif // !_LEGALENTITYSET_DAO_
