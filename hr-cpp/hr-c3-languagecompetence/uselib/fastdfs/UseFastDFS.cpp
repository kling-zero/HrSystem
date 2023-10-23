#include "stdafx.h"
#include "UseFastDFS.h"
#include <iostream>

#ifdef LINUX
#include "../../ServerInfo.h"
#include "NacosClient.h"
#include "YamlHelper.h"
#endif

#include "FastDfsClient.h"

/**
 * ʵ�ֵ���FastDFS
 * �����ˣ���
 */
std::string UseFastDFS::upload(std::string fileName)
{
#ifdef LINUX
	//����ͻ��˶���
	FastDfsClient client("conf/client.conf");
#else
	//����ͻ��˶���
	FastDfsClient client(host);
#endif
	//�ϴ�
	std::string fieldName = client.uploadFile(fileName);
	std::cout << "upload fieldname is : " << fieldName << std::endl;
	return url_prefix + fieldName;
}

std::string UseFastDFS::uploadWithNacos(std::string fileName)
{
	// ��������ǰ׺
	std::string urlPrefix;
#ifdef LINUX
	// ����һ��Nacos�ͻ��˶������ڻ�ȡ����
	NacosClient ns(ServerInfo::getInstance().getNacosAddr(), ServerInfo::getInstance().getNacosNs());
	// ����urlǰ׺
	auto thirdServerConfig = ns.getConfig("third-services.yaml");
	urlPrefix = "http://" + YamlHelper().getString(&thirdServerConfig, "fastdfs.nginx-servers") + "/";
	// ��Nacos�������Ļ�ȡFastDFS�ͻ�����������
	std::string config = ns.getConfigText("client.conf");
	// ����ͻ��˶���
	FastDfsClient client(config, false);
#else
	// ����urlǰ׺
	urlPrefix = url_prefix;
	// ����ͻ��˶���
	FastDfsClient client(host);
#endif
	// �ϴ��ļ�
	std::string fieldName = client.uploadFile(fileName);
	// ��������·��
	std::string downloadUrl = urlPrefix + fieldName;
	// �������·��
	std::cout << "download url: " << downloadUrl << std::endl;
	return downloadUrl;
}