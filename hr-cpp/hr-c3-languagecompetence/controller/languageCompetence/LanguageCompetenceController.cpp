#include "stdafx.h"
#include "LanguageCompetenceController.h"
#include "../../service/language/LanguageService.h"

/**
 * ʵ������������ɾ���ģ��
 * �����ˣ���
 */
LanguagePageJsonVO::Wrapper LanguageCompetenceController::execQueryLanguage(const LanguagePageQuery::Wrapper& query, const PayloadDTO& payload)
{
	// ����һ��Service
	LanguageService service;
	//��ѯ����
	auto result = service.listAll(query);
	//��Ӧ���
	auto jvo = LanguagePageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

LanguageJsonVO::Wrapper LanguageCompetenceController::execQueryOneLanguage(const LanguageQuery::Wrapper& query, const PayloadDTO& payload)
{
	//����һ��Service
	LanguageService service;
	//��ѯ����
	auto result = service.queryOneDataById(query);
	//��Ӧ���
	auto jvo = LanguageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

Int32JsonVO::Wrapper LanguageCompetenceController::execAddLanguage(const LanguageDTO::Wrapper& dto, const PayloadDTO& payload)
{
	//����һ���������ݶ���
	auto jvo = Int32JsonVO::createShared();
	// ����У��
	// �ǿ�У��
	if (!dto->languageType || !dto->languageLevel) {
		jvo->init(Int32(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	//��ЧֵУ��
	if (dto->languageType->empty() || dto->languageLevel->empty()) {
		jvo->init(Int32(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	//��ȡ�����û�ID
	dto->createMan = payload.getId();
	// ����һ��Service
	LanguageService service;
	// ִ����������
	int count = service.saveData(dto);
	if (count > 0) {
		jvo->success(Int32(count));
	}
	else
	{
		jvo->fail(Int32(count));
	}
	//��Ӧ���
	return jvo;
}

Int32JsonVO::Wrapper LanguageCompetenceController::execDeleteLanguage(const DeleteLanguageDTO::Wrapper& dto, const PayloadDTO& payload)
{
	//����һ�����ض���
	auto jvo = Int32JsonVO::createShared();
	// ����У��
	int length = dto->languageAbilityID->size();
	if (length <= 0)
	{
		jvo->init(Int32(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	for (auto it = dto->languageAbilityID->begin(); it != dto->languageAbilityID->end(); it++) {
		if (!(*it)) {
			jvo->init(Int32(-1), RS_PARAMS_INVALID);
			return jvo;
		}
	}
	// ����һ��Service
	LanguageService service;
	// ִ������ɾ��
	int count = service.removeData(dto);
	if (count > 0) {
		jvo->success(Int32(count));
	}
	else
	{
		jvo->fail(Int32(count));
	}
	// ��Ӧ���
	return jvo;
}

BooleanJsonVO::Wrapper LanguageCompetenceController::execUpdateLanguage(const LanguageDTO::Wrapper& dto, const PayloadDTO& payload)
{
	//����һ�����ض���
	auto jvo = BooleanJsonVO::createShared();
	//����У��
	if (!dto->languageAbilityID) {
		jvo->init(false, RS_PARAMS_INVALID);
		return jvo;
	}
	//��ȡ�����û�ID
	dto->updateMan = payload.getId();
	//����һ��Service
	LanguageService service;
	// ִ�������޸�
	if (service.updateData(dto)) {
		jvo->success(true);
	}
	else
	{
		jvo->fail(false);
	}
	// ��Ӧ���
	return jvo;
}
