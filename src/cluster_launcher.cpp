#include "cluster_launcher.h"



namespace sasori {


	ClusterServerInfo::ClusterServerInfo()
	{
		//
	}

	ClusterServerInfo::ClusterServerInfo(std::string theHost, std::string thePort, std::string theUser, std::string thePassword)
	{
		host = theHost;
		port = thePort;
		user = theUser;
		password = thePassword;
	}

	void ClusterServerInfo::printInfo()
	{
		std::cout << "host:" << host << "   port:" << port << "   user:" << user << "   password:" << password << std::endl;
	}


	void ClusterLauncher::launch(std::string configFile)
	{
		parseConfig(configFile);
		for (auto iter = clusterServerInfos.begin(); iter < clusterServerInfos.end(); iter++)
		{
			iter->printInfo();
		}
		mqServerInfo.printInfo();
	}


	void ClusterLauncher::parseConfig(std::string configFile)
	{
		std::ifstream ifs(configFile);
		std::string configStr((std::istreambuf_iterator<char>(ifs)),
			std::istreambuf_iterator<char>());

		Json::Reader reader;
		Json::Value value;

		if (reader.parse(configStr, value))
		{
			const Json::Value arrayObj = value["cluster_server"];
			for (int i = 0; i < arrayObj.size(); i++)
			{
				std::string theHost = arrayObj[i]["host"].asString();
				std::string thePort = arrayObj[i]["port"].asString();
				std::string theUser = arrayObj[i]["user"].asString();
				std::string thePassword = arrayObj[i]["password"].asString();
				
				ClusterServerInfo clusterServerInfo(theHost, thePort, theUser, thePassword);
				clusterServerInfos.push_back(clusterServerInfo);
			}


			ClusterServerInfo theMQServerInfo(value["mq_server"]["host"].asString(),
				value["mq_server"]["port"].asString(),
				value["mq_server"]["user"].asString(),
				value["mq_server"]["password"].asString());
			mqServerInfo = theMQServerInfo;

			//todo:set balancer server info
		}
	}


}