#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include"View.h"
#include<string>

struct url {
	std::string urle="";
	View view;
};
struct urls {
	url* url=NULL;
	int size=0;
};
void AddUrl(urls* urlall, url path);
void LinkProcessing(urls* urlall, std::string url, SOCKET sock);
void DeleteUrls(urls* urle);