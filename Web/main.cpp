#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"processing.h"

using namespace std;
const char test[10] = "text/html";
void Obrobka(const char* url, int size, SOCKET conn) {
		cout << "\n\nindex.html\n\n";
		SendFile("/index.html", conn);
}
int main() {
	cout << "Start привіт\n";
	Connect cn;
	Inithilization(cn, "192.168.0.103", 9999);
	StartServer(cn,Obrobka);
	cin.get();
	cin.get();
	return 0;
}