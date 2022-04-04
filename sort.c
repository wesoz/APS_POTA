void sortArrayList(int **arrayList, int arrayQuantity, int arraySize, void (*func)(int*, int)) {
	int i;
	for (i = 0; i < arrayQuantity; i++) {
		func(arrayList[i], arraySize);
	}
}

void bubbleSort (int *array, int arraySize) {
    int k, j, aux;
    for (k = 1; k < arraySize; k++) {
        for (j = 0; j < arraySize - 1; j++) {
            if (array[j] > array[j + 1]) {
                aux          = array[j];
                array[j]     = array[j + 1];
                array[j + 1] = aux;
            }
        }
    }
}