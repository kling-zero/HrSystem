/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/24 23:17:46

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
#include "UseLibRedis.h"
#include "NacosClient.h"
#include "ServerInfo.h"
#include "YamlHelper.h"
#include "RedisClient.h"

std::unordered_map<std::string, std::string> UseLibRedis::queryRedis(const string &key)
{
	//��ȡ����
	NacosClient nacosClient(ServerInfo::getInstance().getNacosAddr(), ServerInfo::getInstance().getNacosNs());
#ifdef LINUX
	YAML::Node node = nacosClient.getConfig("data-source.yaml");
#else
	YAML::Node node = nacosClient.getConfig("./conf/data-source.yaml");
#endif
	
	//��ȡredis�������
	YamlHelper yaml;
	string host = yaml.getString(&node, "spring.redis.host");
	string port = yaml.getString(&node, "spring.redis.port");
	string password = yaml.getString(&node, "spring.redis.password");

	//����RedisClient����
	RedisClient rc(host, atoi(port.c_str()), password);

	//��ȡֵ
	/*std::vector<std::string> vec;
	rc.execute<int>([&](Redis* redis) {
		redis->lrange(key, 0, -1, std::back_inserter(vec));
		return 1;
	});*/

	std::unordered_map<std::string, std::string> hash;
	rc.execute<int>([&](Redis* redis) {
		redis->hgetall(key, std::inserter(hash, hash.begin()));
		return 1;
	});
	return hash;
}

void UseLibRedis::updateRedis(const std::string &key, const std::unordered_map<std::string, std::string> &m)
{
	//��ȡ����
	NacosClient nacosClient(ServerInfo::getInstance().getNacosAddr(), ServerInfo::getInstance().getNacosNs());
#ifdef LINUX
	YAML::Node node = nacosClient.getConfig("data-source.yaml");
#else
	YAML::Node node = nacosClient.getConfig("./conf/data-source.yaml");
#endif

	//��ȡredis�������
	YamlHelper yaml;
	string host = yaml.getString(&node, "spring.redis.host");
	string port = yaml.getString(&node, "spring.redis.port");
	string password = yaml.getString(&node, "spring.redis.password");

	//����RedisClient����
	RedisClient rc(host, atoi(port.c_str()), password);

	//����ֵ
	/*rc.execute<long long>([&](Redis* redis) {
		return redis->rpush("list", vec.begin(), vec.end());
	});*/
	rc.execute<int>([&](Redis* redis) {
		redis->hmset(key, m.begin(), m.end());
		return 1;
	});
}

void UseLibRedis::updateRedisWithTable(const std::unordered_map<std::string, std::string>& m, std::string tablename)
{
	//��ȡ����
	NacosClient nacosClient(ServerInfo::getInstance().getNacosAddr(), ServerInfo::getInstance().getNacosNs());
#ifdef LINUX
	YAML::Node node = nacosClient.getConfig("data-source.yaml");
#else
	YAML::Node node = nacosClient.getConfig("./conf/data-source.yaml");
#endif

	//��ȡredis�������
	YamlHelper yaml;
	string host = yaml.getString(&node, "spring.redis.host");
	string port = yaml.getString(&node, "spring.redis.port");
	string password = yaml.getString(&node, "spring.redis.password");

	//����RedisClient����
	RedisClient rc(host, atoi(port.c_str()), password);

	//����ֵ
	/*rc.execute<long long>([&](Redis* redis) {
		return redis->rpush("list", vec.begin(), vec.end());
	});*/
	rc.execute<int>([&](Redis* redis) {
		redis->hmset(tablename, m.begin(), m.end());
		return 1;
		});
}
