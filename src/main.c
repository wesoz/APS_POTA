# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <string.h>
# include "arrays.h"
# include "sort.h"
# include <sys/time.h>

int ARR_QTTY = 1;

struct SortParams {
	char name[20];
	void (*func)(int*, int);
};

struct timespec start, end;

int main () {
	printf("Started\n\n");
	srand(time(NULL));

	struct SortParams sortParams[7];
	strcpy(sortParams[0].name, "Bubble Sort");
	sortParams[0].func = bubbleSort;

	strcpy(sortParams[1].name, "Selection Sort");
	sortParams[1].func = selectionSort;

	strcpy(sortParams[2].name, "Insertion Sort");
	sortParams[2].func = insertionSort;

	strcpy(sortParams[3].name, "Heap Sort");
	sortParams[3].func = heapSort;
	
	strcpy(sortParams[4].name, "Merge Sort");
	sortParams[4].func = mergeSort;

	strcpy(sortParams[5].name, "Quick Sort");
	sortParams[5].func = quickSort;

	strcpy(sortParams[6].name, "Counting Sort");
	sortParams[6].func = countingSort;

	int **arr5 = createArrayList(5, ARR_QTTY);

	printArrayList(arr5, ARR_QTTY, 5, "");

 	int n = sizeof(sortParams) / sizeof(sortParams[0]);
	int i;

	for (i = 0; i < n; i++) {

		clock_gettime(CLOCK_MONOTONIC, &start); // Captura o horario antes da execucao do sort
		int **sortedArrayList = sortArrayList(arr5, ARR_QTTY, 5, sortParams[i].func);
		clock_gettime(CLOCK_MONOTONIC, &end); // Captura o horario DEPOIS da execucao do sort

		// Captura o tempo em milissegundos
		int delta_us = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_nsec - start.tv_nsec) / 1000;

		// Converte o tempo para string
		char deltaStr[8];
		sprintf(deltaStr, "%d", delta_us);

		char title[20]; 
		strcpy(title, sortParams[i].name);
		strcat(title, " - ");
		strcat(title, deltaStr);
		strcat(title, "ms");
		
		printf("%s\n", title);
		// printArrayList(sortedArrayList, ARR_QTTY, 5, title);

		free(sortedArrayList);
	}

	printArrayList(arr5, ARR_QTTY, 5, "Original -> ");
	
	free(arr5);
	
	printf("\nFinished\n");
	return 0;
}


