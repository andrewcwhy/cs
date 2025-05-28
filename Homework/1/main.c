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

int main()
{
    char filename[MAX_FILENAME_LENGTH + 1];

    get_filename(filename);

    int search_student_id;
    printf("Enter student ID to search for: ");
    scanf("%d", &search_student_id);

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
        printf("ERROR: Could not open find the file %s.\n", filename);
        return -1;
    }

    file = fopen(filename, "r");

    fscanf(file, "%d\n%s\n%s\n%f", &id, &first_name, &last_name, &gpa);

    fclose(file);
}

void display_student_info(student_t student)
{
    printf("-----Student Information-----\n");
    printf("ID: %d\n", student->id);
    printf("Full Name: %s %s\n", student->first_name, student->last_name);
    printf("GPA: %.2f\n", student->gpa);
}