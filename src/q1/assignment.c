#include <stdio.h>

int main(int arg, char* argc[]) {
	printf("Hello assignment1.\n");
	printf("Size of int: %ld\n", sizeof(int));
	printf("Size of int pointer: %ld\n", sizeof(int*));
	printf("Size of long number: %ld\n", sizeof(long));
	printf("Size of double pointer: %ld\n", sizeof(double*));
	printf("Size of char pointer pointer: %ld\n", sizeof(char**));
	return 0;
}

