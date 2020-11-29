#include"processing.h"

void Meneger(MenC test) {
	int index = 4;
	int size = 10000;
	char* get = new char[size];
	int res = 0;
	res=recvR(test.Connect, get, size);
	if(res!=-1){
		std::cout  << get << "\n\n";
		char* url = GetUrl(get, index);
		std::cout << "\nURL: " << url << "\n\n";
		LinkProcessing2(url, test.Connect, test.link);
		delete[] url;
	}
	
	delete[] get;
	closesocket(test.Connect);
}

void StartServer(Connect& cn, void(*link)(const char* link, int sizelink, SOCKET conn)) {
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
		MenC test;
		test.Connect = newConnection;
		test.link = link;
		CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)Meneger,&test, NULL, NULL);
	}
}
char* GetRozsher(std::string url,int start,int& size) {
	static char* ret;
	start++;
	size = url.length() - start+1;
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
//const char test[77] = "HTTP/1.1 200 OK\r\nContent-length: 12\r\nContent-Type: text/html\r\n\r\n<h1>Hay</h1>";
void SendHtml(SOCKET conn, const char* format, int sizeformat, const char* html,int sizehtml) {
	int sizeget = HTTP + GetLength(sizehtml)+sizeformat;
	char* http = new char[sizeget+sizehtml];
	strcpy(http, "HTTP/1.1 200 OK\r\nContent-length: ");
	strcat(http, std::to_string(sizehtml).c_str());
	strcat(http, "\r\nContent-Type: ");
	strcat(http, format);
	strcat(http, "\r\n\r\n");
	strcat(http, html);
	std::cout <<"\n"<< http<<"\n";
	sendR(conn,http,sizeget+sizehtml);
	delete[] http;
}
void LinkProcessing2(std::string url, SOCKET sock, void(*link)(const char* link, int sizelink, SOCKET conn)) {
	int otvet = CheckFile(url);
	if (otvet != -1) {
		std::cout << "File";
		SendHtml(sock, "text/html", 9, "test", 4);
	}
	else {
	link(url.c_str(), url.length(), sock);
	}
}
//void LinkProcessing(std::string url, SOCKET sock,void(*link)(const char* link,int sizelink,SOCKET conn)) {
//	int i = 0;
//	int otvet = CheckFile(url);
//	if (otvet!=-1) {
//		int size = 0;
//		int sizeget = 0;
//		wchar_t* ur = new wchar_t[url.length()];
//		for (int i = 1; i < url.length(); i++) {
//			ur[i - 1] = url[i];
//		}
//		ur[url.length() - 1] = '\0';
//		int size
//		char* orzsh = GetRozsher(url, otvet);
//		int sizehttp = 0;
//		bool image = false;
//		if (strcmp(orzsh,"html")==0) {
//			sizehttp = HTML_SIZE;
//		}
//		else if (strcmp(orzsh, "css")==0) {
//			sizehttp = CSS_SIZE;
//		}
//		else {
//			sizehttp = IMAGE_SIZE+strlen(orzsh);
//			image = true;
//		}
//		char* file = GetFile(ur, size, sizeget, sizehttp,image);
//		
//		delete[] ur;
//		if (file != NULL) {
//			
//			char* http = new char[sizeget + 1];
//			if (image == true) {
//				strcpy(http, "HTTP/1.1 200 OK\r\nContent-length: ");
//				strcat(http, std::to_string(size).c_str());
//				strcat(http, "\r\nContent-Type: image/");
//				strcat(http, orzsh);
//				strcat(http, "\r\n\r\n");
//			}
//			else {
//				strcpy(http, "HTTP/1.1 200 OK\r\nContent-length: ");
//				strcat(http, std::to_string(size).c_str());
//				strcat(http, "\r\nContent-Type: text/");
//				strcat(http, orzsh);
//				strcat(http, "\r\n\r\n");
//			}
//			AddStart(http, file, sizeget);
//			delete[] http;
//			std::cout << file;
//			sendR(sock, file, size+sizeget);
//			
//		}
//		delete[] file;
//		delete[] orzsh;
//	}
//	else {
//		link(url.c_str(), url.length(),sock);
//	}
//}