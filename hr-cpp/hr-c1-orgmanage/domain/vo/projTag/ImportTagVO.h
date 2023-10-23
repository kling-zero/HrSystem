#pragma once
#ifndef _IMPORTTAG_VO_
#define _IMPORTTAG_VO_

#include "../../GlobalInclude.h"
#include "domain/dto/projTag/ImportTagDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����װ�������ݿ�����ֶε�list
 * �����ˣ�Զ��
 */
class ImportTagVO : public oatpp::DTO
{
	DTO_INIT(ImportTagVO, DTO);
	DTO_FIELD(List<String>, newId) = {};
	DTO_FIELD_INFO(newId) {
		info->description = ZH_WORDS_GETTER("projTag.import.summary");
	}
};

/**
 * ʾ����ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class ImportProjTagJsonVO : public JsonVO<ImportTagVO::Wrapper> {
	DTO_INIT(ImportProjTagJsonVO, JsonVO<ImportTagVO::Wrapper>);
};

/**
 * ʾ����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class ImportProjTagPageJsonVO : public JsonVO<ImportTagPageDTO::Wrapper> {
	DTO_INIT(ImportProjTagPageJsonVO, JsonVO<ImportTagPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_IMPORTTAG_VO_