/**
 * ֤�����ͷ�ҳ��ѯMapper--(֤�����-��ѯ֤��������Ϣ)--weixiaoman
 */
#include "stdafx.h"
#include "CertificateTypeDAO.h"
#include "CertificateTypeMapper.h"
#include <sstream>

 //��������������
#define CERTIFICATETYPE_TERAM_PARSE(query,sql)\
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->certype) { \
	sql << " AND `name` LIKE CONCAT('%',?,'%')"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->certype.getValue("")); \
} 

uint64_t CertificateTypeDAO::count(const CertificateTypeQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM zo_credentialtype";

	CERTIFICATETYPE_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

list<CertificateTypeDO> CertificateTypeDAO::selectWithPage(const CertificateTypeQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT name,id FROM zo_credentialtype";
	CERTIFICATETYPE_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	CertificateTypeMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<CertificateTypeDO, CertificateTypeMapper>(sqlStr, mapper, params);
}