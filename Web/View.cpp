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
char* GetFile(View view,int& size,int& sizeget, int http) {
	static char* file;
	FILE* ptrf;
	fopen_s(&ptrf,view.namefile.c_str(),"r");
	
	size = GetLength(ptrf)+1;
	
	sizeget = http+GetLength(size);
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
char* GetFile(std::string name, int& size, int& sizeget,int http) {
	static char* file;
	FILE* ptrf;
	fopen_s(&ptrf,name.c_str(), "r");
	if (ptrf) 
	{
		size = GetLength(ptrf) + 1;
		sizeget = http + GetLength(size);
		file = new char[size + sizeget];
		int i = sizeget - 1;
		while (file[i] != EOF) {
			i++;
			file[i] = fgetc(ptrf);

		}
		file[i] = '\0';
		size += sizeget;
		fclose(ptrf);
		return file;
	}
	else {
		return NULL;
	}
}