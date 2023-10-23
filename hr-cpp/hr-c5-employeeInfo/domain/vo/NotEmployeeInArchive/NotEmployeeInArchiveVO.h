#pragma once

#ifndef _NOT_EMPLOYEE_IN_ARCHIVE_VO_
#define _NOT_EMPLOYEE_IN_ARCHIVE_VO_

#include "../../GlobalInclude.h"
#include "../../dto/NotEmployeeInArchive/NotEmployeeInArchiveDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class NotEmployeeInArchiveVO : public JsonVO<NotEmployeeInArchiveDTO::Wrapper> {
	DTO_INIT(NotEmployeeInArchiveVO, JsonVO<NotEmployeeInArchiveDTO::Wrapper>);
};

/**
 * ��ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class NotEmployeeInArchivePageJsonVO : public JsonVO<NotEmployeeInArchivePageDTO::Wrapper> {
	DTO_INIT(NotEmployeeInArchivePageJsonVO, JsonVO<NotEmployeeInArchivePageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_NOT_EMPLOYEE_IN_ARCHIVE_