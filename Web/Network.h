#pragma once
#include<WinSock2.h>
#pragma warning(disable:4996)
#pragma comment(lib,"ws2_32.lib")
#include"iostream"
struct Connect {
	WSAData wsaData;
	WORD DLLversion;
	SOCKADDR_IN addr;
	int sizeofaddr = 0;
};
int sendR(SOCKET socket, const char* buff, int size);
int recvR(SOCKET socket, char* buff, int size);
int sendR(SOCKET socket, const wchar_t* buff, int size);
int recvR(SOCKET socket, wchar_t* buff, int size);
void Inithilization(Connect& cn, std::string ip, short int port);

//void SendFile(SOCKET& socket, char* file, int size);