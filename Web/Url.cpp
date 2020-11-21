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

void DeleteUrls(urls* urle) {
	delete [] urle->url;
}

char* GetUrl(char* url, int start) {
	static char* ch;
	int i = start;
	while (url[i] != ' ') {
		i++;
	}
	ch = new char[i - start + 1];
	i = start;
	while (url[i] != ' ') {
		ch[i - start] = url[i];
		i++;
	}
	ch[i - start] = '\0';
	return ch;
}