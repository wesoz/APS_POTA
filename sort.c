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

void bubbleSort (int *array, int size) {
    int k, j, aux;
    for (k = 1; k < size; k++) {
        for (j = 0; j < size - 1; j++) {
            if (array[j] > array[j + 1]) {
                aux          = array[j];
                array[j]     = array[j + 1];
                array[j + 1] = aux;
            }
        }
    }
}