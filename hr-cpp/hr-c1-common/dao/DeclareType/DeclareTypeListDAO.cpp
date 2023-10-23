#include "stdafx.h"
#include "DeclareTypeListDAO.h"
#include "DeclareTypeMapper.h"

std::list<DeclareTypeDO> DeclareTypeListDAO::getDeclareTypeList()
{
	//��ѯ�����б�
	string sql = "SELECT `PIMSTAFFTYPENAME` FROM `t_pimstafftype`";
	DeclareTypeMapper mapper;
	return sqlSession->executeQuery<DeclareTypeDO, DeclareTypeMapper>(sql, mapper);
}
