#pragma once
/*
��֤�����-֤����Ϣ-ɾ��֤�飩--����
*/
#ifndef _DELETECERTIF_DAO_
#define _DELETECERTIF_DAO_
#include "BaseDAO.h"

class DeleteCertifDAO : public BaseDAO
{
public:
	// ͨ��IDɾ������
	int deleteById(string id);
};
#endif // !_DELETECERTIF_DAO_
