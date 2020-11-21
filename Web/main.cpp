#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"processing.h"
using namespace std;
int main() {
	cout << "Start\n";
	urls* urle=new urls;
	View* view=new View;
	View* view2=new View;
	view->namefile = "test.html";
	view2->namefile = "vasa.html";
	url hay;
	url hay2;

	
	hay.urle = "/";
	hay2.urle = "/vasa";
	hay.view=*view;
	hay2.view = *view2;
	Connect cn;
	AddUrl(urle,hay);
	AddUrl(urle,hay2);
	Inithilization(cn, "192.168.0.103", 9999);
	
	StartServer(cn,urle);
	delete view;
	delete view2;
	DeleteUrls(urle);
	cin.get();
	cin.get();
	return 0;
}