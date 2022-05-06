# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include "arrays.h"

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

int ** createArrayList(struct ArrayList arrayList) {
	int **arrays = (int **)calloc(arrayList.quantity, sizeof(int) * arrayList.size * arrayList.quantity);
	
	int i;
	for(i = 0; i < arrayList.quantity; i++) {
		arrays[i] = createArray(arrayList.size);
	}

	return arrays;
}

void printArray(int *arrayPointer, int size) {
	int i;
	for (i = 0; i < size; i++) {
		printf("index[%d]: %d\n", i, *(arrayPointer + i));
	}
}

void printArrayList(struct ArrayList arrayList, char title[]) {
	int i;
	printf("===========================================\n");
	printf("%s%d arrays of size %d\n", title, arrayList.quantity, arrayList.size);
	printf("===========================================\n");
	for(i = 0; i < arrayList.quantity; i++) {
		printf("---------------------------- Array %d --------------------------\n", i + 1);
		printArray(arrayList.arrays[i], arrayList.size);
	}
	printf("===========================================\n");
}
