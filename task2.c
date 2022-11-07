#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>


void firstSubTask() {
	srand(time(NULL)); 
	
	const int maximum_number = 5;
	const int minimum_number = -5;
	
	float sum = 0.0;
	float averageValue;
	
	int inputSize;
	printf("Enter size of array: ");
	scanf("%d", &inputSize);
	
	int * arr = (int*) malloc(inputSize * sizeof(int));
	int i;
	for (i = 0; i < inputSize; i++) {
		arr[i] = (rand() % (maximum_number + 1 - minimum_number)) + minimum_number;
		printf("%d\n", arr[i]);
		sum += arr[i];
	}
	averageValue = sum / inputSize;
	printf("%f - average\n", averageValue);
	
	int quantityOfNumbersGreaterThanAverage = 0;
	for (i = 0; i < inputSize; i++) {
		if (arr[i] > averageValue) {
			quantityOfNumbersGreaterThanAverage++;
		}
	}
	
	printf("Numbers greater than average are %d", quantityOfNumbersGreaterThanAverage);
}

void secondSubTask() {
	srand(time(NULL)); 
	
	const int maximum_number = 5;
	const int minimum_number = -5;
	
	int inputSize;
	printf("Enter size of array: ");
	scanf("%d", &inputSize);
	
	int * arr = (int*) malloc(inputSize * sizeof(int));
	int firstNegativeIndex = 0; 
	bool hasNotFirstNegativeIndex = true;
	int i;
	for (i = 0; i < inputSize; i++) {
		arr[i] = (rand() % (maximum_number + 1 - minimum_number)) + minimum_number;
		printf("%d\n", arr[i]);
		if (arr[i] < 0 && hasNotFirstNegativeIndex) {
			firstNegativeIndex = i;
			hasNotFirstNegativeIndex = false;
		}
	}
	
	float sumOfModules = 0.0;
	//нам не нужно включать первое отрицательное число в нашу сумму
	for (i = firstNegativeIndex + 1; i < inputSize; i++) {
		sumOfModules += abs(arr[i]);
	}
	printf("Sum of modules after first negative value %d is %f", arr[firstNegativeIndex], sumOfModules);
}

int main() {
	//firstSubTask();
	secondSubTask();
	return 0;
}
