#pragma once
#include<iostream>
#include<Windows.h>
#define HTTP 54

struct View
{
	std::wstring namefile;
};
char* GetFile(View view, int& size, int& sizeget, int http);
char* GetFile(std::wstring name, int& size, int& sizeget, int http,bool image);
int GetLength(int number);