/*
 Copyright Zero One Star. All rights reserved.

 @Author: guyier
 @Date: 2023/05/25 22:04:02

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#include "stdafx.h"
#include "EmployeeInformationDAO.h"
#include "EmployeeInformationMapper.h"
#include <sstream>


//�������������꣬�����ظ�����
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->personId) { \
	sql << " AND `PIMPERSONID`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->personId.getValue("")); \
} \
if (query->name) { \
	sql << " AND `PIMPERSONNAME`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->name.getValue("")); \
} \
if (query->id) { \
	sql << " AND `YGBH`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->id.getValue("")); \
} \
if (query->age) { \
	sql << " AND `NL`=?"; \
	SQLPARAMS_PUSH(params, "i", int, query->age.getValue(0)); \
}\
if (query->organize) { \
	sql << " AND `ZZ`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->organize.getValue("")); \
}\
if (query->depart) { \
	sql << " AND `BM`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->depart.getValue("")); \
}\
if (query->job) { \
	sql << " AND `ZW`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->job.getValue("")); \
}\
if (query->post) { \
	sql << " AND `GW`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->post.getValue("")); \
}\
if (query->idMum) { \
	sql << " AND `ZJHM`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->idMum.getValue("")); \
}\
if (query->birthday) { \
	sql << " AND `CSRQ`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->birthday.getValue("")); \
}\
if (query->phone) { \
	sql << " AND `LXDH`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->phone.getValue("")); \
}\
if (query->state) { \
	sql << " AND `YGZT`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->state.getValue("")); \
}


// ͳ����������
uint64_t EmployeeInformationDAO::count(const EmployeeInformationPageQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM t_pimperson";
	SAMPLE_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}
// ��ҳ��ѯ����
std::list<EmployeeInformationPageDO> EmployeeInformationDAO::selectWithPage(const EmployeeInformationPageQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT * FROM t_pimperson";
	SAMPLE_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	EmployeeInformationMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<EmployeeInformationPageDO, EmployeeInformationMapper>(sqlStr, mapper, params);
}
// ��������
uint64_t EmployeeInformationDAO::insert(const EmployeeInformationPageDO& iObj)
{
	string sql= "INSERT INTO `t_pimperson` (`PIMPERSONID`,`CREATEMAN`,`CREATEDATE`,`PIMPERSONNAME`,\
    `NL`,`YGBH`,`ZZ`,`BM`,`ZW`,`GW`,`ZJHM`,`CSRQ`,`LXDH`,`YGZT`) \
     VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
	return sqlSession->executeUpdate(sql,"%s%s%s%s%i%s%s%s%s%s%s%s%s%s",\
		iObj.getPersonId(),iObj.getCreateMan(),iObj.getCreateDate(),iObj.getName(),iObj.getAge(),\
		iObj.getId(),iObj.getOrganize(),iObj.getDepart(),iObj.getJob(), iObj.getPost(),iObj.getIdMum(),\
		iObj.getBirthday(),iObj.getPhone(),iObj.getState());
}
//��Ա����Ϣ����������Ա����Ϣ��
//std::list<std::string> EmployeeInformationDAO::insertMultiEmp(const std::list<EmployeeInformationPageDO>& data) {
//	// �������ض���
//	std::list<std::string> res;
//
//	// ����������
//	sqlSession->beginTransaction();
//
//	// ����������λ����
//	for (auto item : data)
//	{
//		// ���õ�������
//		string sql = "INSERT INTO `t_ormpost` (`PIMPERSONID`,`CREATEMAN`,`CREATEDATE`,`PIMPERSONNAME`,\
//    `NL`,`YGBH`,`ZZ`,`BM`,`ZW`,`GW`,`ZJHM`,`CSRQ`,`LXDH`,`YGZT`) \
//     VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
//
//		int row = sqlSession->executeUpdate(sql, "%s%s%s%s%i%s%s%s%s%s%s%s%s%s", \
//			item.getPersonId(), item.getCreateMan(), item.getCreateDate(), item.getName(), item.getAge(), \
//			item.getId(), item.getOrganize(), item.getDepart(), item.getJob(), item.getPost(), item.getIdMum(), \
//			item.getBirthday(), item.getPhone(), item.getState());
//
//		// �����ɹ���id���뷵���б���
//		if (row == 1)
//		{
//			res.push_back(item.getPersonId());
//		}
//		// ������ع�������ʧ��
//		else
//		{
//			sqlSession->rollbackTransaction();
//			res.clear();
//			return res;
//		}
//	}
//
//	// ȫ�������ɹ����ύ�����سɹ�
//	sqlSession->commitTransaction();
//	return res;
//}

//����Ա����Ϣ(������ҳ��ǰ�����)
std::list<EmployeeInformationPageDO> EmployeeInformationDAO::exportEmpInfo(const PostDetailQuery::Wrapper& query)
{
	stringstream sqltmp;
	sqltmp << "SELECT `PIMPERSONNAME`, `NL`, `YGBH`, `ZZ`, ";
	sqltmp << "`BM`, `ZW`, `GW`, `ZJHM`, `CSRQ`, `LXDH`, `YGZT`, ";
	sqltmp << " FROM `t_pimperson`";
	sqltmp << "ORDER BY `YGBH` ";
	string sql = sqltmp.str();
	if (query->sortTypeAndMethod == "DESC") {
		string sql = sqltmp.str() + " DESC";
	}
	else if (query->sortTypeAndMethod == "ASC") {
		string sql = sqltmp.str() + " ASC";
	}
	//ͳ�Ƹ�λ��Ϣ����
	stringstream sqlcount;
	sqlcount << "SELECT COUNT(`YGBH`) FROM `t_pimperson`";
	string count = sqlcount.str();
	long long infoCount = sqlSession->executeQueryNumerical(count);
	//���Ƶ�������
	if (infoCount) {
		if (infoCount > 5000) {
			infoCount = 5000;
			sql +=" LIMIT " + to_string(infoCount);
		}

	}

	EmployeeInformationMapper mapper;

	return sqlSession->executeQuery<EmployeeInformationPageDO, EmployeeInformationMapper>(sql, mapper);
}
//���ɱ�ͷ
vector<std::string> EmployeeInformationDAO::getEmpInfoHead()
{
	// �������ض���
	vector<std::string> head;

	string sql = "SELECT COLUMN_NAME FROM information_schema.COLUMNS WHERE TABLE_NAME = 't_pimperson' ORDER BY ORDINAL_POSITION";
	Statement* st = sqlSession->getConnection()->createStatement();
	ResultSet* res;

	res = st->executeQuery(sql);
	while (res->next())
	{
		head.push_back(res->getString(1));
	}

	st->close();
	res->close();
	return head;
}


