#include "stdafx.h"
#include "t_pimpatentDAO.h"
#include "t_pimpatentMapper.h"
#include <sstream>

//�������������꣬�����ظ�����
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->PIMPATENTID) { \
	sql << " AND `PIMPATENTID`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->PIMPATENTID.getValue("")); \
}


// ���ָ��Ա����ר����Ϣ
uint64_t t_pimpatentDAO::insert(const PatentinfoDO& iObj, string idStr, string datetime)
{
	string sql = "INSERT INTO `t_pimpatent` (`ZLH`, `PIMPATENTNAME`, `ZLHQSJ`, `ZLPZGB`, `ENCLOLURE`,\
		`CREATEDATE`, `UPDATEDATE`,`PIMPATENTID`) VALUES (?, ?, ?, ?, ?, ?, ?, ?)";
	return sqlSession->executeInsert(sql, "%s%s%s%s%s%s%s%s", iObj.getZLH(), iObj.getPIMPATENTNAME(), iObj.getZLHQSJ(), iObj.getZLPZGB(),iObj.getENCLOLURE()\
		, datetime, datetime, idStr);
}

// ͳ����������
uint64_t t_pimpatentDAO::count(const PatentinfoQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM t_pimpatent";
	SAMPLE_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}


// ��ҳ��ѯ����
list<PatentinfoDO> t_pimpatentDAO::selectWithPage(const PatentinfoQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT ZLH, PIMPATENTNAME, ZLHQSJ, PIMPATENTNAME, ENCLOLURE FROM t_pimpatent";
	SAMPLE_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	t_pimpatentMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<PatentinfoDO, t_pimpatentMapper>(sqlStr, mapper, params);
}


// ͨ��ר�����ɾ������
int t_pimpatentDAO::deleteById(string pimpatentid)
{
	std::string sql = "delete from t_pimpatent where PIMPATENTID=?";
	return sqlSession->executeUpdate(sql, "%s", pimpatentid);
}
