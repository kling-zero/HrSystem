#pragma once
/*
* ������������--ɾ����������(֧������ɾ��)--pine
*/
#ifndef  _DELETE_LEGAL_ENTITY_MAPPER_
#define  _DELETE_LEGAL_ENTITY_MAPPER_

#include "Mapper.h"
#include "../../domain/do/LegalEntitySet/LegalEntitySetDO.h"

class DeleteLegalEntityMapper : public Mapper<LegalEntitySetDO>
{
public:
	LegalEntitySetDO mapper(ResultSet* resultSet) const override
	{
		LegalEntitySetDO data;
		data.setCONTRACTSIGNORGID(resultSet->getString(1));//this
		//data.setORMSIGNORGID(resultSet->getString(1));//this
		//data.setCONTRACTSIGNORGNAME(resultSet->getString(2));//Ҫ�����ѯ//this
		//data.setISDEFAULTSIGNORG(resultSet->getString(3));//this
		return data;
	}
};



/*
SampleMapper��������ǽ�ResultSet�����е�����ӳ�䵽SampleDO�����С�ResultSetͨ�����ڱ�ʾ�����ݿ��м������Ľ������
mapper��������һ��ResultSet*��������ָ��ResultSet�����ָ�룬������һ��SampleDO����
��mapper�����У����ȴ���һ��SampleDO����data��Ȼ��ͨ������resultSet����ĸ��ַ�������getUInt64��getString��getInt��
��ȡ������еľ������ݣ���ʹ��data�������Ӧsetter��������setId��setName��setSex��setAge�����������õ�SampleDO�����С�
��󣬽����õ�SampleDO���󷵻ء�
��δ���չʾ��һ�ֳ���������ӳ��ģʽ�����ڽ����ݿ��ѯ���ӳ�䵽�Զ�������ݶ����С�
*/
#endif // !_SAMPLE_MAPPER_