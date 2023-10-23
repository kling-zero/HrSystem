#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: ahao
 @Date: 2023/06/06 11:25:40

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
#ifndef _IMPORT_ASSIGN_INFO_DTO_
#define _IMPORT_ASSIGN_INFO_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 导入员工信息
 */
class ImportAssignInfoDTO : public oatpp::DTO
{
	DTO_INIT(ImportAssignInfoDTO, DTO);
	// 文件类型
	DTO_FIELD_INFO(fileType) {
		info->description = ZH_WORDS_GETTER("importInfo.import.fileType");
	}
	DTO_FIELD(String, fileType);
	// 数据表名
	DTO_FIELD_INFO(sheetName) {
		info->description = ZH_WORDS_GETTER("importInfo.import.sheetName");
	}
	DTO_FIELD(String, sheetName);
	// 文件路径(后端产生)
	DTO_FIELD(String, filePath);
	DTO_FIELD(Vector<Vector<String>>, fileData);

public:
	ImportAssignInfoDTO()
	{
		fileType = "xlsx";
		filePath = "";
		sheetName = "";
	}

	ImportAssignInfoDTO(String type, String name, String path)
	{
		fileType = type;
		sheetName = name;
		filePath = path;
	}
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_IMPORT_ASSIGN_INFO_DTO_
