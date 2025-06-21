#include <stdio.h>
#include <string.h>

int main() {

	char name1[5] = "Kurt";
	char name2[5] = "Kurt";
	
	if (strcmp(name1, name2) == 0) 
		printf("They are the same!\n");
	else 
		printf("They are different!\n");
	return 0;
}