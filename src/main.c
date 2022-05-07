# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <string.h>
# include "arrays.h"
# include "sort.h"

int ARR_QTTY = 50;

struct SortParams {
	char name[20];
	int (*func)(int*, int);
};

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

	int arraysN = 6;
	struct ArrayList arrayList[arraysN];
	arrayList[0].size = 5;
	arrayList[0].quantity = ARR_QTTY;

	arrayList[1].size = 10;
	arrayList[1].quantity = ARR_QTTY;

	arrayList[2].size = 50;
	arrayList[2].quantity = ARR_QTTY;

	arrayList[3].size = 100;
	arrayList[3].quantity = ARR_QTTY;

	arrayList[4].size = 1000;
	arrayList[4].quantity = ARR_QTTY;

	arrayList[5].size = 10000;
	arrayList[5].quantity = ARR_QTTY;


 	int sortParamsN = sizeof(sortParams) / sizeof(sortParams[0]);
	int i;

	for (i = 0; i < arraysN; i++) {

		arrayList[i].arrays = createArrayList(arrayList[i]);

		printf("\n\n>>>> Array Size: %d <<<<\n\n", arrayList[i].size);

		struct SortResult sortResult[sortParamsN];

		printf("algoritmo;");
		int j;
		for (j = 0; j < sortParamsN; j++) {
			sortResult[j] = sortArrayList(arrayList[i].arrays, arrayList[i].quantity, arrayList[i].size, sortParams[j].func);
			printf("%s;", sortParams[j].name);
		}
		printf("\n");
		printf("comparacoes;");
		for (j = 0; j < sortParamsN; j++) {
			printf("%ld;", sortResult[j].avgCompares);
		}
		printf("\n");
		printf("tempos;");
		for (j = 0; j < sortParamsN; j++) {
			printf("%d;", sortResult[j].avgTime);
		}

		free(arrayList[i].arrays);
	}
	
	printf("\nFinished\n");
	return 0;
}


