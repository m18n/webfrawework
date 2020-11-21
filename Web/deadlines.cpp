#include"deadlines.h"
void AddStart(const char* buff, char* cuda, int size) {
	for (int i = 0; i < size; i++) {
		cuda[i] = buff[i];
	}
}
