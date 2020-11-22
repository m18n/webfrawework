#include"processing.h"
void Meneger(ClinetHandler* Connect) {
	int index = 4;
	int size = 10000;
	char* get = new char[size];
	recvR(Connect->Connect, get, size);
	std::cout << "GET\n\n" << get << "\n\n";
	char* url = GetUrl(get, index);
	delete[] get;
	LinkProcessing(Connect->url, url, Connect->Connect);
	
	std::cout << "\nURL: " << url << "\n\n";
	closesocket(Connect->Connect);
	delete[] url;
	delete Connect;
}
void StartServer(Connect& cn, urls* url) {
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
		CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)Meneger, cl, NULL, NULL);
	}
}
char* GetRozsher(std::string url,int start) {
	static char* ret;
	start++;
	int size = url.length() - start+1;
	ret = new char[size];
	for (int i = start; i < url.length(); i++) {
		ret[i-start] = url[i];
	}
	ret[size-1] = '\0';
	return ret;
}
int CheckFile(std::string url) {
	for (int i = url.length(); i >= 0; i--) {
		if (url[i] == '.') {
			return i;
		}
	}
	return -1;
}
void LinkProcessing(urls* urlall, std::string url, SOCKET sock) {
	int i = 0;
	bool search = false;

	for (i = 0; i < urlall->size; i++) {
		if (urlall->url[i].urle == url)
		{
			search = true;
			break;
		}
	}
	int otvet = CheckFile(url);
	if (otvet!=-1) {
		int size = 0;
		int sizeget = 0;
		wchar_t* ur = new wchar_t[url.length()];
		for (int i = 1; i < url.length(); i++) {
			ur[i - 1] = url[i];
		}
		ur[url.length() - 1] = '\0';
		char* orzsh = GetRozsher(url, otvet);
		int sizehttp = 0;
		bool image = false;
		if (strcmp(orzsh,"html")==0) {
			sizehttp = HTML_SIZE;
		}
		else if (strcmp(orzsh, "css")==0) {
			sizehttp = CSS_SIZE;
		}
		else {
			sizehttp = IMAGE_SIZE+strlen(orzsh);
			image = true;
		}
		char* file = GetFile(ur, size, sizeget, sizehttp,image);
		
		delete[] ur;
		if (file != NULL) {
			
			char* http = new char[sizeget + 1];
			if (image == true) {
				strcpy(http, "HTTP/1.1 200 OK\r\nContent-length: ");
				strcat(http, std::to_string(size).c_str());
				strcat(http, "\r\nContent-Type: image/");
				strcat(http, orzsh);
				strcat(http, "\r\n\r\n");
			}
			else {
				strcpy(http, "HTTP/1.1 200 OK\r\nContent-length: ");
				strcat(http, std::to_string(size).c_str());
				strcat(http, "\r\nContent-Type: text/");
				strcat(http, orzsh);
				strcat(http, "\r\n\r\n");
			}
			AddStart(http, file, sizeget);
			delete[] http;
			std::cout << file;
			sendR(sock, file, size+sizeget);
			
		}
		delete[] file;
		delete[] orzsh;
	}
	if (search == true) {
		int size = 0;
		int sizeget = 0;
		char* file = GetFile(urlall->url[i].view, size, sizeget,HTML_SIZE);
		if (file != NULL) {
			char* http = new char[sizeget + 1];
			strcpy(http, "HTTP/1.1 200 OK\r\nContent-length: ");
			strcat(http, std::to_string(size).c_str());
			strcat(http, "\r\nContent-Type: text/html\r\n\r\n");
			AddStart(http, file, sizeget);
			delete[] http;
			std::cout << file;
			sendR(sock, file, size + sizeget);
		}
		delete[] file;
	}
}