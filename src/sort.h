#ifndef SORT_HEADER_GUARD
#define SORT_HEADER_GUARD

struct SortResult {
    int totalTime;
    int avgTime;
    long totalCompares;
    long avgCompares;
};

long bubbleSort (int array[], int size);
long selectionSort(int *array, int size);
long insertionSort(int array[], int size);
long heapSort(int array[], int size);
long mergeSort(int array[], int size);
long quickSort(int array[], int size);
long countingSort(int array[], int size);
long bucketSort(int array[], int size);

struct SortResult sortArrayList(int **arrayList, int arrayQuantity, int arraySize, long (*func)(int*, int));
int * copyArray(int *array, int size);

#endif