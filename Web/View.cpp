#include"View.h"
using namespace std;
int GetLength(FILE* fl) {
	int length= fseek(fl, 0, SEEK_END);
	fseek(fl, 0, SEEK_SET);
	return length;
}
char* GetFile(View view) {
	static char* file;
	FILE* ptrf;
	fopen_s(&ptrf,view.namefile.c_str(),"r");
	file = new char[GetLength(ptrf)];
	int i = 0;
	do
	{
		file[i] = fgetc(ptrf);
	} while (file[i] != EOF);
	fclose(ptrf);
	return file;
}