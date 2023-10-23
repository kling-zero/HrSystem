#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/05/24 19:36:34

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
#ifndef _ORGLISTDTO_H_
#define _ORGLISTDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��֯�б�DTO����ģ��
 * �����ˣ�Andrew
 */
class OrgListDTO : public oatpp::DTO
{
	DTO_INIT(OrgListDTO, DTO);
	// ������
	DTO_FIELD(String, regionSubsidy);
	DTO_FIELD_INFO(regionSubsidy) {
		info->description = ZH_WORDS_GETTER("projTag.orgList.regionSubsidy");
	}
	// ��˾����֯ID
	DTO_FIELD(String, flag);
	DTO_FIELD_INFO(flag) {
		info->description = ZH_WORDS_GETTER("projTag.orgList.flag");
	}
	// ����ʱ��
	DTO_FIELD(String, createTime);
	DTO_FIELD_INFO(createTime) {
		info->description = ZH_WORDS_GETTER("projTag.orgList.createTime");
	}
	// ������
	DTO_FIELD(String, createby);
	DTO_FIELD_INFO(createby) {
		info->description = ZH_WORDS_GETTER("projTag.orgList.creator");
	}
	// ����ʱ��
	DTO_FIELD(String, updateTime);
	DTO_FIELD_INFO(updateTime) {
		info->description = ZH_WORDS_GETTER("projTag.orgList.updateTime");
	}
	// ������
	DTO_FIELD(String, updater);
	DTO_FIELD_INFO(updater) {
		info->description = ZH_WORDS_GETTER("projTag.orgList.updater");
	}
	// ERP��֯ID
	DTO_FIELD(String, erpOrgId);
	DTO_FIELD_INFO(erpOrgId) {
		info->description = ZH_WORDS_GETTER("projTag.orgList.erpOrgId");
	}
	// ��������
	DTO_FIELD(String, belongRegion);
	DTO_FIELD_INFO(belongRegion) {
		info->description = ZH_WORDS_GETTER("projTag.orgList.belongRegion");
	}
	// ��֯����
	DTO_FIELD(String, legalEntity);
	DTO_FIELD_INFO(legalEntity) {
		info->description = ZH_WORDS_GETTER("projTag.orgList.legalEntity");
	}
	// �������
	DTO_FIELD(String, levelCode);
	DTO_FIELD_INFO(levelCode) {
		info->description = ZH_WORDS_GETTER("projTag.orgList.levelCode");
	}
	// ��֯���
	DTO_FIELD(String, orgCode);
	DTO_FIELD_INFO(orgCode) {
		info->description = ZH_WORDS_GETTER("projTag.orgList.orgCode");
	}
	// ��֯������ʶ
	DTO_FIELD(String, orgId);
	DTO_FIELD_INFO(orgId) {
		info->description = ZH_WORDS_GETTER("projTag.orgList.orgId");
	}
	// ��֯��������
	DTO_FIELD(String, orgName);
	DTO_FIELD_INFO(orgName) {
		info->description = ZH_WORDS_GETTER("projTag.orgList.orgName");
	}
	// �ϼ���֯����
	DTO_FIELD(String, porgId);
	DTO_FIELD_INFO(porgId) {
		info->description = ZH_WORDS_GETTER("projTag.orgList.porgId");
	}
	// �ϼ���֯��������
	DTO_FIELD(String, porgName);
	DTO_FIELD_INFO(porgName) {
		info->description = ZH_WORDS_GETTER("projTag.orgList.porgName");
	}
	// ���
	DTO_FIELD(String, shortname);
	DTO_FIELD_INFO(shortname) {
		info->description = ZH_WORDS_GETTER("projTag.orgList.shortname");
	}
	// ����OU
	DTO_FIELD(String, belongou);
	DTO_FIELD_INFO(belongou) {
		info->description = ZH_WORDS_GETTER("projTag.orgList.belongou");
	}
	// ��ͣ��ʶ
	DTO_FIELD(String, sign);
	DTO_FIELD_INFO(sign) {
		info->description = ZH_WORDS_GETTER("projTag.orgList.sign");
	}
	// ��֯��ַ����
	DTO_FIELD(String, orgAddrCode);
	DTO_FIELD_INFO(orgAddrCode) {
		info->description = ZH_WORDS_GETTER("projTag.orgList.orgAddrCode");
	}
	// ��֯��ַ1
	DTO_FIELD(String, orgAddrOne);
	DTO_FIELD_INFO(orgAddrOne) {
		info->description = ZH_WORDS_GETTER("projTag.orgList.orgAddr1");
	}
	// ��֯��ַ2
	DTO_FIELD(String, orgAddrTwo);
	DTO_FIELD_INFO(orgAddrTwo) {
		info->description = ZH_WORDS_GETTER("projTag.orgList.orgAddr2");
	}
	// ��֯����ʱ��
	DTO_FIELD(String, orgCreateTime);
	DTO_FIELD_INFO(orgCreateTime) {
		info->description = ZH_WORDS_GETTER("projTag.orgList.orgCreateTime");
	}
	// ��֯��ʾ����
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("projTag.orgList.name");
	}
	// ��֯����
	DTO_FIELD(String, orgType);
	DTO_FIELD_INFO(orgType) {
		info->description = ZH_WORDS_GETTER("projTag.orgList.orgType");
	}
	// ��ӦOU
	DTO_FIELD(String, correspondou);
	DTO_FIELD_INFO(correspondou) {
		info->description = ZH_WORDS_GETTER("projTag.orgList.correspondou");
	}

public:
	OrgListDTO()
	{
		regionSubsidy = "";
		flag = "";
		correspondou = "";
		createby = "admin";
		updater = "admin";
		createTime = "2000-01-01 00:00:00";
		updateTime = "2000-01-01 00:00:00";
		erpOrgId = "";
		belongRegion = "";
		legalEntity = "";
		levelCode = "";
		orgCode = "";
		orgId = "";
		orgName = "";
		porgId = "";
		shortname = "";
		belongou = "";
		sign = "";
		orgAddrCode = "";
		orgAddrOne = "";
		orgAddrTwo = "";
		orgCreateTime = "";
		name = "";
		orgType = "";
	}
};

/**
 * ��ҳ��֯�б�DTO
 * �����ˣ�Andrew
 */
class OrgListPageDTO : public PageDTO<OrgListDTO::Wrapper>
{
	DTO_INIT(OrgListPageDTO, PageDTO<OrgListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_ORGLISTDTO_H_