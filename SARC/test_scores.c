#include <stdio.h>
#include <stdlib.h>

// Create a gradebook array of three students, and initialize it.

typedef struct Student
{
    int id;
    test_score_t *scores;
} student_t;

typedef struct TestScore
{
    int grade;
    char letter_grade;
} test_score_t;

void test_scores(test_score_t *scores);

int main(void)
{
    student_t *students = malloc(3 * sizeof(student_t));

    for (int i = 0; i < 3; i++)
    {
        students[i].id = i + 1;
        test_scores(students[i].scores);
    }

    return 0;
}

void test_scores(test_score_t *scores)
{
    scores = malloc(2 * sizeof(test_score_t));
    scores[0].grade = 100;
    scores[0].letter_grade = 'A';
    scores[1].grade = 100;
    scores[1].letter_grade = 'A';
}
