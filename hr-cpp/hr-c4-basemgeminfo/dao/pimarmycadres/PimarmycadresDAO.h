#pragma once


#ifndef _PIMARMYCADRESDAO_H_
#define _PIMARMYCADRESDAO_H_

#include "BaseDAO.h"
#include "domain/query/pimarmycadres/PimarmycadresPageQuery.h"
#include "domain/do/pimarmycadres/PimarmycadresFindDO.h"


#include "../../domain/do/pimarmycadres/AddPimarmycadresDO.h"
#include "../../domain/query/pimarmycadres/PimarmycadresQuery.h"
#include "../../domain/do/pimarmycadres/PimarmycadresDO.h"

class PimarmycadresDAO : public BaseDAO
{
public:
	// ��ҳ��ѯ����
	list<PimarmycadresFindDO> selectWithPage(const PimarmycadresPageQuery::Wrapper& query);

	//��������
	uint64_t insert(const AddPimarmycadresDO& iObj);

	// ͳ����������
	uint64_t count(const PimarmycadresPageQuery::Wrapper& query);
	
	//��ѯ���ݣ��Ѳ�ѯ����������Excel��  (����������
	list<PimarmycadresFindDO> selectDetail(const PimarmycadresQuery::Wrapper& query);
	

	int update(const PimarmycadresDO& uObj);

	//ɾ�����ݣ�֧������ɾ�����ݣ�
	int deleteById(std::string pimpersonid, std::string pimarmycadresid);

};



#endif
