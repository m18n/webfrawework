#pragma once
#include"Network.h"
#include"Url.h"
#include <thread>
#include"deadlines.h"
void LinkProcessing(std::string url, SOCKET sock, void(*link)(const char* link, int sizelink, SOCKET conn));
void LinkProcessing2(std::string url, SOCKET sock, void(*link)(const char* link, int sizelink, SOCKET conn));

void Meneger(SOCKET Connect, void(*link)(const char* link, int sizelink, SOCKET conn));
void StartServer(Connect& cn, void(*link)(const char* link, int sizelink, SOCKET conn));
void SendHtml(SOCKET conn, const char* format, int sizeformat, const char* html, int sizehtml);
void SendFile(std::string url, SOCKET sock);