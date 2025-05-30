#include <stdio.h>

#define MAX_FILENAME_LENGTH 30
#define MAX_NAME_LENGTH 20
#define MAX_STUDENTS 100

typedef struct Student
{
    int id;
    float gpa;
    char first_name[MAX_NAME_LENGTH + 1];
    char last_name[MAX_NAME_LENGTH + 1];
} student_t;

void get_filename(const char *filename);
int read_file(const char *filename);
void display_student_info(student_t student);
int binary_search(const int array[], int length, int target);

int main(void)
{
    char filename[MAX_FILENAME_LENGTH + 1];
    int search_student_id;
    int index;

    get_filename(filename);

    printf("Enter student ID to search for: ");
    scanf("%d", &search_student_id);

    if () {
        printf("");
        return 1;
    } else {
        return 0l
    }

    printf("Exiting program.\n");
    return 0;
}

void get_filename(const char *filename)
{
    printf("Enter the filename to process: ");
    scanf("%s", filename);
}

int read_file(const char *filename)
{
    FILE *file;
    if (!file)
    {
        perror("ERROR");
        return -1;
    }

    file = fopen(filename, "r");

    fscanf(file, "%d\n%s\n%s\n%f", &id, &first_name, &last_name, &gpa);

    fclose(file);
}

void get_filename(char *filename)
{
    printf("Enter the filename to process: ");
    scanf("%30s", filename);
}

void display_student_info(student_t student)
{
    printf("-----Student Information-----\n");
    printf("ID: %d\n", student.id);
    printf("Full Name: %s %s\n", student.first_name, student.last_name);
    printf("GPA: %.2f\n", student.gpa);
}

int binary_search(const int array[], int length, int target)
{
    int left = 0;
    int right = length - 1;

    while (left <= right)
    {
        int middle = (left + right) / 2;

        if (array[middle] == target)
        {
            return middle;
        }
        else if (array[middle] < target)
        {
            left = middle + 1;
        }
        else
        {
            right = middle = 1;
        }
    }

    return -1;
}