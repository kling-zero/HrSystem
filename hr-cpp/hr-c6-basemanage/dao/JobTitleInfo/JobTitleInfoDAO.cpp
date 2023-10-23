#include "stdafx.h"
#include "JobTitleInfoDAO.h"
#include "../JobTitle/JobTitleMapper.h"
#include "../dao-sql-macro/macro.h"		//�Զ���ĺ��ļ�

#define SAMPLE_QUERY_PARSE(query, sql) \
SqlParams params; \
if (query->param) { \
	sql << "and tpp.YGBH like concat('%',?,'%') ";\
    SQLPARAMS_PUSH(params, "s", std::string, query->param.getValue(""));\
	sql << "or tpp.PIMPERSONNAME like concat('%',?,'%')";\
	SQLPARAMS_PUSH(params, "s", std::string, query->param.getValue(""));\
}\
if(query->employee_id){\
	sql <<" and tpp.YGBH = ?";\
	SQLPARAMS_PUSH(params, "s", std::string, query->employee_id.getValue(""));\
}\
if(query->employee_name){\
	sql <<" and tpp.PIMPERSONNAME = ?";\
	SQLPARAMS_PUSH(params, "s", std::string, query->employee_name.getValue(""));\
}\
if(query->org_name){\
	sql <<" and tpp.ORMORGNAME = ?";\
	SQLPARAMS_PUSH(params, "s", std::string, query->org_name.getValue(""));\
}\
if(query->jobtitle_name){\
	sql <<" and tpg.PIMTITLECATALOGUENAME = ?";\
	SQLPARAMS_PUSH(params, "s", std::string, query->jobtitle_name.getValue(""));\
}\
if(query->jobtitle_grades){\
	sql <<" and btt.TITLEGRADENAME = ?";\
	SQLPARAMS_PUSH(params, "s", std::string, query->jobtitle_grades.getValue(""));\
}\
if(query->b_highest_professional_title){\
	sql <<" and tpp.HIGHTITLE = ?";\
	SQLPARAMS_PUSH(params, "s", std::string, query->b_highest_professional_title.getValue(""));\
}\

#define JBT_QUERY_PARSE(query, sql) \
if (query->employee_id) {\
		sql << " and tpp.YGBH = ?"; \
		SQLPARAMS_PUSH(params, "s", std::string, query->employee_id.getValue("")); \
}\
if (query->employee_name) {\
		sql << " and tpp.PIMPERSONNAME = ?"; \
		SQLPARAMS_PUSH(params, "s", std::string, query->employee_name.getValue("")); \
}\
if (query->org_name) {\
		sql << " and tpp.ORMORGNAME = ?"; \
		SQLPARAMS_PUSH(params, "s", std::string, query->org_name.getValue("")); \
}\
if (query->jobtitle_name) {\
		sql << " and tpg.PIMTITLECATALOGUENAME = ?"; \
		SQLPARAMS_PUSH(params, "s", std::string, query->jobtitle_name.getValue("")); \
}\
if (query->jobtitle_grades) {\
		sql << " and btt.TITLEGRADENAME = ?"; \
		SQLPARAMS_PUSH(params, "s", std::string, query->jobtitle_grades.getValue("")); \
}\
if (query->b_highest_professional_title) {\
		sql << " and tpp.HIGHTITLE = ?"; \
		SQLPARAMS_PUSH(params, "s", std::string, query->b_highest_professional_title.getValue("")); \
}\

