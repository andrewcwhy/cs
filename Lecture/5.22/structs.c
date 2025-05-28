#include <stdio.h>

struct Student {
    char first_name;
    char last_name;
    char NID;
    float GPA;
};

void print_student(struct Student s);


int main() {
    // Create a structure variable of Student called s1
    struct Student student1 = {"Andrew", "Young", "an570531", 3.2};

    print_student(student1);

    return 0;;
}

void print_student(struct Student s) {
    printf("Name: %s %s\n:", s.first_name, s.last_name);
    printf("NID: %s\n", s.NID);
    printf("GPA: %.2f\n", s.GPA);
}