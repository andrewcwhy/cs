#include <stdio.h>

#define MAX_NID_LENGTH 8
#define MAX_NAME_LENGTH 32

typedef struct Student
{
    char nid[MAX_NID_LENGTH + 1];
    char sex;
    float gpa;
    char first_name[MAX_NAME_LENGTH + 1];
    char last_name[MAX_NAME_LENGTH + 1];
} student_t;

void display_student_info(const student_t student);

int main(void)
{
    student_t students[2];

    students[0] = (student_t){"an570531", 'm', 3.2, "Andrew", "Young"};
    students[1] = (student_t){"an570532", 'f', 3.2, "Briana", "Young"};

    size_t count = sizeof(students) / sizeof(students[0]);

    for (int i = 0; i < count; i++)
    {
        display_student_info(students[i]);
    }

    return 0;
}

void display_student_info(const student_t student)
{
    printf("-----Student %s-----\n", student.nid);
    printf("Full Name: %s %s\n", student.first_name, student.last_name);
    printf("Sex: %c\n", student.sex);
    printf("GPA: %.2f\n", student.gpa);
}