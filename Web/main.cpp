#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"Network.h"
using namespace std;
int main() {
	cout << "Start\n";
	urls* urle=new urls;
	View view;
	view.namefile = "index.html";
	url hay;

	
	hay.urle = "/";
	hay.view=view;
	Connect cn;
	AddUrl(urle,hay);
	Inithilization(cn, "192.168.0.103", 9999);
	
	StartServer(cn,urle);
	cin.get();
	cin.get();
	return 0;
}