#pragma once

#include "stdafx.h"



namespace sasori {

	class ClusterServerInfo
	{
	public:
		std::string host;
		std::string port;
		std::string user;
		std::string password;
		ClusterServerInfo();
		ClusterServerInfo(std::string theHost, std::string thePort, std::string theUser, std::string thePassword);
		void printInfo();
	};

	class ClusterLauncher
	{
	public:
		void launch(std::string configFile);


	private:
		std::vector<ClusterServerInfo> clusterServerInfos;
		ClusterServerInfo mqServerInfo;


	private:
		void parseConfig(std::string configFile);
	};

}