#pragma once
/*
 Copyright Zero One Star. All rights reserved.
#include "domain/vo/work-history/ModWorkHistoryVO.h"
#include "domain/vo/work-history/WorkHistoryVO.h"
#include "domain/query/work-history/WorkHistoryQuery.h"
#include "domain/dto/work-history/ModWorkHistoryDTO.h"
#include "domain/dto/work-history/WorkHistoryDTO.h"
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#ifndef _WORKHISTORYSERVICE_H_
#define _WORKHISTORYSERVICE_H_

#include "domain/dto/work-history/WorkHistoryFindDTO.h"
#include "domain/query/work-history/WorkHistoryPageQuery.h"
#include "domain/dto/work-history/WorkHistoryDTO.h"
#include "domain/query/work-history/WorkHistoryQuery.h"
#include "domain/dto/work-history/AddWorkHistoryDTO.h"
#include "domain/dto/work-history/DelWorkHistoryDTO.h"
#include "controller/work-history/WorkHistoryController.h"

class WorkHistoryService
{
public:
	// ��ҳ��ѯ��������
	WorkHistoryFindPageDTO::Wrapper listAll(const WorkHistoryPageQuery::Wrapper& query);


	// ����һ������
	uint64_t saveData(const AddWorkHistoryDTO::Wrapper& dto, const PayloadDTO& payload);


	//ɾ������(֧������ɾ��)
	bool removeData(const DelWorkHistoryDTO::Wrapper& dto);


	//ִ�е��루�������������ݣ�
	uint64_t saveManyData(const std::string fileName, const String& pimpersonid, const String& createName);

	//ִ�е������������ݷ���Excel���У�����fastdfs���ӣ�
	std::string exportData(const WorkHistoryExportQuery::Wrapper& query);






	////��ѯ��������
	WorkHistoryDTO::Wrapper listDetail(const WorkHistoryQuery::Wrapper& query);

	bool updateData(const ModWorkHistoryDTO::Wrapper& dto);
};

#endif // !_WORKHISTORYSERVICE_H_