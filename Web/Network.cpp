#include "Network.h"
//const char http[HTTP_SIZE] = "HTTP/1.1 200 OK\r\nContent-length: \r\nContent-Type: text/html\r\n\r\n";
bool CheckWord(char* buff, const char* slovo, int size,int start) {
	bool search = false;
	size += start;
	for (int i = start; i < size; i++) {
		if (buff[i] == slovo[i-start]) {
			if (slovo[i-start+1] == '\0') 
			{
				search = true;
				break;
			}
			else
				search = false;
		}
		else {
			search = false;
			break;
		}
	}
	return search;
}
int recvR(SOCKET socket, char* buff, int size) {
	int res;
	int i = 0;
	res = recv(socket, buff, size, MSG_PEEK);
	if (res <= 0) {
		closesocket(socket);
		std::cout << "Disconnet\n";
		return -1;
	}
	for (i = 0; i < res; i++) {
		if (buff[i] == '\r') {
			if(CheckWord(buff, "\r\n\r\n", 4, i))
				break;
		}
	}

	res = recv(socket, buff, i, NULL);
	buff[res] = '\0';
	if (res <= 0) {
		closesocket(socket);
		std::cout << "Disconnet\n";
		return -1;
	}
	return res;
}
int sendR(SOCKET socket, const char* buff, int size) {
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
char* GetUrl(char* url,int start) {
	static char* ch;
	int i = start;
	while (url[i] != ' ') {
		i++;
	}
	ch = new char[i-start+1];
	i = start;
	while (url[i] != ' ') {
		ch[i - start] = url[i];
		i++;
	}
	ch[i - start] = '\0';
	return ch;
}
struct ClinetHandler {
	SOCKET Connect;
	urls* url;
};
void Meneger(ClinetHandler* Connect) {
	int index = 4;
	int size = 10000;
	char* get = new char[size];
	recvR(Connect->Connect,get,size);
	std::cout << "GET\n\n" << get << "\n";
	char* url = GetUrl(get, index);
 	delete[] get;
	LinkProcessing(Connect->url,url,Connect->Connect);
	std::cout << "URL: " << url << "\n\n";
	delete[] url;
	delete Connect;
}
void StartServer(Connect& cn,urls* url) {
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
		ClinetHandler* cl = new ClinetHandler;
		cl->Connect = newConnection;
		cl->url = url;
		CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)Meneger,cl, NULL, NULL);
	}
}
void CharCut(char* vsavka, char* cude, int start, int size) {
	for (int i = start; i < size; i++) {
		cude[i] = vsavka[i - start];
	}
}
//void SendFile(SOCKET& socket, char* file, int size) {
//
//}