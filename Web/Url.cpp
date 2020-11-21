#include"Url.h"
void AddUrl(urls* urlall, url path) {
	url* temp = new url[urlall->size + 1];
	for (int i = 0; i < urlall->size; i++)
	{
		temp[i] = urlall->url[i];
	}
	temp[urlall->size] = path;
	urlall->size++;
	urlall->url = new url[urlall->size];
	for (int i = 0; i < urlall->size; i++)
		urlall->url[i] = temp[i];
	delete[] temp;
}
void AddStart(const char* buff, char* cuda, int size) {
	for (int i = 0; i < size; i++) {
		cuda[i] = buff[i];
	}
}
void LinkProcessing(urls* urlall, std::string url,SOCKET sock) {
	int i = 0;
	bool search = false;
	for (i = 0; i < urlall->size; i++) {
		if (urlall->url[i].urle == url)
		{
			search = true;
			break;
		}
	}
	if (search == true) {
		int size = 0;
		int sizeget = 0;
		char* file = GetFile(urlall->url[i].view, size, sizeget);
		char* http = new char[sizeget + 1];
		strcpy(http, "HTTP/1.1 200 OK\r\nContent-length: ");
		strcat(http, std::to_string(size).c_str());
		strcat(http, "\r\nContent-Type: text/html\r\n\r\n");
		AddStart(http, file, sizeget);
		delete[] http;
		std::cout << file;
		sendR(sock, file, size);
		delete[] file;
	}
}
void DeleteUrls(urls* urle) {
	delete [] urle->url;
}