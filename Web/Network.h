#pragma once
#include<WinSock2.h>
#pragma warning(disable:4996)
#pragma comment(lib,"ws2_32.lib")
#include"Url.h"

struct Connect {
	WSAData wsaData;
	WORD DLLversion;
	SOCKADDR_IN addr;
	int sizeofaddr = 0;
};
int sendR(SOCKET socket, const char* buff, int size);
int recvR(SOCKET socket, char* buff, int size);
void Inithilization(Connect& cn, std::string ip, short int port);
void StartServer(Connect& cn, urls* url);

//void SendFile(SOCKET& socket, char* file, int size);