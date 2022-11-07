#include <stdio.h>
#include <stdlib.h>

void printElementsOfArray(int* array, int size) {
	int i;
	printf("Our array: \n");
	for(i = 0; i < size; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
}

//method adding element at the end of list
int* add(int* array, int element, int* size) {
	*size+=1;
	array = (int*) realloc(array, *size * (int)sizeof(int));
	array[*size - 1] = element;
	return array;
}

int sizeOfArray(int size) {
	printf("Size of ArrayList is %d\n", size);
	return size;
}

int* insert(int* array, int index, int* size, int element) {
	*size+=1;
	array = realloc(array, (*size) * sizeof(int));
	int i;
	for(i = index; i < *size -1; i++)
	{
		array[i] = array[i + 1];
	} 
	array[index] = element;  
	return array;
}

int* removeElementByIndex(int* array, int index, int* size) {
	int i;
	for(i = index; i < *size - 1; i++)
	{
		array[i] = array[i + 1];
	} 
	array = realloc(array, (*size - 1) * sizeof(int));
	*size-=1;
	return array;
}

void set(int* array, int element, int index) {
	array[index] = element;
	return;
}

int get(int* array, int index) {
	printf("Element by %d index is %d\n", index, array[index]);
	return array[index];
}

int main() {
	int size = 0, *array = NULL;
	array = add(array, 3, &size);
	array = add(array, 4, &size);
	array = add(array, 5, &size);
	printElementsOfArray(array, size);
	
	set(array, 12, 0);
	printElementsOfArray(array, size);
	
	array = removeElementByIndex(array, 0, &size);
	printElementsOfArray(array, size);
	
	array = insert(array, 1, &size, 22);
	printElementsOfArray(array, size);
	return 0;
}
