#pragma once
#include<iostream>
#define HTTP_SIZE 63
struct View
{
	std::string namefile;
};
char* GetFile(View view, int& size, int& sizeget);