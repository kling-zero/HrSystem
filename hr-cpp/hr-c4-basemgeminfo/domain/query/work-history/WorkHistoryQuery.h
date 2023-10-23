#pragma once
#ifndef _WORKHISTORY_QUERY_H_
#define _WORKHISTORY_QUERY_H_
#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"
#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * ����һ����ѯ�û���Ϣ�����ݴ���ģ��
 */
class WorkHistoryQuery : public oatpp::DTO
{
	// �����ʼ��
	DTO_INIT(WorkHistoryQuery, DTO);
	
	//��ְ��ʼʱ��
	DTO_FIELD(String, rzkssj);
	DTO_FIELD_INFO(rzkssj) {
		info->description = ZH_WORDS_GETTER("workhistory.field.rzkssj");
	}


	//��ְ����ʱ��
	DTO_FIELD(String, rzjssj);
	DTO_FIELD_INFO(rzjssj) {
		info->description = ZH_WORDS_GETTER("workhistory.field.rzjssj");
	}

	//������λ
	DTO_FIELD(String, ormorgname);
	DTO_FIELD_INFO(ormorgname) {
		info->description = ZH_WORDS_GETTER("workhistory.field.ormorgname");
	}

	//4����
	DTO_INIT_(String, ormorgsectorname, "workhistory.field.ormorgsectorname")

	//5ְ��
	DTO_INIT_(String, ormdutyname, "workhistory.field.ormdutyname")

	//6��λ
	DTO_INIT_(String, ormpostname, "workhistory.field.ormpostname")

	//7��ְ�������
	DTO_FIELD(String, cfplx);
	DTO_FIELD_INFO(cfplx) {
		info->description = ZH_WORDS_GETTER("workhistory.field.cfplx");
	}

	//8�Ƿ���Ҫ����
	DTO_FIELD(UInt64, experience);
	DTO_FIELD_INFO(experience) {
		info->description = ZH_WORDS_GETTER("workhistory.field.experience");
	}
	//��Ա��Ϣid
	DTO_FIELD(String, pimpersionid);
	DTO_FIELD_INFO(pimpersionid) {
		info->description = ZH_WORDS_GETTER("workhistory.field.pimpersionid");
	}

	//��Ա��Ϣ��ʶpimworkhistoryid
	DTO_FIELD(String, pimworkhistoryid);
	DTO_FIELD_INFO(pimworkhistoryid) {
		info->description = ZH_WORDS_GETTER("workhistory.field.pimworkhistoryid");
	}
	//����ʱ��updatedate
	DTO_FIELD(String, updatedate);
	DTO_FIELD_INFO(updatedate) {
		info->description = ZH_WORDS_GETTER("workhistory.field.updatedate");
	}
	//������updateman
	DTO_FIELD(String, updateman);
	DTO_FIELD_INFO(updateman) {
		info->description = ZH_WORDS_GETTER("workhistory.field.updateman");
	}
	
};

#include OATPP_CODEGEN_END(DTO)
#endif 
