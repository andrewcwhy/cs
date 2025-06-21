#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char letter;
    struct Node *next;
};

void mix_words(struct Node *w1, struct Node *w2);

int main(void)
{

    char w1[] = "hello";
    char w2[] = "computer";

    mix_words(w1, w2);

    return 0;
}

void mix_words(struct Node *w1, struct Node *w2)
{
    while (w1 != NULL && w2 != NULL)
    {
        if (w1 != NULL)
        {
            printf("%c", w1->letter);
            w1 = w1->next;
        }

        if (w2 != NULL)
        {
            printf("%c", w2->letter);
            w2 = w2->next;
        }
    }
}