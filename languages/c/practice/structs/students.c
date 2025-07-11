#include <stdio.h>
#include <stdlib.h>

typedef struct student
{
    char *name;
    int age;
    float gpa;
} student_t;

student_t *create_student(const char *name, int age, float gpa);

int main(void)
{
    student_t student1 = {"Alice", 20, 3.5};
    student_t student2 = {"Bob", 22, 3.8};

    student_t students[2] = {student1, student2};

    for (int i = 0; i < sizeof(students)/ sizeof(students[0]); i++)
    {
        printf("Student %d:\n", i + 1);
        printf("Name: %s\n", students[i].name);
        printf("Age: %d\n", students[i].age);
        printf("GPA: %.2f\n", students[i].gpa);
        printf("\n");
    }

    return 0;
}

student_t *create_student(const char *name, int age, float gpa)
{
    student_t *student = malloc(sizeof(student_t));

    if (!student) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < sizeof(), i++) {
        student[i].name = malloc(strlen(name) + 1);
        strcpy(student[i].name, name);
    }

}