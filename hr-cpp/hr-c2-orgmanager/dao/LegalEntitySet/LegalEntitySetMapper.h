#pragma once
/*
��֯���� ������������ ���� ������������  -- cpt

�����������������б� `LegalEntitySetPullDownList`

����ָ������������Ϣ  `UpdateLegalerSettingMessage`

������������ `LegalEntitySet`

�����������ã�֧������������** `LegalEntitySet`
*/
#ifndef _LEGALENTITYSET_MAPPER_
#define _LEGALENTITYSET_MAPPER_
#include "Mapper.h"
#include "../../domain/do/LegalEntitySet/LegalEntitySetDO.h"
/**
 * ʾ�����ֶ�ƥ��ӳ��
 */
class LegalEntitySetMapper : public Mapper<LegalEntitySetDO>
{
public:
	LegalEntitySetDO mapper(ResultSet* resultSet) const override
	{
		LegalEntitySetDO data;
		data.setCONTRACTSIGNORGID(resultSet->getString(1));
		data.setCONTRACTSIGNORGNAME(resultSet->getString(2));
		data.setORMSIGNORGID(resultSet->getString(3));
		data.setORMORGID(resultSet->getString(4));
		data.setISDEFAULTSIGNORG(resultSet->getString(5));
		return data;
	}
};
// �����б��ֶ�ƥ��ӳ��
class LegalEntitySetPullDownListMapper : public Mapper<LegalEntitySetDO>
{
public:
	LegalEntitySetDO mapper(ResultSet* resultSet) const override
	{
		LegalEntitySetDO data;
		data.setORMSIGNORGID(resultSet->getString(1));
		return data;
	}
};
/*
LegalEntitySetMapper��������ǽ�ResultSet�����е�����ӳ�䵽LegalEntitySetDO�����С�ResultSetͨ�����ڱ�ʾ�����ݿ��м������Ľ������
mapper��������һ��ResultSet*��������ָ��ResultSet�����ָ�룬������һ��LegalEntitySetDO����
��mapper�����У����ȴ���һ��LegalEntitySetDO����data��Ȼ��ͨ������resultSet����ĸ��ַ�������getUInt64��getString��getInt��
��ȡ������еľ������ݣ���ʹ��data�������Ӧsetter��������setId��setName��setSex��setAge�����������õ�LegalEntitySetDO�����С�
��󣬽����õ�LegalEntitySetDO���󷵻ء�
��δ���չʾ��һ�ֳ���������ӳ��ģʽ�����ڽ����ݿ��ѯ���ӳ�䵽�Զ�������ݶ����С�
*/
#endif // !_LEGALENTITYSET_MAPPER_