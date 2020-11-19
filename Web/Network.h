#pragma once
#include"Network.h"
#include<WinSock2.h>
#include"Url.h"
#include<iostream>
#pragma warning(disable:4996)
#pragma comment(lib,"ws2_32.lib")
using namespace std;
struct Connect {
	WSAData wsaData;
	WORD DLLversion;
	SOCKADDR_IN addr;
	int sizeofaddr = 0;
};
int sendR(SOCKET& socket, const char* buff, int size) {
	int res = 0;
	res = send(socket, buff, size, NULL);
	if (res < 0) {
		closesocket(socket);
		cout << "Disconnet\n";
		return -1;
	}

	return res;
}
int recvR(SOCKET& socket, char* buff, int size) {
	int res;
	int i = 0;
	res = recv(socket, buff, size, MSG_PEEK);
	if (res <= 0) {
		closesocket(socket);
		cout << "Disconnet\n";
		return -1;
	}
	for (i = 0; i < res; i++) {
		if (buff[i] == '\0')
			break;
	}

	res = recv(socket, buff, i + 1, NULL);
	if (res <= 0) {
		closesocket(socket);
		cout << "Disconnet\n";
		return -1;
	}
	return res;
}
void Inithilization(Connect& cn, string ip, short int port) {
	cn.DLLversion = MAKEWORD(2, 2);
	if (WSAStartup(cn.DLLversion, &cn.wsaData) != 0) {
		cout << "Error 1\n";
		exit(1);
	}
	cn.sizeofaddr = sizeof(cn.addr);
	cn.addr.sin_addr.s_addr = inet_addr(ip.c_str());
	cn.addr.sin_port = htons(port);
	cn.addr.sin_family = AF_INET;
}
void StartServer(Connect& cn) {
	SOCKET sListen = socket(AF_INET, SOCK_STREAM, NULL);
	bind(sListen, (SOCKADDR*)&cn.addr, sizeof(cn.addr));
	cout << "Start Server\n";
	listen(sListen, SOMAXCONN);
	SOCKET newConnection;
	while (true)
	{
		newConnection = accept(sListen, (SOCKADDR*)&cn.addr, &cn.sizeofaddr);
		if (newConnection == 0)
			cout << "Error Connection\n";
		else
			cout << "Connect\n";
		
		CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)Handle, pl, NULL, NULL);
	}
}