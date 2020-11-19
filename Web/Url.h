#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include"View.h"
#include<string>
struct url {
	std::string url;
	View view;
};
struct urls {
	url* url;
	int size=0;
};
void Addurl(urls* urlall, url path);
void LinkProcessing(urls* urlall, std::string url);