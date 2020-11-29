#pragma once
#include"Network.h"
#include"Url.h"
#include"deadlines.h"
void LinkProcessing(std::string url, SOCKET sock, void(*link)(const char* link, int sizelink, SOCKET conn));
void LinkProcessing2(std::string url, SOCKET sock, void(*link)(const char* link, int sizelink, SOCKET conn));
struct ClinetHandler {
	SOCKET Connect;
	urls* url;
};
struct MenC {
	SOCKET Connect;
	void(*link)(const char* link, int sizelink, SOCKET conn);
};
void Meneger(MenC test);
void StartServer(Connect& cn, void(*link)(const char* link, int sizelink, SOCKET conn));
void SendHtml(SOCKET conn, const char* format, int sizeformat, const char* html, int sizehtml);