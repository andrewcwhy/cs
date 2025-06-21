#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 30
#define MAX_NAME_LENGTH 20
#define MAX_STUDENTS 100

typedef struct Student
{
    int id;
    char first_name[MAX_NAME_LENGTH + 1];
    char last_name[MAX_NAME_LENGTH + 1];
    float gpa;
} student_t;

int read_file(const char *filename, student_t students[], int *num_students);
void display_student(const student_t *student);
int binary_search(const student_t students[], int len, int target);

int main(void)
{
    char filename[MAX_FILENAME_LENGTH + 1];
    student_t students[MAX_STUDENTS];
    int num_students = 0;

    printf("Enter the filename to process: ");
    scanf("%30s", filename);

    if (read_file(filename, students, &num_students) != 0)
    {
        // Error message already printed inside read_file
        printf("Exiting program.\n");
        return 1;
    }

    int search_id;
    printf("Enter student ID to search for: ");
    scanf("%d", &search_id);

    int idx = binary_search(students, num_students, search_id);
    if (idx != -1)
    {
        display_student(&students[idx]);
    }
    else
    {
        printf("Student ID %d not found.\n", search_id);
    }

    printf("Exiting program.\n");
    return 0;
}

int read_file(const char *filename, student_t students[], int *num_students)
{
    FILE *file = fopen(filename, "r");

    if (!file)
    {
        printf("Error: Cannot open file '%s'.\n", filename);
        return -1;
    }

    int count = 0;
    int prev_id = -1;
    while (count < MAX_STUDENTS)
    {
        student_t student;
        int scanned = fscanf(file, "%d\n%20s\n%20s\n%f\n",
                             &student.id, student.first_name, student.last_name, &student.gpa);
        if (scanned == EOF)
        {
            break;
        }

        if (scanned != 4)
        {
            printf("Error: File format incorrect at line %d.\n", count + 1);
            fclose(file);
            return -1;
        }

        // Check sorted order
        if (student.id <= prev_id)
        {
            printf("Error: Student IDs not in increasing order (record %d).\n", count + 1);
            fclose(file);
            return -1;
        }
        prev_id = student.id;

        students[count++] = student;
    }

    *num_students = count;
    fclose(file);
    return 0;
}

void display_student(const student_t *student)
{
    printf("----- Student Info -----\n");
    printf("ID: %d\n", student->id);
    printf("Full Name: %s %s\n", student->first_name, student->last_name);
    printf("GPA: %.2f\n", student->gpa);
}

int binary_search(const student_t students[], int len, int target)
{
    int left = 0, right = len - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (students[mid].id == target)
        {
            return mid;
        }

        else if (students[mid].id < target)
        {
            left = mid + 1;
        }
        
        else
        {
            right = mid - 1;
        }
    }

    return -1;
}