# include <stdio.h>
# include <stdlib.h>
# include <time.h>

int ARR_QTTY = 3;
int MAX_ARR_ELEM_VALUE = 2000;

int * createArray(int arraySize);
int ** createArrayList(int arraySize, int arrayQuantity);
void printArray(int *arrayPointer, int arraySize);
void printArrayList(int **arrayList, int arrayQuantity, int arraySize);
void populateArray(int *arrayPointer, int arraySize);

int main () {
	printf("Started\n\n");
	
	srand(time(NULL));
	
	int **arr5 = createArrayList(5, ARR_QTTY);
	int **arr10 = createArrayList(10, ARR_QTTY);
	
	printArrayList(arr5, ARR_QTTY, 5);
	printArrayList(arr10, ARR_QTTY, 10);
	
	free(arr5);
	free(arr10);
	
	printf("\nFinished\n");
	return 0;
}

void populateArray(int *arrayPointer, int arraySize) {
	int i;
	for (i = 0; i < arraySize; i++) {
		arrayPointer[i] = rand() % MAX_ARR_ELEM_VALUE;
	}
}

int * createArray(int arraySize) {
	int *newArray = (int *)calloc(arraySize, sizeof(int));
	populateArray(newArray, arraySize);
	
	return newArray;
}

int ** createArrayList(int arraySize, int arrayQuantity) {
	int **arrayList = (int **)calloc(arrayQuantity, sizeof(int) * arraySize * arrayQuantity);
	
	int i;
	for(i = 0; i < arrayQuantity; i++) {
		arrayList[i] = createArray(arraySize);
	}
	
	return arrayList;
}

void printArray(int *arrayPointer, int arraySize) {
	int i;
	for (i = 0; i < arraySize; i++) {
		printf("index[%d]: %d\n", i, *(arrayPointer + i));
	}
}

void printArrayList(int **arrayList, int arrayQuantity, int arraySize) {
	int i;
	printf("===========================================\n");
	printf("Arrays of size %d\n", arraySize);
	printf("===========================================\n");
	for(i = 0; i < arrayQuantity; i++) {
		printf("---------------------------- Array %d --------------------------\n", i + 1);
		printArray(arrayList[i], arraySize);
	}
	printf("===========================================\n");
}
