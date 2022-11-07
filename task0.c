#include <stdio.h>
#include <time.h>

struct Dot {
	float weight;
};

struct Dot* removeElement(struct Dot* array, int sizeOfArray, int indexToRemove)
{
    struct Dot* temp = malloc((sizeOfArray - 1) * sizeof(struct Dot)); // allocate an array with a size 1 less than the current one

    if (indexToRemove != 0)
        memcpy(temp, array, indexToRemove * sizeof(struct Dot)); // copy everything BEFORE the index

    if (indexToRemove != (sizeOfArray - 1))
        memcpy(temp+indexToRemove, array+indexToRemove+1, (sizeOfArray - indexToRemove - 1) * sizeof(struct Dot)); // copy everything AFTER the index
          
    free (array);
    return temp;
}

int findIndexOfLowestWeightDot(struct Dot* dots, int quantityOfDots) {
	float minValue = dots[0].weight;
	int indexOfLowestElement = 0;
	int i, j;
	for (i = 0; i < quantityOfDots; i++) {
		for (j = 0; j < quantityOfDots; j++)
		if (minValue > dots[j].weight) {
			minValue = dots[j].weight;
			indexOfLowestElement = j;
		}
	}
	printf("Lowest number: %f\n", dots[indexOfLowestElement].weight);
	printf("Lowest index: %d\n", indexOfLowestElement);
	return indexOfLowestElement;
}


int main() {
	srand(time(NULL));
	int quantityOfDots;
	printf("Enter quantityOfDots: ");
	scanf("%d", &quantityOfDots);
	
	//struct Dot* dots[quantityOfDots];
	struct Dot* dots = malloc(quantityOfDots * sizeof(struct Dot));
	int i;
	for (i = 0; i < quantityOfDots; i++) {
	dots[i].weight = (float) rand() / 100;
	printf("%f\n", dots[i].weight);
}
	int indexToRemove;
	while(quantityOfDots != 1) {
		printf("\n\nOur array\n");
		for (i = 0; i < quantityOfDots; i++) {
		printf("%f\n", dots[i].weight);
		}
		indexToRemove = findIndexOfLowestWeightDot(dots, quantityOfDots);
		//если у нас последний элемент, мы передаем массу предыщему элементу
		// в ином слуаче передаем массу следующему элементу
		if (indexToRemove ==  quantityOfDots - 1) {
			dots[indexToRemove - 1].weight += dots[indexToRemove].weight;
		} else {
			dots[indexToRemove + 1].weight += dots[indexToRemove].weight;
		}
		dots = removeElement(dots, quantityOfDots, indexToRemove);
		quantityOfDots--;
	}
	
	
	for (i = 0; i < quantityOfDots; i++) {
		printf("Last dot is %f\n", dots[i].weight);
	}
	
	
	
	return 0;
}
