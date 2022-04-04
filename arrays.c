# include <stdio.h>
# include <stdlib.h>
# include <time.h>

int MAX_ARR_ELEM_VALUE = 2000;

void populateArray(int *arrayPointer, int size) {
	int i;
	for (i = 0; i < size; i++) {
		arrayPointer[i] = rand() % MAX_ARR_ELEM_VALUE;
	}
}

int * createArray(int size) {
	int *newArray = (int *)calloc(size, sizeof(int));
	populateArray(newArray, size);
	
	return newArray;
}

int ** createArrayList(int size, int quantity) {
	int **arrayList = (int **)calloc(quantity, sizeof(int) * size * quantity);
	
	int i;
	for(i = 0; i < quantity; i++) {
		arrayList[i] = createArray(size);
	}
	
	return arrayList;
}

void printArray(int *arrayPointer, int size) {
	int i;
	for (i = 0; i < size; i++) {
		printf("index[%d]: %d\n", i, *(arrayPointer + i));
	}
}

void printArrayList(int **arrayList, int quantity, int size) {
	int i;
	printf("===========================================\n");
	printf("Arrays of size %d\n", size);
	printf("===========================================\n");
	for(i = 0; i < quantity; i++) {
		printf("---------------------------- Array %d --------------------------\n", i + 1);
		printArray(arrayList[i], size);
	}
	printf("===========================================\n");
}
