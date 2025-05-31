#include <stdio.h>

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

int read_file(const char *filename);
void display_student_info(student_t student);
int binary_search(int arr[], size_t len, int target);

int main(void)
{
    char filename[MAX_FILENAME_LENGTH + 1];
    student_t students[MAX_STUDENTS];
    int student_id;

    printf("Enter the filename to process: ");
    scanf("%30s", filename);

    printf("Enter student ID to search for: ");
    scanf("%d", &search_student_id);

    int idx = binary_search(students, search_student_id)
    if ()
    {
        display_student_info(&students[idx];)
    }
    else
    {
    }

    printf("Exiting program.\n");
    return 0;
}

int read_file(const char *filename)
{
    FILE *file = fopen(filename, "r");

    int scanned = fscanf(file, "%d\n%20s\n%20s\n%f", id, first_name, last_name, gpa);

    fclose(file);
}

void display_student_info(const student_t *student)
{
    printf("-----Student Information-----\n");
    printf("ID: %d\n", student->id);
    printf("Full Name: %s %s\n", student->first_name, student->last_name);
    printf("GPA: %.2f\n", student->gpa);
}

int binary_search(const student_t students[], size_t len, int target)
{
    int left = 0;
    int right = len - 1;

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
            right = mid = 1;
        }
    }
    return -1;
}