#include "stdafx.h"
#include <iostream>

#ifdef LINUX
#include "ServerInfo.h"
#include "NacosClient.h"
#include "YamlHelper.h"
#endif
#include "TerminationRemidnerFastdfs.h"
#include "FastDfsClient.h"

std::string TerminationFastDfs::downloadDfs(string fileName)
{
#ifdef LINUX
	//����ͻ��˶���
	FastDfsClient client("conf/client.conf");
#else
	//����ͻ��˶���
	FastDfsClient client("8.130.87.15");
#endif

	//�����ϴ�
	std::string fieldName = client.uploadFile(fileName);
	//std::cout << "upload fieldname is : " << fieldName << std::endl;
	std::string url = "8.130.87.15:8888/" + fieldName;
	return url;
}

