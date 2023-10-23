#include "stdafx.h"
#include "GoshDAO.h"
#include "GoshMapper.h"
#include <sstream>

//�������������꣬�����ظ�����
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->personid) { \
	sql << " AND t_pimcontract.`PIMPERSONID`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->personid.getValue("")); \
} \
if (query->name) { \
	sql << " AND t_pimperson.`PIMPERSONNAME`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->name.getValue("")); \
} \
if (query->person_condition) { \
	sql << " AND t_pimperson.YGZT=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->person_condition.getValue("")); \
}\
if (query->id) { \
	sql << " AND t_pimcontract.PIMCONTRACTID=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->id.getValue("")); \
}\
if (query->type) { \
	sql << " AND t_pimcontract.HTLX=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->type.getValue("")); \
}\
if (query->condition) { \
	sql << " AND t_pimcontract.HTZT=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->condition.getValue("")); \
}\
if (query->date) { \
	sql << " AND t_pimcontract.QSRQ=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->date.getValue("")); \
}\
if (query->date_over) { \
	sql << " AND t_pimcontract.JSRQ=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->date_over.getValue("")); \
}\
if (query->variety) { \
	sql << " AND t_pimcontract.CONTRACTTYPE=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->variety.getValue("")); \
}


uint64_t GoshDAO::count(const ContractQuery::Wrapper & query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM t_pimcontract join t_pimperson on t_pimcontract.`PIMPERSONID`=t_pimperson.`PIMPERSONID`";
	SAMPLE_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<ContractDO> GoshDAO::selectWithPage(const ContractQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT t_pimcontract.`PIMPERSONID`,t_pimcontract.`PIMCONTRACTID`,t_pimperson.`PIMPERSONNAME`,t_pimcontract.`HTLX`,";
	sql << "t_pimcontract.`CONTRACTTYPE`,t_pimcontract.`QSRQ`,t_pimcontract.`HTZT`,t_pimcontract.`LEGALORG`,t_pimcontract.`SYDQSJ`,t_pimcontract.`ORMORGNAME`,";
	sql << "t_pimperson.`YGZT`,t_pimperson.`DBDWSJ`,t_pimcontract.`JSRQ`,DATEDIFF(t_pimcontract.`QSRQ`,t_pimcontract.`JSRQ`) as rest ";
	sql << "FROM `t_pimcontract` inner join `t_pimperson` on t_pimcontract.`PIMPERSONID`=t_pimperson.`PIMPERSONID`";
	SAMPLE_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	GoshMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<ContractDO, GoshMapper>(sqlStr, mapper, params);
}

std::list<ContractDO> GoshDAO::selectByName(const string& name)
{
	//1��Ա�����2����ͬ���3��Ա������4����ͬ���5����ͬ����6����ʼ����7����ͬ״̬8����ͬǩ����λ9�����õ���ʱ��10��Ա��������λ
	//11��Ա��״̬12��������λʱ��13����������14����ͬʣ������������Ϊǰ��ҳ��Ҫ��ʾ�ֶ�
	string sql = "SELECT t_pimcontract.`PIMPERSONID`,t_pimcontract.`PIMCONTRACTID`,t_pimperson.`PIMPERSONNAME`,t_pimcontract.`HTLX`,\
	t_pimcontract.`CONTRACTTYPE`,t_pimcontract.`QSRQ`,t_pimcontract.`HTZT`,t_pimcontract.`LEGALORG`,t_pimcontract.`SYDQSJ`,t_pimcontract.`ORMORGNAME`,\
	t_pimperson.`YGZT`,t_pimperson.`DBDWSJ`,t_pimcontract.`JSRQ`,DATEDIFF(t_pimcontract.`QSRQ`,t_pimcontract.`JSRQ`) as rest\
	FROM `t_pimcontract` inner join `t_pimperson` on t_pimperson.`PIMPERSONNAME` like CONCAT('%',?,'%')\
	limit 5;";
	GoshMapper mapper;
	return sqlSession->executeQuery<ContractDO, GoshMapper>(sql, mapper, "%s",name);
}

uint64_t GoshDAO::insert(const ContractDO& iObj)
{
	//����t_srforg���е���������Ϊt_pimcontract�������������
	string sll = "INSERT INTO t_srforg(ORGID)VALUES(?);";
	sqlSession->executeInsert(sll, "%s", iObj.getDepartment_m());
	//����t_pimperson�е���������Ϊt_pimcontract�������������
	string sml = "INSERT INTO t_pimperson(`PIMPERSONID`) VALUES(?)";
	sqlSession->executeInsert(sml, "%s", iObj.getPersonid());
	//��t_pimcontract�в����ǰ�˶�ȡ��ֵ
	int a=3;
	string sql = "INSERT INTO t_pimcontract(`PIMPERSONID`,`PIMCONTRACTID`,`HTLX`,`CONTRACTTYPE`,`QSRQ`,`HTZT`,`ORMORGID`,`SYDQSJ`,`DEMO`) VALUES ( ?,?,?,?,?,?,?,?,?);";
	a = 3;
	return sqlSession->executeInsert(sql, "%s%s%s%s%s%s%s%s%s", iObj.getPersonid(),iObj.getId(), iObj.getType(), iObj.getVariety(), iObj.getDate(), iObj.getCondition(), iObj.getDepartment_m(), iObj.getDate_end(), iObj.getTip());
}

int GoshDAO::deleteById(std::string id)
{
	string sql = "DELETE FROM `t_pimcontract` WHERE `PIMCONTRACTID`=?";
	return sqlSession->executeUpdate(sql, "%s", id);
}