/*
* ������������--ɾ����������(֧������ɾ��)--pine
*/
#include "stdafx.h"
#include "DeleteLegalEntityDAO.h"
#include "DeleteLegalEntityMapper.h"
#include <sstream>
//t_ormsignorg + t_contractsignorg
int DeleteLegalEntityDAO::update(string id)
{
	string sql = "UPDATE t_pimcontract SET CONTRACTSIGNORGID = NULL WHERE CONTRACTSIGNORGID =?;";
	return sqlSession->executeUpdate(sql, "s", id);
}
int DeleteLegalEntityDAO::deleteById(string id)
{
	string sql = "DELETE FROM t_contractsignorg WHERE CONTRACTSIGNORGID =?;";
	return sqlSession->executeUpdate(sql, "s", id);
}
