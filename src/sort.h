#ifndef SORT_HEADER_GUARD
#define SORT_HEADER_GUARD

struct SortResult {
    int totalTime;
    int avgTime;
    int totalComparisons;
};

void bubbleSort (int array[], int size);
void selectionSort(int *array, int size);
void insertionSort(int array[], int size);
void heapSort(int array[], int size);
void mergeSort(int array[], int size);
void quickSort(int array[], int size);
void countingSort(int array[], int size);

struct SortResult sortArrayList(int **arrayList, int arrayQuantity, int arraySize, void (*func)(int*, int));
int * copyArray(int *array, int size);

#endif