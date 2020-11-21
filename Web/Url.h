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
void DeleteUrls(urls* urle);
char* GetUrl(char* url, int start);