uint64_t JobTitleInfoDAO::count(const JobTitleQuery::Wrapper& query)
{
	stringstream sql;
	sql << "select count(*) from t_pimtitle as tpt LEFT JOIN t_pimperson as tpp on tpt.PIMPERSONID = tpp.PIMPERSONID LEFT JOIN t_pimtitlecatalogue as tpc ON ";
	sql << "tpt.PIMTITLEID = tpc.PIMTITLEID LEFT JOIN bis_titlegrade_t as btt on tpt.ZCDJ = btt.TITLEGRADEVALUE LEFT JOIN bis_professoranalysis_t as bpt ON bpt.EMPLOYEEID = tpt.EMPLOYTIME ";
	sql << "LEFT JOIN t_personstatemgr  as tpr ON tpr.PERSONSTATECODE = tpp.YGZT LEFT JOIN t_pimtitlecatalogue as tpg ON tpg.PIMTITLECATALOGUEID = tpt.PIMTITLECATALOGUEID ";
	sql << "where 1=1 ";
	//sql << "where tpp.YGBH is not NULL and tpg.PIMTITLECATALOGUENAME is not NULL ";
	// �鿴�Ƿ��в���������д��ϲ�����ѯ
	SAMPLE_QUERY_PARSE(query, sql);
	string sqlStr = sql.str();
	if (!query->param && !query->employee_id && !query->employee_name && !query->org_name && !query->jobtitle_name && !query->jobtitle_grades && !query->b_highest_professional_title) {
		cout << "sql��䣺" << sqlStr << endl;
		return sqlSession->executeQueryNumerical(sqlStr);
	}
	//cout << "sql��䣺" << sqlStr << endl;
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<JobTitleDO> JobTitleInfoDAO::selectAll(const JobTitleDTO::Wrapper& query)
{
	stringstream sql;
	sql << "select tpt.PIMTITLEID as 'ְ����Ϣ��ʶ',tpp.YGBH as 'Ա�����',tpp.PIMPERSONNAME as 'Ա������',tpr.PERSONSTATEMGRNAME as 'Ա��״̬',tpp.ORMORGNAME as '��֯',\
		tpg.PIMTITLECATALOGUENAME as 'ְ������', tpt.ZCHQRQ as 'ְ�ƻ�ȡ����', tpt.ZCBH as '֤����', tpt.MAJORENGAGED as 'רҵ���',\
		btt.TITLEGRADENAME as 'ְ�Ƶȼ�', tpt.EMPLOYTIME as 'ְ��Ƹ��ʱ��', tpt.LSSUINGAGENCY as 'ǩ������', tpt.REVIEWBODY as '����λ', tpp.HIGHTITLE as '���ְ��'\
		from t_pimtitle as tpt LEFT JOIN t_pimperson as tpp on tpt.PIMPERSONID = tpp.PIMPERSONID LEFT JOIN t_pimtitlecatalogue as tpc ON tpt.PIMTITLEID = tpc.PIMTITLEID LEFT JOIN bis_titlegrade_t as btt on tpt.ZCDJ = btt.TITLEGRADEVALUE LEFT JOIN bis_professoranalysis_t as bpt ON bpt.EMPLOYEEID = tpt.EMPLOYTIME LEFT JOIN t_personstatemgr  as tpr ON tpr.PERSONSTATECODE = tpp.YGZT LEFT JOIN t_pimtitlecatalogue as tpg ON tpg.PIMTITLECATALOGUEID = tpt.PIMTITLECATALOGUEID";
	SqlParams params;
	sql << " WHERE 1=1 ";
	JBT_QUERY_PARSE(query, sql);
	JobTitleMapper mapper;
	string sqlStr = sql.str();
	cout << sqlStr << endl;
	return sqlSession->executeQuery<JobTitleDO, JobTitleMapper>(sqlStr,mapper, params);
}

std::vector<std::string> JobTitleInfoDAO::getHead(const JobTitleDTO::Wrapper& query)
{
	// �������ض���
	vector<std::string> head;
	//if (query->employee_id)
		head.push_back(u8"Ա�����");
	//if (query->employee_name)
		head.push_back(u8"Ա������");
	//if (query->org_name)
		head.push_back(u8"��֯");
	//if (query->jobtitle_name)
		head.push_back(u8"ְ������");
	//if (query->get_time)
		head.push_back(u8"��ȡʱ��");
	//if (query->professional_cate)
		head.push_back(u8"רҵ���");
		head.push_back(u8"ְ�Ƶȼ�");
		head.push_back(u8"ְ��Ƹ��ʱ��");
		head.push_back(u8"ǩ������");
		head.push_back(u8"����λ");
		head.push_back(u8"�Ƿ����ְ��");
	return head;
}

int JobTitleInfoDAO::update(const JobTitleDO& uObj)
{
	stringstream sql;
	stringstream fmts; fmts<< "%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s";
	sql << "UPDATE t_pimtitle as tpt\
		LEFT JOIN t_pimperson as tpp ON tpt.PIMPERSONID = tpp.PIMPERSONID\
		LEFT JOIN t_pimtitlecatalogue as tpc ON tpt.PIMTITLEID = tpc.PIMTITLEID\
		LEFT JOIN bis_titlegrade_t as btt on tpt.ZCDJ = btt.TITLEGRADEVALUE\
		LEFT JOIN t_personstatemgr as tpr ON tpr.PERSONSTATECODE = tpp.YGZT\
		LEFT JOIN t_pimtitlecatalogue as tpg ON tpg.PIMTITLECATALOGUEID = tpt.PIMTITLECATALOGUEID\
		SET ";
	sql << "tpp.YGBH = ?,\
		tpp.PIMPERSONNAME = ?,\
		tpr.PERSONSTATEMGRNAME = ?,\
		tpp.ORMORGNAME = ?,\
		tpg.PIMTITLECATALOGUENAME = ?,\
		tpt.ZCHQRQ = ?,\
		tpt.ZCBH = ?,\
		tpt.MAJORENGAGED = ?,\
		btt.TITLEGRADENAME = ?,\
		tpt.EMPLOYTIME = ?,\
		tpt.LSSUINGAGENCY = ?,\
		tpt.REVIEWBODY = ?,\
		tpp.HIGHTITLE = ?\
		WHERE tpt.PIMTITLEID = ? AND tpp.YGBH = ?";
	/*	tpp.YGBH = '123123',\
		tpp.PIMPERSONNAME = '123342231',\
		tpr.PERSONSTATEMGRNAME = '',\
		tpp.ORMORGNAME = 'testOrg',\
		tpg.PIMTITLECATALOGUENAME = '',\
		tpt.ZCHQRQ = '2019-03-01 00:00:00',\
		tpt.ZCBH = '12345678910',\
		tpt.MAJORENGAGED = '',\
		btt.TITLEGRADENAME = '',\
		tpt.EMPLOYTIME = '2019-03-01 00:00:00',\
		tpt.LSSUINGAGENCY = 'δ֪',\
		tpt.REVIEWBODY = 'δ֪',\
		tpp.HIGHTITLE = 'δ֪'\
		WHERE tpt.PIMTITLEID = '04CE5FCB-0581-4EA9-9A01-7B88A01A0027' AND tpp.YGBH = '1813****'; ";*/
	cout << sql.str() << endl;
	return sqlSession->executeUpdate(sql.str(), fmts.str().c_str(),
		uObj.getEmployee_Id(),
		uObj.getEmployee_Name(),
		uObj.getEmployee_State(),
		uObj.getOrg_Name(),
		uObj.getJobtitle_Name(),
		uObj.getGet_Time(),
		uObj.getCertificate_Id(),
		uObj.getProfessional_Cate(),
		uObj.getJobtitle_Grades(),
		uObj.getTitle_Employment_Time(),
		uObj.getIssuing_Authority(),
		uObj.getJudging_Unit(),
		uObj.getB_Highest_Professional_Title(),
		uObj.getId(),uObj.getEmployee_Id());
}
