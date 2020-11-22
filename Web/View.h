#pragma once
#include<iostream>
#include<Windows.h>
#define HTML 4
#define CSS 3
#define IMAGE 1
#define HTTP 58 
#define IMAGE_SIZE IMAGE+HTTP
#define HTML_SIZE HTML+HTTP
#define CSS_SIZE CSS+HTTP
struct View
{
	std::wstring namefile;
};
char* GetFile(View view, int& size, int& sizeget, int http);
char* GetFile(std::wstring name, int& size, int& sizeget, int http,bool image);