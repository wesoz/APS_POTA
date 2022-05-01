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

void heapify(int arr[], int n, int i) {
    // Find largest among root, left child and right child
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
  
    if (left < n && arr[left] > arr[largest])
      largest = left;
  
    if (right < n && arr[right] > arr[largest])
      largest = right;
  
    // Swap and continue heapifying if root is not largest
    if (largest != i) {
      swap(&arr[i], &arr[largest]);
      heapify(arr, n, largest);
    }
  }
  
  // Main function to do heap sort
void heapSort(int arr[], int n) {
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
      heapify(arr, n, i);
  
    // Heap sort
    for (int i = n - 1; i >= 0; i--) {
      swap(&arr[0], &arr[i]);
  
      // Heapify root element to get highest element at root again
      heapify(arr, i, 0);
    }
  }