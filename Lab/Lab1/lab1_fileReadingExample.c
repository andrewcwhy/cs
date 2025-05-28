#include <stdio.h> 

int main() {
	
	FILE *inputFilePtr; 
	int number; 
	
	inputFilePtr = fopen("input.txt", "r");
	
	if (!inputFilePtr) { // also show inputFilePtr == NULL
		printf("ERROR: Could not open the input file.\n"); 
		return 1; 
	} 
	
	// We assume the file contains one integer on each line. 
	// We will read those values from the file and print them one by one. 
	while (fscanf(inputFilePtr, "%d", &number) != EOF) {
		printf("%d\n", number); 
	}
	
	fclose(inputFilePtr); 
	return 0; 
}