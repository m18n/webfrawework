#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"processing.h"

using namespace std;
int wmain() {
	cout << "Start привіт\n";
	urls* urle=new urls;
	Connect cn;
	Inithilization(cn, "192.168.0.103", 9999);
	
	StartServer(cn,urle);
	DeleteUrls(urle);
	cin.get();
	cin.get();
	return 0;
}