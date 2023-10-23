#pragma once
/*
֤�����-��ҳ��ѯ֤���б�--pine
*/
#ifndef  _CHECK_CER_LIST_MAPPER_
#define  _CHECK_CER_LIST_MAPPER_

#include "Mapper.h"
#include "../../domain/do/CertificateManage/CertificateDO.h"

class ChechCerListMapper : public Mapper<CertificateDO>
{
public:
	CertificateDO mapper(ResultSet* resultSet) const override
	{
		CertificateDO data;
		data.setYgbh(resultSet->getString(1));//this
		data.setPimperSonName(resultSet->getString(2));//this
		data.setYgzt(resultSet->getString(3));
		data.setZZ(resultSet->getString(4));
		data.setZGZSBH(resultSet->getString(5));//֤����
		data.setBcardNumber(resultSet->getString(6));
		data.setPimVocationalName(resultSet->getString(7));//this		
		data.setZslx(resultSet->getString(8));
		data.setZghqrq(resultSet->getString(9));
		data.setZgsydw(resultSet->getString(10));
		data.setZcdw(resultSet->getString(11));
		data.setSxrq(resultSet->getString(12));
		data.setFzyxq(resultSet->getString(13));

		data.setPIMPERSONID(resultSet->getString(14));
		data.setREGISNUMBER(resultSet->getString(15));
		data.setSOCSECPAYUNIT(resultSet->getString(16));
		data.setCSZCSJ(resultSet->getString(17));
		data.setXZCSJ(resultSet->getString(18));
		data.setPimvocationalid(resultSet->getString(19));//֤��Ψһ��ʶ
		return data;
	}
};
/*
*get�����ǲ鵽�ķ��������ı������,Ҫ��ʵ�ʵ��������Ӧ���У�����ֻ����Ҫ���������
*/


/*
SampleMapper��������ǽ�ResultSet�����е�����ӳ�䵽SampleDO�����С�ResultSetͨ�����ڱ�ʾ�����ݿ��м������Ľ������
mapper��������һ��ResultSet*��������ָ��ResultSet�����ָ�룬������һ��SampleDO����
��mapper�����У����ȴ���һ��SampleDO����data��Ȼ��ͨ������resultSet����ĸ��ַ�������getUInt64��getString��getInt��
��ȡ������еľ������ݣ���ʹ��data�������Ӧsetter��������setId��setName��setSex��setAge�����������õ�SampleDO�����С�
��󣬽����õ�SampleDO���󷵻ء�
��δ���չʾ��һ�ֳ���������ӳ��ģʽ�����ڽ����ݿ��ѯ���ӳ�䵽�Զ�������ݶ����С�
*/
#endif // !_SAMPLE_MAPPER_