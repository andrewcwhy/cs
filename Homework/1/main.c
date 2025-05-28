#include <stdio.h>

#define MAX_FILENAME_LENGTH 30
#define MAX_NAME_LENGTH 20
#define MAX_STUDENTS 100

typedef struct
{
    int id;
    char first_name[MAX_NAME_LENGTH + 1];
    char last_name[MAX_NAME_LENGTH + 1];
    float gpa;
} Student;

void get_filename(const char *filename);
int read_file(const char *filename);
void print_student_info(const Student *s);

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

void print_student_info(const Student *s)
{
    printf("Student Information:\n");
    printf("ID: %d\n", s->id);
    printf("Name: %s %s\n", s->first_name, s->last_name);
    printf("GPA: %.2f\n", s->gpa);
}