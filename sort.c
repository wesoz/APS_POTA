# include <stdlib.h>

int * copyArray(int *array, int size)
{
    int *arrayCopy = (int *)calloc(size, sizeof(int));
    for (int i = 0; i < size; ++i)
    {
        arrayCopy[i] = array[i];
    }
    return arrayCopy;
}

int ** sortArrayList(int **arrayList, int arrayQuantity, int arraySize, void (*func)(int*, int)) {
    int **arrayListCopy = (int **)calloc(arrayQuantity, sizeof(int) * arraySize * arrayQuantity);
	int i;
	for (i = 0; i < arrayQuantity; i++) {
        int *array = copyArray(arrayList[i], arraySize);
		func(array, arraySize);
        arrayListCopy[i] = array;
	}
    return arrayListCopy;
}

void swap(int *elementA, int *elementB)
{
    int temp = *elementA;
    *elementA = *elementB;
    *elementB = temp;
}

void bubbleSort (int *array, int size) {
    int k, j, aux;
    for (k = 1; k < size; k++) {
        for (j = 0; j < size - 1; j++) {
            if (array[j] > array[j + 1]) {
                swap(&array[j], &array[j + 1]);
            }
        }
    }
}

void selectionSort(int *array, int size) {
    int i, j, min_idx;
  
    for (i = 0; i < size-1; i++)
    {
        min_idx = i;
        for (j = i+1; j < size; j++)
          if (array[j] < array[min_idx])
            min_idx = j;
        swap(&array[min_idx], &array[i]);
    }
}

void insertionSort(int array[], int size) {
    int i, key, j;
    for (i = 1; i < size; i++) {
        key = array[i];
        j = i - 1;
 
        /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
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
  
void heapSort(int array[], int size) {
    
    for (int i = size / 2 - 1; i >= 0; i--)
      heapify(array, size, i);
  
    for (int i = size - 1; i >= 0; i--) {
      swap(&array[0], &array[i]);
      heapify(array, i, 0);
    }
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
  
void doMergeSort(int array[], int leftIndex, int rightIndex)
{
    if (leftIndex < rightIndex) {
        int middleIndex = leftIndex + (rightIndex - leftIndex) / 2;
  
        doMergeSort(array, leftIndex, middleIndex);
        doMergeSort(array, middleIndex + 1, rightIndex);
  
        merge(array, leftIndex, middleIndex, rightIndex);
    }
}

void mergeSort(int array[], int size) {
    doMergeSort(array, 0, size - 1);
}