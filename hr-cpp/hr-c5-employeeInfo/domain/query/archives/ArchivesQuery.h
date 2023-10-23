#pragma once
#ifndef _ARVHIVES_QUERY_
#define _ARVHIVES_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ҳ��ѯ����
 */
class ArchivesQuery : public PageQuery
{
	DTO_INIT(ArchivesQuery, PageQuery);

	//�ֶ�ע�ͣ��������ֶ��ڱ��е�����	
	//������Ϣ��ʶ��t_pimarchives, 1
	DTO_FIELD(String, pimArchivesId);
	DTO_FIELD_INFO(pimArchivesId) {
		info->description = ZH_WORDS_GETTER("archives.newField.pimArchivesId");
	}

	// ������ţ�t_pimarchives, 8
	DTO_FIELD(String, dabh);
	DTO_FIELD_INFO(dabh) {
		info->description = ZH_WORDS_GETTER("archives.newField.dabh");
	}

	// ����λ��t_srforg��7
	DTO_FIELD(String, orgName);
	DTO_FIELD_INFO(orgName) {
		info->description = ZH_WORDS_GETTER("archives.newField.orgName");
	}

	// �������ܵأ�t_pimarchives, 10
	DTO_FIELD(String, dabgd);
	DTO_FIELD_INFO(dabgd) {
		info->description = ZH_WORDS_GETTER("archives.newField.dabgd");
	}

	// �����ң�t_archivescenter, 2
	DTO_FIELD(String, archivesCenterName);
	DTO_FIELD_INFO(archivesCenterName) {
		info->description = ZH_WORDS_GETTER("archives.newField.archivesCenterName");
	}

	// ����״̬��t_pimarchives, 9
	DTO_FIELD(String, dazt);
	DTO_FIELD_INFO(dazt) {
		info->description = ZH_WORDS_GETTER("archives.newField.dazt");
	}

	// Ա����ţ�t_pimperson, 8
	DTO_FIELD(String, ygbh);
	DTO_FIELD_INFO(ygbh) {
		info->description = ZH_WORDS_GETTER("archives.newField.ygbh");
	}

	// Ա��������t_pimperson, 3
	DTO_FIELD(String, pimPersonName);
	DTO_FIELD_INFO(pimPersonName) {
		info->description = ZH_WORDS_GETTER("archives.newField.pimPersonName");
	}

	// Ա��״̬, t_pimperson, 35
	DTO_FIELD(String, ygzt);
	DTO_FIELD_INFO(ygzt) {
		info->description = ZH_WORDS_GETTER("archives.newField.ygzt");
	}

	// ������λ, t_pimarchives, 30
	DTO_FIELD(String, ormOrgName);
	DTO_FIELD_INFO(ormOrgName) {
		info->description = ZH_WORDS_GETTER("archives.newField.ormOrgName");
	}

	//����δת������

	// ��������״̬, t_pimarchives
	DTO_FIELD(String, zt);
	DTO_FIELD_INFO(zt) {
		info->description = ZH_WORDS_GETTER("archives.newField.zt");
	}

	//-----------��������ϸ��ѯ�Լ�������Ҫ�õ����ֶ�-----------------

	// ��������״̬, t_pimarchives
	DTO_FIELD(String, education);
	DTO_FIELD_INFO(education) {
		info->description = ZH_WORDS_GETTER("archives.newField.education");
	}

	// ��������ʱ��, t_pimarchives
	DTO_FIELD(String, dateOfBirth);
	DTO_FIELD_INFO(dateOfBirth) {
		info->description = ZH_WORDS_GETTER("archives.newField.dateOfBirth");
	}

	// �����뵳ʱ��, t_pimarchives
	DTO_FIELD(String, joinPartyDate);
	DTO_FIELD_INFO(joinPartyDate) {
		info->description = ZH_WORDS_GETTER("archives.newField.joinPartyDate");
	}

	// ��ӹ���ʱ��, t_pimarchives
	DTO_FIELD(String, startWorkDatae);
	DTO_FIELD_INFO(startWorkDatae) {
		info->description = ZH_WORDS_GETTER("archives.newField.startWorkDatae");
	}
	//-------------�����Ψһ��ʶ----------------
	// Ψһ��ʶ�������, t_pimperson
	DTO_FIELD(String, pimPersonId);
	DTO_FIELD_INFO(pimPersonId) {
		info->description = ZH_WORDS_GETTER("archives.newField.pimPersonId");
	}
	// Ψһ��ʶ�������, t_srforg
	DTO_FIELD(String, orMorGId3);
	DTO_FIELD_INFO(orMorGId3) {
		info->description = ZH_WORDS_GETTER("archives.newField.orMorGId3");
	}
	// Ψһ��ʶ�������, t_archivescenter
	DTO_FIELD(String, archivesCenterId);
	DTO_FIELD_INFO(archivesCenterId) {
		info->description = ZH_WORDS_GETTER("archives.newField.archivesCenterId");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_QUERY_