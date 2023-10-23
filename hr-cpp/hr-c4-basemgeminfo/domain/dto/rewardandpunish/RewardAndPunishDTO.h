#pragma once
#ifndef _REWARDANDPUNISHDTO_H_
#define _REWARDANDPUNISHDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
class RewardAndPunishDTO : public oatpp::DTO {
	DTO_INIT(RewardAndPunishDTO, DTO);

	//����ʱ��
	DTO_FIELD(String, CREATEDATE);
	DTO_FIELD_INFO(CREATEDATE) {
		info->description = ZH_WORDS_GETTER("rewardandpunish.createdate");
	}

	//����ʱ��
	DTO_FIELD(String, UPDATEDATE);
	DTO_FIELD_INFO(UPDATEDATE) {
		info->description = ZH_WORDS_GETTER("rewardandpunish.updatedate");
	}

	//��������
	DTO_FIELD(String, PIMREWARDPUNISHMENTNAME);
	DTO_FIELD_INFO(PIMREWARDPUNISHMENTNAME) {
		info->description = ZH_WORDS_GETTER("rewardandpunish.pimrewardpunishmentname");
	}

	//������
	DTO_FIELD(String, UPDATEMAN);
	DTO_FIELD_INFO(UPDATEMAN) {
		info->description = ZH_WORDS_GETTER("rewardandpunish.updateman");
	}

	//������
	DTO_FIELD(String, CREATEMAN);
	DTO_FIELD_INFO(CREATEMAN) {
		info->description = ZH_WORDS_GETTER("rewardandpunish.createman");
	}

	//����
	DTO_FIELD(String, ENABLE);
	DTO_FIELD_INFO(ENABLE) {
		info->description = ZH_WORDS_GETTER("rewardandpunish.enable");
	}

	//����
	DTO_FIELD(String, FJ);
	DTO_FIELD_INFO(FJ) {
		info->description = ZH_WORDS_GETTER("rewardandpunish.fj");
	}

	//���ͷ���
	DTO_FIELD(String, LX);
	DTO_FIELD_INFO(LX) {
		info->description = ZH_WORDS_GETTER("rewardandpunish.lx");
	}

	//��������
	DTO_FIELD(String, CSRQ);
	DTO_FIELD_INFO(CSRQ) {
		info->description = ZH_WORDS_GETTER("rewardandpunish.csrq");
	}

	// ���ͳͷ���ʶ��������
	DTO_FIELD(String, PIMREWARDPUNISHMENTID);
	DTO_FIELD_INFO(PIMREWARDPUNISHMENTID) {
		info->description = ZH_WORDS_GETTER("rewardandpunish.pimrewardpunishmentid");
	}

	// ��Ա��Ϣ��ʶ
	DTO_FIELD(String, PIMPERSONID);
	DTO_FIELD_INFO(PIMPERSONID) {
		info->description = ZH_WORDS_GETTER("rewardandpunish.pimpersonid");
	}

	//���ͼ���
	DTO_FIELD(String, JCJB);
	DTO_FIELD_INFO(JCJB) {
		info->description = ZH_WORDS_GETTER("rewardandpunish.jcjb");
	}

	//���ͼ���
	DTO_FIELD(String, JCLX);
	DTO_FIELD_INFO(JCLX) {
		info->description = ZH_WORDS_GETTER("rewardandpunish.jclx");
	}

	//����ʱ��
	DTO_FIELD(String, JLSJ);
	DTO_FIELD_INFO(JLSJ) {
		info->description = ZH_WORDS_GETTER("rewardandpunish.jlsj");
	}

	//�ͷ�ʱ��
	DTO_FIELD(String, CFSJ);
	DTO_FIELD_INFO(CFSJ) {
		info->description = ZH_WORDS_GETTER("rewardandpunish.cfsj");
	}

	//���ͽ��
	DTO_FIELD(String, JCJE);
	DTO_FIELD_INFO(JCJE) {
		info->description = ZH_WORDS_GETTER("rewardandpunish.jcje");
	}

	//�����¼�
	DTO_FIELD(String, JCSJ);
	DTO_FIELD_INFO(JCSJ) {
		info->description = ZH_WORDS_GETTER("rewardandpunish.jcsj");
	}

	//��ע
	DTO_FIELD(String, BZ);
	DTO_FIELD_INFO(BZ) {
		info->description = ZH_WORDS_GETTER("rewardandpunish.bz");
	}

	//�ͷ�����
	DTO_FIELD(String, CFLX);
	DTO_FIELD_INFO(CFLX) {
		info->description = ZH_WORDS_GETTER("rewardandpunish.cflx");
	}

	//��¼����
	DTO_FIELD(String, JLSS);
	DTO_FIELD_INFO(JLSS) {
		info->description = ZH_WORDS_GETTER("rewardandpunish.jlss");
	}

	//��¼������
	DTO_FIELD(String, JLGLBH);
	DTO_FIELD_INFO(JLGLBH) {
		info->description = ZH_WORDS_GETTER("rewardandpunish.jlglbh");
	}

	//��¼����״̬
	DTO_FIELD(String, JLSPZT);
	DTO_FIELD_INFO(JLSPZT) {
		info->description = ZH_WORDS_GETTER("rewardandpunish.jlspzt");
	}

	//��¼������
	DTO_FIELD(String, JLCZZ);
	DTO_FIELD_INFO(JLCZZ) {
		info->description = ZH_WORDS_GETTER("rewardandpunish.jlczz");
	}

	//Ӱ���ڽ�������
	DTO_FIELD(String, YXQJSRQ);
	DTO_FIELD_INFO(YXQJSRQ) {
		info->description = ZH_WORDS_GETTER("rewardandpunish.yxqjsrq");
	}

	//���赥λ
	DTO_FIELD(String, DEPARTMENT);
	DTO_FIELD_INFO(DEPARTMENT) {
		info->description = ZH_WORDS_GETTER("rewardandpunish.department");
	}

	//�ܾ�ԭ��
	DTO_FIELD(String, REASON);
	DTO_FIELD_INFO(REASON) {
		info->description = ZH_WORDS_GETTER("rewardandpunish.reason");
	}

};

/**
 * ʾ����ҳ�������
 */
class RewardAndPunishPageDTO : public PageDTO<RewardAndPunishDTO::Wrapper>
{
	DTO_INIT(RewardAndPunishPageDTO, PageDTO<RewardAndPunishDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)
#endif