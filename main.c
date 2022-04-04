# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include "arrays.h"
# include "sort.h"

int ARR_QTTY = 3;


int main () {
	printf("Started\n\n");
	srand(time(NULL));

	int **arr5 = createArrayList(5, ARR_QTTY);
	//int **arr10 = createArrayList(10, ARR_QTTY);

	printArrayList(arr5, ARR_QTTY, 5);
	//bubbleSort(arr5[0], 5);
	sortArrayList(arr5, ARR_QTTY, 5, bubbleSort);
	printArrayList(arr5, ARR_QTTY, 5);
	//printArrayList(arr10, ARR_QTTY, 10);
	
	free(arr5);
	//free(arr10);
	
	printf("\nFinished\n");
	return 0;
}


