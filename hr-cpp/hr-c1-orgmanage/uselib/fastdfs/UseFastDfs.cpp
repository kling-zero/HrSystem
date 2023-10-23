/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/05/28 16:21:27

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#include "stdafx.h"
#include "UseFastDfs.h"
#include <iostream>

#include "../../ServerInfo.h"
#include "NacosClient.h"
#include "YamlHelper.h"

#include "FastDfsClient.h"
#include "StringUtil.h"

std::string UseFastDfs::uploadWithNacos(std::string fileName)
{
	// ����һ��Nacos�ͻ��˶������ڻ�ȡ����
	NacosClient ns(ServerInfo::getInstance().getNacosAddr(), ServerInfo::getInstance().getNacosNs());
	// ��������ǰ׺
	std::string urlPrefix;
#ifdef LINUX
	// ����urlǰ׺
	auto thirdServerConfig = ns.getConfig("third-services.yaml");
	urlPrefix = "http://" + YamlHelper().getString(&thirdServerConfig, "fastdfs.nginx-servers") + "/";
	// ��Nacos�������Ļ�ȡFastDFS�ͻ�����������
	std::string config = ns.getConfigText("client.conf");
	// ����ͻ��˶���
	FastDfsClient client(config, false);
#else
	// �������ļ���ȡ
	YAML::Node node = ns.getConfig("./conf/third-services.yaml");
	// ����urlǰ׺
	YamlHelper yaml;
	std::string host = yaml.getString(&node, "fastdfs.nginx-servers");
	urlPrefix = "http://" + host + "/";
	auto tmp = StringUtil::split(yaml.getString(&node, "fastdfs.tracker-servers"), ":");
	// ����ͻ��˶���
	FastDfsClient client(tmp[0], atoi(tmp[1].c_str()));
#endif
	// �ϴ��ļ�
	std::string fieldName = client.uploadFile(fileName);
	// ��������·��
	std::string downloadUrl = urlPrefix + fieldName;
	// �������·��
	std::cout << "download url: " << downloadUrl << std::endl;
	return downloadUrl;
}