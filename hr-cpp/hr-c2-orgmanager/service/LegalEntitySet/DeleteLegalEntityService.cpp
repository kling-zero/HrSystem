/*
* ������������--ɾ����������(֧������ɾ��)--pine
*/
#include "stdafx.h"
#include "DeleteLegalEntityService.h"
#include "../../dao/LegalEntitySet/DeleteLegalEntityDAO.h"

bool DeleteLegalEntityService::removeData(const DeleteLegalEntityDTO::Wrapper& dto)
{
	DeleteLegalEntityDAO dao;
	for (auto it = dto->contractsignorgid->begin(); it != dto->contractsignorgid->end(); ++it)
	{
		//*it��String���͵Ķ���deleteById��Ҫ����string�Ĳ�������
		dao.update((*it).getValue(""));
		dao.deleteById((*it).getValue(""));
	}
	return true;
}


