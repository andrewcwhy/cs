#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 100

typedef struct hub
{
    char name[MAX_NAME_LEN];
    int distance;
    int hour;
    struct hub *next;
} hub_t;

int is_empty(Hub *head);
void insert_at_head(Hub **head, const char *name, int distance, int hour);
void insert_at_tail(Hub **head, const char *name, int distance, int hour);
void print_chain(Hub *head);
int total_distance(Hub *head);
void print_chain_reverse(Hub *head);
void display_bottleneck(Hub *head);
Hub search_hub(Hub *head, const char *keyword);
void remove_first_match(Hub **head, const char *keyword);

int main(void)
{
    printf("=== ParcelTrack Delivery Chain Test ===\n\n");
    Hub *chain = NULL;
    // Test insert_at_head and insert_at_tail
    insert_at_head(&chain, "Orlando", 0, 9);
    insert_at_tail(&chain, "Atlanta", 400, 14);
    insert_at_tail(&chain, "Charlotte", 350, 17);
    printf("Delivery chain:\n");
    print_chain(chain);
    printf("\n");
    // Test total_distance
    int total = total_distance(chain);
    printf("Total distance: %d km\n\n", total);
    // Test display_bottleneck
    // Uncomment the line below if bonus attempted
    // display_bottleneck(chain);
    // Test search_hub
    Hub found = search_hub(chain, "lanta");
    if (strcmp(found.name, "None"))
    {
        printf("Search result: Found ");
        printf("\"{%s, %d, %d}\"\n\n", found.name, found.distance,
               found.hour);
    }
    else
        printf("Search result: No match found\n\n");
    // Test print_chain_reverse
    printf("Reverse delivery chain:\n");
    print_chain_reverse(chain);
    printf("\n");
    // Test remove_first_match
    remove_first_match(&chain, "lanta");
    printf("After removing first match for \"lanta\":\n");
    print_chain(chain);
    printf("\n");
    return 0;
}

// Returns 1 if the list is empty, 0 otherwise.
int is_empty(Hub *head)
{
    return head == NULL;
}

// Inserts a new hub at the beginning of the list.
void insert_at_head(Hub **head, const char *name, int distance, int hour)
{
    Hub *node = (Hub *)malloc(sizeof(Hub));
    strncpy(node->name, name, MAX_NAME_LEN - 1);
    node->name[MAX_NAME_LEN - 1] = '\0';
    node->distance = distance;
    node->hour = hour;
    node->next = *head;
    *head = node;
}

// Recursively inserts a new hub at the end of the list.
void insert_at_tail(Hub **head, const char *name, int distance, int hour)
{
    if (*head == NULL)
    {
        insert_at_head(head, name, distance, hour);
        return;
    }
    insert_at_tail(&(*head)->next, name, distance, hour);
}

// Iteratively prints all hubs in order.
void print_chain(Hub *head)
{
    for (Hub *curr = head; curr != NULL; curr = curr->next)
    {
        printf("%s - %d km, %dh\n", curr->name, curr->distance, curr->hour);
    }
}

// Returns the total sum of all distances across the list.
int total_distance(Hub *head)
{
    int sum = 0;
    for (Hub *curr = head; curr != NULL; curr = curr->next)
    {
        sum += curr->distance;
    }
    return sum;
}

// Recursively prints delivery chain in reverse order.
void print_chain_reverse(Hub *head)
{
    if (head == NULL)
        return;
    print_chain_reverse(head->next);
    printf("%s - %d km, %dh\n", head->name, head->distance, head->hour);
}

// Finds and prints the segment with the maximum time between hubs.
void display_bottleneck(Hub *head)
{
    if (!head || !head->next)
    {
        printf("Not enough hubs to determine a bottleneck.\n");
        return;
    }
    Hub *curr = head;
    Hub *bottleneck_from = head;
    Hub *bottleneck_to = head->next;
    int max_diff = bottleneck_to->hour - bottleneck_from->hour;
    if (max_diff < 0)
        max_diff = -max_diff;
    curr = curr->next;
    while (curr->next)
    {
        int diff = curr->next->hour - curr->hour;
        if (diff < 0)
            diff = -diff;
        if (diff > max_diff)
        {
            max_diff = diff;
            bottleneck_from = curr;
            bottleneck_to = curr->next;
        }
        curr = curr->next;
    }
    printf("Bottleneck: %s -> %s, %d hour(s)\n",
           bottleneck_from->name,
           bottleneck_to->name,
           max_diff);
}

// Returns a copy of the first hub whose name contains keyword.
Hub search_hub(Hub *head, const char *keyword)
{
    Hub result;
    while (head)
    {
        if (strstr(head->name, keyword))
        {
            strncpy(result.name, head->name, MAX_NAME_LEN - 1);
            result.name[MAX_NAME_LEN - 1] = '\0';
            result.distance = head->distance;
            result.hour = head->hour;
            result.next = NULL;
            return result;
        }
        head = head->next;
    }
    // No match found
    strncpy(result.name, "None", MAX_NAME_LEN - 1);
    result.name[MAX_NAME_LEN - 1] = '\0';
    result.distance = -1;
    result.hour = -1;
    result.next = NULL;
    return result;
}

// Removes the first node whose name contains keyword.
void remove_first_match(Hub **head, const char *keyword)
{
    if (!head || !*head)
        return;
    Hub *curr = *head;
    // If head matches
    if (strstr(curr->name, keyword))
    {
        *head = curr->next;
        free(curr);
        return;
    }
    Hub *prev = curr;
    curr = curr->next;
    while (curr)
    {
        if (strstr(curr->name, keyword))
        {
            prev->next = curr->next;
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}
