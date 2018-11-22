#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void quicksort(char array[][20], int low, int high);
int partition(char array[][20], int low, int high);
void printArray(char array[][20], int sizeArray);

int main(void) {

	int size;
	scanf("%d", &size);
	/* condicional */
	if (size > 100 || size < 0) {
		return 0;
	}

	int sc = 0; /* se comportou */
	int nsc = 0; /* nao se comportou */
	char myArray[size][20];
	char simbol;
	
	int i;
	for (i = 0; i < size; i++) {
		scanf(" %c %s", &simbol, myArray[i]);
		if (simbol == '+') {
			sc++;
		}else if (simbol == '-') {
			nsc++;
		}
	}

	quicksort(myArray, 0, size-1);
	printArray(myArray, size);
	printf("Se comportaram: %d | Nao se comportaram: %d\n", sc, nsc);

	return 0;
}

void quicksort(char array[][20], int low, int high) {
	if (low < high) {
		int pIndex = partition(array, low, high);
		quicksort(array, low, pIndex-1);
		quicksort(array, pIndex+1, high);
	}
}

int partition(char array[][20], int low, int high) {
	char pivot[20];
	strcpy(pivot, array[high]);
	char i = low-1;
	int j;
	for (j = low; j <= high-1; j++) {
		if (strcmp(array[j], pivot) < 0) {
			i++;
			/* swap */
			char temp[20];
			strcpy(temp, array[i]);
			strcpy(array[i], array[j]);
			strcpy(array[j], temp);
		}
	}
	/* swap */
	char temp[20];
	strcpy(temp, array[i+1]);
	strcpy(array[i+1], array[high]);
	strcpy(array[high], temp);
	return (i+1);
}

void printArray(char array[][20], int sizeArray) {
	int i;
	for (i = 0; i < sizeArray; i++) {
		printf("%s\n", array[i]);
	}
}
