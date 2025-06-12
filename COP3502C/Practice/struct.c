#include <stdio.h>

typedef struct Student
{
	char *firstName;
	char *lastName;
	int ID;
	float GPA;
} student_t;

int main(void)
{

	student_t s1;
	s1.firstName = "Kurt";
	s1.lastName = "Kullu";
	s1.ID = 1234567;
	s1.GPA = 3.4;

	printStudent(s1);
	return 0;
}

void display_student(student_t s)
{
	printf("[%s %s, %d, %f]\n", s.firstName, s.lastName, s.ID, s.GPA);
}