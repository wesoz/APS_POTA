#ifndef ARRAYS_HEADER_GUARD
#define ARRAYS_HEADER_GUARD

struct ArrayList {
	int **arrays;
	int size;
	int quantity;
};

int * createArray(int size);
int ** createArrayList(struct ArrayList arrayList);
void printArray(int *arrayPointer, int size);
void printArrayList(struct ArrayList arrayList, char title[]);
void populateArray(int *arrayPointer, int size);

#endif