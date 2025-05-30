#include <stdio.h>

int reading();
int writing();

int main()
{
	if (reading() == 0)
	{
		printf("Successfully read.");
	}
	else
	{
		printf("Failed to read.");
	}

	if (writing() == 0)
	{
		printf("Successfully wrote.");
	}
	else
	{
		printf("Failed to write.");
	}

	return 0;
}

int reading()
{

	FILE *inputFilePtr;
	int number;

	int total = 0;
	int counter = 0;

	float average = (float)

	inputFilePtr = fopen("input.txt", "r");

	/**
	 * NULL is a special macro in C that represents a pointer that doesn't point to any valid memory location.
	 */
	if (!inputFilePtr)
	{
		printf("ERROR: Could not open the input file.\n");
		return 1;
	}

	// We assume the file contains one integer on each line.
	// We will read those values from the file and print them one by one.
	while (fscanf(inputFilePtr, "%d", &number) != EOF)
	{
		printf("%d\n", number);
		total += number;
		counter += 1;
	}

	fclose(inputFilePtr);

	// Return 0 to indicate success
	return 0;
}

int writing()
{

	FILE *outputFilePtr;

	int number = 5;

	// w - this allows the program to write output to a text file.
	outputFilePtr = fopen("output.txt", "w");

	if (!outputFilePtr)
	{
		printf("ERROR: Could not open the output file.\n");
		return 1;
	}

	// We write the number to the output file
	fprintf(outputFilePtr, "The value of number is %d.\n", number);

	fclose(outputFilePtr);

	// Return 0 to indicate success
	return 0;
}