#include "Network.h"
//const char http[HTTP_SIZE] = "HTTP/1.1 200 OK\r\nContent-length: \r\nContent-Type: text/html\r\n\r\n";
int recvR(SOCKET& socket, char* buff, int size) {
	int res;
	int i = 0;
	res = recv(socket, buff, size, MSG_PEEK);
	if (res <= 0) {
		closesocket(socket);
		std::cout << "Disconnet\n";
		return -1;
	}
	for (i = 0; i < res; i++) {
		if (buff[i] == '\0')
			break;
	}

	res = recv(socket, buff, i + 1, NULL);
	if (res <= 0) {
		closesocket(socket);
		std::cout << "Disconnet\n";
		return -1;
	}
	return res;
}
int sendR(SOCKET& socket, const char* buff, int size) {
	int res = 0;
	res = send(socket, buff, size, NULL);
	if (res < 0) {
		closesocket(socket);
		std::cout << "Disconnet\n";
		return -1;
	}

	return res;
}
void Inithilization(Connect& cn, std::string ip, short int port) {
	cn.DLLversion = MAKEWORD(2, 2);
	if (WSAStartup(cn.DLLversion, &cn.wsaData) != 0) {
		std::cout << "Error 1\n";
		exit(1);
	}
	cn.sizeofaddr = sizeof(cn.addr);
	cn.addr.sin_addr.s_addr = inet_addr(ip.c_str());
	cn.addr.sin_port = htons(port);
	cn.addr.sin_family = AF_INET;
}
void GetUrl(char* url) {

}
void Meneger(SOCKET* Connect) {

}
void StartServer(Connect& cn) {
	SOCKET sListen = socket(AF_INET, SOCK_STREAM, NULL);
	bind(sListen, (SOCKADDR*)&cn.addr, sizeof(cn.addr));
	std::cout << "Start Server\n";
	listen(sListen, SOMAXCONN);
	SOCKET newConnection;
	while (true)
	{
		newConnection = accept(sListen, (SOCKADDR*)&cn.addr, &cn.sizeofaddr);
		if (newConnection == 0)
			std::cout << "Error Connection\n";
		else
			std::cout << "Connect\n";

		CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)Meneger,&newConnection, NULL, NULL);
	}
}
void CharCut(char* vsavka, char* cude, int start, int size) {
	for (int i = start; i < size; i++) {
		cude[i] = vsavka[i - start];
	}
}
//void SendFile(SOCKET& socket, char* file, int size) {
//}