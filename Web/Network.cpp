#include "Network.h"
const char http[54] = "HTTP/1.1 200 OK\r\nContent-length: \r\nContent-Type: \r\n\r\n";
bool CheckWord(wchar_t* buff, const wchar_t* slovo, int size,int start) {
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
bool CheckWord(char* buff, const char* slovo, int size, int start) {
	bool search = false;
	size += start;
	for (int i = start; i < size; i++) {
		if (buff[i] == slovo[i - start]) {
			if (slovo[i - start + 1] == '\0')
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

	res = recv(socket, buff, i+4, NULL);
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
	res = send(socket,buff, size, NULL);
	if (res < 0) {
		closesocket(socket);
		std::cout << L"Disconnet\n";
		return -1;
	}

	return res;
}
void Inithilization(Connect& cn, std::string ip, short int port) {
	cn.DLLversion = MAKEWORD(2, 2);
	if (WSAStartup(cn.DLLversion, &cn.wsaData) != 0) {
		std::wcout << L"Error 1\n";
		exit(1);
	}
	cn.sizeofaddr = sizeof(cn.addr);
	cn.addr.sin_addr.s_addr = inet_addr(ip.c_str());
	cn.addr.sin_port = htons(port);
	cn.addr.sin_family = AF_INET;
}



void CharCut(char* vsavka, char* cude, int start, int size) {
	for (int i = start; i < size; i++) {
		cude[i] = vsavka[i - start];
	}
}
//void SendFile(SOCKET& socket, char* file, int size) {
//
//}