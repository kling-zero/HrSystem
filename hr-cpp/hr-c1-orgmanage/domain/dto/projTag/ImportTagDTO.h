#pragma once
 /*
 Copyright Zero One Star. All rights reserved.

 @Author: yuanxiang
 @Date: 2023/05/19 9:00:36

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
#ifndef _IMPORTTAGDTO_H_
#define _IMPORTTAGDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * ������Ŀ��ǩDTO
 * �����ˣ�Զ��
 */
class ImportTagDTO : public oatpp::DTO
{
	DTO_INIT(ImportTagDTO, DTO);
	// �ļ�����
	DTO_FIELD_INFO(fileType) {
		info->description = ZH_WORDS_GETTER("projTag.import.fileType");
	}
	DTO_FIELD(String, fileType);
	// ���ݱ���
	DTO_FIELD_INFO(sheetName) {
		info->description = ZH_WORDS_GETTER("projTag.import.sheetName");
	}
	DTO_FIELD(String, sheetName);
	// �ļ�·��(��˲���)
	DTO_FIELD(String, filePath);
	DTO_FIELD(Vector<Vector<String>>, fileData);
public:
	ImportTagDTO() {
		fileType = "xlsx";
		sheetName = "sheet1";
		filePath = "";
	}
	ImportTagDTO(String fileN, String sheetN, String fileP) {
		fileType = fileN;
		sheetName = sheetN;
		filePath = fileP;
	}
};
class ImportTagPageDTO : public PageDTO<ImportTagDTO::Wrapper>
{
	DTO_INIT(ImportTagPageDTO, PageDTO<ImportTagDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)

#endif // !_IMPORTTAGDTO_H_