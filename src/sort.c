# include <stdlib.h>
# include "sort.h"
# include <time.h>

struct timespec start, end;

int * copyArray(int *array, int size)
{
    int *arrayCopy = (int *)calloc(size, sizeof(int));
    for (int i = 0; i < size; ++i)
    {
        arrayCopy[i] = array[i];
    }
    return arrayCopy;
}

struct SortResult sortArrayList(int **arrayList, int arrayQuantity, int arraySize, int (*func)(int*, int)) {
    int **arrayListCopy = (int **)calloc(arrayQuantity, sizeof(int) * arraySize * arrayQuantity);
    struct SortResult sortResult;
    sortResult.totalCompares = 0;
	int i;
    clock_gettime(CLOCK_MONOTONIC, &start); // Captura o horario antes da execucao do sort
	for (i = 0; i < arrayQuantity; i++) {
        int *array = copyArray(arrayList[i], arraySize);
		sortResult.totalCompares += func(array, arraySize);
        arrayListCopy[i] = array;
	}
    clock_gettime(CLOCK_MONOTONIC, &end); // Captura o horario DEPOIS da execucao do sort

    sortResult.avgCompares = sortResult.totalCompares / arrayQuantity;

    // Captura o tempo em milissegundos
    sortResult.totalTime = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_nsec - start.tv_nsec) / 1000;

    sortResult.avgTime = sortResult.totalTime / arrayQuantity;

    free(arrayListCopy);
    return sortResult;
}

void swap(int *elementA, int *elementB)
{
    int temp = *elementA;
    *elementA = *elementB;
    *elementB = temp;
}

int bubbleSort (int *array, int size) {
    int k, j;
    int compares = 0;
    for (k = 1; k < size; k++) {
        for (j = 0; j < size - 1; j++) {
            if (array[j] > array[j + 1]) {
                swap(&array[j], &array[j + 1]);
            }
        }
    }
    return compares;
}

int selectionSort(int *array, int size) {
    int i, j, min_idx;
    int compares = 0;
    for (i = 0; i < size-1; i++)
    {
        min_idx = i;
        for (j = i+1; j < size; j++)
          if (array[j] < array[min_idx])
            min_idx = j;
        swap(&array[min_idx], &array[i]);
    }
    return compares;
}

int insertionSort(int array[], int size) {
    int i, key, j;
    int compares = 0;
    for (i = 1; i < size; i++) {
        key = array[i];
        j = i - 1;
 
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
    return compares;
}

void heapify(int array[], int size, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
  
    if (left < size && array[left] > array[largest])
      largest = left;
  
    if (right < size && array[right] > array[largest])
      largest = right;
  
    if (largest != i) {
      swap(&array[i], &array[largest]);
      heapify(array, size, largest);
    }
}
  
int heapSort(int array[], int size) {
    int compares = 0;
    for (int i = size / 2 - 1; i >= 0; i--)
      heapify(array, size, i);
  
    for (int i = size - 1; i >= 0; i--) {
      swap(&array[0], &array[i]);
      heapify(array, i, 0);
    }
    return compares;
}

void merge(int array[], int leftIndex, int middleIndex, int rightIndex)
{
    int i, j, k;
    int n1 = middleIndex - leftIndex + 1;
    int n2 = rightIndex - middleIndex;
  
    int L[n1], R[n2];
  
    for (i = 0; i < n1; i++)
        L[i] = array[leftIndex + i];
    for (j = 0; j < n2; j++)
        R[j] = array[middleIndex + 1 + j];
  
    i = 0;
    j = 0;
    k = leftIndex;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            array[k] = L[i];
            i++;
        }
        else {
            array[k] = R[j];
            j++;
        }
        k++;
    }
  
    while (i < n1) {
        array[k] = L[i];
        i++;
        k++;
    }
  
    while (j < n2) {
        array[k] = R[j];
        j++;
        k++;
    }
}
  
void _mergeSort(int array[], int leftIndex, int rightIndex)
{
    if (leftIndex < rightIndex) {
        int middleIndex = leftIndex + (rightIndex - leftIndex) / 2;
  
        _mergeSort(array, leftIndex, middleIndex);
        _mergeSort(array, middleIndex + 1, rightIndex);
  
        merge(array, leftIndex, middleIndex, rightIndex);
    }
}

int mergeSort(int array[], int size) {
    int compares = 0;
    _mergeSort(array, 0, size - 1);
    return compares;
}

void _quickSort(int array[], int left, int right) {
    int i, j, x;
     
    i = left;
    j = right;
    x = array[(left + right) / 2];
     
    while(i <= j) {
        while(array[i] < x && i < right) {
            i++;
        }
        while(array[j] > x && j > left) {
            j--;
        }
        if(i <= j) {
            swap(&array[i], &array[j]);
            i++;
            j--;
        }
    }
     
    if(j > left) {
        _quickSort(array, left, j);
    }
    if(i < right) {
        _quickSort(array, i, right);
    }
}

int quickSort(int array[], int size) {
    int compares = 0;
    _quickSort(array, 0, size - 1);
    return compares;
}

int countingSort(int array[], int size) {

    int output[size];
    int compares = 0;

    int max = array[0];
    for (int i = 1; i < size; i++) {
    if (array[i] > max)
        max = array[i];
    }

    int count[max + 1];

    for (int i = 0; i <= max; ++i) {
        count[i] = 0;
    }

    for (int i = 0; i < size; i++) {
        count[array[i]]++;
    }

    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    for (int i = size - 1; i >= 0; i--) {
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    for (int i = 0; i < size; i++) {
        array[i] = output[i];
    }
    return compares;
}
