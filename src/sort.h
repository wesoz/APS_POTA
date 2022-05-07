#ifndef SORT_HEADER_GUARD
#define SORT_HEADER_GUARD

struct SortResult {
    int totalTime;
    int avgTime;
    long totalCompares;
    long avgCompares;
};

int bubbleSort (int array[], int size);
int selectionSort(int *array, int size);
int insertionSort(int array[], int size);
int heapSort(int array[], int size);
int mergeSort(int array[], int size);
int quickSort(int array[], int size);
int countingSort(int array[], int size);

struct SortResult sortArrayList(int **arrayList, int arrayQuantity, int arraySize, int (*func)(int*, int));
int * copyArray(int *array, int size);

#endif