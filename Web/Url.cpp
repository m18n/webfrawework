#include"Url.h"
void Addurl(urls* urlall, url path) {
	url* temp = new url[urlall->size + 1];
	for (int i = 0; i < urlall->size; i++)
	{
		temp[i] = urlall->url[i];
	}
	temp[urlall->size] = path;
	urlall->size++;
	delete[] urlall->url;
	urlall->url = new url[urlall->size];
	for (int i = 0; i < urlall->size; i++)
		urlall->url[i] = temp[i];
	delete[] temp;
}
void LinkProcessing(urls* urlall, std::string url) {
	int i = 0;
	for (i = 0; i < urlall->size; i++) {
		if (urlall->url[i].url == url)
			break;
	}
	char* file= GetFile(urlall->url[i].view);

	delete[] file;
}