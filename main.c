# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <string.h>
# include "arrays.h"
# include "sort.h"

int ARR_QTTY = 1;

struct SortParams {
	char name[20];
	void (*func)(int*, int);
};

int main () {
	printf("Started\n\n");
	srand(time(NULL));

	struct SortParams sortParams[4];
	strcpy(sortParams[0].name, "Bubble Sort");
	sortParams[0].func = bubbleSort;

	strcpy(sortParams[1].name, "Selection Sort");
	sortParams[1].func = selectionSort;

	strcpy(sortParams[2].name, "Insertion Sort");
	sortParams[2].func = insertionSort;

	strcpy(sortParams[3].name, "Heap Sort");
	sortParams[3].func = heapSort;
	

	int **arr5 = createArrayList(5, ARR_QTTY);
	//int **arr10 = createArrayList(10, ARR_QTTY);

	printArrayList(arr5, ARR_QTTY, 5, "");
	//bubbleSort(arr5[0], 5);

	int i;
	for (i = 0; i < 4; i++) {

		char title[20]; 
		strcpy(title, sortParams[i].name);
		strcat(title, " -> ");

		int **sortedArrayList = sortArrayList(arr5, ARR_QTTY, 5, sortParams[i].func);
		printArrayList(sortedArrayList, ARR_QTTY, 5, title);

		free(sortedArrayList);
	}

/*
	int **bubbleArrayList = sortArrayList(arr5, ARR_QTTY, 5, sortParams[0].func);
	printArrayList(bubbleArrayList, ARR_QTTY, 5, strcat(sortParams[0].name, " -> "));

	int **selectionArrayList = sortArrayList(arr5, ARR_QTTY, 5, selectionSort);
	printArrayList(selectionArrayList, ARR_QTTY, 5, "Selection Sort -> ");

	int **insertionArrayList = sortArrayList(arr5, ARR_QTTY, 5, insertionSort);
	printArrayList(insertionArrayList, ARR_QTTY, 5, "Insertion Sort -> ");
*/
	printArrayList(arr5, ARR_QTTY, 5, "Original -> ");
	//printArrayList(arr10, ARR_QTTY, 10);
	
	free(arr5);
	//free(arr10);
	
	printf("\nFinished\n");
	return 0;
}


