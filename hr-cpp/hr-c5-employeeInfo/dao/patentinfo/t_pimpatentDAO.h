#pragma once

#ifndef _T_PIMPATENT_DAO_
#define _T_PIMPATENT_DAO_
#include "BaseDAO.h"
#include "../../domain/do/patentinfo/t_pimpatentDO.h"
#include "../../domain/query/patentinfo/PatentinfoQuery.h"

/**
 * ר����Ϣ�����ݿ����ʵ��
 */
class t_pimpatentDAO : public BaseDAO
{
public:
	// ���ָ��Ա����ר����Ϣ
	uint64_t insert(const PatentinfoDO& iObj, string idStr, string datetime);
	// ͳ����������
	uint64_t count(const PatentinfoQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<PatentinfoDO> selectWithPage(const PatentinfoQuery::Wrapper& query);

	// ͨ��Ա�����ɾ������
	int deleteById(string pimpaperid);
	// ͨ��DTO��ѯ����ID
	uint64_t selectpatentID(const PatentinfoDO& sdo);
};
#endif
