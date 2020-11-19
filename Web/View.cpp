#include"View.h"
using namespace std;
int GetLength(FILE* fl) {
	fseek(fl, 0, SEEK_END);
	int length = ftell(fl);
	fseek(fl, 0, SEEK_SET);
	return length;
}
int GetLength(int number) {
	int i = 0;
	for (; number > 0; i++) {
		number /= 10;
	}
	return i;
}
char* GetFile(View view,int& size,int& sizeget) {
	static char* file;
	FILE* ptrf;
	fopen_s(&ptrf,"index.html","r");
	
	size = GetLength(ptrf)+1;
	sizeget = HTTP_SIZE+GetLength(size);
	file = new char[size+sizeget];

	int i = sizeget-1;
	while (file[i] != EOF) {
		i++;
		file[i] = fgetc(ptrf);
		
	}
	file[i] = '\0';
	size += sizeget;
	fclose(ptrf);
	return file;
}