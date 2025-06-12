#include <stdio.h> 
#include <stdlib.h>

int main() {
	
	float input;
	int entryCount = 0;
	printf("Enter the number of entries: "); 
	scanf("%d", &entryCount); 
	
	float *tempsPtr = malloc(sizeof(float)*entryCount);
	if (!tempsPtr) { // tempsPtr == NULL
		printf("ERROR: memory allocation failed!\n"); 
		return 1; 
	}
	
	for (int i = 0; i < entryCount; i++) {
		printf("Enter the next data: "); 
		scanf("%f", &input);
		tempsPtr[i] = input;
	}
	
	float sum = 0;
	for (int i = 0; i < entryCount; i++) {
		sum += tempsPtr[i]; // sum = sum + tempsPtr[i];
	}
	free(tempsPtr); 
	tempsPtr = NULL;
	
	printf("The average temperature is %f\n", sum / entryCount);
}