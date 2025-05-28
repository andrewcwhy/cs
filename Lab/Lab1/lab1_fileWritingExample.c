#include <stdio.h> 

int main() {
	
	FILE *outputFilePtr; 
	
	int number = 5;
	
	outputFilePtr = fopen("output.txt", "w");
	
	if (!outputFilePtr) { 
		printf("ERROR: Could not open the output file.\n"); 
		return 1; 
	} 
	
	// We write the number to the output file
	fprintf(outputFilePtr, "The value of number is %d.\n", number); 
	
	fclose(outputFilePtr); 
	return 0; 
}