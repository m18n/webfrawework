#pragma once
#include"Network.h"
#include"Url.h"
#include"deadlines.h"
void LinkProcessing(urls* urlall, std::string url, SOCKET sock);
struct ClinetHandler {
	SOCKET Connect;
	urls* url;
};
void Meneger(ClinetHandler* Connect);
void StartServer(Connect& cn, urls* url);