#include <stdio.h>

#define MAX_NID_LENGTH 8
#define MAX_NAME_LENGTH 32

struct Student
{
    char nid[MAX_NID_LENGTH + 1];
    char first_name[MAX_NAME_LENGTH + 1];
    char last_name[MAX_NAME_LENGTH + 1];
    char sex;
    float gpa;
};

void display_student_info(const struct Student student);

int main(void)
{
    struct Student students[3];

    students[0] = (struct Student){"an570531", "Andrew", "Young", 'm', 3.2};
    students[1] = (struct Student){"an570532", "Briana", "Young", 'f', 3.2};
    students[2] = (struct Student){"an570533", "Rosana", "Young", 'f', 3.2};

    size_t count = sizeof(students) / sizeof(students[0]);

    for (int i = 0; i < count; i++)
    {
        display_student_info(students[i]);
    }

    return 0;
}

void display_student_info(const struct Student student)
{
    printf("-----Student %s-----\n", student.nid);
    printf("Full Name: %s %s\n", student.first_name, student.last_name);
    printf("Sex: %c\n", student.sex);
    printf("GPA: %.2f\n", student.gpa);
}