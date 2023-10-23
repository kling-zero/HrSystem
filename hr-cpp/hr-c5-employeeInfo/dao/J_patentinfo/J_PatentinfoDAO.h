#pragma once
#ifndef _J_PATENTINFO_DAO_
#define _J_PATENTINFO_DAO_
#include "BaseDAO.h"
#include "../../domain/do/J_patentinfo/J_t_pimpatentDO.h"

/**
 * ר�������ݿ����ʵ��
 */
class PatentinfoDAO : public BaseDAO
{
public:


	// ͨ��ר����Ϣ�����ѯ����
	list<J_PatentinfoDO> selectByPIMPATENTID(const string& pimpatentid);
	// �޸�����
	int update(const J_PatentinfoDO& uObj);

};
#endif // !_PATENTINFO_DAO_