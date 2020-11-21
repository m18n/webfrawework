#pragma once
#include<iostream>
#define HTTP_SIZE 62
#define HTTP_CSS 61
struct View
{
	std::string namefile;
};
char* GetFile(View view, int& size, int& sizeget, int http);
char* GetFile(std::string name, int& size, int& sizeget, int http);