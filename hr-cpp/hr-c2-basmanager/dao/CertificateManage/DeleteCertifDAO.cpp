/*
��֤�����-֤����Ϣ-ɾ��֤�飩--����
*/
#include "stdafx.h"
#include <sstream>
#include "BaseDAO.h"
#include "DeleteCertifDAO.h"

int DeleteCertifDAO::deleteById(string id)
{
	string sql = "DELETE FROM `t_pimvocational` WHERE `PIMVOCATIONALID`=?";
	return sqlSession->executeUpdate(sql,"s",id);
}