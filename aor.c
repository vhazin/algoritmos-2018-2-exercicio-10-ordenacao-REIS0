#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// void sort(char const *array[], int size);
// void swap(char const **a, char const **b);
void printArray(char array[][20], int sizeArray);

int main(void) {

	int N;
	scanf("%d", &N);
	/* condicional */
	if (N > 100 || N < 0) {
		return 0;
	}

	int sc = 0; /* se comportou */
	int nsc = 0; /* nao se comportou */
	char myArray[N][20];
	char simbol;

	for (int i = 0; i < N; i++) {
		scanf(" %c %s", &simbol, myArray[i]);
		if (simbol == '+') {
			sc++;
		}else if (simbol == '-') {
			nsc++;
		}
	}

	printArray(myArray, N);
	printf("sc = %d ; nsc = %d\n", sc, nsc);

	return 0;
}

// void sort(char const *array[], int size) {
// 	int i;
// 	int pivot = 0;
// 	if (size <= 1) {
// 		return;
// 	}
// }

void printArray(char array[][20], int sizeArray) {
	for (int i = 0; i < sizeArray; i++) {
		printf("%s\n", array[i]);
	}
}
