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
#ifndef _PIMARMYCADRESSERVICE_H_
#define _PIMARMYCADRESSERVICE_H_

#include "domain/dto/pimarmycadres/PimarmycadresFindDTO.h"
#include "domain/dto/pimarmycadres/AddPimarmycadresDTO.h"
#include "domain/dto/pimarmycadres/DelPimarmycadresDTO.h"
#include "domain/query/pimarmycadres/PimarmycadresPageQuery.h"
#include "domain/dto/pimarmycadres/PimarmycadresIntoDTO.h"
#include "domain/query/pimarmycadres/PimarmycadresQuery.h"
//#include"D:\big��Ŀ\zero-one-hrsys\hr-cpp\lib-oatpp\include\oatpp\web\server\api\ApiController.hpp"
#include"../lib-oatpp/include/oatpp/web/server/api/ApiController.hpp"
#include <oatpp/web/client/ApiClient.hpp>
#include <oatpp/web/client/ApiClient.hpp>
class PimarmycadresService
{
public:
	// ��ҳ��ѯ��������	
	PimarmycadresFindPageDTO::Wrapper listAll(const PimarmycadresPageQuery::Wrapper& query);

	uint64_t saveData(const AddPimarmycadresDTO::Wrapper& dto, const PayloadDTO& payload);




	//ɾ������(֧������ɾ��)
	bool removeData(const DelPimarmycadresDTO::Wrapper& dto);


	//ִ�е��루�������������ݣ�
	uint64_t saveManyData(const oatpp::String& fileBody, const oatpp::data::mapping::type::String& suffix, const oatpp::data::mapping::type::String& pimpersonid, const PayloadDTO& payload);

	//�б���ϸ
	PimarmycadresDTO::Wrapper listDetail(const PimarmycadresQuery::Wrapper& query);

	bool updateData(const PimarmycadresDTO::Wrapper& dto);
};

#endif 